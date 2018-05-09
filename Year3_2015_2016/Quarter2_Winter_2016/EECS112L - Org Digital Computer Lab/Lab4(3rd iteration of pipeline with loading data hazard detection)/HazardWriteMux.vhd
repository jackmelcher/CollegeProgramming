----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:29:58 03/04/2016 
-- Design Name: 
-- Module Name:    HazardDetectionWriteEnableMux - Behavioral 
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

entity HazardDetectionWriteEnableMux is
    Port ( reg_we : in  STD_LOGIC;
           ram_we : in  STD_LOGIC;
			  sel : in STD_LOGIC;
           reg_we_out : out  STD_LOGIC;
           ram_we_out : out  STD_LOGIC);
end HazardDetectionWriteEnableMux;

architecture Behavioral of HazardDetectionWriteEnableMux is

begin
	reg_we_out <= 	'0' when sel = '1' else
						reg_we;
	
	ram_we_out <= 	'0' when sel = '1' else
						ram_we;

end Behavioral;

