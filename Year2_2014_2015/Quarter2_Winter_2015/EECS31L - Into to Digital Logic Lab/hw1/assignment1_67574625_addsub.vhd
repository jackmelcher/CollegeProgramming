----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:44:23 01/14/2015 
-- Design Name: 
-- Module Name:    assignment1_67574625_addsub - DataFlow 
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

entity assignment1_67574625_addsub is
    Port ( in_0 : in  STD_LOGIC;
           in_1 : in  STD_LOGIC;
           cin : in  STD_LOGIC;
           AddOrSub : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           cout : out  STD_LOGIC);
end assignment1_67574625_addsub;

architecture DataFlow of assignment1_67574625_addsub is

begin
	sum <=(in_0 XOR (in_1 XOR AddorSub)) XOR cin;
	cout <= (in_0 AND (in_1 XOR AddorSub)) OR (cin AND (in_0 XOR (in_1 XOR AddorSub)));
end DataFlow;

