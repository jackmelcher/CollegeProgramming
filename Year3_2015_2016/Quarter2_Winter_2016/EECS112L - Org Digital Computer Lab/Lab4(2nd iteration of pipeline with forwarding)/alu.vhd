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


entity alu is
    Port ( Func_in : in  STD_LOGIC_VECTOR (5 downto 0);
           A_in : in  STD_LOGIC_VECTOR (31 downto 0);
           B_in : in  STD_LOGIC_VECTOR (31 downto 0);
			  O_out : out  STD_LOGIC_VECTOR (31 downto 0));
end alu;

architecture Behavioral of alu is

begin

	O_out <= A_in + B_in 	when Func_in = alu_func_add else -- add
				A_in - B_in 	when Func_in = alu_func_sub else -- sub
				A_in AND B_in 	when Func_in = alu_func_and else -- and
				A_in OR B_in 	when Func_in = alu_func_or else -- or
				A_in XOR B_in 	when Func_in = alu_func_xor else -- xor
				A_in NOR B_in	when Func_in = alu_func_nor else -- nor
				(0 => '1', OTHERS => '0') when A_in < B_in AND Func_in = alu_func_slt else -- slt
				(OTHERS => '0') when A_in >= B_in AND Func_in = alu_func_slt else -- slt
				std_logic_vector(unsigned(B_in) sll to_integer(unsigned(A_in))) when Func_in = "000111" else -- sll
				std_logic_vector(unsigned(B_in) srl to_integer(unsigned(A_in))) when Func_in = "001000" else -- srl
				to_stdlogicvector(to_bitvector(B_in) sra to_integer(unsigned(A_in))) when Func_in = "001001" else -- sra
				
				B_in(15 downto 0) & ZERO(31 downto 16) when Func_in = alu_func_lui else -- lui
				
				(OTHERS => '0'); -- error, default is to ouput zero

end Behavioral;

