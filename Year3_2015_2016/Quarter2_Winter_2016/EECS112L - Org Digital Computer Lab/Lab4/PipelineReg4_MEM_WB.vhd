----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:10:53 02/28/2016 
-- Design Name: 
-- Module Name:    PipelineReg4_MEM_WB - Behavioral 
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

entity PipelineReg4_MEM_WB is
	Port (	clk : in  STD_LOGIC;
				
				reg_we_in : in STD_LOGIC;
				reg_write_addr_in : in STD_LOGIC_VECTOR (4 downto 0);
				alu_output_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				ram_output_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				jump_return_addrs_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				out_mux_sel_in : in STD_LOGIC_VECTOR(1 DOWNTO 0);

				reg_we_out : out STD_LOGIC;
				reg_write_addr_out : out STD_LOGIC_VECTOR (4 downto 0);
				alu_output_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				ram_output_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				jump_return_addrs_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				out_mux_sel_out : out STD_LOGIC_VECTOR(1 DOWNTO 0));
				
end PipelineReg4_MEM_WB;

architecture Behavioral of PipelineReg4_MEM_WB is

-- Array for register file
TYPE regfileA IS ARRAY (0 TO 2) OF STD_LOGIC_VECTOR (NBIT-1 downto 0);

begin

	PROCESS(clk)
		VARIABLE temp_regfileA: regfileA := (OTHERS => (OTHERS => '0'));	-- all values initialized to 0
		Variable temp_regfileD : STD_LOGIC_VECTOR (4 downto 0) := (OTHERS => '0'); -- all values initialized to 0
		Variable temp_regfileE : STD_LOGIC_VECTOR (1 downto 0) := (OTHERS => '0'); -- all values initialized to 0
		Variable temp_regfileF : STD_LOGIC; -- all values initialized to 0

	BEGIN
		-- Register file functions
		-- Write Data
		IF (clk'EVENT AND clk = '1') THEN
			temp_regfileF	  := reg_we_in;
			temp_regfileD	  := reg_write_addr_in;
			temp_regfileA(0) := alu_output_in;
			temp_regfileA(1) := ram_output_in;
			temp_regfileA(2) := jump_return_addrs_in;
			temp_regfileE    := out_mux_sel_in;

		END IF;
		
		-- Assuming that you can read from regfile at any given time
		-- Read Data
		reg_we_out					<= temp_regfileF;
		reg_write_addr_out		<= temp_regfileD;
		alu_output_out				<= temp_regfileA(0);		
		ram_output_out				<= temp_regfileA(1);		
		jump_return_addrs_out 	<= temp_regfileA(2);
		out_mux_sel_out   		<= temp_regfileE;
		
		
		
	END PROCESS;


end Behavioral;

