----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:49:08 01/14/2015 
-- Design Name: 
-- Module Name:    assignment1_67574625_decoder - Behavioral 
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

entity assignment1_67574625_decoder is
    Port ( in_0 : in  STD_LOGIC;
           enable : in  STD_LOGIC;
           f_0 : out  STD_LOGIC;
           f_1 : out  STD_LOGIC);
end assignment1_67574625_decoder;

architecture Behavioral of assignment1_67574625_decoder is

begin
	f_0 <= enable AND NOT in_0;
	f_1 <= enable AND in_0;

end Behavioral;

