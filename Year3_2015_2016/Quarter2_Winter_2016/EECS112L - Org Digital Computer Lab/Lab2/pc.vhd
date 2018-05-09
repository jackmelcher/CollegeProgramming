----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:50:32 01/13/2016 
-- Design Name: 
-- Module Name:    pc - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity pc is
	GENERIC (NBIT: INTEGER := 32;
				STEP: INTEGER := 1;
				OP: INTEGER := 14); -- The pc will count from 0 to 13, reseting at 14
				
   Port (	clk : in  STD_LOGIC;
				enable: in STD_LOGIC;
				rst_s : in STD_LOGIC;
				dout : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
end pc;

architecture Behavioral of pc is

begin

	PROCESS(clk)
		VARIABLE count: STD_LOGIC_VECTOR(NBIT-1 downto 0) := (OTHERS => '0');
	BEGIN
		-- counting functions
		IF(clk'event AND clk = '1') THEN
			-- reset counter
			IF (rst_s = '1') THEN
				count := (OTHERS => '0');
			ELSIF (enable = '1') THEN
				-- increment
				count := count + STEP;
			END IF;
		END IF;
		-- reset counter
		IF (count = OP) THEN
			count := (OTHERS => '0');
		END IF;
	-- output
	dout <= count;
	END PROCESS;

end Behavioral;

