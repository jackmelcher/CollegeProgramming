----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:17:23 02/07/2015 
-- Design Name: 
-- Module Name:    arithmetic_unit - Behavioral 
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

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity arithmetic_unit is
    Port ( B : in  STD_LOGIC;
           sel : in  STD_LOGIC_VECTOR (2 downto 0);
           output : out  STD_LOGIC);
end arithmetic_unit;

architecture Behavioral of arithmetic_unit is

begin
 -- use when.. else statement
    output <=	B when sel="000" else --ADD
			(NOT B) when sel="001" else --SUB
			'0' when sel="010" else --Move
			'0' when sel="100" else --Increment
			'1' when sel="101" else --Decrement
			B when sel="110" else --ADD & Increment
			'0';

end Behavioral;

