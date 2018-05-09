----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:41:13 02/15/2015 
-- Design Name: 
-- Module Name:    assignment4_67574625_register - Behavioral 
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

entity assignment4_67574625_register is
   GENERIC(NBIT: INTEGER := 32);
	
	Port ( clk : in  STD_LOGIC;
           rst_a : in  STD_LOGIC; -- asynchronous reset
           rst_s : in  STD_LOGIC; -- synchronous reset
           inc : in  STD_LOGIC; -- increment
           we : in  STD_LOGIC; -- write enable
           din : in  STD_LOGIC_VECTOR (NBIT-1 downto 0); -- input data
           dout : out  STD_LOGIC_VECTOR (NBIT-1 downto 0)); -- output data
end assignment4_67574625_register;

architecture Behavioral of assignment4_67574625_register is
begin
	PROCESS(clk, rst_a, rst_s, inc, we)
		VARIABLE temp: STD_LOGIC_VECTOR(NBIT-1 downto 0);
	BEGIN
		-- asynchronous reset
		IF (rst_a = '1') THEN
			temp := (OTHERS => '0');
		-- register functions
		Elsif (clk'EVENT AND clk = '1') THEN
			-- synchronous reset
			IF (rst_s = '1') THEN
				temp := (OTHERS => '0');
			-- write to register
			ELSIF (we = '1' AND inc = '0') THEN
				temp := din;
			-- increment value in register
			ELSIF (we = '1' AND inc = '1') THEN
				temp := temp + 1;
			END IF;
		END IF;
	-- output
	dout <= temp;
	END PROCESS;

end Behavioral;

