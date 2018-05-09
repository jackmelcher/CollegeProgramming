----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:41:51 01/11/2016 
-- Design Name: 
-- Module Name:    rom - Behavioral 
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
-- Added Package
library work;
use work.lab2_pack.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity rom is
	GENERIC (NBIT: INTEGER := 32;
				OP: INTEGER := 14*4); -- Total number of instructions, 0  to 14
				
    Port ( addr : in  STD_LOGIC_VECTOR (31 downto 0);
           dataIO : inout  STD_LOGIC_VECTOR (31 downto 0));
end rom;

architecture Behavioral of rom is

	type mux_instructions is array((OP-1) downto 0) of std_logic_vector(NBIT-1 downto 0);
	-- Signal Declaration
	SIGNAL operations : mux_instructions;
	
	begin
		-- Hard coded processor instructions
		
		-- R type instruction (Arithmetic and Logic involving two registers)
		-- (31 downto 26), (25 downto 21), (20 downto 16), (15 downto 11), (10 downto 6), (5 downto 0)
		-- 	opcode			rs						rt					rd					shamt				funct
		
		-- I type instruction (Arithmetic and Logic involving one register and immediate)
		-- (31 downto 26), (25 downto 21), (20 downto 16), (15 downto 0)	
		--  opcode				rs						rt					immediate
		
		--addi
		operations(0) 	<= func_addi & r0 & r1 & "0000000001001011";
		--slti
		operations(1) 	<= func_slti & r1 & r2 & "0000000010100110";
		--andi
		operations(2) 	<= func_andi & r1 & r3 & "1100110010100110";
		--ori
		operations(3) 	<= func_ori  & r1 & r4 & "0100110101010101";
		--xori
		operations(4) 	<= func_xori & r1 & r5 & "1010111000101001";
		--add
		operations(5) 	<= func_reg & r1 & r2 & r6 & "00000" & func_add;
		--sub
		operations(6) 	<= func_reg & r1 & r2 & r7 & "00000" & func_sub;
		--and
		operations(7) 	<= func_reg & r1 & r2 & r8 & "00000" & func_and;
		--or
		operations(8) 	<= func_reg & r1 & r2 & r9 & "00000" & func_or;
		--xor
		operations(9) 	<= func_reg & r1 & r2 & r10 & "00000" & func_xor;
		--nor
		operations(10) <= func_reg & r1 & r2 & r11 & "00000" & func_nor;
		--slt
		operations(11) <= func_reg & r1 & r2 & r12 & "00000" & func_slt;
		--sw
		operations(12) <= func_sw & r2 & r1 & "0000000000000000";
		--lw
		operations(13) <= func_lw & r2 & r13 & "0000000000000000";


		dataIO <= operations(to_integer(unsigned(addr)));
		
end Behavioral;

