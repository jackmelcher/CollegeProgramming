`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:50:41 01/16/2016
// Design Name:   pc
// Module Name:   C:/Users/Ryan/Desktop/CSE 132L Processor/Lab2/pc_tb.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: pc
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module pc_tb;

	// Inputs
	reg clk;
	reg enable;
	reg rst_s;

	// Outputs
	wire [31:0] dout;

	// Instantiate the Unit Under Test (UUT)
	pc uut (
		.clk(clk), 
		.enable(enable), 
		.rst_s(rst_s), 
		.dout(dout)
	);

	initial begin
		clk = 0;
		enable = 0;
		rst_s = 0;
		#100;

		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		enable = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		rst_s = 1;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		rst_s = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		#100;
	end
      
endmodule

