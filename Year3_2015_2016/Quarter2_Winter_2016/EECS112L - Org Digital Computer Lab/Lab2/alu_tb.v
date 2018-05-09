`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:35:05 01/16/2016
// Design Name:   alu
// Module Name:   C:/Users/Ryan/Desktop/CSE 132L Processor/Lab2/alu_tb.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: alu
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module alu_tb;

	// Inputs
	reg [5:0] Func_in;
	reg [31:0] A_in;
	reg [31:0] B_in;

	// Outputs
	wire [31:0] O_out;

	// Instantiate the Unit Under Test (UUT)
	alu uut (
		.Func_in(Func_in), 
		.A_in(A_in), 
		.B_in(B_in), 
		.O_out(O_out)
	);

	initial begin
		Func_in = 6'b000000;
		A_in = 32'b00000000000000000000000000000001;
		B_in = 32'b00000000000000000000000000000001;
		#100;
		
		Func_in = 6'b000001;
		#100;
		
		Func_in = 6'b000010;
		#100;
		
		Func_in = 6'b000011;
		#100;
		
		Func_in = 6'b000100;
		#100;
		
		Func_in = 6'b000101;
		#100;
		
		Func_in = 6'b000110;
		#100;
		
		Func_in = 6'b000000;
		A_in = 32'b00000000000000000000000000000001;
		B_in = 32'b00000000000000000000000000000000;
		#100;
		
		Func_in = 6'b000001;
		#100;
		
		Func_in = 6'b000010;
		#100;
		
		Func_in = 6'b000011;
		#100;
		
		Func_in = 6'b000100;
		#100;
		
		Func_in = 6'b000101;
		#100;
		
		Func_in = 6'b000110;
		#100;
		
		Func_in = 6'b000000;
		A_in = 32'b00000000000000000000000000000000;
		B_in = 32'b00000000000000000000000000000001;
		#100;
		
		Func_in = 6'b000001;
		#100;
		
		Func_in = 6'b000010;
		#100;
		
		Func_in = 6'b000011;
		#100;
		
		Func_in = 6'b000100;
		#100;
		
		Func_in = 6'b000101;
		#100;
		
		Func_in = 6'b000110;
		#100;		

	end
      
endmodule

