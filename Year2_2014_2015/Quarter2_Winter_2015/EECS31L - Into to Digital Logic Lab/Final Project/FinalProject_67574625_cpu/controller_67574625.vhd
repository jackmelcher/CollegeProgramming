----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:17:05 03/08/2015 
-- Design Name: 
-- Module Name:    controller_67574625 - Behavioral 
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
-- Final Project Package
library work;
use work.c31L_pack.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity controller_67574625 is
port(	instruction : in std_logic_vector(BW-1 downto 0);
		--increased size to 32 bits for sign extension
		rt_and_imm : out std_logic_vector (31 downto 0);
		write_enable : out std_logic;
		rs_index : out std_logic_vector(reg_field-1 downto 0);
		rt_index : out std_logic_vector(reg_field-1 downto 0);
		rd_index : out std_logic_vector(reg_field-1 downto 0);
		b_mux_sel : out std_logic;
		alu_func : out alu_function_type );
end controller_67574625;

architecture Behavioral of controller_67574625 is

begin
	-- Register or Immediate
	b_mux_sel <= instruction(BW-1);
	-- Reg Source index
	rs_index <= instruction(BW-2 downto BW-7);
	-- Reg Destination index
	rd_index <= instruction(BW-8 downto BW-13);
	-- Function operation
	alu_func <= instruction(BW-14 downto BW-17);
	-- Reg Target index
	rt_index <= instruction(BW-18 downto BW-23);
	-- Immediate value
	rt_and_imm <= 	ONES(31 downto 15) & instruction(BW-18 downto 0) WHEN instruction(BW-18) = '1' ELSE
						ZERO(31 downto 15) & instruction(BW-18 downto 0);
	-- When to enable write
	write_enable <=	'0' WHEN instruction(BW-14 downto BW-17)= alu_nop ELSE
							'1';

end Behavioral;

