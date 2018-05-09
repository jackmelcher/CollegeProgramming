----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:09:52 02/28/2016 
-- Design Name: 
-- Module Name:    PipelineReg3_EX_MEM - Behavioral 
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

entity PipelineReg3_EX_MEM is
	Port (	clk : in  STD_LOGIC;
				
				rt_data_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				reg_we_in : in STD_LOGIC;
				reg_write_addr_in : in STD_LOGIC_VECTOR (4 downto 0);
				ram_we_in : in STD_LOGIC;
				ram_size_in : in STD_LOGIC_VECTOR (2 downto 0);
				branch_enable_in : in  STD_LOGIC;
				jump_enable_in : in std_logic;			
				next_address_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				jump_return_addrs_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				alu_output_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
				out_mux_sel_in : in STD_LOGIC_VECTOR(1 DOWNTO 0);

				rt_data_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				reg_we_out : out STD_LOGIC;
				reg_write_addr_out : out STD_LOGIC_VECTOR (4 downto 0);
				ram_we_out : out STD_LOGIC;
				ram_size_out : out STD_LOGIC_VECTOR (2 downto 0);
				branch_enable_out : out STD_LOGIC;
				jump_enable_out : out std_logic;			
				next_address_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				jump_return_addrs_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				alu_output_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
				out_mux_sel_out : out STD_LOGIC_VECTOR(1 DOWNTO 0));

end PipelineReg3_EX_MEM;

architecture Behavioral of PipelineReg3_EX_MEM is

-- Array for register file
TYPE regfileA IS ARRAY (0 TO 3) OF STD_LOGIC_VECTOR (NBIT-1 downto 0);
TYPE regfileC IS ARRAY (0 TO 3) OF STD_LOGIC;

begin

	PROCESS(clk)
		VARIABLE temp_regfileA : regfileA := (OTHERS => (OTHERS => '0'));	-- all values initialized to 0
		VARIABLE temp_regfileC : regfileC := (OTHERS => '0');	-- all values initialized to 0
		Variable temp_regfileD : STD_LOGIC_VECTOR (4 downto 0) := (OTHERS => '0'); -- all values initialized to 0
		Variable temp_regfileE : STD_LOGIC_VECTOR (2 downto 0) := (OTHERS => '0'); -- all values initialized to 0
		Variable temp_regfileF : STD_LOGIC_VECTOR (1 downto 0) := (OTHERS => '0'); -- all values initialized to 0

	BEGIN
		-- Register file functions
		-- Write Data
		IF (clk'EVENT AND clk = '1') THEN
			temp_regfileA(0) := rt_data_in;
			temp_regfileC(0) := reg_we_in;
			temp_regfileD	  := reg_write_addr_in;
			temp_regfileC(1) := ram_we_in;
			temp_regfileE	  := ram_size_in;
			temp_regfileC(2) := branch_enable_in;
			temp_regfileC(3) := jump_enable_in;
			temp_regfileA(1) := next_address_in;
			temp_regfileA(2) := jump_return_addrs_in;
			temp_regfileA(3) := alu_output_in;
			temp_regfileF    := out_mux_sel_in;

		END IF;
		
		-- Assuming that you can read from regfile at any given time
		-- Read Data
		rt_data_out				<= temp_regfileA(0);
		reg_we_out				<= temp_regfileC(0);
		reg_write_addr_out	<= temp_regfileD;
		ram_we_out 				<= temp_regfileC(1);
		ram_size_out 			<= temp_regfileE;
		branch_enable_out		<= temp_regfileC(2);
		jump_enable_out 		<= temp_regfileC(3);
		next_address_out 		<= temp_regfileA(1);
		jump_return_addrs_out <= temp_regfileA(2);
		alu_output_out			<= temp_regfileA(3);		
		out_mux_sel_out   	<= temp_regfileF;
		
		
		
	END PROCESS;
	
end Behavioral;

