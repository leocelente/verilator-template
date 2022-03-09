
// Include common routines
#include "verilated.h"
#include <memory>
// Include model header, generated from Verilating "top.v"
#include "Vtop.h"

struct Top {
  std::unique_ptr<Vtop> top;

  [[nodiscard]] Top() { top = std::make_unique<Vtop>(); }

  void run() {
    while (!Verilated::gotFinish()) {
      // Evaluate model
      top->eval();
    }
  }

  ~Top() { top->final(); }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv,
         [[maybe_unused]] char **env) {

  Top top{};
  top.run();

  return 0;
}
