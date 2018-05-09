----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:44:51 01/11/2016 
-- Design Name: 
-- Module Name:    regfile - Behavioral 
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

-- Added Package
library work;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;


entity regfile is
	Generic (NBIT: INTEGER := 32;			-- 32 bit size data
				NSEL: INTEGER := 5;			-- address 0 to 63
				reg_field: INTEGER := 5); 	-- 64 entries in register file
	Port ( clk : in  STD_LOGIC;
           rst_s : in  STD_LOGIC;
           we : in  STD_LOGIC;
           raddr_1 : in  STD_LOGIC_VECTOR (NSEL-1 downto 0);
           raddr_2 : in  STD_LOGIC_VECTOR (NSEL-1 downto 0);
           waddr : in  STD_LOGIC_VECTOR (NSEL-1  downto 0);
           rdata_1 : out  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           rdata_2 : out  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           wdata : in  STD_LOGIC_VECTOR (NBIT-1 downto 0));
end regfile;

architecture Behavioral of regfile is

-- Array for register file
TYPE regfile IS ARRAY (0 TO 2**reg_field-1) OF STD_LOGIC_VECTOR (NBIT-1 downto 0);

begin

	PROCESS(clk)
		VARIABLE temp_regfile: regfile := (OTHERS => (OTHERS => '0'));	-- all values initialized to 0
		VARIABLE temp_rdata_1, temp_rdata_2 : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	BEGIN
		-- Register file functions
		IF (clk'EVENT AND clk = '0') THEN
			-- Synchronous Reset Register file
			IF (rst_s = '1') THEN
				FOR i IN 0 TO 2**reg_field-1 LOOP
					temp_regfile(i) := (OTHERS => '0');
				END LOOP;
			-- Write to registers (except to register 0)
			ELSIF (we = '1' AND rst_s = '0' AND waddr /= 0) THEN
				temp_regfile(to_integer(unsigned(waddr))) := wdata;
			END IF;
		END IF;
		--Assuming that you can read from regfile at any given time
		-- Read address 1
		temp_rdata_1 := temp_regfile(to_integer(unsigned(raddr_1)));
		-- Read address 2
		temp_rdata_2 := temp_regfile(to_integer(unsigned(raddr_2)));

		-- Output the value of read address
		rdata_1 <= temp_rdata_1;
		rdata_2 <= temp_rdata_2;
	END PROCESS;

end Behavioral;

