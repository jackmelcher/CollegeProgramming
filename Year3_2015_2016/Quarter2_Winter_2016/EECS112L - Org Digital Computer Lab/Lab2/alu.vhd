----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:38:02 01/11/2016 
-- Design Name: 
-- Module Name:    alu - Behavioral 
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
use IEEE.STD_LOGIC_SIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity alu is
    Port ( Func_in : in  STD_LOGIC_VECTOR (5 downto 0);
           A_in : in  STD_LOGIC_VECTOR (31 downto 0);
           B_in : in  STD_LOGIC_VECTOR (31 downto 0);
			  --shift_amount : in  STD_LOGIC_VECTOR (4 downto 0);			  
			  O_out : out  STD_LOGIC_VECTOR (31 downto 0));
           --Branch_out : out  STD_LOGIC;
           --Jump_out : out  STD_LOGIC);
end alu;

architecture Behavioral of alu is

begin
	--O_out <= A_in + B_in 	when Func_in = "100000" else -- add
	--			A_in - B_in 	when Func_in = "100010" else -- sub
	--			A_in AND B_in 	when Func_in = "100100" else -- and
	--			A_in OR B_in 	when Func_in = "100101" else -- or
	--			A_in XOR B_in 	when Func_in = "100110" else -- xor
	--			A_in NOR B_in	when Func_in = "100111" else -- nor
	--			(0 => '1', OTHERS => '0') when A < B AND Func_in = "101010" else -- slt
	--			(OTHERS => '0') when A >= B AND Func_in = "101010" else -- slt
	--
	--			A_in + B_in 	when Func_in = "001000" else -- addi
	--			A_in AND B_in 	when Func_in = "001100" else -- andi
	--			A_in OR B_in 	when Func_in = "001101" else -- ori
	--			A_in XOR B_in 	when Func_in = "001110" else -- xori
	--			(0 => '1', OTHERS => '0') when A_in < B AND Func_in = "001010" else -- slti
	--			(OTHERS => '0') when A >= B AND Func_in = "001010" else -- slti
	--			
	--			A_in + B_in 	when Func_in = "100011" else -- lw
	--			A_in + B_in 	when Func_in = "101011" else -- sw
	--			
	--			(OTHERS => 'Z'); -- error

	O_out <= A_in + B_in 	when Func_in = "000000" else -- add
				A_in - B_in 	when Func_in = "000001" else -- sub
				A_in AND B_in 	when Func_in = "000010" else -- and
				A_in OR B_in 	when Func_in = "000011" else -- or
				A_in XOR B_in 	when Func_in = "000100" else -- xor
				A_in NOR B_in	when Func_in = "000101" else -- nor
				(0 => '1', OTHERS => '0') when A_in < B_in AND Func_in = "000110" else -- slt
				(OTHERS => '0') when A_in >= B_in AND Func_in = "000110" else -- slt
				(OTHERS => 'Z'); --error

end Behavioral;

