--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:02:56 02/15/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw4/assignment4_67574625/testbenchfortestcounter.vhd
-- Project Name:  assignment4_67574625
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Counter2_VHDL
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
 
ENTITY testbenchfortestcounter IS
END testbenchfortestcounter;
 
ARCHITECTURE behavior OF testbenchfortestcounter IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Counter2_VHDL
    PORT(
         Clock_enable_B : IN  std_logic;
         Clock : IN  std_logic;
         Reset : IN  std_logic;
         Output : OUT  std_logic_vector(0 to 3)
        );
    END COMPONENT;
    

   --Inputs
   signal Clock_enable_B : std_logic := '0';
   signal Clock : std_logic := '0';
   signal Reset : std_logic := '0';

 	--Outputs
   signal Output : std_logic_vector(0 to 3);

   -- Clock period definitions
   constant Clock_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Counter2_VHDL PORT MAP (
          Clock_enable_B => Clock_enable_B,
          Clock => Clock,
          Reset => Reset,
          Output => Output
        );
 
   Clock_process :process
   begin
		Reset <= '1';
		Clock <= '0';
		wait for Clock_period/2;
		Reset <= '0';
		Clock <= '1';
		wait for Clock_period/2;
		Clock <= '0';
		wait for Clock_period/2;
		Clock <= '1';
		wait for Clock_period/2;
		Clock <= '0';
		wait for Clock_period/2;
		Clock <= '1';
		wait for Clock_period/2;
		Clock <= '0';
		wait for Clock_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		
      -- insert stimulus here 

      wait;
   end process;

END;
