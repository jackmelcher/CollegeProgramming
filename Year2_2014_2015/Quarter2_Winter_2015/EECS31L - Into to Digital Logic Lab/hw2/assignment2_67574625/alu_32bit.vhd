----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:40:17 02/07/2015 
-- Design Name: 
-- Module Name:    alu_32bit - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity alu_32bit is
    Port ( A : in  STD_LOGIC_VECTOR (31 downto 0);
           B : in  STD_LOGIC_VECTOR (31 downto 0);
           opsel : in  STD_LOGIC_VECTOR (2 downto 0);
           mode : in  STD_LOGIC;
           cout : out  STD_LOGIC;
           output : out  STD_LOGIC_VECTOR (31 downto 0));
end alu_32bit;

architecture Behavioral of alu_32bit is

-- Component Declaration
	COMPONENT alu_1bit IS
	    Port (	A : in  STD_LOGIC;
					B : in  STD_LOGIC;
					opsel : in  STD_LOGIC_VECTOR (2 downto 0);
					mode : in  STD_LOGIC;
					cout : out STD_LOGIC;
					output : out  STD_LOGIC
				);
	END COMPONENT;

-- Signal Declaration
	SIGNAL carry: std_logic_vector(30 downto 0);

begin

	A1: alu_1bit PORT MAP (A=>A(0) , B=>b(0) , opsel=>opsel , mode=>mode , cout=>carry(0) , output=>output(0) );
	G1: FOR i IN 1 TO 30 GENERATE
			ALUs: alu_1bit PORT MAP (A=>A(i) , B=>b(i) , opsel=>opsel , mode=>mode , cout=>carry(i) , output=>output(i));

end Behavioral;

