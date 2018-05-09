----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:46:30 01/11/2016 
-- Design Name: 
-- Module Name:    controller - Behavioral 
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


entity controller is
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
			  mem_read : out STD_LOGIC;
			  
			  --added for data hazard when loading or storing
			  load_or_store : out STD_LOGIC);
end controller;

architecture Behavioral of controller is

begin
	-- R type instruction (Arithmetic and Logic involving two registers)
	-- (31 downto 26), (25 downto 21), (20 downto 16), (15 downto 11), (10 downto 6), (5 downto 0)
	-- 	opcode			rs						rt					rd					shamt				funct
	-- opcode is "000000"
	-- A is rs and B is rt inputs to ALU
	-- output of ALU is written to rd
	-- shamt is for shifting functions, otherwise its "00000"
	-- funct is what the ALU should perform
	
	-- I type instruction (Arithmetic and Logic involving one register and immediate)
	-- (31 downto 26), (25 downto 21), (20 downto 16), (15 downto 0)	
	--  opcode				rs						rt					immediate
	-- includes branch, load, and store
	-- opcode is what ALU should perform, is anything but "000000"
	-- A is rs and B is immediate inputs to ALU
	-- output of ALU is written to rt
	-- load, rs contains the address of ram to access, rt is the register where the data from ram is loaded into
	-- store, rs contains the address of ram to access, rt is the register where the data is obtained to be stored into ram
	
	reg_read_addr1 <=	instruction(25 downto 21);
	reg_read_addr2 <=	instruction(20 downto 16);
	
	reg_write_addr <=	"11111" when instruction(31 downto 26) = "000011" else -- write addrs 31 if jal 
							instruction(15 downto 11) when instruction(31 downto 26) = "000000" else -- write addrs is rd
							instruction(20 downto 16);	-- write addrs is rt

	reg_write_enable <= 	'0' when instruction(31 downto 26) = func_sw else -- dont write to registers when storing
								'0' when instruction(31 downto 26) = func_sh else
								'0' when instruction(31 downto 26) = func_sb else
								'0' when instruction(31 downto 26) = "000010" else -- dont write to reg when j
								'0' when instruction(31 downto 26) = "000000" AND instruction(5 downto 0) = "001000" else -- dont write when jr
								'0' when instruction(31 downto 26) = "000100" else -- dont write when beq
								'0' when instruction(31 downto 26) = "000101" else -- dont write when bne
								'0' when instruction(31 downto 26) = "000110" else -- dont write when blez
								'0' when instruction(31 downto 26) = "000111" else -- dont write when bgtz
								'0' when instruction(31 downto 26) = "000001" else -- dont write when bltz
								'0' when instruction(31 downto 26) = "000001" else -- dont write when bgez
								'1';
	
	ram_write_enable <=	'1' when instruction(31 downto 26) = func_sw else --write to ram only when storing
								'1' when instruction(31 downto 26) = func_sh else
								'1' when instruction(31 downto 26) = func_sb else
								'0';
	
	ram_size <= "000" when instruction(31 downto 26) = func_lb else
					"000" when instruction(31 downto 26) = func_sb else
					"001" when instruction(31 downto 26) = func_lbu else
					"010" when instruction(31 downto 26) = func_lh else
					"010" when instruction(31 downto 26) = func_sh else
					"011" when instruction(31 downto 26) = func_lhu else
					"100" when instruction(31 downto 26) = func_lw else
					"100" when instruction(31 downto 26) = func_sw else
					"111"; -- defualt, will cause no storing and load output to be zero
					
	shift_amount <= 	ONES(31 downto 5) & instruction(10 downto 6) when instruction(10) = '1' else
							ZERO(31 downto 5) & instruction(10 downto 6);
	
	immediate <=	ONES(31 downto 16) & instruction(15 downto 0) when instruction(15) = '1' else
						ZERO(31 downto 16) & instruction(15 downto 0);
	
	target <=		ONES(31 downto 26) & instruction(25 downto 0) when instruction(25) = '1' else
						ZERO(31 downto 26) & instruction(25 downto 0);

	a_mux_sel <= 	'1' when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_sll else -- use shift amount for shifting
						'1' when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_srl else -- use shift amount for shifting
						'1' when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_sra else -- use shift amount for shifting
						'0'; -- use data in rs
						
	b_mux_sel <= 	'0' when instruction(31 downto 26) = "000000" else -- '0' is R-type, '1' is I-type
						'1';
						
	alu_funct <=alu_func_add 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_add else -- add
					alu_func_sub 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_sub else -- sub
					alu_func_and 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_and else -- and
					alu_func_or 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_or else -- or
					alu_func_xor 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_xor else -- xor
					alu_func_nor	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_nor else -- nor
					alu_func_slt 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_slt else -- slt
					
					alu_func_add 	when instruction(31 downto 26) = func_addi else -- addi
					alu_func_and 	when instruction(31 downto 26) = func_andi else -- andi
					alu_func_or 	when instruction(31 downto 26) = func_ori else -- ori
					alu_func_xor 	when instruction(31 downto 26) = func_xori else -- xori
					alu_func_slt 	when instruction(31 downto 26) = func_slti else -- slti
					
					alu_func_add 	when instruction(31 downto 26) = func_lb else  -- all load and store functions just add
					alu_func_add 	when instruction(31 downto 26) = func_lbu else
					alu_func_add 	when instruction(31 downto 26) = func_lh else 
					alu_func_add 	when instruction(31 downto 26) = func_lhu else
					alu_func_add 	when instruction(31 downto 26) = func_lw else 
					alu_func_add 	when instruction(31 downto 26) = func_sb else 
					alu_func_add 	when instruction(31 downto 26) = func_sh else 
					alu_func_add 	when instruction(31 downto 26) = func_sw else 					
					
					alu_func_sll 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_sll else -- sll
					alu_func_srl 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_srl else -- srl
					alu_func_sra 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_sra else -- sra
					alu_func_sll 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_sllv else -- sllv
					alu_func_srl 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_srlv else -- srlv
					alu_func_sra 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_srav else -- srav

					alu_func_add 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_addu else --addu
					alu_func_sub 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_subu else -- subu
					alu_func_slt 	when instruction(31 downto 26) = func_reg AND instruction(5 downto 0) = func_sltu else -- sltu

					alu_func_lui	when instruction(31 downto 26) = func_lui else -- lui
					alu_func_add 	when instruction(31 downto 26) = func_addiu else -- addiu
					alu_func_slt 	when instruction(31 downto 26) = func_sltiu else -- slti


					alu_func_zero; -- if error, default alu to output zero
	
	branch_funct <= 	branch_func_beq when instruction(31 downto 26) = "000100" else
							branch_func_bne when instruction(31 downto 26) = "000101" else
							branch_func_blez when instruction(31 downto 26) = "000110" AND instruction(20 downto 16) = "00000" else
							branch_func_bgtz when instruction(31 downto 26) = "000111" AND instruction(20 downto 16) = "00000" else
							branch_func_bltz when instruction(31 downto 26) = "000001" AND instruction(20 downto 16) = "00000" else
							branch_func_bgez when instruction(31 downto 26) = "000001" AND instruction(20 downto 16) = "00001" else
							"111111";-- dont branch
	
	jump_funct <=	'1' when instruction(31 downto 26) = "000000" AND instruction(5 downto 0) = "001000" else -- target for jr
						'1' when instruction(31 downto 26) = "000000" AND instruction(5 downto 0) = "001001" else -- target for jalr
						'0'; -- target for j and jal
	
	jump_enable <= '1' when instruction(31 downto 26) = "000010" else
						'1' when instruction(31 downto 26) = "000011" else
						'1' when instruction(31 downto 26) = "000000" AND instruction(5 downto 0) = "001000" else
						'1' when instruction(31 downto 26) = "000000" AND instruction(5 downto 0) = "001001" else
						'0';
							
	out_mux_sel <= "10" when instruction(31 downto 26) = "000011" else -- output is return address for $ra if jal
						"10" when instruction(31 downto 26) = "000000" AND instruction(5 downto 0) = "001001" else -- output is return address for rd if jalr
						"01" when instruction(31 downto 26) = "100011" else -- output is read data ram if lw
						"01" when instruction(31 downto 26) = "101011" else -- output is read data ram if sw
						"00"; -- output is alu results otherwise
	
	-- all load functions for loading control hazard	
	mem_read <= '1' when instruction(31 downto 26) = func_lb else  
					'1' when instruction(31 downto 26) = func_lbu else
					'1' when instruction(31 downto 26) = func_lh else 
					'1' when instruction(31 downto 26) = func_lhu else
					'1' when instruction(31 downto 26) = func_lw else 
					'0';

	-- set to 1 when loading or storing is being performed, data hazard stuff
	load_or_store <= '1' when instruction(31 downto 26) = func_lb else  
							'1' when instruction(31 downto 26) = func_lbu else
							'1' when instruction(31 downto 26) = func_lh else 
							'1' when instruction(31 downto 26) = func_lhu else
							'1' when instruction(31 downto 26) = func_lw else 
							'1' when instruction(31 downto 26) = func_sb else 
							'1' when instruction(31 downto 26) = func_sh else 
							'1' when instruction(31 downto 26) = func_sw else 
							'0';
end Behavioral;

