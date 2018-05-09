----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:22:07 03/05/2016 
-- Design Name: 
-- Module Name:    branchforwarding - Behavioral 
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

entity branchforwarding is
    Port ( alu_funct_EX : in  STD_LOGIC_VECTOR (5 downto 0);
           alu_result_EX : in  STD_LOGIC_VECTOR (31 downto 0);
           rs_addr_ID : in  STD_LOGIC_VECTOR (4 downto 0);
           rt_addr_ID : in  STD_LOGIC_VECTOR (4 downto 0);
           rs_data_ID : in  STD_LOGIC_VECTOR (31 downto 0);
           rt_data_ID : in  STD_LOGIC_VECTOR (31 downto 0);
           wb_addr_EX : in  STD_LOGIC_VECTOR (4 downto 0);
           rs_data_out : out  STD_LOGIC_VECTOR (31 downto 0);
           rt_data_out : out  STD_LOGIC_VECTOR (31 downto 0));
end branchforwarding;

architecture Behavioral of branchforwarding is

begin

	rs_data_out <= alu_result_EX when alu_funct_EX = alu_func_slt AND wb_addr_EX = rs_addr_ID else
						rs_data_ID;
						
	rt_data_out <= alu_result_EX when alu_funct_EX = alu_func_slt AND wb_addr_EX = rt_addr_ID else
						rt_data_ID;

end Behavioral;

