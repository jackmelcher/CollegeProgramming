----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:35:18 01/11/2016 
-- Design Name: 
-- Module Name:    processor - Behavioral 
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


entity processor is
    Port (	p_clk : in std_logic;
				pc_enable : in std_logic;
				p_rst_s:in std_logic;
				
				rom_addrs : out STD_LOGIC_VECTOR(31 downto 0);
				instruction:out std_logic_vector(31 downto 0);
				reg_read1:out std_logic_vector(4 downto 0);
				reg_read2:out std_logic_vector(4 downto 0);
				reg_data1:out std_logic_vector(31 downto 0);
				reg_data2:out std_logic_vector(31 downto 0);
				immediate:out std_logic_vector(31 downto 0);
				shamt: out std_logic_vector(31 downto 0);
				a_output:out std_logic_vector(31 downto 0);
				b_output:out std_logic_vector(31 downto 0);
				alu_output:out std_logic_vector(31 downto 0);
				ram_we:out std_logic;
				ram_rdata:out std_logic_vector(31 downto 0);
				reg_we:out std_logic;
				
				
				reg_addrRS:out std_logic_vector(4 downto 0);
				reg_addrRT:out std_logic_vector(4 downto 0);
				reg_waddrMEM:out std_logic_vector(4 downto 0);
				reg_waddrWB:out std_logic_vector(4 downto 0);
				
				pc_enable_hbu : out std_logic;
			
				o_output:out std_logic_vector(31 downto 0));
end processor;

architecture Behavioral of processor is

