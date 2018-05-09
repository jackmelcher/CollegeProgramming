----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:14:16 02/07/2015 
-- Design Name: 
-- Module Name:    logic_unit - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity logic_unit is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
			  shl: in STD_LOGIC;
           sel : in  STD_LOGIC_VECTOR (2 downto 0);
           output : out  STD_LOGIC);
end logic_unit;

architecture Behavioral of logic_unit is

begin
 -- use when.. else statement
    output <=	(A AND B) when sel="000" else --AND
					(A OR B) when sel="001" else --OR
					(A XOR B) when sel="010" else --XOR
					(NOT A) when sel="011" else --NOT
					shl when sel="101" else --SHL
					'0';

end Behavioral;

