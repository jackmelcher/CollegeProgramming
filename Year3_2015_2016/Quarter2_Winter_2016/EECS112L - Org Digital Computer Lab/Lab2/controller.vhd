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

			  --shift_amount : out  STD_LOGIC_VECTOR (4 downto 0);
			  immediate : out  STD_LOGIC_VECTOR (31 downto 0);
           --target : out  STD_LOGIC_VECTOR (25 downto 0);			  
			  
			  alu_funct : OUT STD_LOGIC_VECTOR (5 DOWNTO 0);
			  
			  b_mux_sel : out std_logic;
			  out_mux_sel : out std_logic);
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
	-- load, rt is the register where the data from memory is stored
	-- store, rt is the register where the data is obtained to be put in memory
	
	reg_read_addr1 <=	instruction(25 downto 21);
	reg_read_addr2 <=	instruction(20 downto 16);
	
	reg_write_addr <=	instruction(15 downto 11) when instruction(31 downto 26) = "000000" else
						instruction(20 downto 16);

	reg_write_enable <= 	'0' when instruction(31 downto 26) = "101011" else --write to registers in all cases except when storing
								'1';
	
	ram_write_enable <=	'1' when instruction(31 downto 26) = "101011" else --write to ram only when storing
								'0';
	
	--shift_amount <= instruction(10 downto 6);
	
	immediate <=	ONES(31 downto 16) & instruction(15 downto 0) when instruction(15) = '1' else
						ZERO(31 downto 16) & instruction(15 downto 0);
	
	--target <=		instruction(25 downto 0);
	
	b_mux_sel <= 	'0' when instruction(31 downto 26) = "000000" else -- '0' is R-type, '1' is I-type
						'1';

	--alu_funct <=	instruction(5 downto 0) when instruction(31 downto 26) = "000000" else
	--					instruction(31 downto 26);
	
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
					
					alu_func_add 	when instruction(31 downto 26) = func_lw else -- lw
					alu_func_add 	when instruction(31 downto 26) = func_sw else -- sw

					(OTHERS => 'Z'); -- error

	out_mux_sel <= '1' when instruction(31 downto 26) = "100011" else
						'1' when instruction(31 downto 26) = "101011" else
						'0';
end Behavioral;

