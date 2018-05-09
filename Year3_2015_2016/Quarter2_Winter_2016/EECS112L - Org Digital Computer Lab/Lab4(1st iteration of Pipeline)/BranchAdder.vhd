----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:36:16 02/28/2016 
-- Design Name: 
-- Module Name:    BranchAdder - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity BranchAdder is
    Port ( current_addrs : in  STD_LOGIC_VECTOR (31 downto 0);
           offset : in  STD_LOGIC_VECTOR (31 downto 0);
           target : in  STD_LOGIC_VECTOR (31 downto 0);
           branch_enable : in  STD_LOGIC;
           jump_enable : in  STD_LOGIC;
			  next_address : out  STD_LOGIC_VECTOR (31 downto 0);
			  jump_return_addrs : out STD_LOGIC_VECTOR (31 downto 0));
			  
end BranchAdder;

architecture Behavioral of BranchAdder is

begin
	next_address <= 	current_addrs + 4 + (offset(29 downto 0)&"00") when branch_enable = '1' else -- branch
							(target (29 downto 0)&"00") when jump_enable = '1' else -- jump
							(OTHERS => '0'); -- if neither, output Zeros
	
	jump_return_addrs <= current_addrs + 4; -- return address for jal and jalr is PC+4 b/c of no branch delay
	
end Behavioral;

