----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:48:34 01/11/2016 
-- Design Name: 
-- Module Name:    ram - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ram is
	Generic (NBIT: INTEGER := 32;			-- 32 bit data
				NSEL: INTEGER := 9;			-- address 0 to 512
				ram_field: INTEGER := 9); 	-- 512 entries in register file
    Port ( clk : in  STD_LOGIC;
           we : in  STD_LOGIC;
           addr : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           dataI : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           dataO : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
end ram;

architecture Behavioral of ram is

-- Array for RAM
TYPE ramfile IS ARRAY (0 TO 2**ram_field-1) OF STD_LOGIC_VECTOR (NBIT-1 downto 0);

begin
	PROCESS(clk)
		VARIABLE temp_ramfile : ramfile := (others => (others => '0'));	-- all values initialized to 0
		VARIABLE temp_read : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	BEGIN
		-- RAM functions
		IF (clk'EVENT AND clk = '1') THEN
			-- Write to ram
			IF (we = '1') THEN
				temp_ramfile(to_integer(unsigned(addr))) := dataI;
			END IF;
		END IF;
		--Assuming that you can read from ramfile at any given time
		-- Read address
		IF(addr <= 2**ram_field-1)THEN
			temp_read := temp_ramfile(to_integer(unsigned(addr)));
		ELSE
			temp_read := (others => '0');
		END IF;

		-- Output the value of read address
		dataO <= temp_read;
	END PROCESS;

end Behavioral;

