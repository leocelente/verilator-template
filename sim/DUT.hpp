#pragma once
// Smart Pointers
#include <memory>
// Verilator Lib
#include <verilated.h>
// Tracing support
#include <verilated_vcd_c.h>

/*
  Struct wrapping verilator's tracer feature
  to create VCDs (Value Change Dump) files with RTTI
*/
struct VCDTracer {
  std::unique_ptr<VerilatedVcdC> m_trace;
  [[nodiscard]] VCDTracer() {
    Verilated::traceEverOn(true);
    m_trace = std::make_unique<VerilatedVcdC>();
  }
  ~VCDTracer() { m_trace->close(); }
};

/*
  Generic DUT (Device Under Test) class
  templated on the class generated by verilator.
  To use it the user must provide a implementation of
  the `run` method that is specialized on the class of
  interest.

  `template <> void DUT< GeneratedClass > ::run(vluint64_t max_cycles)`

*/
template <class Model> struct DUT {
  std::unique_ptr<Model> top{};
  vluint64_t cycles = 0;
  VCDTracer tracer{};

  [[nodiscard]] DUT() {
    top = std::make_unique<Model>();
    top->trace(tracer.m_trace.get(), 5);
    Verilated::mkdir("waves");
    tracer.m_trace->open("waves/top.vcd");
  }

  /* User gives specilized implementation to run their model */
  void run(vluint64_t max_cycles);

  ~DUT() { top->final(); }
};
