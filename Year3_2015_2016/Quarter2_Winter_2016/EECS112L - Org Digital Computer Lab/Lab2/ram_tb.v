`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:01:06 01/18/2016
// Design Name:   ram
// Module Name:   C:/Users/Ryan/Desktop/CSE 132L Processor/Lab2/ram_tb.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ram
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ram_tb;

	// Inputs
	reg clk;
	reg we;
	reg [8:0] addr;
	reg [31:0] dataI;

	// Outputs
	wire [31:0] dataO;

	// Instantiate the Unit Under Test (UUT)
	ram uut (
		.clk(clk), 
		.we(we), 
		.addr(addr), 
		.dataI(dataI), 
		.dataO(dataO)
	);

	initial begin
		clk = 0;
		we = 0;
		addr = 9'b000000000;
		dataI = 32'b00000000000000000000000000000001;
		#100;
        
		clk = 1;
		#100;
		
		clk = 0;
		we = 1;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		addr = 9'b000000001;
		dataI = 32'b00000000000000000000000000000010;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		addr = 9'b000000000;
		#100;

	end
      
endmodule

