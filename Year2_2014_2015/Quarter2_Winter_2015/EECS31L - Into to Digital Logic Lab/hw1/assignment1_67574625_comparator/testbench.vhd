--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:22:56 01/18/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw1/assignment1_67574625_comparator/testbench.vhd
-- Project Name:  assignment1_67574625_comparator
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: assignment1_67574625_comparator
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
 
    COMPONENT assignment1_67574625_comparator
    PORT(
         in_0 : IN  std_logic;
         in_1 : IN  std_logic;
         greater : OUT  std_logic;
         equal : OUT  std_logic;
         less : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal in_0 : std_logic := '0';
   signal in_1 : std_logic := '0';

 	--Outputs
   signal greater : std_logic;
   signal equal : std_logic;
   signal less : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: assignment1_67574625_comparator PORT MAP (
          in_0 => in_0,
          in_1 => in_1,
          greater => greater,
          equal => equal,
          less => less
        );

   -- Clock process definitions
   clk_process :process
   begin
		in_0 <= '0';
		in_1 <= '0';
		wait for clk_period/2;
		in_0 <= '0';
		in_1 <= '1';
		wait for clk_period/2;
		in_0 <= '1';
		in_1 <= '0';
		wait for clk_period/2;
		in_0 <= '1';
		in_1 <= '1';
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
