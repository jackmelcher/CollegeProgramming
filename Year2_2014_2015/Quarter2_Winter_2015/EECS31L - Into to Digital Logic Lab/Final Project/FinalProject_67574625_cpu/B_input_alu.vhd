----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:08:10 02/07/2015 
-- Design Name: 
-- Module Name:    mux2to1 - Behavioral 
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
-- Final Project Package
library work;
use work.c31L_pack.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity b_input is
	Port ( in0 : in  STD_LOGIC_VECTOR(BW-1 downto 0);
          in1 : in  STD_LOGIC_VECTOR(BW-1 downto 0);
          sel : in  STD_LOGIC;
          output : out  STD_LOGIC_VECTOR(BW-1 downto 0));
end b_input;

architecture Behavioral of b_input is

begin
 -- use when.. else statement
    output <=	in0 when sel='0' else
					in1 when sel='1' else
					(OTHERS => 'Z');

end Behavioral;

