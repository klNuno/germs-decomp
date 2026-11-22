# disks

<sub>[germs-decomp](../README.md) / disks</sub>

Put your own dump of the game disc here. Git ignores everything in this folder except this file.

Expected names:

- `SLPS-02107.bin`: the raw MODE2/2352 image, or a link to it (190,013,376 bytes, sha1
  `8ef1ed69c8f532d8e2ee91e1e4650b6a014ac2d4` for the retail disc).
- `SLPS-02107.cue`: the cue sheet, three lines:

  ```text
  FILE "SLPS-02107.bin" BINARY
    TRACK 01 MODE2/2352
      INDEX 01 00:00:00
  ```

A CHD converts with:

```sh
cd disks
chdman extractcd -i "/path/to/your-dump.chd" -o SLPS-02107.cue -ob SLPS-02107.bin
```

Then `make check-disk` extracts the disc into `extract/` and checks that `SLPS_021.07` has the sha1 in
`config/SLPS_021.07.sha1`.
