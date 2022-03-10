# Verilator Template
This is a template repository to jumpstart (System)Verilog HDL projects based on the Verilator simulator.

## Dependencies
I don't use any specific version of Verilator (yet), so the default debian package should be enough.
 - `verilator`
 - `gtkwave`
 - `cmake`
 - `make`
 - C++ Compiler supporting C++17

I've only tested this on Linux (PopOS 21.10)

## Run
The convenient version is:
```bash
$ source cmd_aliases
$ config
$ compile
$ execute
$ view
```

This is based on the short aliases. But they are nothing much, just:
```bash
alias config="cmake -B build ."
alias compile="cmake --build build --config Debug -j `nproc`"
alias execute="./build/Vtop"
alias view="gtkwave waves/*.vcd"
```

## Notes
If GTKWave signals are small on the screen, add this to a `~/.gtkwaverc` config file:
```
fontname_signals Monospace 12
fontname_waves Monospace 12
```



