----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:11:38 03/04/2016 
-- Design Name: 
-- Module Name:    HazardDetectionUnit - Behavioral 
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

entity HazardDetectionUnit is
	Port (  rs_ID : in  STD_LOGIC_VECTOR (4 downto 0);
			  rt_ID : in  STD_LOGIC_VECTOR (4 downto 0);
			  rt_EX : in  STD_LOGIC_VECTOR (4 downto 0);
  			  mem_read_EX : in  STD_LOGIC;
			  
			  pc_enable : out  STD_LOGIC;
			  NOP_select : out  STD_LOGIC;
			  pipe1_enable : out  STD_LOGIC);
end HazardDetectionUnit;

architecture Behavioral of HazardDetectionUnit is

begin

--if (ID/EX.MemRead and
--((ID/EX.RegisterRt = IF/ID.RegisterRs) or
--(ID/EX.RegisterRt = IF/ID.RegisterRt)))
--stall the pipeline

	pc_enable <= '0' when (mem_read_EX = '1' AND((rt_EX = rs_ID) OR (rt_EX = rt_ID))) 
							AND rs_ID /= "00000" AND rt_ID /= "00000" AND rt_EX /= "00000" else
					 '1';
	
	NOP_select <= '1' when (mem_read_EX = '1' AND((rt_EX = rs_ID) OR (rt_EX = rt_ID))) 
									AND rs_ID /= "00000" AND rt_ID /= "00000" AND rt_EX /= "00000" else

					  '0';
	
	pipe1_enable <= '0' when (mem_read_EX = '1' AND((rt_EX = rs_ID) OR (rt_EX = rt_ID))) 
									AND rs_ID /= "00000" AND rt_ID /= "00000" AND rt_EX /= "00000" else
						 '1';
	
end Behavioral;

