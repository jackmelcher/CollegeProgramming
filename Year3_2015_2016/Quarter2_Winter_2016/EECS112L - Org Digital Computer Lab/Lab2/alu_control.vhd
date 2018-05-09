----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:00:51 01/12/2016 
-- Design Name: 
-- Module Name:    alu_control - Behavioral 
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

entity alu_control is
    Port ( alu_op : in  STD_LOGIC_VECTOR (1 downto 0);
           alu_funct : in  STD_LOGIC_VECTOR (5 downto 0);
           alu_sel : out  STD_LOGIC_VECTOR (3 downto 0));
end alu_control;

architecture Behavioral of alu_control is

begin
	alu_sel <= 	"0010" when 	(alu_op = "" AND alu_funct = "") OR
										(alu_op = "" AND alu_funct = "") OR
										(alu_op = "" AND alu_funct = "") OR
										(alu_op = "" AND alu_funct = "")else
					"0000";

end Behavioral;

