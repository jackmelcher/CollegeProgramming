----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:42:07 01/14/2015 
-- Design Name: 
-- Module Name:    assignment1_67574625_mux4to1 - DataFlow 
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

entity assignment1_67574625_mux4to1 is
    Port ( in_0 : in  STD_LOGIC;
           in_1 : in  STD_LOGIC;
           in_2 : in  STD_LOGIC;
           in_3 : in  STD_LOGIC;
           sel_0 : in  STD_LOGIC;
           sel_1 : in  STD_LOGIC;
           f : out  STD_LOGIC);
end assignment1_67574625_mux4to1;

architecture DataFlow of assignment1_67574625_mux4to1 is

begin
	f <= (in_0 AND NOT sel_1 AND NOT sel_0)
			OR(in_1 AND NOT sel_1 AND sel_0)
			OR(in_2 AND sel_1 AND NOT sel_0)
			OR(in_3 AND sel_1 AND sel_0);

end DataFlow;

