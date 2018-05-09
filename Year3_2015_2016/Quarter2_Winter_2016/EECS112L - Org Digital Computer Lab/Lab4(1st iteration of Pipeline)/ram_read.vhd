----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:42:11 02/13/2016 
-- Design Name: 
-- Module Name:    ram_read - Behavioral 
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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ram_read is
    Port ( addr : in  STD_LOGIC_VECTOR (8 downto 0);
           dsize : in  STD_LOGIC_VECTOR (2 downto 0);
           ram_read_in : in  STD_LOGIC_VECTOR (31 downto 0);
           ram_read_out : out  STD_LOGIC_VECTOR (31 downto 0));
end ram_read;

architecture Behavioral of ram_read is

begin
	ram_read_out <= 	ram_read_in when dsize = "100" else	--lw
					
							ZERO(31 downto 16) & ram_read_in(31 downto 16) when dsize = "011" AND addr(1) = '1' else	--lhu
							ZERO(31 downto 16) & ram_read_in(15 downto 0)  when dsize = "011" AND addr(1) = '0' else	--lhu
			
							ONES(31 downto 16) & ram_read_in(31 downto 16) when dsize = "010" AND addr(1) = '1' AND ram_read_in(31) = '1' else	--lh, upper half, MSB = '1'
							ZERO(31 downto 16) & ram_read_in(31 downto 16) when dsize = "010" AND addr(1) = '1' AND ram_read_in(31) = '0' else	--lh, upper half, MSB = '0'
							ONES(31 downto 16) & ram_read_in(15 downto 0)  when dsize = "010" AND addr(1) = '0' AND ram_read_in(15) = '1' else	--lh, lower half, MSB = '1'
							ZERO(31 downto 16) & ram_read_in(15 downto 0)  when dsize = "010" AND addr(1) = '0' AND ram_read_in(15) = '0' else	--lh, lower half, MSB = '0'

							ZERO(31 downto 8) & ram_read_in(31 downto 24) when dsize = "001" AND addr(1 downto 0) = "11" else	--lbu, 3rd Byte
							ZERO(31 downto 8) & ram_read_in(23 downto 16) when dsize = "001" AND addr(1 downto 0) = "10" else	--lbu, 2nd Byte
							ZERO(31 downto 8) & ram_read_in(15 downto 8)  when dsize = "001" AND addr(1 downto 0) = "01" else	--lbu, 1st half
							ZERO(31 downto 8) & ram_read_in(7 downto 0)   when dsize = "001" AND addr(1 downto 0) = "00" else	--lbu, 0th half
							
							ONES(31 downto 8) & ram_read_in(31 downto 24) when dsize = "000" AND addr(1 downto 0) = "11" AND ram_read_in(31) = '1' else	--lb, 3rd Byte, MSB = '1'
							ZERO(31 downto 8) & ram_read_in(31 downto 24) when dsize = "000" AND addr(1 downto 0) = "11" AND ram_read_in(31) = '0' else	--lb, 3rd Byte, MSB = '0'
							ONES(31 downto 8) & ram_read_in(23 downto 16) when dsize = "000" AND addr(1 downto 0) = "10" AND ram_read_in(23) = '1' else	--lb, 2nd half, MSB = '1'
							ZERO(31 downto 8) & ram_read_in(23 downto 16) when dsize = "000" AND addr(1 downto 0) = "10" AND ram_read_in(23) = '0' else	--lb, 2nd half, MSB = '0'
							ONES(31 downto 8) & ram_read_in(15 downto 8)  when dsize = "000" AND addr(1 downto 0) = "01" AND ram_read_in(15) = '1' else	--lb, 1st Byte, MSB = '1'
							ZERO(31 downto 8) & ram_read_in(15 downto 8)  when dsize = "000" AND addr(1 downto 0) = "01" AND ram_read_in(15) = '0' else	--lb, 1st Byte, MSB = '0'
							ONES(31 downto 8) & ram_read_in(7 downto 0)   when dsize = "000" AND addr(1 downto 0) = "00" AND ram_read_in(7) = '1'  else	--lb, 0th half, MSB = '1'
							ZERO(31 downto 8) & ram_read_in(7 downto 0)   when dsize = "000" AND addr(1 downto 0) = "00" AND ram_read_in(7) = '0'  else	--lb, 0th half, MSB = '0'
							
							(OTHERS => '0'); -- defualt, load output to be zero

end Behavioral;

