----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:50:07 02/15/2015 
-- Design Name: 
-- Module Name:    assignment4_67574625_registerfile - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

entity assignment4_67574625_registerfile is
   GENERIC(NBIT: INTEGER := 32;
				NSEL: INTEGER := 3);
	
	Port ( clk : in  STD_LOGIC;
           rst_s : in  STD_LOGIC; -- synchronous reset
           we : in  STD_LOGIC; -- write enable
           raddr_1 : in  STD_LOGIC_VECTOR (NSEL-1 downto 0); -- read address 1
           raddr_2 : in  STD_LOGIC_VECTOR (NSEL-1 downto 0); -- read address 2
           waddr : in  STD_LOGIC_VECTOR (NSEL-1 downto 0); -- write address
           rdata_1 : out  STD_LOGIC_VECTOR (NBIT-1 downto 0); -- read data 1
           rdata_2 : out  STD_LOGIC_VECTOR (NBIT-1 downto 0); -- read data 2
           wdata : in  STD_LOGIC_VECTOR (NBIT-1 downto 0)); -- write data
end assignment4_67574625_registerfile;

architecture Behavioral of assignment4_67574625_registerfile is

-- Array for register file
TYPE regfile IS ARRAY (0 TO 2**NSEL-1) OF STD_LOGIC_VECTOR (NBIT-1 downto 0);

begin
	PROCESS(clk, rst_s, we)
		VARIABLE regfile_temp: regfile;
		VARIABLE temp_rdata_1, temp_rdata_2 : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	BEGIN
		-- Register file functions
		IF (clk'EVENT AND clk = '1') THEN
			-- Synchronous Reset Register file
			IF (rst_s = '1') THEN
				FOR i IN 0 TO 2**NSEL-1 LOOP
					regfile_temp(i) := (OTHERS => '0');
				END LOOP;
			-- Write to registers
			ELSIF (we = '1') THEN
				regfile_temp(to_integer(unsigned(waddr))) := wdata;
			END IF;
			-- Read address 1
			temp_rdata_1 := regfile_temp(to_integer(unsigned(raddr_1)));
			-- Read address 2
			temp_rdata_2 := regfile_temp(to_integer(unsigned(raddr_2)));
		END IF;
	-- Output the value of read address
	rdata_1 <= temp_rdata_1;
	rdata_2 <= temp_rdata_2;
	END PROCESS;

end Behavioral;

