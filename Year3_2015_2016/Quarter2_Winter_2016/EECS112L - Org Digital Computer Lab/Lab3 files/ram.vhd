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
				NRAM: INTEGER := 8;			-- because ram is byte addressable, each row of memory has 8 bits.
				NSEL: INTEGER := 11;			-- address 0 to 2047, 2^11 entries. 512 words total
				ram_field: INTEGER := 11); -- 2048 entries in register file
    Port ( clk : in  STD_LOGIC;
           we : in  STD_LOGIC;
			  dsize : in STD_LOGIC_VECTOR (2 downto 0);
           addr : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           dataI : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
           dataO : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
end ram;

architecture Behavioral of ram is

-- Array for RAM
TYPE ramfile IS ARRAY (0 TO 2**ram_field-1) OF STD_LOGIC_VECTOR (NRAM-1 downto 0);

begin
	PROCESS(clk,we,dsize,addr)
		VARIABLE temp_ramfile : ramfile := (others => (others => '0'));	-- all values initialized to 0
		VARIABLE temp_read : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	BEGIN
		-- RAM functions
		IF (clk'EVENT AND clk = '1') THEN
			-- Write to ram
			IF (we = '1') THEN
				IF (dsize = "100") THEN -- store word, using Little Endian
					IF (addr(1 downto 0) = "00") THEN -- address must be divisible by 4
						temp_ramfile(to_integer(unsigned(addr)) + 0) := dataI(31 downto 24);
						temp_ramfile(to_integer(unsigned(addr)) + 1) := dataI(23 downto 16);
						temp_ramfile(to_integer(unsigned(addr)) + 2) := dataI(15 downto 8);
						temp_ramfile(to_integer(unsigned(addr)) + 3) := dataI(7 downto 0);

					END IF;
				ELSIF (dsize = "010") THEN --store halfword, using Little Endian
					IF (addr(0) = '0') THEN  -- address must be divisible by 2
						temp_ramfile(to_integer(unsigned(addr)) + 0) := dataI(15 downto 8);
						temp_ramfile(to_integer(unsigned(addr)) + 1) := dataI(7 downto 0);
					END IF;
				ELSIF (dsize = "000") THEN -- store byte
						temp_ramfile(to_integer(unsigned(addr))) := dataI(7 downto 0);
				END IF;
			END IF;
		END IF;
		--Assuming that you can read from ramfile at any given time
		-- Read address
		IF(addr <= 2**ram_field-1) THEN
			IF (dsize = "100") THEN -- load word, using Little Endian
				IF (addr(1 downto 0) = "00") THEN -- address must be divisible by 4
					temp_read:= temp_ramfile(to_integer(unsigned(addr)) + 0) & 
									temp_ramfile(to_integer(unsigned(addr)) + 1) &
									temp_ramfile(to_integer(unsigned(addr)) + 2) &
									temp_ramfile(to_integer(unsigned(addr)) + 3);
				ELSE
					temp_read := (others => '0'); -- failed divisibility test
				END IF;
			
			ELSIF (dsize = "011") THEN -- load halfword unsigned, using Little Endian
				IF (addr(0) = '0') THEN -- address must be divisible by 2
					temp_read:= ZERO(31 downto 16) &
									temp_ramfile(to_integer(unsigned(addr)) + 0) &
									temp_ramfile(to_integer(unsigned(addr)) + 1);				
				ELSE
					temp_read := (others => '0'); -- failed divisibility test
				END IF;
			
			ELSIF (dsize = "010") THEN -- load halfword, using Little Endian
				IF (addr(0) = '0') THEN -- address must be divisible by 2
					IF(temp_read(15) = '1') THEN
						temp_read:= ONES(31 downto 16) &
										temp_ramfile(to_integer(unsigned(addr)) + 0) &
										temp_ramfile(to_integer(unsigned(addr)) + 1);
						
					ELSE
						temp_read:= ZERO(31 downto 16) &
										temp_ramfile(to_integer(unsigned(addr)) + 0) &
										temp_ramfile(to_integer(unsigned(addr)) + 1);	
					END IF;					
				ELSE
					temp_read := (others => '0'); -- failed divisibility test
				END IF;
			
			ELSIF (dsize = "001") THEN -- load byte unsigned
					temp_read:= ZERO(31 downto 8) &
									temp_ramfile(to_integer(unsigned(addr)));
			
			ELSIF (dsize = "000") THEN -- load byte
				IF(temp_read(7) = '1') THEN
						temp_read:= ONES(31 downto 8) &
										temp_ramfile(to_integer(unsigned(addr)));
					ELSE
						temp_read:= ZERO(31 downto 8) &
										temp_ramfile(to_integer(unsigned(addr)));
					END IF;
			
			ELSE
				temp_read := (others => '0'); -- no match for dsize
			END IF;
		ELSE
			temp_read := (others => '0'); -- address outside of memory
		END IF;

		-- Output the value of read address
		dataO <= temp_read;
	END PROCESS;

end Behavioral;

