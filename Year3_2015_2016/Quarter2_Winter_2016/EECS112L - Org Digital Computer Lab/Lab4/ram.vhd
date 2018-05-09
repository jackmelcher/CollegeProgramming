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

-- Added Package
library work;
use work.lab2_pack.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;


entity ram is
	Generic (NBIT: INTEGER := 32;			-- size of data and the addressing
				ram_field: INTEGER := 9); -- address 0 to 511, 2^9 entries. 512 bytes, 128 words
    Port ( clk : in  STD_LOGIC;
           we : in  STD_LOGIC;
			  dsize : in STD_LOGIC_VECTOR (2 downto 0);
           addr : in  STD_LOGIC_VECTOR (8 downto 0);
           dataI : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           dataO : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
end ram;

architecture Behavioral of ram is

-- Array for RAM
TYPE ramfile IS ARRAY (0 TO 2**ram_field-1) OF STD_LOGIC_VECTOR (7 downto 0);

begin
	PROCESS(clk,we,dsize,addr)
		Variable temp_ramfile : ramfile := (others => (others => '0'));	-- all values initialized to 0

		Variable read_out : STD_LOGIC_VECTOR (31 downto 0);
		--Variable halfword : STD_LOGIC_VECTOR (15 downto 0);
		--Variable byte : STD_LOGIC_VECTOR (7 downto 0);
		
		Variable ram_address : INTEGER;
		Variable halfword_offset : INTEGER;
		Variable byte_offset : INTEGER;
	BEGIN
		ram_address := to_integer(unsigned(addr) srl 2);--/4;
		--halfword_offset := to_integer(unsigned(addr(1 downto 1)));
		--byte_offset := to_integer(unsigned(addr(1 downto 0)));
		
		-- RAM functions

		
			-- Write RAM
			IF (falling_edge(clk) AND we = '1') THEN
				IF (dsize = "100") THEN -- store word, using Little Endian
					temp_ramfile(ram_address+3) := dataI(31 downto 24);
					temp_ramfile(ram_address+2) := dataI(23 downto 16);
					temp_ramfile(ram_address+1) := dataI(15 downto 8);
					temp_ramfile(ram_address) := dataI(7 downto 0);

				ELSIF (dsize = "010") THEN
					IF(addr(1) = '1') THEN --store halfword, using Little Endian
						temp_ramfile(ram_address+3):= dataI(15 downto 8);
						temp_ramfile(ram_address+2):= dataI(7 downto 0);
					ELSE
						temp_ramfile(ram_address+1):= dataI(15 downto 8);
						temp_ramfile(ram_address):= dataI(7 downto 0);					
					END IF;
				ELSE--ELSIF (dsize = "000") THEN -- store byte
					IF(addr(1 downto 0) = "11")THEN
						temp_ramfile(ram_address+3) := dataI(7 downto 0);
					ELSIF(addr(1 downto 0) = "10")THEN
						temp_ramfile(ram_address+2) := dataI(7 downto 0);
					ELSIF(addr(1 downto 0) = "01")THEN
						temp_ramfile(ram_address+1) := dataI(7 downto 0);
					ELSE
						temp_ramfile(ram_address) := dataI(7 downto 0);
					END IF;
				END IF;
			END IF;

			--Read RAM
			dataO <= temp_ramfile(ram_address+3) & temp_ramfile(ram_address+2) & temp_ramfile(ram_address+1) & temp_ramfile(ram_address);


	END PROCESS;

	
end Behavioral;

