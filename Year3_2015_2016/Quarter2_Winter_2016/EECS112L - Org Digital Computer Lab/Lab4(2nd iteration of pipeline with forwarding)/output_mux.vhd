----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:38:24 01/13/2016 
-- Design Name: 
-- Module Name:    output_mux - Behavioral 
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


entity output_mux is
	Port ( alu_out : in  STD_LOGIC_VECTOR (31 downto 0);
			 ram_out : in  STD_LOGIC_VECTOR (31 downto 0);
 			 jump_out : in  STD_LOGIC_VECTOR (31 downto 0);
			 sel : in  STD_LOGIC_VECTOR (1 downto 0);
			 outp : out  STD_LOGIC_VECTOR (31 downto 0));
end output_mux;

architecture Behavioral of output_mux is

begin
    outp <=	alu_out when sel="00" else
			   ram_out when sel="01" else
			   "00"&jump_out(31 downto 2) when sel="10" else
				(OTHERS => 'Z');

end Behavioral;

