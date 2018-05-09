----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:36:19 03/03/2016 
-- Design Name: 
-- Module Name:    fwd_b - Behavioral 
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

entity fwd_b is
    Port ( pipe2_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd1_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd2_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd1 : in  STD_LOGIC;
           fwd2 : in  STD_LOGIC;
           b_out : out  STD_LOGIC_VECTOR (31 downto 0));
end fwd_b;

architecture Behavioral of fwd_b is

begin
	b_out <= fwd1_input when fwd1 = '1' else
				fwd2_input when fwd2 = '1' else
				pipe2_input;

end Behavioral;
