`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:42:21 01/19/2016
// Design Name:   b_mux
// Module Name:   C:/Users/Ryan/Desktop/CSE 132L Processor/Lab2/b_mux_tb.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: b_mux
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module b_mux_tb;

	// Inputs
	reg [31:0] reg_b;
	reg [31:0] imm_b;
	reg sel;

	// Outputs
	wire [31:0] outp;

	// Instantiate the Unit Under Test (UUT)
	b_mux uut (
		.reg_b(reg_b), 
		.imm_b(imm_b), 
		.sel(sel), 
		.outp(outp)
	);

	initial begin
		reg_b = 32'b00000000000000000000000000000000;
		imm_b = 32'b11111111111111111111111111111111;
		sel = 0;
		#100;
		
		sel = 1;
		#100;

	end
      
endmodule

