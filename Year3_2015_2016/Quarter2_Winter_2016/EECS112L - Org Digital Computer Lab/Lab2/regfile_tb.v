`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:15:51 01/16/2016
// Design Name:   regfile
// Module Name:   C:/Users/Ryan/Desktop/CSE 132L Processor/Lab2/regfile_tb.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: regfile
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module regfile_tb;

	// Inputs
	reg clk;
	reg rst_s;
	reg we;
	reg [5:0] raddr_1;
	reg [5:0] raddr_2;
	reg [5:0] waddr;
	reg [31:0] wdata;

	// Outputs
	wire [31:0] rdata_1;
	wire [31:0] rdata_2;

	// Instantiate the Unit Under Test (UUT)
	regfile uut (
		.clk(clk), 
		.rst_s(rst_s), 
		.we(we), 
		.raddr_1(raddr_1), 
		.raddr_2(raddr_2), 
		.waddr(waddr), 
		.rdata_1(rdata_1), 
		.rdata_2(rdata_2), 
		.wdata(wdata)
	);

	initial begin
		clk = 0;
		rst_s = 0;
		we = 0;
		raddr_1 = 6'b000000;
		raddr_2 = 6'b000001;
		waddr = 6'b000000;
		wdata = 32'b00000000000000000000000000000001;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		we = 1;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		waddr = 6'b000001;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		raddr_1 = 6'b000010;
		waddr = 6'b000010;
		wdata = 32'b00000000000000000000000000000010;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		raddr_2 = 6'b000011;
		waddr = 6'b000011;
		wdata = 32'b00000000000000000000000000000011;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		rst_s = 1;
		#100;
		
		clk = 1;
		#100;
		
		clk = 0;
		raddr_1 = 6'b000000;
		raddr_2 = 6'b000001;
		#100;

	end
      
endmodule

