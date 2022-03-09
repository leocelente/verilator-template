
// Include common routines
#include "verilated.h"
#include <memory>
// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

struct DUT {
  std::unique_ptr<Vtop> top;

  [[nodiscard]] DUT() { top = std::make_unique<Vtop>(); }

  void run() {
    while (!Verilated::gotFinish()) {
      // Evaluate model
      top->eval();
    }
  }

  ~DUT() { top->final(); }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv,
         [[maybe_unused]] char **env) {

  DUT dut{};
  dut.run();

  return 0;
}
