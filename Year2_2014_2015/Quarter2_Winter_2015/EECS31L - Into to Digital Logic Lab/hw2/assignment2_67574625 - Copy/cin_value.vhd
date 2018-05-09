----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:27:32 02/07/2015 
-- Design Name: 
-- Module Name:    cin_value - Behavioral 
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

entity cin_value is
    Port ( sel : in  STD_LOGIC_VECTOR (2 downto 0);
           cin : out  STD_LOGIC);
end cin_value;

architecture Behavioral of cin_value is

begin
 cin <=	'0' when sel="000" else
			'1' when sel="001" else
			'0' when sel="010" else
			'1' when sel="011" else
			'1' when sel="100" else
			'0' when sel="101" else
			'1' when sel="110" else
			'Z';

end Behavioral;

