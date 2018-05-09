--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:19:15 01/21/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw1/assignment1_67574625_addsub/testbench.vhd
-- Project Name:  assignment1_67574625_addsub
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: assignment1_67574625_addsub
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
 
    COMPONENT assignment1_67574625_addsub
    PORT(
         in_0 : IN  std_logic;
         in_1 : IN  std_logic;
         cin : IN  std_logic;
         AddOrSub : IN  std_logic;
         sum : OUT  std_logic;
         cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal in_0 : std_logic := '0';
   signal in_1 : std_logic := '0';
   signal cin : std_logic := '0';
   signal AddOrSub : std_logic := '0';

 	--Outputs
   signal sum : std_logic;
   signal cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: assignment1_67574625_addsub PORT MAP (
          in_0 => in_0,
          in_1 => in_1,
          cin => cin,
          AddOrSub => AddOrSub,
          sum => sum,
          cout => cout
        );

   -- Clock process definitions
   clk_process :process
   begin
	--Addition
		in_0 <= '0';
		in_1 <= '0';
		cin <= '0';
		AddOrSub <= '0';
		wait for clk_period/4;
		in_0 <= '0';
		in_1 <= '1';
		wait for clk_period/4;
		in_0 <= '1';
		in_1 <= '0';
		wait for clk_period/4;
		in_0 <= '1';
		in_1 <= '1';
		wait for clk_period/4;
	--Subtraction
		in_0 <= '0';
		in_1 <= '0';
		cin <= '1';
		AddOrSub <= '1';
		wait for clk_period/4;
		in_0 <= '0';
		in_1 <= '1';
		wait for clk_period/4;
		in_0 <= '1';
		in_1 <= '0';
		wait for clk_period/4;
		in_0 <= '1';
		in_1 <= '1';
		wait for clk_period/4;
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
