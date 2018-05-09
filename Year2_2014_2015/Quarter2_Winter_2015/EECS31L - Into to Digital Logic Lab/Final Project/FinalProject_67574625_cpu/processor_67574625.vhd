----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:47:52 03/05/2015 
-- Design Name: 
-- Module Name:    processor_67574625 - Behavioral 
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
-- Final Project Package
library work;
use work.c31L_pack.ALL;



entity processor_67574625 is
	port(	clk : in std_logic;
			pc_enable : in std_logic;
			rst_s:in std_logic;
			memory_addrs : out STD_LOGIC_VECTOR(NBIT-1 downto 0);
			instruction:out std_logic_vector(BW-1 downto 0);
			reg_source:out std_logic_vector(BW-1 downto 0);
			reg_target:out std_logic_vector(BW-1 downto 0);
			immediate:out std_logic_vector(BW-1 downto 0);
			carry:out std_logic;
			output:out std_logic_vector(BW-1 downto 0));
 
end processor_67574625;

architecture Behavioral of processor_67574625 is

-- Component Declarations
	-- Program Counter
	COMPONENT pcounter_67574625 IS
		Port (	clk : in  STD_LOGIC;
					enable : in STD_LOGIC;
					rst_s : in STD_LOGIC;
					dout : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
	END COMPONENT;
	-- Memory of instructions
	COMPONENT memory_67574625 IS
		Port ( addr : in  STD_LOGIC_VECTOR (NBIT-1 downto 0);
				 read_data : out  STD_LOGIC_VECTOR (BW-1 downto 0));
	END COMPONENT;
	
	-- Controller
	COMPONENT controller_67574625 IS
		Port(	instruction : in std_logic_vector(BW-1 downto 0);
				--increased size to 32 bits for sign extension
				rt_and_imm : out std_logic_vector (31 downto 0);
				write_enable : out std_logic;
				rs_index : out std_logic_vector(reg_field-1 downto 0);
				rt_index : out std_logic_vector(reg_field-1 downto 0);
				rd_index : out std_logic_vector(reg_field-1 downto 0);
				b_mux_sel : out std_logic;
				alu_func : out alu_function_type );
	END COMPONENT;
	
	-- Register file bank
	COMPONENT register_bank_67574625 IS
		Port(	clk : in std_logic;
				rst_s : in  STD_LOGIC; 
				write_enable : in std_logic;
				rs_index : in std_logic_vector(reg_field-1 downto 0);
				rt_index : in std_logic_vector(reg_field-1 downto 0);
				rd_index : in std_logic_vector(reg_field-1 downto 0);
				reg_source_out : out std_logic_vector(BW-1 downto 0);
				reg_target_out : out std_logic_vector(BW-1 downto 0);
				reg_dest_new : in std_logic_vector(BW-1 downto 0));
	END COMPONENT;
	
	-- A input for ALU and other ALU settings
	COMPONENT a_input_67574625 is
		PORT (reg_source : IN STD_LOGIC_VECTOR (BW-1 DOWNTO 0);
				immediate : IN STD_LOGIC_VECTOR (BW-1 DOWNTO 0);
				alu_op : IN alu_function_type;
				instruction_type : IN STD_LOGIC;
				opsel : OUT STD_LOGIC_VECTOR (2 DOWNTO 0);
				mode : OUT STD_LOGIC;
				output : OUT STD_LOGIC_VECTOR (BW-1 DOWNTO 0));
	END COMPONENT;
	
	-- B input for ALU
	COMPONENT b_input IS
    	Port ( in0 : in  STD_LOGIC_VECTOR(BW-1 downto 0);
				 in1 : in  STD_LOGIC_VECTOR(BW-1 downto 0);
				 sel : in  STD_LOGIC;
				 output : out  STD_LOGIC_VECTOR(BW-1 downto 0));
	END COMPONENT;
	
	-- ALU 32bit
	COMPONENT alu_32bit IS
		Port (	A : in  STD_LOGIC_VECTOR (31 downto 0);
					B : in  STD_LOGIC_VECTOR (31 downto 0);
					opsel : in  STD_LOGIC_VECTOR (2 downto 0);
					mode : in  STD_LOGIC;
					cout : out  STD_LOGIC;
					output : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;

-- Signal Declarations
	SIGNAL pc_to_memory : STD_LOGIC_VECTOR(NBIT-1 downto 0);
	
	SIGNAL memory_to_controller : std_logic_vector(BW-1 downto 0);
	
	SIGNAL controller_to_reg_rs : std_logic_vector(reg_field-1 downto 0);
	SIGNAL controller_to_reg_rt : std_logic_vector(reg_field-1 downto 0);
	SIGNAL controller_to_reg_rd : std_logic_vector(reg_field-1 downto 0);
	SIGNAL controller_to_reg_write_enable : STD_LOGIC;
	
	SIGNAL controller_to_immediate: std_logic_vector(31 downto 0);
	SIGNAL R_or_I : STD_LOGIC;
	SIGNAL target_to_mux : std_logic_vector(BW-1 downto 0);
	
	SIGNAL alu_function : alu_function_type;
	SIGNAL source_to_a : std_logic_vector(BW-1 downto 0);
	SIGNAL opsel_wire :  std_logic_vector(2 downto 0);
	SIGNAL mode_wire : STD_LOGIC;
	SIGNAL a_to_alu : std_logic_vector(BW-1 downto 0);
	SIGNAL b_to_alu : std_logic_vector(BW-1 downto 0);
	
	Signal alu_to_reg : std_logic_vector(BW-1 downto 0);
	
begin

	-- Port Mapping
	PC: pcounter_67574625 Port MAP (	clk => clk,
												enable => pc_enable,
												rst_s => rst_s,
												dout => pc_to_memory);
												
	MEM: memory_67574625 Port MAP (	addr => pc_to_memory, 
												read_data => memory_to_controller);
												
	CON: controller_67574625 PORT MAP (	instruction => memory_to_controller, 
													rt_and_imm => controller_to_immediate, 
													write_enable => controller_to_reg_write_enable,
													rs_index => controller_to_reg_rs, 
													rt_index => controller_to_reg_rt, 
													rd_index => controller_to_reg_rd,
													b_mux_sel => R_or_I,	
													alu_func => alu_function);
				 
	REG: register_bank_67574625 PORT MAP(	clk => clk,
														rst_s => rst_s,
														write_enable => controller_to_reg_write_enable,
														rs_index => controller_to_reg_rs, 
														rt_index => controller_to_reg_rt, 
														rd_index => controller_to_reg_rd,
														reg_source_out => source_to_a,
														reg_target_out => target_to_mux,
														reg_dest_new => alu_to_reg);
	
	A: a_input_67574625	PORT MAP(	reg_source => source_to_a,
												immediate => controller_to_immediate,
												alu_op => alu_function,
												instruction_type => R_or_I,
												opsel => opsel_wire,
												mode => mode_wire,
												output => a_to_alu);									
	
	B: b_input PORT MAP (	in0 => target_to_mux,
									in1 => controller_to_immediate,
									sel => R_or_I,
									output => b_to_alu);
	
	ALU: alu_32bit PORT MAP (	A => a_to_alu,
										B => b_to_alu,
										opsel => opsel_wire,
										mode => mode_wire,
										cout => carry,
										output => alu_to_reg);
	-- Display output of ALU operation
	output <= alu_to_reg;
	memory_addrs <= pc_to_memory;
	instruction <= memory_to_controller;
	reg_source <= source_to_a;
	reg_target <= target_to_mux;
	immediate <= controller_to_immediate;
	
end Behavioral;

