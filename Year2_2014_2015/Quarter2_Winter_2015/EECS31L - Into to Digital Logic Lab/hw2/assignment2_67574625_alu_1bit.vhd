----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:32:32 02/07/2015 
-- Design Name: 
-- Module Name:    alu_1bit - Behavioral 
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

entity alu_1bit is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
			  cin : inout STD_LOGIC;
           opsel : in  STD_LOGIC_VECTOR (2 downto 0);
           mode : in  STD_LOGIC;
			  cout : out STD_LOGIC;
           output : out  STD_LOGIC);
end alu_1bit;

architecture Behavioral of alu_1bit is


--Component Declarations

	COMPONENT mux2to1 IS
	Port ( in0 : in  STD_LOGIC;
          in1 : in  STD_LOGIC;
          sel : in  STD_LOGIC;
          output : out  STD_LOGIC
	);
	END COMPONENT;

	COMPONENT logic_unit is
	Port ( A : in  STD_LOGIC;
          B : in  STD_LOGIC;
			 shl: in STD_LOGIC;
          sel : in  STD_LOGIC_VECTOR (2 downto 0);
          output : out  STD_LOGIC
	);
	END COMPONENT;
	
	COMPONENT arithmetic_unit is
	Port ( B : in  STD_LOGIC;
          sel : in  STD_LOGIC_VECTOR (2 downto 0);
          output : out  STD_LOGIC
	);
	END COMPONENT;

	COMPONENT full_adder is
   Port ( A : in  STD_LOGIC;
          B : in  STD_LOGIC;
          cin : in  STD_LOGIC;
          cout : out  STD_LOGIC;
          sum : out  STD_LOGIC
	);
	END COMPONENT;

--Signal Declarations
	signal cin_to_adder: std_logic;
	signal B_to_adder: std_logic;
	signal LU_to_mode: std_logic;
	signal AU_to_mode: std_logic;

begin
	cin <='0' when opsel="000" else
			'1' when opsel="001" else
			'0' when opsel="010" else
			'1' when opsel="011" else
			'1' when opsel="100" else
			'0' when opsel="101" else
			'1' when opsel="110" else
			'Z';

	LU:		logic_unit PORT MAP (A=>A, B=>B, shl=>'0', sel=>opsel, output=>LU_to_mode);
	B_AU:		arithmetic_unit PORT MAP (B=>B, sel=>opsel, output=>B_to_adder);
	FA:		full_adder PORT MAP (A=>A, B=>B_to_adder, cin=>cin, cout=>cout, sum=>AU_to_mode);
	ALU:		mux2to1 PORT MAP (in1=>LU_to_mode, in0=>AU_to_mode, sel=>mode, output=>output);


end Behavioral;

