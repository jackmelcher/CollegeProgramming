----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:09:31 02/28/2016 
-- Design Name: 
-- Module Name:    PipelineReg2_ID_EX - Behavioral 
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

entity PipelineReg2_ID_EX is
Port (	clk : in  STD_LOGIC;
			
			rs_data_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
			rt_data_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
			reg_we_in : in STD_LOGIC;
			reg_write_addr_in : in STD_LOGIC_VECTOR (4 downto 0);
			ram_we_in : in STD_LOGIC;
			ram_size_in : in STD_LOGIC_VECTOR (2 downto 0);
			alu_funct_in : in STD_LOGIC_VECTOR (5 DOWNTO 0);
			branch_funct_in : in STD_LOGIC_VECTOR (5 DOWNTO 0);
			jump_funct_in : in std_logic;
			jump_enable_in : in std_logic;			
			immediate_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
			target_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
			a_output_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
			b_output_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
			out_mux_sel_in : in STD_LOGIC_VECTOR(1 DOWNTO 0);
			current_addrs_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
			
			rs_data_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
			rt_data_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
			reg_we_out : out STD_LOGIC;
			reg_write_addr_out : out STD_LOGIC_VECTOR (4 downto 0);
			ram_we_out : out STD_LOGIC;
			ram_size_out : out STD_LOGIC_VECTOR (2 downto 0);
			alu_funct_out : out STD_LOGIC_VECTOR (5 DOWNTO 0);
			branch_funct_out : out STD_LOGIC_VECTOR (5 DOWNTO 0);
			jump_funct_out : out std_logic;
			jump_enable_out : out std_logic;			
			immediate_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
			target_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
			a_output_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
			b_output_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
			out_mux_sel_out : out STD_LOGIC_VECTOR(1 DOWNTO 0);
			current_addrs_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
			
			-- Added for Forwarding
			reg_addr1_in : in STD_LOGIC_VECTOR (4 downto 0);
			reg_addr2_in : in STD_LOGIC_VECTOR (4 downto 0);
			reg_addr1_out : out STD_LOGIC_VECTOR (4 downto 0);
			reg_addr2_out : out STD_LOGIC_VECTOR (4 downto 0));
			
end PipelineReg2_ID_EX;

architecture Behavioral of PipelineReg2_ID_EX is

-- Array for register file
TYPE regfileA IS ARRAY (0 TO 6) OF STD_LOGIC_VECTOR (NBIT-1 downto 0);
TYPE regfileB IS ARRAY (0 TO 1) OF STD_LOGIC_VECTOR (5 downto 0);
TYPE regfileC IS ARRAY (0 TO 3) OF STD_LOGIC;
TYPE regfileD IS ARRAY (0 TO 2) OF STD_LOGIC_VECTOR (4 downto 0);

begin

	PROCESS(clk)
		VARIABLE temp_regfileA: regfileA := (OTHERS => (OTHERS => '0'));	-- all values initialized to 0
		VARIABLE temp_regfileB: regfileB := (OTHERS => (OTHERS => '0'));	-- all values initialized to 0
		VARIABLE temp_regfileC: regfileC := (OTHERS => '0');	-- all values initialized to 0
		VARIABLE temp_regfileD: regfileD := (OTHERS => (OTHERS => '0'));	-- all values initialized to 0
		Variable temp_regfileE : STD_LOGIC_VECTOR (2 downto 0) := (OTHERS => '0'); -- all values initialized to 0
		Variable temp_regfileF : STD_LOGIC_VECTOR (1 downto 0) := (OTHERS => '0'); -- all values initialized to 0

	BEGIN
		-- Register file functions
		-- Write Data
		IF (clk'EVENT AND clk = '1') THEN
			temp_regfileA(0) := rs_data_in;
			temp_regfileA(1) := rt_data_in;
			temp_regfileC(0) := reg_we_in;
			temp_regfileD(0) := reg_write_addr_in;
			temp_regfileC(1) := ram_we_in;
			temp_regfileE	  := ram_size_in;
			temp_regfileB(0) := alu_funct_in;
			temp_regfileB(1) := branch_funct_in;
			temp_regfileC(2) := jump_funct_in;
			temp_regfileC(3) := jump_enable_in;
			temp_regfileA(2) := immediate_in;
			temp_regfileA(3) := target_in;
			temp_regfileA(4) := a_output_in;
			temp_regfileA(5) := b_output_in;
			temp_regfileF    := out_mux_sel_in;
			temp_regfileA(6) := current_addrs_in;
			
			temp_regfileD(1) := reg_addr1_in;
			temp_regfileD(2) := reg_addr2_in;

		END IF;
		
		-- Assuming that you can read from regfile at any given time
		-- Read Data
		rs_data_out 			<= temp_regfileA(0);
		rt_data_out				<= temp_regfileA(1);
		reg_we_out				<= temp_regfileC(0);
		reg_write_addr_out	<= temp_regfileD(0);
		ram_we_out 				<= temp_regfileC(1);
		ram_size_out 			<= temp_regfileE;
		alu_funct_out 			<= temp_regfileB(0);
		branch_funct_out 		<= temp_regfileB(1);
		jump_funct_out 		<= temp_regfileC(2);
		jump_enable_out 		<= temp_regfileC(3);
		immediate_out 			<= temp_regfileA(2);
		target_out 				<= temp_regfileA(3);
		a_output_out 			<= temp_regfileA(4);
		b_output_out 				<= temp_regfileA(5);
		out_mux_sel_out   	<= temp_regfileF;
		current_addrs_out 	<= temp_regfileA(6);
		
		reg_addr1_out	<= temp_regfileD(1);
		reg_addr2_out	<= temp_regfileD(2);

		
	END PROCESS;

end Behavioral;

