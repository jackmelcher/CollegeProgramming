----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:26:02 03/08/2015 
-- Design Name: 
-- Module Name:    memory_67574625 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
-- Final Project Package
library work;
use work.c31L_pack.ALL;

entity memory_67574625 is
    Port ( addr : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           read_data : out  STD_LOGIC_VECTOR (BW-1 downto 0));
end memory_67574625;

architecture Behavioral of memory_67574625 is

-- Signal Declaration
	SIGNAL operations : mux_instructions;

begin
		-- Hard coded processor instructions
		-- First stores immediate values into regfile
		-- For simplicity, just taking values from reg_bank addr 1 and 2 for all operations
		-- and storing the results in another address
		-- a counter will be included in the processor to activate each instruction in order

								-- NOP
		operations(0) <= '0'&"000000"&"000000"&alu_nop&"000000"&"010101110";
								-- MOVI(Move in immediate to regfile)
		operations(1) <= '1'&"000001"&"000001"&alu_mov&"011100"&"010101110";
		operations(2) <= '1'&"000001"&"000010"&alu_mov&"001001"&"011001010";
								-- MOV(Move in Source to regfile)
		operations(3) <= '0'&"000001"&"000011"&alu_mov&"000010"&"010101110";
								-- ADD
		operations(4) <= '0'&"000001"&"000100"&alu_add&"000010"&"010101110";
								-- ADDI
		operations(5) <= '1'&"000001"&"000101"&alu_add&"001001"&"010101110";
								-- SUB
		operations(6) <= '0'&"000001"&"000110"&alu_sub&"000010"&"010101110";
								-- SUBI
		operations(7) <= '1'&"000001"&"000111"&alu_sub&"001001"&"010101110";
								-- NOT
		operations(8) <= '0'&"000001"&"001000"&alu_not&"000010"&"010101110";
								-- NOTI
		operations(9) <= '1'&"000001"&"001001"&alu_not&"001001"&"010101110";
								-- AND
		operations(10) <='0'&"000001"&"001010"&alu_and&"000010"&"010101110";
								-- ANDI
		operations(11) <='1'&"000001"&"001011"&alu_and&"100110"&"010101110";
								-- OR
		operations(12) <='0'&"000001"&"001100"&alu_or&"000010"&"010101110";
								-- ORI
		operations(13) <='1'&"000001"&"001101"&alu_or&"100110"&"010101110";
								-- XOR
		operations(14) <='0'&"000001"&"001110"&alu_xor&"000010"&"010101110";
								-- XORI
		operations(15) <='1'&"000001"&"001111"&alu_xor&"100110"&"010101110";
								-- SLL(Shift Left Source 1 bit)
		operations(16) <='0'&"000001"&"010000"&alu_shift_logic_left&"000010"&"010101110";
								-- SLLI(Shift Left immediate value 1 bit)
		operations(17) <='1'&"000001"&"010001"&alu_shift_logic_left&"100110"&"010101110";

		read_data <= operations(to_integer(unsigned(addr)));
								
end Behavioral;

