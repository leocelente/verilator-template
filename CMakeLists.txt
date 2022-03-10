cmake_minimum_required(VERSION 3.21)
project(cmake_example VERSION 0.1.0 LANGUAGES CXX)

# Export compile_commands.json on configure
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Create a symbolic link to the compile_commands.json to the top project dir
execute_process(
    COMMAND ln -s build/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json
    ERROR_QUIET
    )

find_package(verilator HINTS $ENV{VERILATOR_ROOT})
if (NOT verilator_FOUND)
  message(FATAL_ERROR "Verilator was not found. Either install it, or set the VERILATOR_ROOT environment variable")
endif()

add_executable(Vtop sim/main.cpp)
# Run verilator command on SystemVerilog sources
verilate(Vtop TRACE SOURCES src/top.sv)
# Lets use C++17 for modern features
target_compile_features(Vtop PRIVATE cxx_std_17)
