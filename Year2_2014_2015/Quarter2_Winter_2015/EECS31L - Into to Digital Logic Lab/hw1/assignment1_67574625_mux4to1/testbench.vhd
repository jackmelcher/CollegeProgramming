--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   14:48:12 01/18/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw1/assignment1_67574625_mux4to1/testbench.vhd
-- Project Name:  assignment1_67574625_mux4to1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: assignment1_67574625_mux4to1
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
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY testbench IS
END testbench;
 
ARCHITECTURE behavior OF testbench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT assignment1_67574625_mux4to1
    PORT(
         in_0 : IN  std_logic;
         in_1 : IN  std_logic;
         in_2 : IN  std_logic;
         in_3 : IN  std_logic;
         sel_0 : IN  std_logic;
         sel_1 : IN  std_logic;
         f : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal in_0 : std_logic := '0';
   signal in_1 : std_logic := '1';
   signal in_2 : std_logic := '0';
   signal in_3 : std_logic := '1';
   signal sel_0 : std_logic := '0';
   signal sel_1 : std_logic := '0';

 	--Outputs
   signal f : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: assignment1_67574625_mux4to1 PORT MAP (
          in_0 => in_0,
          in_1 => in_1,
          in_2 => in_2,
          in_3 => in_3,
          sel_0 => sel_0,
          sel_1 => sel_1,
          f => f
        );

   -- Clock process definitions
   clk_process :process
   begin
		sel_0 <= '0';
		sel_1 <= '0';
		wait for clk_period/2;
		sel_0 <= '1';
		sel_1 <= '0';
		wait for clk_period/2;
		sel_0 <= '0';
		sel_1 <= '1';
		wait for clk_period/2;
		sel_0 <= '1';
		sel_1 <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
