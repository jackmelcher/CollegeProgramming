----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:36:35 03/08/2015 
-- Design Name: 
-- Module Name:    register_bank_67574625 - Behavioral 
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
-- Final Project Package
library work;
use work.c31L_pack.ALL;



entity register_bank_67574625 is
	port(	clk : in std_logic;
			rst_s : in  STD_LOGIC; -- synchronous reset
			write_enable : in std_logic;
			rs_index : in std_logic_vector(reg_field-1 downto 0);
			rt_index : in std_logic_vector(reg_field-1 downto 0);
			rd_index : in std_logic_vector(reg_field-1 downto 0);
			reg_source_out : out std_logic_vector(BW-1 downto 0);
			reg_target_out : out std_logic_vector(BW-1 downto 0);
			reg_dest_new : in std_logic_vector(BW-1 downto 0));
end register_bank_67574625;

architecture Behavioral of register_bank_67574625 is

-- Array for register file
TYPE regfile IS ARRAY (0 TO 2**reg_field-1) OF STD_LOGIC_VECTOR (BW-1 downto 0);

begin
	PROCESS(clk)
		VARIABLE regfile_temp: regfile;
		VARIABLE temp_rs, temp_rt : STD_LOGIC_VECTOR (BW-1 downto 0);
	BEGIN
	-- Reg values are loaded into regfile by using move immediate instruction
		-- Register file functions
		IF (clk'EVENT AND clk = '1') THEN
			-- Synchronous Reset Register file
			IF (rst_s = '1') THEN
				FOR i IN 0 TO 2**reg_field-1 LOOP
					regfile_temp(i) := (OTHERS => '0');
				END LOOP;
			-- Write to registers
			ELSIF (write_enable = '1' AND rst_s = '0') THEN
				regfile_temp(to_integer(unsigned(rd_index))) := reg_dest_new;
			END IF;
		END IF;
--Assuming that you can read from regfile at any given time
		-- Read address 1
		temp_rs := regfile_temp(to_integer(unsigned(rs_index)));
		-- Read address 2
		temp_rt := regfile_temp(to_integer(unsigned(rt_index)));

		-- Output the value of read address
		reg_source_out <= temp_rs;
		reg_target_out <= temp_rt;
	END PROCESS;

end Behavioral;

