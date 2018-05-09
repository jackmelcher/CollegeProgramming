--
--	Package File Template
--
--	Purpose: This package defines supplemental types, subtypes, 
--		 constants, and functions 
--
--   To use any of the example code shown below, uncomment the lines and modify as necessary
--

library IEEE;
use IEEE.STD_LOGIC_1164.all;

package lab2_pack is

-- type <new_type> is
--  record
--    <type_name>        : std_logic_vector( 7 downto 0);
--    <type_name>        : std_logic;
-- end record;
--
-- Declare constants
--
-- constant <constant_name>		: time := <time_unit> ns;
-- constant <constant_name>		: integer := <value;
--
-- Declare functions and procedure
--
-- function <function_name>  (signal <signal_name> : in <type_declaration>) return <type_declaration>;
-- procedure <procedure_name> (<type_declaration> <constant_name>	: in <type_declaration>);
--

constant ZERO          : std_logic_vector(31 downto 0) :=
      "00000000000000000000000000000000";
constant ONES          : std_logic_vector(31 downto 0) :=
      "11111111111111111111111111111111";


constant NBIT	: integer := 32;		-- Bit Width
constant NSEL	: integer := 5;		

constant SEL3	: integer := 3;
constant SEL1	: integer := 1;
constant OP	: integer:=18; --Number of instructions stored in Memory(changed to 17)
constant reg_field: integer := 6; -- 64 entries for Register File
constant immediate_size: integer:=15;
-- For the program counter and Memory
constant OP_binary : std_logic_vector(NBIT-1 downto 0) := "00000000000000000000000000010010";


-- note about u functions, they check for 
	
subtype instruction_function_type is std_logic_vector(5 downto 0);

-- R type instruction (Arithmetic and Logic involving two registers)
-- (31 downto 26), (25 downto 21), (20 downto 16), (15 downto 11), (10 downto 6), (5 downto 0)
-- 	opcode			rs						rt					rd					shamt				funct

	constant func_reg  : instruction_function_type := "000000"; -- opcode
	-- funct of r-type
	constant func_sll  : instruction_function_type := "000000";
	constant func_srl  : instruction_function_type := "000010";
	constant func_sra  : instruction_function_type := "000011";
	constant func_sllv : instruction_function_type := "000100";
	constant func_srlv : instruction_function_type := "000110";
	constant func_srav : instruction_function_type := "000111";

	constant func_add  : instruction_function_type := "100000";
	constant func_addu  : instruction_function_type := "100001";
	constant func_sub  : instruction_function_type := "100010";
	constant func_subu  : instruction_function_type := "100011";
	constant func_and  : instruction_function_type := "100100";
	constant func_or   : instruction_function_type := "100101";
	constant func_xor  : instruction_function_type := "100110";
	constant func_nor  : instruction_function_type := "100111";
	constant func_slt  : instruction_function_type := "101010";
	constant func_sltu  : instruction_function_type := "101011";
	
	
-- I type instruction (Arithmetic and Logic involving one register and immediate)
-- (31 downto 26), (25 downto 21), (20 downto 16), (15 downto 0)	
--  opcode				rs						rt					immediate

	-- I-type codes
	constant func_addi : instruction_function_type := "001000";
	constant func_addiu : instruction_function_type := "001001";
	constant func_slti : instruction_function_type := "001010";
	constant func_sltiu : instruction_function_type := "001011";	
	constant func_andi : instruction_function_type := "001100";
	constant func_ori  : instruction_function_type := "001101";
	constant func_xori : instruction_function_type := "001110";
	constant func_lui : instruction_function_type := "001111";
	constant func_lb : instruction_function_type := "100000";
	constant func_lh : instruction_function_type := "100001";
	constant func_lw   : instruction_function_type := "100011";
	constant func_lbu : instruction_function_type := "100110";
	constant func_lhu : instruction_function_type := "100111";
	constant func_sb : instruction_function_type := "101000";
	constant func_sh : instruction_function_type := "101001";
	constant func_sw   : instruction_function_type := "101011";


	-- Branch codes. (15 downto 0) is now called Offset
	-- branch between rs and rt
	constant func_beq		: instruction_function_type := "000100";
	constant func_bne		: instruction_function_type := "000101";
	-- branch between rs and rt = 0
	constant func_blez	: instruction_function_type := "000110";
	constant func_bgtz	: instruction_function_type := "000111";
	-- more branches, opcode = 1, for bltz rt = 0, for bgez rt = 1
	constant func_specialbranch	: instruction_function_type := "000001";
	constant func_bltz	: instruction_function_type := "000000";
	constant func_bgez	: instruction_function_type := "000001";

