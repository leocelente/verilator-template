/* 
  Module: Top
  Description: This is a test module to test a SystemVerilog Simulation
  toolchain based on Verilator
*/
module top #(parameter WORD = 8)(
  input logic clock_in,
  input logic reset_in,
  input logic direction_in,
  output logic [WORD-1:0] count_out,
  output logic overflow_out
);

localparam MAX_COUNT = (1 << WORD) - 1;

logic [WORD-1:0] count;
logic overflow;

always_ff @( posedge clock_in or posedge reset_in) begin : next
  if (reset_in) begin
    // reset state to 0s
    count <= 'b0; 
    overflow <= 1'b0; 
  end

  else if (count < MAX_COUNT) begin
    // currently not overflowing...
    if (direction_in) begin
      count <= count + 1;
    end
    else begin
      count <= count - 1;
    end 
  end
  else if (count == 0 && direction_in == 1'b0) begin
    // overflowing down
    overflow <= 1'b1;
  end
  else begin
    // overflowing up
    overflow <= 1'b1;
  end
end
assign overflow_out = overflow;
assign count_out = count;
endmodule
