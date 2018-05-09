----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:45:52 01/14/2015 
-- Design Name: 
-- Module Name:    assignment1_67574625_comparator - DataFlow 
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

entity assignment1_67574625_comparator is
    Port ( in_0 : in  STD_LOGIC;
           in_1 : in  STD_LOGIC;
           greater : out  STD_LOGIC;
           equal : out  STD_LOGIC;
           less : out  STD_LOGIC);
end assignment1_67574625_comparator;

architecture DataFlow of assignment1_67574625_comparator is

begin
	greater <= in_0 AND NOT in_1;
	equal <= (in_0 XNOR in_1);
	less <= NOT in_0 AND in_1;
end DataFlow;

