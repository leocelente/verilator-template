# SystemVerilog Template
This is a template repository to jumpstart SystemVerilog HDL projects based 
on the Verilator simulator.

## Dependencies
I don't use any specific version of verilator (yet), so the default debian package should be enough.
 - `verilator`
 - `gtkwave`
 - `cmake`
 - `make`
 - C++ Compiler supporting C++17

I've only tested this on Linux (PopOS 21.10)

## Run
```bash
$ source cmd_aliases
$ config
$ compile
$ execute
```

This is based on the short aliases. But they are nothing much, just:
```
alias config="cmake -B build ."
alias compile="cmake --build build --config Debug -j `nproc`"
alias execute="./build/Vtop"
```

