--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:58:05 03/09/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/Final Project/FinalProject_67574625_cpu/testbench_processor.vhd
-- Project Name:  FinalProject_67574625_cpu
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: processor_67574625
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
-- Final Project Package
library work;
use work.c31L_pack.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY testbench_processor IS
END testbench_processor;
 
ARCHITECTURE behavior OF testbench_processor IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT processor_67574625
    PORT(	clk : in std_logic;
				pc_enable:in std_logic;
				rst_s:in std_logic;
				memory_addrs : out STD_LOGIC_VECTOR(NBIT-1 downto 0);
				instruction:out std_logic_vector(BW-1 downto 0);
				reg_source:out std_logic_vector(BW-1 downto 0);
				reg_target:out std_logic_vector(BW-1 downto 0);
				immediate:out std_logic_vector(BW-1 downto 0);
				carry:out std_logic;
				output:out std_logic_vector(BW-1 downto 0)
			);
    END COMPONENT;
    
   --Inputs
   signal clk : std_logic := '0';
   signal rst_s : std_logic := '0';
	signal pc_enable : std_logic := '0';
	
	--Outputs
	signal memory_addrs : std_logic_vector(5 downto 0);
	signal instruction: std_logic_vector(BW-1 downto 0);
	signal reg_source : std_logic_vector(BW-1 downto 0);
   signal reg_target : std_logic_vector(BW-1 downto 0);
   signal immediate : std_logic_vector(BW-1 downto 0);
	signal carry : std_logic;
   signal output : std_logic_vector(31 downto 0);
	
	-- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: processor_67574625 PORT MAP (
          clk => clk,
			 pc_enable => pc_enable,
          rst_s => rst_s,
			 memory_addrs => memory_addrs,
			 instruction => instruction,
			 reg_source => reg_source,
			 reg_target => reg_target,
			 immediate=> immediate,
          carry => carry,
          output => output
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here 
		rst_s <= '1';
		wait for clk_period;
		rst_s <= '0';
		pc_enable <= '1';
		
      wait;
   end process;

END;
