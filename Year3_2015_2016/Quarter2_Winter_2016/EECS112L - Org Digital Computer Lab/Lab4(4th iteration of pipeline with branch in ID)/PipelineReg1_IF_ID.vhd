----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:09:09 02/28/2016 
-- Design Name: 
-- Module Name:    PipelineReg1_IF_ID - Behavioral 
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
-- Added Package
library work;
use work.lab2_pack.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity PipelineReg1_IF_ID is
	Port (	clk : in  STD_LOGIC;
				instruction_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				current_addrs_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				enable: in STD_LOGIC;
				rst_s : in STD_LOGIC;
				instruction_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				current_addrs_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0));
end PipelineReg1_IF_ID;

architecture Behavioral of PipelineReg1_IF_ID is

-- Array for register file
TYPE regfile IS ARRAY (0 TO 1) OF STD_LOGIC_VECTOR (NBIT-1 downto 0);

begin

	PROCESS(clk)
		VARIABLE temp_regfile: regfile := (OTHERS => (OTHERS => '0'));	-- all values initialized to 0
	BEGIN
		-- Register file functions
		-- Write Data
		IF (clk'EVENT AND clk = '1' AND enable = '1') THEN
			IF (rst_s = '1') THEN
				temp_regfile(0) := (OTHERS => '0');
				temp_regfile(1) := (OTHERS => '0');
			ELSE
				temp_regfile(0) := instruction_in;
				temp_regfile(1) := current_addrs_in;
			END IF;
		END IF;
		
		-- Assuming that you can read from regfile at any given time
		instruction_out <= temp_regfile(0);
		current_addrs_out <= temp_regfile(1);

	END PROCESS;

end Behavioral;

