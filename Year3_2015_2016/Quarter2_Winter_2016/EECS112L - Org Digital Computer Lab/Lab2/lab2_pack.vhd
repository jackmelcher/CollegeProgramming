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

subtype intruction_function_type is std_logic_vector(5 downto 0);
	-- R-type codes
	constant func_reg		: intruction_function_type := "000000";
	constant func_add 	: intruction_function_type := "100000";
	constant func_sub 	: intruction_function_type := "100010";
	constant func_and 	: intruction_function_type := "100100";
	constant func_or 		: intruction_function_type := "100101";
	constant func_xor 	: intruction_function_type := "100110";
	constant func_nor 	: intruction_function_type := "100111";
	constant func_slt		: intruction_function_type := "101010";
   -- I-type codes
	constant func_addi 	: intruction_function_type := "001000";
	constant func_slti 	: intruction_function_type := "001010";
	constant func_andi 	: intruction_function_type := "001100";
	constant func_ori 	: intruction_function_type := "001101";
	constant func_xori 	: intruction_function_type := "001110";
	constant func_lw		: intruction_function_type := "100011";
	constant func_sw		: intruction_function_type := "101011";

subtype alu_function_type is std_logic_vector(5 downto 0);
	constant alu_func_add 	: alu_function_type := "000000";
	constant alu_func_sub 	: alu_function_type := "000001";
	constant alu_func_and 	: alu_function_type := "000010";
	constant alu_func_or		: alu_function_type := "000011";
	constant alu_func_xor 	: alu_function_type := "000100";
	constant alu_func_nor 	: alu_function_type := "000101";
	constant alu_func_slt		: alu_function_type := "000110";

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
