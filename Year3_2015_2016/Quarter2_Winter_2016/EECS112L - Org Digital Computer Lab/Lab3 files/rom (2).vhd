----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:41:51 01/11/2016 
-- Design Name: 
-- Module Name:    rom - Behavioral 
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
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all; 
use STD.TEXTIO.all;

entity rom is -- instruction memory
	port(addr: in STD_LOGIC_VECTOR(31 downto 0);
		  dataO: out STD_LOGIC_VECTOR(31 downto 0)
	);
end;

architecture behavioral of rom is
begin

process(addr)
	file mem_file: TEXT;
	variable L: line;
	variable ch: character;
	variable i, index, result: integer;
	type ramtype is array (255 downto 0) of STD_LOGIC_VECTOR(31 downto 0);
	variable mem: ramtype;
begin
	-- initialize memory from file
	for i in 0 to 63 loop -- set all contents low
		mem(i) := (others => '0');
	end loop;

	index := 0;
	FILE_OPEN (mem_file, "imem.h", READ_MODE);
	while not endfile(mem_file) loop
		readline(mem_file, L);
		result := 0;

		for i in 1 to 8 loop
			read (L, ch);
			if '0' <= ch and ch <= '9' then
				result := character'pos(ch) - character'pos('0');
			elsif 'a' <= ch and ch <= 'f' then
				result := character'pos(ch) - character'pos('a')+10;
			else report "Format error on line" & integer'
				image(index) severity error;
			end if;
			mem(index)(35-i*4 downto 32-i*4) := std_logic_vector(to_unsigned(result, 4));
		end loop;
		index := index + 4;
	end loop;
	file_close(mem_file);
	-- read memory
	dataO <= mem(to_integer(unsigned(addr)));

end process;

end behavioral;
