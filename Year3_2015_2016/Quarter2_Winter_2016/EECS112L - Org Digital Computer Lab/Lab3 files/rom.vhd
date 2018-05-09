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
				OP: INTEGER := 72); -- Total number of instructions, 0  to 14
				
    Port ( addr : in  STD_LOGIC_VECTOR (31 downto 0);
           dataO : out  STD_LOGIC_VECTOR (31 downto 0));
end rom;

architecture Behavioral of rom is

	type mux_instructions is array((OP)-1 downto 0) of std_logic_vector(NBIT-1 downto 0);
	-- Signal Declaration
	SIGNAL operations : mux_instructions;
	
	begin
		-- Hard coded processor instructions
		
		-- The codes that have to be run for Lab 3 
		operations(0)  <= x"20020005";
		operations(4)  <= x"2003000c";
		operations(8)  <= x"2067fff7";
		operations(12) <= x"00e22025";
		operations(16) <= x"00642824";
		operations(20) <= x"00a42820";
		operations(24) <= x"10a7000a";
		operations(28) <= x"0064202a";
		operations(32) <= x"10800001";
		operations(36) <= x"20050000";
		operations(40) <= x"00e2202a";
		operations(44) <= x"00853820";
		operations(48) <= x"00e23822";
		operations(52) <= x"ac670044";
		operations(56) <= x"8c020050";
		operations(60) <= x"08000011";
		operations(64) <= x"20020001";
		operations(68) <= x"ac020054";
		
		-- new load and store function tests
		--operations(0)  <= func_addi & r0 & r1 & "0000000000001100"; -- rs = r1 = address 12 of RAM
		--operations(4) 	<= func_addi & r0 & r2 & "1111111111111111";
		--operations(8) 	<= func_sb  & r1 & r2 & "0000000000001000"; --sb offset + r1 = 8 + 8 = address 16 of RAM
		--operations(12)	<= func_lb  & r1 & r3 & "0000000000001000"; --lb
		--operations(16)	<= func_lbu & r1 & r4 & "0000000000001000"; --lbu
		--operations(20)	<= func_sh  & r1 & r2 & "0000000000001000"; --sh
		--operations(24)	<= func_lh  & r1 & r5 & "0000000000001000"; --lh
		--operations(28)	<= func_lhu & r1 & r6 & "0000000000001000"; --lhu
		--operations(32)	<= func_sw  & r1 & r2 & "0000000001000100"; --sw
		--operations(36)	<= func_lw  & r0 & r7 & "0000000001010000"; --lw
		--operations(40) <= "000010"&"00000000000000000000000000"; -- jump to instruction 0 -> address 0, j
		
		-- test of shifting
		-- operations(0)  <= func_addi & r0 & r1 & "1100000000001111";
		-- operations(4) 	<= func_addi & r0 & r2 & "0000000000001000";
		-- operations(8) 	<= func_reg & r2 & r1 & r3 & "00100" & func_sll; --sll
		-- operations(12)	<= func_reg & r2 & r1 & r4 & "00100" & func_srl; --srl
		-- operations(16)	<= func_reg & r2 & r1 & r5 & "00100" & func_sra; --sra
		-- operations(20)	<= func_reg & r2 & r1 & r6 & "00000" & func_sllv; --sllv
		-- operations(24)	<= func_reg & r2 & r1 & r7 & "00000" & func_srlv; --srlv
		-- operations(28)	<= func_reg & r2 & r1 & r8 & "00000" & func_srav; --srav
		-- operations(32) <= "000010"&"00000000000000000000000000"; -- jump to instruction 0 -> address 0, j

		
		--test for branch codes
		--operations(0)  <= func_addi & r0 & r1 & "0000000000001010";
		--operations(4) 	<= func_addi & r0 & r2 & "1111111000110100";
		--operations(8) 	<= "000100"& r1 & r1 & "0000000000000001"; -- beq
		--operations(16) <= "000101"& r1 & r2 & "0000000000000001"; -- bne
		--operations(24) <= "000110"& r2 & "00000" & "0000000000000001"; -- blez
		--operations(32) <= "000111"& r1 & "00000" & "0000000000000001"; -- bgtz
		--operations(40) <= "000001"& r2 & "00000" & "0000000000000001"; -- bltz
		--operations(48) <= "000001"& r1 & "00001" & "1111111111110011"; -- bgez
		
		--test for jump codes
		--operations(0) 	<= "000010"&"00000000000000000000000010"; -- jump to instruction 2 -> address 8, j
		--operations(4) 	<= x"2003000c";
		--operations(8) 	<= "000011"&"00000000000000000000000100"; -- jump to instruction 4 -> address 16, save return at register 31, jal
		--operations(12) <= "000000"&r1&r0&r3&r0&"001001"; -- jump to instruction in r1,save return address at register 3, jalr
		--operations(16) <= func_addi & r0 & r1 & "0000000000001010"; -- addi, set r1 to instruction 10 -> address 40
		--operations(20) <= "000000"&"11111"&"000000000000000"&"001000"; -- jump to instruction in register 31, jr
		--operations(24) <= x"10a7000a";
		--operations(28) <= x"0064202a";
		--operations(32) <= func_addi & r2 & r1 & "0000000001011000"; -- addi
		--operations(36) <= x"20050000";
		--operations(40) <= func_addi & r2 & r1 & "0000000000010000"; -- addi, set r2 to instruction 16 -> address 64
		--operations(44) <= "000000"&r3&"000000000000000"&"001000"; -- jump to instruction in register 3, jr
		--operations(48) <= func_addi & r2 & r4 & "0000000001011000"; -- addi
		--operations(52) <= x"ac670044";
		--operations(56) <= x"8c020050";
		--operations(60) <= x"08000011";
		--operations(64) <= "000000"&r3&"000000000000000"&"001000"; -- jump to instruction in r3, jr
		--operations(68) <= x"ac020054";
		
		--test of unsigned functions
		--operations(0) 	<= func_addiu & r0 & r1 & "0000000000001000"; 	--addiu
		--operations(4)  <= func_reg & r1 & r1 & r2 & "00000" & func_addu;--addu
		--operations(8) 	<= func_reg & r2 & r1 & r3 & "00100" & func_subu; --subu
		--operations(12)	<= func_lui & r0 & r4 & "0000000000001110"; --lui
		--operations(16)	<= func_reg & r2 & r1 & r5 & "00100" & func_sltu; --sltu
		--operations(20)	<= func_sltiu & r0 & r6 & "0000000000001000"; --sltiu
		--operations(24) <= "000010"&"00000000000000000000000000"; -- jump to instruction 0 -> address 0, j
		
		
		dataO <= operations(to_integer(unsigned(addr)));
		
end Behavioral;

