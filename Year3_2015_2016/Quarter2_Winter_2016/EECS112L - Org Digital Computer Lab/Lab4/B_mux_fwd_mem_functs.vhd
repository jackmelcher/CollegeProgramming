----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:42:39 03/05/2016 
-- Design Name: 
-- Module Name:    B_mux_fwd_mem_functs - Behavioral 
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

entity B_mux_fwd_mem_functs is
    Port ( b_input_initial : in  STD_LOGIC_VECTOR (31 downto 0);
			  immediate : in STD_LOGIC_VECTOR (31 downto 0);
           load_or_store : in  STD_LOGIC;
           b_input_final : out  STD_LOGIC_VECTOR (31 downto 0));
end B_mux_fwd_mem_functs;

architecture Behavioral of B_mux_fwd_mem_functs is

begin

	b_input_final <= 	immediate when load_or_store = '1' else  -- all load and store functions just add
							b_input_initial;

end Behavioral;

