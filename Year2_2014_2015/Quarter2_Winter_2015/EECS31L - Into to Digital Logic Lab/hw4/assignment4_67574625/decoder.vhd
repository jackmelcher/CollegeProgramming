----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:01:53 02/17/2015 
-- Design Name: 
-- Module Name:    decoder - Behavioral 
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



ENTITY decoder IS
	GENERIC(m: INTEGER:=3);
	PORT ( 	ena : IN STD_LOGIC;
				sel : IN STD_LOGIC_VECTOR (m-1 DOWNTO 0);
				x : OUT STD_LOGIC_VECTOR (2**m-1 DOWNTO 0)
			);
END decoder;

architecture Behavioral of decoder is

begin

PROCESS (ena, sel)
	VARIABLE temp1 : STD_LOGIC_VECTOR (x'HIGH DOWNTO 0);
	VARIABLE temp2 : INTEGER RANGE 0 TO x'HIGH;
BEGIN
	temp1 := (OTHERS => '1');
	temp2 := 0;
	IF (ena='1') THEN
		FOR i IN sel'RANGE LOOP -- sel range is m-1 downto 0
			IF (sel(i)='1') THEN -- Bin-to-Integer conversion
			temp2:=2*temp2+1;
			ELSE
			temp2 := 2*temp2;
			END IF;
		END LOOP;
	temp1(temp2):='0';
	END IF;
	x <= temp1;
END PROCESS;

end Behavioral;

