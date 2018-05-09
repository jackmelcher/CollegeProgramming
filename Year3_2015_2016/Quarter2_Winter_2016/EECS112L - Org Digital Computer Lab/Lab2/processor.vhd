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
				
				--ref_clk : out  STD_LOGIC;
				--reset : out  STD_LOGIC
				rom_addrs : out STD_LOGIC_VECTOR(31 downto 0);
				instruction:out std_logic_vector(31 downto 0);
				reg_read1:out std_logic_vector(4 downto 0);
				reg_read2:out std_logic_vector(4 downto 0);
				reg_data1:out std_logic_vector(31 downto 0);
				reg_data2:out std_logic_vector(31 downto 0);
				immediate:out std_logic_vector(31 downto 0);
				b_output:out std_logic_vector(31 downto 0);
				alu_output:out std_logic_vector(31 downto 0);
				ram_we:out std_logic;
				ram_rdata:out std_logic_vector(31 downto 0);
				reg_we:out std_logic;
				reg_waddr:out std_logic_vector(4 downto 0);
				o_output:out std_logic_vector(31 downto 0));
end processor;

architecture Behavioral of processor is

-- Component Declarations
	--PC
	COMPONENT pc is			
		Port (	clk : in  STD_LOGIC;
					enable: in STD_LOGIC;
					rst_s : in STD_LOGIC;
					dout : out  STD_LOGIC_VECTOR (NBIT-1 downto 0));
	END COMPONENT;
	
	--Instruction Memory
	COMPONENT rom is
		 Port ( addr : in  STD_LOGIC_VECTOR (31 downto 0);
				  dataIO : inout  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--Controller
	COMPONENT controller is
    Port ( instruction : in  STD_LOGIC_VECTOR (31 downto 0);

           reg_read_addr1 : out  STD_LOGIC_VECTOR (4 downto 0);
           reg_read_addr2 : out  STD_LOGIC_VECTOR (4 downto 0);
           reg_write_addr : out  STD_LOGIC_VECTOR (4 downto 0);
			  reg_write_enable : out std_logic;
           
			  ram_write_enable : out std_logic;

			  --shift_amount : out  STD_LOGIC_VECTOR (4 downto 0);
			  immediate : out  STD_LOGIC_VECTOR (31 downto 0);
           --target : out  STD_LOGIC_VECTOR (25 downto 0);			  
			  
			  alu_funct : OUT STD_LOGIC_VECTOR (5 DOWNTO 0);
			  
			  b_mux_sel : out std_logic;
			  out_mux_sel : out std_logic);
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
	
	--B mux
	COMPONENT b_mux is
		Port ( reg_b : in  STD_LOGIC_VECTOR (31 downto 0);
				 imm_b : in  STD_LOGIC_VECTOR (31 downto 0);
				 sel : in  STD_LOGIC;
				 outp : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--ALU
	COMPONENT alu is
		 Port ( Func_in : in  STD_LOGIC_VECTOR (5 downto 0);
				  A_in : in  STD_LOGIC_VECTOR (31 downto 0);
				  B_in : in  STD_LOGIC_VECTOR (31 downto 0);
				  --shift_amount : in  STD_LOGIC_VECTOR (4 downto 0);			  
				  O_out : out  STD_LOGIC_VECTOR (31 downto 0));
				  --Branch_out : out  STD_LOGIC;
				  --Jump_out : out  STD_LOGIC);
	END COMPONENT;
	
	--Data Memory
	COMPONENT ram is
		 Port ( clk : in  STD_LOGIC;
				  we : in  STD_LOGIC;
				  addr : in  STD_LOGIC_VECTOR (31 downto 0);
				  dataI : in  STD_LOGIC_VECTOR (31 downto 0);
				  dataO : out  STD_LOGIC_VECTOR (31 downto 0));
	END COMPONENT;
	
	--Output mux
	COMPONENT output_mux is
		Port ( alu_out : in  STD_LOGIC_VECTOR (31 downto 0);
				 ram_out : in  STD_LOGIC_VECTOR (31 downto 0);
				 sel : in  STD_LOGIC;
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

	SIGNAL controller_to_bmux_sel : STD_LOGIC;
	SIGNAL controller_to_bmux_immediate: std_logic_vector(31 downto 0);
	SIGNAL register_rdata2_to_bmux_reg_and_ram_dataI: std_logic_vector(31 downto 0);
	
	SIGNAL controller_to_alu_function : std_logic_vector(5 downto 0);
	SIGNAL reg_rdata1_to_alu : std_logic_vector(31 downto 0);
	SIGNAL b_to_alu : std_logic_vector(31 downto 0);
	
	Signal alu_output_to_ram_addr_and_outmux_alu_out : std_logic_vector(31 downto 0);

	Signal ram_dataO_to_outmux_ram_out : std_logic_vector(31 downto 0);
	
	Signal controller_to_outmux_sel : STD_LOGIC;
	Signal outmux_output_to_reg_wdata : std_logic_vector(31 downto 0);
	
begin
	-- Port Mapping
	PCounter: pc Port MAP(	clk => p_clk,
									enable => pc_enable,
									rst_s => p_rst_s,
									dout => pc_to_rom);
							
	ROMemory: rom Port MAP( addr => pc_to_rom,
									dataIO => rom_to_controller);
						
	CON: controller Port Map(	instruction => rom_to_controller,

										reg_read_addr1 => controller_to_reg_raddr1,
										reg_read_addr2 => controller_to_reg_raddr2,
										reg_write_addr => controller_to_reg_waddr,
										reg_write_enable => controller_to_reg_we,
										  
										ram_write_enable => controller_to_ram_we,

										--shift_amount => ;
										immediate => controller_to_bmux_immediate,
										--target => ;			  
										  
										alu_funct => controller_to_alu_function,
										 
										b_mux_sel => controller_to_bmux_sel,
										out_mux_sel => controller_to_outmux_sel);
	
	REG: regfile PORT MAP( clk => p_clk,
								  rst_s => p_rst_s,
								  we => controller_to_reg_we,
								  raddr_1 => controller_to_reg_raddr1,
								  raddr_2 => controller_to_reg_raddr2,
								  waddr => controller_to_reg_waddr,
								  rdata_1 => reg_rdata1_to_alu,
								  rdata_2 => register_rdata2_to_bmux_reg_and_ram_dataI,
								  wdata => outmux_output_to_reg_wdata);
	
	BMUX: b_mux Port Map( reg_b => register_rdata2_to_bmux_reg_and_ram_dataI,
								 imm_b => controller_to_bmux_immediate,
								 sel => controller_to_bmux_sel,
								 outp => b_to_alu);
	
	ALUnit: alu Port Map( Func_in => controller_to_alu_function,
								 A_in => reg_rdata1_to_alu,
								 B_in => b_to_alu,
								 --shift_amount => ,
								 O_out => alu_output_to_ram_addr_and_outmux_alu_out);
								 --Branch_out => ,
								 --Jump_out => ;
	
	RAMemory: ram Port Map( clk => p_clk,
									we => controller_to_ram_we,
									addr => alu_output_to_ram_addr_and_outmux_alu_out,
									dataI => register_rdata2_to_bmux_reg_and_ram_dataI,
									dataO => ram_dataO_to_outmux_ram_out);
	
	OMUX: output_mux Port MAP( alu_out => alu_output_to_ram_addr_and_outmux_alu_out,
										ram_out => ram_dataO_to_outmux_ram_out,
										sel => controller_to_outmux_sel,
										outp => outmux_output_to_reg_wdata);
	
	-- Display output of Processor operation
	--ref_clk <= ;
	--reset <= ;
	rom_addrs <= pc_to_rom;
	instruction <= rom_to_controller;
	reg_read1 <= controller_to_reg_raddr1;
	reg_read2 <= controller_to_reg_raddr2;
	reg_data1 <= reg_rdata1_to_alu;
	reg_data2 <= register_rdata2_to_bmux_reg_and_ram_dataI;
	immediate <= controller_to_bmux_immediate;
	b_output <= b_to_alu;
	alu_output <= alu_output_to_ram_addr_and_outmux_alu_out;
	ram_we <= controller_to_ram_we;
	ram_rdata <= ram_dataO_to_outmux_ram_out;
	reg_we <= controller_to_reg_we;
	reg_waddr <= controller_to_reg_waddr;
	o_output <= outmux_output_to_reg_wdata;
	
end Behavioral;

