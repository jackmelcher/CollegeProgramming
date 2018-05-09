----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:35:49 02/15/2015 
-- Design Name: 
-- Module Name:    assignment4_67574625_counter - Behavioral 
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

entity assignment4_67574625_counter is
	GENERIC (NBIT: INTEGER := 32;
				STEP: INTEGER := 1);
				
   Port ( clk : in  STD_LOGIC;
           rst_s : in  STD_LOGIC; -- synchronous reset
           asc : in  STD_LOGIC; -- ascending (if it is '0', count descending)
           preload : in  STD_LOGIC; -- read din as the counting seed
           din : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           dout : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
end assignment4_67574625_counter;

architecture Behavioral of assignment4_67574625_counter is

begin

	PROCESS(clk, rst_s, asc, preload)
		VARIABLE count: STD_LOGIC_VECTOR(NBIT-1 downto 0);
	BEGIN
		-- counting functions
		IF(clk'event AND clk = '1') THEN
			-- reset counter
			IF (rst_s = '1') THEN
				count := (OTHERS => '0');
			-- load din into counter
			ELSIF(preload = '1') THEN
				count := din;
			-- increment
			ELSIF(preload = '0' AND asc = '1') THEN
				count := count + STEP;
				-- When most significant bit becomes '1'
				IF(count(NBIT-1) = '1') THEN
					count := (OTHERS => '0');
				END IF;
			-- decrement
			ELSIF(preload = '0' AND asc = '0') THEN
				count := count - STEP;
				-- When most significant bit becomes '1'
				IF(count(NBIT-1) = '1') THEN
					count := (NBIT-1=>'0',OTHERS => '1');
				END IF;
			END IF;
		END IF;
	-- output
	dout <= count;
	END PROCESS;
	
end Behavioral;

