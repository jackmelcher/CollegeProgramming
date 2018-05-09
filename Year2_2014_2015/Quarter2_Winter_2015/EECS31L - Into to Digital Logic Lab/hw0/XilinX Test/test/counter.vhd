----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:56:55 01/08/2015 
-- Design Name: 
-- Module Name:    counter - Behavioral 
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
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

entity counter is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           counter_out : out  STD_LOGIC_VECTOR (4 downto 0));
end counter;

architecture Behavioral of counter is
	signal count_int : std_logic_vector(4 downto 0) := b"00000";
	begin
		process (clk, rst)
			begin
			if rst='1' then
				count_int <= b"00000";
			else if clk='1' and clk'event then
					count_int <= count_int+ b"0001";
				end if;
			end if;
		end process;
	counter_out <= count_int;
end Behavioral;

