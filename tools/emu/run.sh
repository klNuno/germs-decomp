#!/usr/bin/env bash
# Licence: MIT for the code written for this project only; game-derived data and Sony names in it are excluded (LICENSING.md).
# Run the game headless in PCSX-Redux (no window, sound only to a file) and drive it with Lua.
#   tools/emu/run.sh [extra.lua ...]
# tools/emu/probe.lua always runs first; it reads these variables:
#   GERMS_EMU_FRAMES  quit after this many vsyncs (default 1800, about 30 s)
#   GERMS_EMU_SHOTS   comma-separated vsync numbers to capture, e.g. 2700,3600
#   GERMS_EMU_REGS    print pc, gp, sp, ra every N vsyncs (default 0, off)
#   GERMS_EMU_OUT     capture folder (default captures, ignored by git)
#   GERMS_EMU_DEBUG   1 runs the interpreter with the debugger, needed for PCSX.addBreakpoint (slower)
#   GERMS_EMU_AUDIO   record the sound output to this .wav file (SDL's disk driver, 44.1 kHz stereo,
#                     paced in real time); a bare name goes in GERMS_EMU_OUT; also written when the run
#                     times out; unset, the sound goes to SDL's dummy driver
# Also: GERMS_BIOS (default disks/bios.bin), GERMS_DISC (default disks/SLPS-02107.cue), GERMS_EMU_TIMEOUT (seconds, default 300).
set -euo pipefail
cd "$(dirname "$0")/../.."
emu=tools/src/pcsx-redux/AppRun
bios=${GERMS_BIOS:-disks/bios.bin}
disc=${GERMS_DISC:-disks/SLPS-02107.cue}
[ -x "$emu" ] || { echo "no emulator: run tools/setup.sh"; exit 1; }
[ -f "$bios" ] || { echo "no BIOS: link your own dump of a Japanese BIOS as $bios (see disks/README.md)"; exit 1; }
[ -f "$disc" ] || { echo "no disc: see disks/README.md"; exit 1; }
export GERMS_EMU_OUT=${GERMS_EMU_OUT:-captures}
mkdir -p "$GERMS_EMU_OUT"
if [ -n "${GERMS_EMU_AUDIO:-}" ]; then
  audio=$GERMS_EMU_AUDIO
  case $audio in */*) ;; *) audio=$GERMS_EMU_OUT/$audio ;; esac
  mkdir -p "$(dirname "$audio")"
  audio_raw=$(mktemp "${TMPDIR:-/tmp}/germs-audio.XXXXXX")
  finish_audio() {
    local status=$? conv=0
    if [ -s "$audio_raw" ]; then
      ffmpeg -loglevel error -y -f f32le -ar 44100 -ac 2 -i "$audio_raw" -c:a pcm_s16le "$audio" || conv=$?
    fi
    rm -f "$audio_raw"
    [ "$conv" = 0 ] || echo "sound: conversion to $audio failed" >&2
    [ "$status" != 0 ] || status=$conv
    exit "$status"
  }
  trap finish_audio EXIT
  export SDL_AUDIO_DRIVER=disk SDL_AUDIO_DISK_OUTPUT_FILE=$audio_raw
else
  export SDL_AUDIO_DRIVER=dummy
fi
args=(-dofile tools/emu/probe.lua)
[ "${GERMS_EMU_DEBUG:-0}" = 1 ] && args=(-debugger -interpreter "${args[@]}")
for s in "$@"; do args+=(-dofile "$s"); done
timeout -k 10 "${GERMS_EMU_TIMEOUT:-300}" nice -n 10 "$emu" -cli -stdout -lua_stdout -no-gui-logs \
  -bios "$bios" -iso "$disc" -run "${args[@]}"
for raw in "$GERMS_EMU_OUT"/*.raw; do
  [ -e "$raw" ] || continue
  .venv/bin/python -I tools/emu/raw2png.py "$raw" && rm "$raw"
done
