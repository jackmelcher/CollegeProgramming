----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:48:34 02/03/2016 
-- Design Name: 
-- Module Name:    a_mux - Behavioral 
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

entity a_mux is
    Port ( shift_amount : in  STD_LOGIC_VECTOR (31 downto 0);
           rs_data : in  STD_LOGIC_VECTOR (31 downto 0);
			  sel : in STD_LOGIC;
           a_output : out  STD_LOGIC_VECTOR (31 downto 0));
end a_mux;

architecture Behavioral of a_mux is

begin
    a_output <=	shift_amount when sel='1' else
						rs_data; -- sel = '0'

end Behavioral;

