----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:41:34 01/31/2016 
-- Design Name: 
-- Module Name:    PCadder - Behavioral 
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
-- use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity PCadder is
    Port ( current_addrs : in  STD_LOGIC_VECTOR (31 downto 0);
           branch_or_jump_addrs : in  STD_LOGIC_VECTOR (31 downto 0);
			  branch_enable : in  STD_LOGIC;
           jump_enable : in  STD_LOGIC;
			  next_address : out  STD_LOGIC_VECTOR (31 downto 0));
end PCadder;

architecture Behavioral of PCadder is

begin

	next_address <= 	branch_or_jump_addrs when branch_enable = '1' OR jump_enable = '1' else -- branch or jump
							current_addrs + 4; -- default PC+4
		
end Behavioral;

