----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:27:36 01/12/2016 
-- Design Name: 
-- Module Name:    b_mux - Behavioral 
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

entity b_mux is
    Port ( reg_b : in  STD_LOGIC_VECTOR (31 downto 0);
           imm_b : in  STD_LOGIC_VECTOR (31 downto 0);
           sel : in  STD_LOGIC;
			  outp : out  STD_LOGIC_VECTOR (31 downto 0));
end b_mux;

architecture Behavioral of b_mux is

begin
    outp <=	reg_b when sel='0' else
				imm_b when sel='1' else
				(OTHERS => 'Z');

end Behavioral;