-- J type instruction (Unconditional change to program counter address)
-- (31 downto 26), (25 downto 0)
--  opcode				target 			
		
	-- J-Type codes
	constant func_j	: instruction_function_type := "000010";
	-- jal saves address of the next instruction into $ra = register31
	constant func_jal	: instruction_function_type := "000011";
	-- special jumps
	-- (31 downto 26), (25 downto 21), (20 downto 6), (5 downto 0)
	--  		0					rs 				0					8
	-- jr is a jump to address in rs
	constant func_jr	: instruction_function_type := "001000";
	-- (31 downto 26), (25 downto 21), (20 downto 16), (15 downto 11), (10 downto 6), (5 downto 0)
	--  		0					rs 				0					rd						0					9
	-- jalr is a jump to address in rs and saves the next address into rd (defaults to 31)
	constant func_jalr	: instruction_function_type := "001001";

subtype alu_function_type is std_logic_vector(5 downto 0);
	constant alu_func_add : alu_function_type := "000000";
	constant alu_func_sub : alu_function_type := "000001";
	constant alu_func_and : alu_function_type := "000010";
	constant alu_func_or  : alu_function_type := "000011";
	constant alu_func_xor : alu_function_type := "000100";
	constant alu_func_nor : alu_function_type := "000101";
	constant alu_func_slt : alu_function_type := "000110";
	
	constant alu_func_sll : alu_function_type := "000111";
	constant alu_func_srl : alu_function_type := "001000";
	constant alu_func_sra : alu_function_type := "001001";
	
	constant alu_func_lui : alu_function_type := "001010";
	constant alu_func_zero : alu_function_type := "111111";

	
subtype branch_function_type is std_logic_vector(5 downto 0);
	constant branch_func_beq 	: alu_function_type := "000000";
	constant branch_func_bne 	: alu_function_type := "000001";
	constant branch_func_blez 	: alu_function_type := "000010";
	constant branch_func_bgtz	: alu_function_type := "000011";
	constant branch_func_bltz 	: alu_function_type := "000100";
	constant branch_func_bgez 	: alu_function_type := "000101";
	
subtype reg_addr_type is std_logic_vector(4 downto 0);
	constant r0 : reg_addr_type := "00000";
	constant r1 : reg_addr_type := "00001";
	constant r2 : reg_addr_type := "00010";
	constant r3 : reg_addr_type := "00011";
	constant r4 : reg_addr_type := "00100";
	constant r5 : reg_addr_type := "00101";
	constant r6 : reg_addr_type := "00110";
	constant r7 : reg_addr_type := "00111";
	constant r8 : reg_addr_type := "01000";
	constant r9 : reg_addr_type := "01001";
	constant r10 : reg_addr_type := "01010";
	constant r11 : reg_addr_type := "01011";
	constant r12 : reg_addr_type := "01100";
	constant r13 : reg_addr_type := "01101";

type mux_instructions is array((OP-1) downto 0) of std_logic_vector(NBIT-1 downto 0);
type mux_in_2 is array(1 downto 0) of std_logic_vector(NBIT-1 downto 0);

end lab2_pack;

--package body lab2_pack is

---- Example 1
--  function <function_name>  (signal <signal_name> : in <type_declaration>  ) return <type_declaration> is
--    variable <variable_name>     : <type_declaration>;
--  begin
--    <variable_name> := <signal_name> xor <signal_name>;
--    return <variable_name>; 
--  end <function_name>;

---- Example 2
--  function <function_name>  (signal <signal_name> : in <type_declaration>;
--                         signal <signal_name>   : in <type_declaration>  ) return <type_declaration> is
--  begin
--    if (<signal_name> = '1') then
--      return <signal_name>;
--    else
--      return 'Z';
--    end if;
--  end <function_name>;

---- Procedure Example
--  procedure <procedure_name>  (<type_declaration> <constant_name>  : in <type_declaration>) is
--    
--  begin
--    
--  end <procedure_name>;
 
--end lab2_pack;
