----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:39:37 03/03/2016 
-- Design Name: 
-- Module Name:    ForwardingUnit - Behavioral 
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

entity ForwardingUnit is
	Port (  raddr_1_con : in  STD_LOGIC_VECTOR (4 downto 0);
           raddr_2_con : in  STD_LOGIC_VECTOR (4 downto 0);
			  reg_waddr_MEM : in  STD_LOGIC_VECTOR (4 downto 0);
			  reg_waddr_WB : in  STD_LOGIC_VECTOR (4 downto 0);

           forward_a1 : out  STD_LOGIC;
           forward_a2 : out  STD_LOGIC;

           forward_b1 : out  STD_LOGIC;
           forward_b2 : out  STD_LOGIC);

end ForwardingUnit;

architecture Behavioral of ForwardingUnit is

begin

-- 1. EX hazard:
-- if (EX/MEM.RegWrite
-- and (EX/MEM.RegisterRd ? 0)
-- and (EX/MEM.RegisterRd = ID/EX.RegisterRs)) ForwardA = 10
-- if (EX/MEM.RegWrite
-- and (EX/MEM.RegisterRd ? 0)
-- and (EX/MEM.RegisterRd = ID/EX.RegisterRt)) ForwardB = 10

-- 2. MEM hazard:
-- if (MEM/WB.RegWrite
-- and (MEM/WB.RegisterRd ? 0)
-- and not(EX/MEM.RegWrite and (EX/MEM.RegisterRd ? 0)
-- 			and (EX/MEM.RegisterRd ? ID/EX.RegisterRs))
-- and ( MEM/WB.RegisterRd = ID/EX.RegisterRs)) ForwardA = 01
-- 
-- if (MEM/WB.RegWrite
-- and (MEM/WB.RegisterRd ? 0)
-- and not(EX/MEM.RegWrite and (EX/MEM.RegisterRd ? 0)
-- 			and (EX/MEM.RegisterRd ? ID/EX.RegisterRt))
-- and (MEM/WB.RegisterRd = ID/EX.RegisterRt)) ForwardB = 01

	forward_a1 <= 	'1' when reg_waddr_MEM = raddr_1_con AND reg_waddr_MEM /= "00000" else
						'0';

	forward_a2 <=	'1' when reg_waddr_WB = raddr_1_con AND reg_waddr_MEM /= "00000" else
						'0';
						
	forward_b1 <= 	'1' when reg_waddr_MEM = raddr_2_con  AND reg_waddr_MEM /= "00000" else
						'0';

	forward_b2 <=	'1' when reg_waddr_WB = raddr_2_con AND reg_waddr_MEM /= "00000" else
						'0';

end Behavioral;

