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

entity a_input_67574625 is
	PORT (reg_source : IN STD_LOGIC_VECTOR (BW-1 DOWNTO 0);
			immediate : IN STD_LOGIC_VECTOR (BW-1 DOWNTO 0);
			alu_op : IN alu_function_type;
			instruction_type : IN STD_LOGIC;
			opsel : OUT STD_LOGIC_VECTOR (2 DOWNTO 0);
			mode : OUT STD_LOGIC;
			output : OUT STD_LOGIC_VECTOR (BW-1 DOWNTO 0));
end a_input_67574625;

architecture Behavioral of a_input_67574625 is

begin

	opsel <= "000" when alu_op = alu_add else --Arithmetic
				"001" when alu_op = alu_sub else
				"010" when alu_op = alu_mov else
				"100" when alu_op = alu_increment else
				"101" when alu_op = alu_decrement else
				"110" when alu_op = alu_add_increment else
				"000" when alu_op = alu_and else --Logic
				"001" when alu_op = alu_or else
				"010" when alu_op = alu_xor else
				"011" when alu_op = alu_not else
				"101" when alu_op = alu_shift_logic_left else
				"010";--default to move
	
	mode <=	'0' when alu_op = alu_add else --Arithmetic
				'0' when alu_op = alu_sub else
				'0' when alu_op = alu_mov else
				'0' when alu_op = alu_increment else
				'0' when alu_op = alu_decrement else
				'0' when alu_op = alu_add_increment else
				'1' when alu_op = alu_and else --Logic
				'1' when alu_op = alu_or else
				'1' when alu_op = alu_not else
				'1' when alu_op = alu_xor else
				'1' when alu_op = alu_shift_logic_left else
				'0';--default to move

	output <=	immediate when instruction_type = '1' AND alu_op = alu_mov else
					immediate when instruction_type = '1' AND alu_op = alu_not else
					immediate when instruction_type = '1' AND alu_op = alu_shift_logic_left else
					immediate when instruction_type = '1' AND alu_op = alu_increment else
					immediate when instruction_type = '1' AND alu_op = alu_decrement else
					immediate when instruction_type = '1' AND alu_op = alu_add_increment else
					reg_source;

end Behavioral;

