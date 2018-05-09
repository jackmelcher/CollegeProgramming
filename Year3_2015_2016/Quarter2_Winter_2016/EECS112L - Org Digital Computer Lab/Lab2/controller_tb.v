`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:53:11 01/19/2016
// Design Name:   controller
// Module Name:   C:/Users/Ryan/Desktop/CSE 132L Processor/Lab2/controller_tb.v
// Project Name:  Lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: controller
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module controller_tb;

	// Inputs
	reg [31:0] instruction;

	// Outputs
	wire [4:0] reg_read_addr1;
	wire [4:0] reg_read_addr2;
	wire [4:0] reg_write_addr;
	wire reg_write_enable;
	wire ram_write_enable;
	wire [31:0] immediate;
	wire [5:0] alu_funct;
	wire b_mux_sel;
	wire out_mux_sel;

	// Instantiate the Unit Under Test (UUT)
	controller uut (
		.instruction(instruction), 
		.reg_read_addr1(reg_read_addr1), 
		.reg_read_addr2(reg_read_addr2), 
		.reg_write_addr(reg_write_addr), 
		.reg_write_enable(reg_write_enable), 
		.ram_write_enable(ram_write_enable), 
		.immediate(immediate), 
		.alu_funct(alu_funct), 
		.b_mux_sel(b_mux_sel), 
		.out_mux_sel(out_mux_sel)
	);

	initial begin
		instruction = 32'b00100000000000010000000001001011;
		#100;
		
		instruction = 32'b00000000001000100011000000100000;
		#100;

		instruction = 32'b10101100010000010000000000000000;
		#100;
		
		instruction = 32'b10001100010011010000000000000000;
		#100;
	end
      
endmodule

