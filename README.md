# myls

Implementation of unix `ls` command. <br />
List files and directories in specified order.


### Usage
```
myls [path|mask] [-l] [-h|--help] [--sort=U|S|t|X|D|s] [-r]
```
`-l` -- print detailed information about each file / directory. <br />
`-h|--help` -- help screen. <br />
`--sort` -- sorting option. <br />
- `U` -- unsorted. <br />
- `S` -- by size. <br />
- `t` -- by time of last modification. <br />
- `N` -- by name (default option). <br />
- `D` -- directories first. <br />
- `s` -- specific files separately. <br />

`-r` -- reversed order of sorted option. <br />
`-F` -- specify type of special files. <br />
`-R` -- bypass directories recursively. <br />
