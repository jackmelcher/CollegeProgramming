----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:45:28 01/31/2016 
-- Design Name: 
-- Module Name:    branch_control - Behavioral 
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
use IEEE.STD_LOGIC_SIGNED.ALL;

-- Added Package
library work;
use work.lab2_pack.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
-- use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity branch_and_jump_control is
    Port ( branch_funct : in  STD_LOGIC_VECTOR (5 downto 0);
			  jump_funct : in  STD_LOGIC;
			  rs_data: in STD_LOGIC_VECTOR (31 downto 0);
			  rt_data: in STD_LOGIC_VECTOR (31 downto 0);
           target_in: in STD_LOGIC_VECTOR (31 downto 0);
			  branch_enable : out  STD_LOGIC;
			  target_out: out STD_LOGIC_VECTOR (31 downto 0));
end branch_and_jump_control;

architecture Behavioral of branch_and_jump_control is

begin
	
	branch_enable <= 	'1' when branch_funct = branch_func_beq AND (rs_data - rt_data = 0) else
							'1' when branch_funct = branch_func_bne AND (rs_data - rt_data /= 0) else
							'1' when branch_funct = branch_func_blez AND (rs_data <= 0) else
							'1' when branch_funct = branch_func_bgtz AND (rs_data > 0) else
							'1' when branch_funct = branch_func_bltz AND (rs_data < 0) else
							'1' when branch_funct = branch_func_bgez AND (rs_data >= 0) else
							'0';
							
	target_out <= 	rs_data when jump_funct = '1' else -- target for jr or jalr
						target_in; -- target for j and jal
						
						

end Behavioral;

