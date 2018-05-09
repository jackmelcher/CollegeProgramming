`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:46:10 01/19/2016
// Design Name:   output_mux
// Module Name:   C:/Users/Ryan/Desktop/CSE 132L Processor/Lab2/output_mux_tb.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: output_mux
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module output_mux_tb;

	// Inputs
	reg [31:0] alu_out;
	reg [31:0] ram_out;
	reg sel;

	// Outputs
	wire [31:0] outp;

	// Instantiate the Unit Under Test (UUT)
	output_mux uut (
		.alu_out(alu_out), 
		.ram_out(ram_out), 
		.sel(sel), 
		.outp(outp)
	);

	initial begin
		alu_out = 32'b00000000000000000000000000000000;
		ram_out = 32'b11111111111111111111111111111111;
		sel = 0;
		#100;
		
		sel = 1;
		#100;

	end
      
endmodule