-- Component Declarations
	--PC
	COMPONENT pc is			
		Port (	clk : in  STD_LOGIC;
					enable: in STD_LOGIC;
					--enable_hdu: in STD_LOGIC;
					rst_s : in STD_LOGIC;
					addr : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
					dout : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
	END COMPONENT;
	
	--PC Adder (NEW)
	COMPONENT PCadder is
    Port ( current_addrs : in  STD_LOGIC_VECTOR (31 downto 0);
           branch_or_jump_addrs : in  STD_LOGIC_VECTOR (31 downto 0);
			  branch_enable : in  STD_LOGIC;
           jump_enable : in  STD_LOGIC;
			  next_address : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--Instruction Memory
	COMPONENT rom is
		 Port ( addr : in  STD_LOGIC_VECTOR (31 downto 0);
				  dataO : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	-- IF/ID Pipeline REG (NEW)
	COMPONENT PipelineReg1_IF_ID is
		Port (	clk : in  STD_LOGIC;
					instruction_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
					current_addrs_in : in STD_LOGIC_VECTOR (NBIT-1 downto 0);
					enable: in STD_LOGIC;
					instruction_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0);
					current_addrs_out : out STD_LOGIC_VECTOR (NBIT-1 downto 0));
	end COMPONENT;
	
	--Controller
	COMPONENT controller is
    Port ( instruction : in  STD_LOGIC_VECTOR (31 downto 0);

           reg_read_addr1 : out  STD_LOGIC_VECTOR (4 downto 0);
           reg_read_addr2 : out  STD_LOGIC_VECTOR (4 downto 0);
           reg_write_addr : out  STD_LOGIC_VECTOR (4 downto 0);
			  reg_write_enable : out std_logic;
           
			  ram_write_enable : out std_logic;
			  ram_size : out STD_LOGIC_VECTOR (2 downto 0);

			  shift_amount : out  STD_LOGIC_VECTOR (31 downto 0);
			  immediate : out  STD_LOGIC_VECTOR (31 downto 0);
           target : out  STD_LOGIC_VECTOR (31 downto 0);			  
			  
			  alu_funct : OUT STD_LOGIC_VECTOR (5 DOWNTO 0);
			  branch_funct : OUT STD_LOGIC_VECTOR (5 DOWNTO 0);
 			  jump_funct: out std_logic;
			  jump_enable: out std_logic;
			  
  			  a_mux_sel : out std_logic;
			  b_mux_sel : out std_logic;
			  out_mux_sel : out STD_LOGIC_VECTOR(1 DOWNTO 0);
			  
			  --added for control hazard
			  mem_read : out STD_LOGIC);	
	END COMPONENT;
	
	--Register File
	COMPONENT regfile is
		Port ( clk : in  STD_LOGIC;
				  rst_s : in  STD_LOGIC;
				  we : in  STD_LOGIC;
				  raddr_1 : in  STD_LOGIC_VECTOR (NSEL-1 downto 0);
				  raddr_2 : in  STD_LOGIC_VECTOR (NSEL-1 downto 0);
				  waddr : in  STD_LOGIC_VECTOR (NSEL-1  downto 0);
				  rdata_1 : out  STD_LOGIC_VECTOR (NBIT-1 downto 0);
				  rdata_2 : out  STD_LOGIC_VECTOR (NBIT-1 downto 0);
				  wdata : in  STD_LOGIC_VECTOR (NBIT-1 downto 0));
	END COMPONENT;
	
	--A mux
	COMPONENT a_mux is
		Port ( shift_amount : in  STD_LOGIC_VECTOR (31 downto 0);
				 rs_data : in  STD_LOGIC_VECTOR (31 downto 0);
				 sel : in STD_LOGIC;
				 a_output : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--B mux
	COMPONENT b_mux is
		Port ( reg_b : in  STD_LOGIC_VECTOR (31 downto 0);
				 imm_b : in  STD_LOGIC_VECTOR (31 downto 0);
				 sel : in  STD_LOGIC;
				 b_output : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	-- Hazard Detection
	COMPONENT HazardDetectionUnit is
	Port (  rs_ID : in  STD_LOGIC_VECTOR (4 downto 0);
			  rt_ID : in  STD_LOGIC_VECTOR (4 downto 0);
			  rt_EX : in  STD_LOGIC_VECTOR (4 downto 0);
  			  mem_read_EX : in  STD_LOGIC;
			  
			  pc_enable : out  STD_LOGIC;
			  NOP_select : out  STD_LOGIC;
			  pipe1_enable : out  STD_LOGIC);
	end COMPONENT;
	
	-- Hazard Detection
	COMPONENT HazardDetectionWriteEnableMux is
		Port ( reg_we : in  STD_LOGIC;
			    ram_we : in  STD_LOGIC;
			    sel : in STD_LOGIC;
			    reg_we_out : out  STD_LOGIC;
			    ram_we_out : out  STD_LOGIC);
	end COMPONENT;

	-- ID/EX Pipeline REG (NEW)
	COMPONENT PipelineReg2_ID_EX is
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
					reg_addr2_out : out STD_LOGIC_VECTOR (4 downto 0);
					
					-- Added for loading control hazard
					mem_read_in : in STD_LOGIC;
					mem_read_out : out STD_LOGIC);	
	end COMPONENT;
	
	--A mux
	COMPONENT fwd_a is
    Port ( pipe2_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd1_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd2_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd1 : in  STD_LOGIC;
           fwd2 : in  STD_LOGIC;
           a_out : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--B mux
	COMPONENT fwd_b is
    Port ( pipe2_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd1_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd2_input : in  STD_LOGIC_VECTOR (31 downto 0);
           fwd1 : in  STD_LOGIC;
           fwd2 : in  STD_LOGIC;
           b_out : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--ALU
	COMPONENT alu is
		 Port ( Func_in : in  STD_LOGIC_VECTOR (5 downto 0);
				  A_in : in  STD_LOGIC_VECTOR (31 downto 0);
				  B_in : in  STD_LOGIC_VECTOR (31 downto 0);
				  O_out : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--Addition branch and jump controls
	COMPONENT branch_and_jump_control is
    Port ( branch_funct : in  STD_LOGIC_VECTOR (5 downto 0);
			  jump_funct : in  STD_LOGIC;
			  rs_data: in STD_LOGIC_VECTOR (31 downto 0);
			  rt_data: in STD_LOGIC_VECTOR (31 downto 0);
           target_in: in STD_LOGIC_VECTOR (31 downto 0);
			  branch_enable : out  STD_LOGIC;
			  target_out: out STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;

	--Branch Adder (FORMERLY PC ADDER)
	COMPONENT BranchAdder is
    Port ( current_addrs : in  STD_LOGIC_VECTOR (31 downto 0);
           offset : in  STD_LOGIC_VECTOR (31 downto 0);
           target : in  STD_LOGIC_VECTOR (31 downto 0);
           branch_enable : in  STD_LOGIC;
           jump_enable : in  STD_LOGIC;
			  next_address : out  STD_LOGIC_VECTOR (31 downto 0);
			  jump_return_addrs : out STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--Forwarding Unit
	COMPONENT ForwardingUnit is
	Port (  raddr_1_con : in  STD_LOGIC_VECTOR (4 downto 0);
           raddr_2_con : in  STD_LOGIC_VECTOR (4 downto 0);
			  reg_waddr_MEM : in  STD_LOGIC_VECTOR (4 downto 0);
			  reg_waddr_WB : in  STD_LOGIC_VECTOR (4 downto 0);

           forward_a1 : out  STD_LOGIC;
           forward_a2 : out  STD_LOGIC;

           forward_b1 : out  STD_LOGIC;
           forward_b2 : out  STD_LOGIC);
	end COMPONENT;
	
	-- EX/MEM Pipeline REG (NEW)
	COMPONENT PipelineReg3_EX_MEM is
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

	end COMPONENT;
	
	--Data Memory
	COMPONENT ram is
		 Port ( clk : in  STD_LOGIC;
				  we : in  STD_LOGIC;
				  dsize : in STD_LOGIC_VECTOR (2 downto 0);
				  addr : in  STD_LOGIC_VECTOR (8 downto 0);
				  dataI : in  STD_LOGIC_VECTOR (31 downto 0);
				  dataO : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--RAM READ BLOCK
	COMPONENT ram_read is
    Port ( addr : in  STD_LOGIC_VECTOR (8 downto 0);
           dsize : in  STD_LOGIC_VECTOR (2 downto 0);
           ram_read_in : in  STD_LOGIC_VECTOR (31 downto 0);
           ram_read_out : out  STD_LOGIC_VECTOR (31 downto 0));
	end COMPONENT;
	
	-- MEM/WB Pipeline REG (NEW)
	COMPONENT PipelineReg4_MEM_WB is
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
					
	end COMPONENT;

	--Output mux
	COMPONENT output_mux is
		Port ( alu_out : in  STD_LOGIC_VECTOR (31 downto 0);
				 ram_out : in  STD_LOGIC_VECTOR (31 downto 0);
	  			 jump_out : in  STD_LOGIC_VECTOR (31 downto 0);
				 sel : in  STD_LOGIC_VECTOR (1 downto 0);
				 outp : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	


	-- Signal Declarations
	SIGNAL pc_to_rom : STD_LOGIC_VECTOR(31 downto 0);
	
	SIGNAL rom_to_controller : std_logic_vector(31 downto 0);
	
	SIGNAL controller_to_reg_raddr1 : std_logic_vector(4 downto 0);
	SIGNAL controller_to_reg_raddr2 : std_logic_vector(4 downto 0);
	SIGNAL controller_to_reg_waddr : std_logic_vector(4 downto 0);
	SIGNAL controller_to_reg_we : STD_LOGIC;
	
	SIGNAL controller_to_ram_we : STD_LOGIC;

	SIGNAL reg_rdata1_to_alu : std_logic_vector(31 downto 0);

	SIGNAL controller_to_amux_sel : STD_LOGIC;
	SIGNAL controller_to_amux_shamt: std_logic_vector(31 downto 0);

	SIGNAL controller_to_bmux_sel : STD_LOGIC;
	SIGNAL controller_to_bmux_immediate: std_logic_vector(31 downto 0);
	SIGNAL register_rdata2_to_bmux_reg_and_ram_dataI: std_logic_vector(31 downto 0);
	
	SIGNAL controller_to_alu_function : std_logic_vector(5 downto 0);
	SIGNAL a_to_alu : std_logic_vector(31 downto 0);
	SIGNAL b_to_alu : std_logic_vector(31 downto 0);
	
	Signal alu_output_to_ram_addr_and_outmux_alu_out : std_logic_vector(31 downto 0);

	Signal ram_dataO_to_ramread : std_logic_vector(31 downto 0);
	
	Signal controller_to_outmux_sel : std_logic_vector(1 downto 0);
	Signal outmux_output_to_reg_wdata : std_logic_vector(31 downto 0);
	
	Signal controller_to_bc_target : std_logic_vector(31 downto 0);
	Signal controller_to_bc_bfunc : std_logic_vector(5 downto 0);
	Signal controller_to_bc_jenable : STD_LOGIC;
	Signal controller_to_bc_jfunct: STD_LOGIC;
	
	Signal pcadder_to_pc_addrs : std_logic_vector(31 downto 0);
	Signal pcadder_to_outmux_ra : std_logic_vector(31 downto 0);
	
	Signal bc_to_pcadder_target : std_logic_vector(31 downto 0);
	Signal bc_to_pcadder_benable : STD_LOGIC;
	
	Signal branchadder_to_pcadder : std_logic_vector(31 downto 0);
	
	Signal controller_to_ram_dsize : std_logic_vector(2 downto 0);
	
	SIGNAL ram_read_to_output_mux : std_logic_vector(31 downto 0);
	
	--New Pipeline Signals
	Signal pipe1_to_pipe2_currentaddrs : std_logic_vector(31 downto 0);
	Signal pipe1_to_controller_instruction : std_logic_vector(31 downto 0);

	Signal pipe2_to_bc_rs_data : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe2_to_bc_rt_data : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe2_to_pipe3_reg_we : STD_LOGIC;
	Signal pipe2_to_pipe3_reg_write_addr : STD_LOGIC_VECTOR (4 downto 0);
	Signal pipe2_to_pipe3_ram_we : STD_LOGIC;
	Signal pipe2_to_pipe3_ram_size : STD_LOGIC_VECTOR (2 downto 0);
	Signal pipe2_to_alu_alu_funct : STD_LOGIC_VECTOR (5 DOWNTO 0);
	Signal pipe2_to_bc_branch_funct : STD_LOGIC_VECTOR (5 DOWNTO 0);
	Signal pipe2_to_bc_jump_funct : std_logic;
	Signal pipe2_to_badder_jump_enable : std_logic;			
	Signal pipe2_to_badder_immediate : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe2_to_bc_target : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe2_to_alu_a_output : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe2_to_alu_b_output : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe2_to_pipe3_out_mux_sel : STD_LOGIC_VECTOR(1 DOWNTO 0);
	Signal pipe2_to_badder_current_addrs : STD_LOGIC_VECTOR (NBIT-1 downto 0);		
	
	Signal pipe3_to_ram_rt_data : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe3_to_pipe4_reg_we : STD_LOGIC;
	Signal pipe3_to_pipe4_reg_write_addr : STD_LOGIC_VECTOR (4 downto 0);
	Signal pipe3_to_ram_we : STD_LOGIC;
	Signal pipe3_to_ram_size : STD_LOGIC_VECTOR (2 downto 0);
	Signal pipe3_to_pcadder_branch_enable : STD_LOGIC;
	Signal pipe3_to_pcadder_jump_enable : std_logic;			
	Signal pipe3_to_pcadder_next_address : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe3_to_pipe4_jump_return_addrs : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe3_to_ram_addr_and_pipe4_alu_output : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe3_to_pipe4_out_mux_sel : STD_LOGIC_VECTOR(1 DOWNTO 0);
	
	Signal pipe4_to_reg_we : STD_LOGIC;
	Signal pipe4_to_reg_write_addr : STD_LOGIC_VECTOR (4 downto 0);
	Signal pipe4_to_outmux_alu_output : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe4_to_outmux_ram_output : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe4_to_outmux_jump_return_addrs : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe4_to_outmux_sel : STD_LOGIC_VECTOR(1 DOWNTO 0);
	
	Signal fwda_to_alu : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal fwdb_to_alu : STD_LOGIC_VECTOR (NBIT-1 downto 0);
	Signal pipe2_to_fwd_rs : STD_LOGIC_VECTOR (4 downto 0); 
	Signal pipe2_to_fwd_rt : STD_LOGIC_VECTOR (4 downto 0); 
	Signal fwding_to_amux1 : STD_LOGIC;
	Signal fwding_to_amux2 : STD_LOGIC;
	Signal fwding_to_bmux1 : STD_LOGIC;
	Signal fwding_to_bmux2 : STD_LOGIC;
	
	Signal con_to_hdm_reg_we: STD_LOGIC; 
	Signal con_to_hdm_ram_we: STD_LOGIC; 
	Signal hdu_to_hdm_select: STD_LOGIC;
	Signal hdu_to_pc_enable: STD_LOGIC;
	Signal hdu_to_pipe1_enable: STD_LOGIC;
	Signal con_to_pipe2_memRead: STD_LOGIC;
	Signal pipe2_to_hdu_memRead: STD_LOGIC;

begin
	-- Port Mapping
	PCounter: pc Port MAP(	clk => p_clk,
									enable => hdu_to_pc_enable,
									--enable => pc_enable,
									--enable_hdu => hdu_to_pc_enable,
									rst_s => p_rst_s,
									addr => pcadder_to_pc_addrs,
									dout => pc_to_rom);
									
	PCA: PCadder Port MAP( current_addrs => pc_to_rom,
								  branch_or_jump_addrs => branchadder_to_pcadder,
								  branch_enable => bc_to_pcadder_benable,
								  jump_enable => controller_to_bc_jenable,
								  next_address => pcadder_to_pc_addrs);		
			  
	ROMemory: rom Port MAP( addr => pc_to_rom,
									dataO => rom_to_controller);
	
	PIPE1: PipelineReg1_IF_ID Port MAP(	clk => p_clk,
													instruction_in => rom_to_controller,
													current_addrs_in => pc_to_rom,
													enable => hdu_to_pipe1_enable,
													instruction_out => pipe1_to_controller_instruction,
													current_addrs_out => pipe1_to_pipe2_currentaddrs);
	
	CON: controller Port Map(	instruction => pipe1_to_controller_instruction,

										reg_read_addr1 => controller_to_reg_raddr1,
										reg_read_addr2 => controller_to_reg_raddr2,
										reg_write_addr => controller_to_reg_waddr,
										reg_write_enable => con_to_hdm_reg_we,
										  
										ram_write_enable => con_to_hdm_ram_we,
										ram_size => controller_to_ram_dsize,
										
										shift_amount => controller_to_amux_shamt,
										immediate => controller_to_bmux_immediate,
										target => controller_to_bc_target,			  
										  
										alu_funct => controller_to_alu_function,
										branch_funct => controller_to_bc_bfunc,
										jump_funct => controller_to_bc_jfunct,
										jump_enable => controller_to_bc_jenable,
			  
										a_mux_sel => controller_to_amux_sel,
										b_mux_sel => controller_to_bmux_sel,
										out_mux_sel => controller_to_outmux_sel,
										
										--added for control hazard
										mem_read => con_to_pipe2_memRead);
	
	REG: regfile PORT MAP( clk => p_clk,
								  rst_s => p_rst_s,
								  we => pipe4_to_reg_we,
								  raddr_1 => controller_to_reg_raddr1,
								  raddr_2 => controller_to_reg_raddr2,
								  waddr => pipe4_to_reg_write_addr,
								  rdata_1 => reg_rdata1_to_alu,
								  rdata_2 => register_rdata2_to_bmux_reg_and_ram_dataI,
								  wdata => outmux_output_to_reg_wdata);
		
	AMUX:  a_mux Port Map( 	shift_amount => controller_to_amux_shamt,
								rs_data => reg_rdata1_to_alu,
								sel => controller_to_amux_sel,						
								a_output => a_to_alu);
	
	
	BMUX: b_mux Port Map( reg_b => register_rdata2_to_bmux_reg_and_ram_dataI,
								 imm_b => controller_to_bmux_immediate,
								 sel => controller_to_bmux_sel,
								 b_output => b_to_alu);
	
	-- Hazard Detection
	HDU: HazardDetectionUnit Port Map(  rs_ID => controller_to_reg_raddr1,
												  rt_ID => controller_to_reg_raddr2,
												  rt_EX => controller_to_reg_raddr2,
												  mem_read_EX => pipe2_to_hdu_memRead,
												  
												  pc_enable => hdu_to_pc_enable,
												  NOP_select => hdu_to_hdm_select,
												  pipe1_enable => hdu_to_pipe1_enable);
	
	-- Hazard Detection
	HDM: HazardDetectionWriteEnableMux Port Map( reg_we => con_to_hdm_reg_we,
																 ram_we => con_to_hdm_ram_we,
																 sel => hdu_to_hdm_select,
																 reg_we_out => controller_to_reg_we,
																 ram_we_out => controller_to_ram_we);
	
	-- ID/EX Pipeline REG (NEW)
	PIPE2: PipelineReg2_ID_EX Port MAP(	clk => p_clk,
													
													rs_data_in => reg_rdata1_to_alu,
													rt_data_in => register_rdata2_to_bmux_reg_and_ram_dataI,
													reg_we_in => controller_to_reg_we,
													reg_write_addr_in => controller_to_reg_waddr,
													ram_we_in => controller_to_ram_we,
													ram_size_in => controller_to_ram_dsize,
													alu_funct_in => controller_to_alu_function,
													branch_funct_in => controller_to_bc_bfunc,
													jump_funct_in => controller_to_bc_jfunct,
													jump_enable_in => controller_to_bc_jenable,			
													immediate_in => controller_to_bmux_immediate,
													target_in => controller_to_bc_target,
													a_output_in => a_to_alu,
													b_output_in => b_to_alu,
													out_mux_sel_in => controller_to_outmux_sel,
													current_addrs_in => pipe1_to_pipe2_currentaddrs,
													
													rs_data_out => pipe2_to_bc_rs_data,
													rt_data_out => pipe2_to_bc_rt_data,
													reg_we_out => pipe2_to_pipe3_reg_we,
													reg_write_addr_out => pipe2_to_pipe3_reg_write_addr,
													ram_we_out => pipe2_to_pipe3_ram_we,
													ram_size_out => pipe2_to_pipe3_ram_size,
													alu_funct_out => pipe2_to_alu_alu_funct,
													branch_funct_out => pipe2_to_bc_branch_funct,
													jump_funct_out => pipe2_to_bc_jump_funct,
													jump_enable_out => pipe2_to_badder_jump_enable,		
													immediate_out => pipe2_to_badder_immediate,
													target_out => pipe2_to_bc_target,
													a_output_out => pipe2_to_alu_a_output,
													b_output_out => pipe2_to_alu_b_output,
													out_mux_sel_out => pipe2_to_pipe3_out_mux_sel,
													current_addrs_out => pipe2_to_badder_current_addrs,		
	
													-- Added for Forwarding
													reg_addr1_in => controller_to_reg_raddr1,
													reg_addr2_in => controller_to_reg_raddr2,
													reg_addr1_out => pipe2_to_fwd_rs,
													reg_addr2_out => pipe2_to_fwd_rt,
																
													-- Added for loading control hazard
													mem_read_in => con_to_pipe2_memRead,
													mem_read_out => pipe2_to_hdu_memRead);	
					
	AFWD:  fwd_a Port MAP( pipe2_input => pipe2_to_alu_a_output,
								  fwd1_input => pipe3_to_ram_addr_and_pipe4_alu_output,
								  fwd2_input => outmux_output_to_reg_wdata,
								  fwd1 => fwding_to_amux1,
								  fwd2 => fwding_to_amux2,
								  a_out => fwda_to_alu);
	
	
	BFWD: fwd_b Port MAP( pipe2_input => pipe2_to_alu_b_output,
								  fwd1_input => pipe3_to_ram_addr_and_pipe4_alu_output,
								  fwd2_input => outmux_output_to_reg_wdata,
								  fwd1 => fwding_to_bmux1,
								  fwd2 => fwding_to_bmux2,
								  b_out => fwdb_to_alu);
	
	ALUnit: alu Port Map( Func_in => pipe2_to_alu_alu_funct,
								 A_in => fwda_to_alu,
								 B_in => fwdb_to_alu,
								 O_out => alu_output_to_ram_addr_and_outmux_alu_out);
	
	BC: branch_and_jump_control Port MAP(	branch_funct => pipe2_to_bc_branch_funct,
														jump_funct => pipe2_to_bc_jump_funct,
														rs_data => pipe2_to_bc_rs_data,
														rt_data => pipe2_to_bc_rt_data,
														target_in => pipe2_to_bc_target,
														branch_enable => bc_to_pcadder_benable,
														target_out => bc_to_pcadder_target);
	
	BRA: BranchAdder Port MAP( current_addrs => pipe2_to_badder_current_addrs,
										offset => pipe2_to_badder_immediate,
										target => bc_to_pcadder_target,
										branch_enable => bc_to_pcadder_benable,
										jump_enable => pipe2_to_badder_jump_enable,
										next_address => branchadder_to_pcadder,
										jump_return_addrs => pcadder_to_outmux_ra);
	
	FWD: ForwardingUnit Port MAP(  raddr_1_con => pipe2_to_fwd_rs,
											 raddr_2_con => pipe2_to_fwd_rt,
											  reg_waddr_MEM => pipe3_to_pipe4_reg_write_addr,
											  reg_waddr_WB => pipe4_to_reg_write_addr,

											  forward_a1 => fwding_to_amux1,
											  forward_a2 => fwding_to_amux2,

											  forward_b1 => fwding_to_bmux1,
											  forward_b2 => fwding_to_bmux2);
	
	-- EX/MEM Pipeline REG (NEW)
	PIPE3: PipelineReg3_EX_MEM Port MAP(	clk => p_clk,

														rt_data_in => pipe2_to_bc_rt_data,
														reg_we_in => pipe2_to_pipe3_reg_we,
														reg_write_addr_in => pipe2_to_pipe3_reg_write_addr,
														ram_we_in => pipe2_to_pipe3_ram_we,
														ram_size_in => pipe2_to_pipe3_ram_size,
														branch_enable_in => bc_to_pcadder_benable,
														jump_enable_in => pipe2_to_badder_jump_enable,			
														next_address_in => branchadder_to_pcadder,
														jump_return_addrs_in => pcadder_to_outmux_ra,
														alu_output_in => alu_output_to_ram_addr_and_outmux_alu_out,
														out_mux_sel_in => pipe2_to_pipe3_out_mux_sel,

														rt_data_out => pipe3_to_ram_rt_data,
														reg_we_out => pipe3_to_pipe4_reg_we,
														reg_write_addr_out => pipe3_to_pipe4_reg_write_addr,
														ram_we_out => pipe3_to_ram_we,
														ram_size_out => pipe3_to_ram_size,
														branch_enable_out => pipe3_to_pcadder_branch_enable,
														jump_enable_out => pipe3_to_pcadder_jump_enable,			
														next_address_out => pipe3_to_pcadder_next_address,
														jump_return_addrs_out => pipe3_to_pipe4_jump_return_addrs,
														alu_output_out => pipe3_to_ram_addr_and_pipe4_alu_output,
														out_mux_sel_out => pipe3_to_pipe4_out_mux_sel);
	
	
	RAMemory: ram Port Map( clk => p_clk,
									we => pipe3_to_ram_we,
									dsize => pipe3_to_ram_size,
									addr => pipe3_to_ram_addr_and_pipe4_alu_output(8 downto 0),
									dataI => pipe3_to_ram_rt_data,
									dataO => ram_dataO_to_ramread);
	
	RAMread: ram_read Port MAP( addr => pipe3_to_ram_addr_and_pipe4_alu_output(8 downto 0),
									  dsize => pipe3_to_ram_size,
									  ram_read_in => ram_dataO_to_ramread,
									  ram_read_out => ram_read_to_output_mux);
	
	-- MEM/WB Pipeline REG (NEW)
	PIPE4: PipelineReg4_MEM_WB Port MAP (	clk => p_clk,
														
														reg_we_in => pipe3_to_pipe4_reg_we,
														reg_write_addr_in => pipe3_to_pipe4_reg_write_addr,
														alu_output_in => pipe3_to_ram_addr_and_pipe4_alu_output,
														ram_output_in => ram_read_to_output_mux,
														jump_return_addrs_in => pipe3_to_pipe4_jump_return_addrs,
														out_mux_sel_in => pipe3_to_pipe4_out_mux_sel,

														reg_we_out => pipe4_to_reg_we,
														reg_write_addr_out => pipe4_to_reg_write_addr,
														alu_output_out => pipe4_to_outmux_alu_output,
														ram_output_out => pipe4_to_outmux_ram_output,
														jump_return_addrs_out => pipe4_to_outmux_jump_return_addrs,
														out_mux_sel_out => pipe4_to_outmux_sel);
					
	
	OMUX: output_mux Port MAP( alu_out => pipe4_to_outmux_alu_output,
										ram_out => pipe4_to_outmux_ram_output,
										jump_out => pipe4_to_outmux_jump_return_addrs,
										sel => pipe4_to_outmux_sel,
										outp => outmux_output_to_reg_wdata);
										


	-- Display output of Processor operation
	rom_addrs <= pc_to_rom;
	instruction <= rom_to_controller;
	reg_read1 <= controller_to_reg_raddr1;
	reg_read2 <= controller_to_reg_raddr2;
	reg_data1 <= reg_rdata1_to_alu;
	reg_data2 <= register_rdata2_to_bmux_reg_and_ram_dataI;
	immediate <= controller_to_bmux_immediate;
	shamt <= controller_to_amux_shamt;
	a_output <= a_to_alu;
	b_output <= b_to_alu;
	alu_output <= alu_output_to_ram_addr_and_outmux_alu_out;
	ram_we <= controller_to_ram_we;
	ram_rdata <= ram_read_to_output_mux;
	reg_we <= controller_to_reg_we;

				reg_addrRS <= pipe2_to_fwd_rs;
				reg_addrRT <= pipe2_to_fwd_rt;
				reg_waddrMEM <= pipe3_to_pipe4_reg_write_addr;
				reg_waddrWB <= pipe4_to_reg_write_addr;
				
				pc_enable_hbu <= hdu_to_pipe1_enable;

				
	o_output <= outmux_output_to_reg_wdata;
	
end Behavioral;

