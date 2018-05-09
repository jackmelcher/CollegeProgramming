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
-- Final Project Package
library work;
use work.c31L_pack.ALL;

entity alu_32bit is
    Port (	A : in  STD_LOGIC_VECTOR (31 downto 0);
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
					cin : in STD_LOGIC;
					shl : in STD_LOGIC;
					opsel : in  STD_LOGIC_VECTOR (2 downto 0);
					mode : in  STD_LOGIC;
					cout : out STD_LOGIC;
					output : out  STD_LOGIC);
	END COMPONENT;

-- Signal Declaration
	Signal cin : STD_LOGIC;
	SIGNAL carry: std_logic_vector(30 downto 0);

begin
	cin <=	'0' when opsel="000" else --ADD
				'1' when opsel="001" else --SUB
				'0' when opsel="010" else --MOVE
				'1' when opsel="100" else --increment
				'0' when opsel="101" else --decrement
				'1' when opsel="110" else --ADD & Increment
				'0';--default to 0 carry in

	
-- First bit
	A1: alu_1bit PORT MAP (A=>A(0) , B=>b(0) , cin=>cin, shl=>'0', opsel=>opsel , mode=>mode , cout=>carry(0) , output=>output(0));
-- bits between 1 and 30
	G1: FOR i IN 1 TO 30 GENERATE
			ALUs: alu_1bit PORT MAP (A=>A(i) , B=>b(i) , cin=>carry(i-1), shl=>A(i-1), opsel=>opsel , mode=>mode , cout=>carry(i) , output=>output(i));
	END GENERATE;
--Last bit	
	A32: alu_1bit PORT MAP (A=>A(31) , B=>b(31) , cin=>carry(30), shl=>A(30), opsel=>opsel , mode=>mode , cout=>cout , output=>output(31));

end Behavioral;

