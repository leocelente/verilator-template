
// Include model header, generated from Verilating "top.v"
#include "DUT.hpp"
#include "Vtop.h"

template <> void DUT<Vtop>::run(vluint64_t max_cycles) {
  // initialize input/output signals
  top->clock_in = 0;
  top->reset_in = 0;
  top->direction_in = 1;

  // Simulation Loop
  for (cycles = 0; !Verilated::gotFinish() && cycles < max_cycles; ++cycles) {
    top->clock_in ^= 1; // toggle clock
    top->eval();
    tracer.m_trace->dump(cycles);
  }
}

int main(int argc, char **argv, [[maybe_unused]] char **env) {

  Verilated::commandArgs(argc, argv);

  DUT<Vtop> dut{};
  dut.run(64);

  return 0;
}
