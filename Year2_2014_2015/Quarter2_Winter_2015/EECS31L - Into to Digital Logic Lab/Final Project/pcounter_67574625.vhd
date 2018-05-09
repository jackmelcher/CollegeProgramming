----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:30:34 03/08/2015 
-- Design Name: 
-- Module Name:    pcounter_67574625 - Behavioral 
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.ALL;
-- Final Project Package
library work;
use work.c31L_pack.ALL;

entity pcounter_67574625 is
	GENERIC (STEP: INTEGER := 1);
				
   Port (	clk : in  STD_LOGIC;
				enable: in STD_LOGIC;
				rst_s : in STD_LOGIC;
				dout : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
end pcounter_67574625;

architecture Behavioral of pcounter_67574625 is

begin
	PROCESS(clk)
		VARIABLE count: STD_LOGIC_VECTOR(NBIT-1 downto 0);
	BEGIN
		-- counting functions
		IF(clk'event AND clk = '1') THEN
			-- reset counter
			IF (rst_s = '1') THEN
				count := (OTHERS => '0');
			ELSIF(enable = '1') THEN
				-- increment
				count := count + STEP;
			END IF;
		END IF;
		-- reset counter
		IF (count = OP_binary) THEN
			count := (OTHERS => '0');
		END IF;
	-- output
	dout <= count;
	END PROCESS;

end Behavioral;

