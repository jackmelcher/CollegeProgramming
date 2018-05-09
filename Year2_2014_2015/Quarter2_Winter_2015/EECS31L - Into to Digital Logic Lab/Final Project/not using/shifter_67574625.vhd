----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:56:38 03/09/2015 
-- Design Name: 
-- Module Name:    shifter_67574625 - Behavioral 
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

-- Used Shifter from Lectures Slides as a reference
-- Max number of times a number can be shifted is BW times

entity shifter_67574625 is
	PORT (reg_source : IN STD_LOGIC_VECTOR (BW-1 DOWNTO 0);
			immediate : IN STD_LOGIC_VECTOR (BW-1 DOWNTO 0);
			alu_op : IN alu_function_type;
			instruction_type : IN STD_LOGIC;
			output : OUT STD_LOGIC_VECTOR (BW-1 DOWNTO 0));
end shifter_67574625;

architecture Behavioral of shifter_67574625 is
-- Array declaration
TYPE matrix IS ARRAY (0 TO BW) OF  STD_LOGIC_VECTOR (BW-1 DOWNTO 0);
SIGNAL row: matrix;
SIGNAL sel : STD_LOGIC_VECTOR(5 downto 0);

begin
	sel <= 	immediate(8 downto 0) WHEN immediate(8 downto 0) <= "000100000" ELSE
				"000100000";-- default to 32 if immediate is any number higher than that
	
	row(0) <= reg_source;
	Gen: FOR i IN 1 TO BW GENERATE
		row(i) <= row(i-1)(BW-2 downto 0) & '0';
	END GENERATE;
	
	output <= 	row(1) WHEN (alu_op = alu_shift_logic_left AND instruction_type = '0') ELSE --Shift 1 bit
					row(to_integer(unsigned(sel))) WHEN (alu_op = alu_shift_logic_left AND instruction_type = '1') ELSE --Shift Immediate number of bits
					immediate WHEN (alu_op = alu_shift_logic_left AND instruction_type = '0') ELSE --Move in Immediate
					row(0); --Move reg_source
end Behavioral;

