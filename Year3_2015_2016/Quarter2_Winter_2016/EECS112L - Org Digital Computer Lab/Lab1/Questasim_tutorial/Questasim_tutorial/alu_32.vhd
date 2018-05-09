library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
 
entity ALU_32 is
   port
   (
      A, B     : in  std_logic_vector(31 downto 0);
      opcode   : in  std_logic_vector(3 downto 0);
      overflow : out std_logic;
      c_out    : out std_logic;
      equal    : out std_logic;
      output1  : out std_logic_vector(31 downto 0)
   );
end entity ALU_32;
 
architecture Behavioral of ALU_32 is

   signal temp: std_logic_vector(32 downto 0);

begin

   process(A, B, opcode, temp) is
   begin
      overflow <= '0';
      case opcode is
 	 when "0000" =>  -- No operation
 	    output1    <= (others => '0');
 	    c_out      <= '0';
 	    overflow   <= '0';
	    equal      <= '0';

 	 when "0001" => -- ADD
 	    Temp     <= std_logic_vector((unsigned("0" & A) + unsigned(B)));
            output1  <= temp(31 downto 0);
 	    c_out    <= temp(32);
 	    overflow <= temp(32);
	    equal <= '0';

 	 when "0010" => -- SUB
 	    if (A >= B) then
 	       output1 <= std_logic_vector(unsigned(A) - unsigned(B));
 	       overflow   <= '0';
	       equal <= '0';
            else
 	       output1 <= std_logic_vector(unsigned(B) - unsigned(A));
 	       overflow   <= '1';
	       equal <= '0';
            end if;

 	 when "0011" => -- COMP
            if (A = B) then
		    equal <= '1';
 	            c_out      <= '0';
 	            overflow   <= '0';
	    else
		    equal <= '0';
 	            c_out      <= '0';
 	            overflow   <= '0';
	    end if;

 	 when "0101" => -- AND
 	    output1 <= A and B;
	    equal <= '0';
 	    c_out      <= '0';
 	    overflow   <= '0';

 	 when "0110" => -- OR
 	    output1 <= A or B;
	    equal <= '0';
 	    c_out      <= '0';
 	    overflow   <= '0';

 	 when "0111" => -- NOT
 	    output1 <= not A;
	    equal <= '0';
 	    c_out      <= '0';
 	    overflow   <= '0';

 	 when "1000" => -- XOR
 	    output1 <= A xor B;
	    equal <= '0';
 	    c_out      <= '0';
 	    overflow   <= '0';

  	 when "1001" => -- SLL
            output1 <= std_logic_vector(unsigned(A) sll to_integer(unsigned(B)));
	    equal <= '0';

  	 when "1011" => -- MOV
            output1 <= A;
	    equal <= '0';
 	 when others =>
 	    output1    <= (others => '0');
 	    c_out      <= '0';
 	    overflow   <= '0';
	    equal      <= '0';
      end case;
   end process;

end architecture Behavioral;
