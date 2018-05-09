--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:23:20 02/07/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw2/assignment3_67574625/alu_1bit_testbench.vhd
-- Project Name:  assignment3_67574625
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: alu_1bit
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
 
ENTITY alu_1bit_testbench IS
END alu_1bit_testbench;
 
ARCHITECTURE behavior OF alu_1bit_testbench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu_1bit
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
			cin : INOUT std_logic;
         opsel : IN  std_logic_vector(2 downto 0);
         mode : IN  std_logic;
         output : OUT  std_logic;
         cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
	signal cin : std_logic := '0';
   signal opsel : std_logic_vector(2 downto 0) := (others => '0');
   signal mode : std_logic := '0';

 	--Outputs
   signal output : std_logic;
   signal cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu_1bit PORT MAP (
          A => A,
          B => B,
			 cin => cin,
          opsel => opsel,
          mode => mode,
			 output => output,
          cout => cout
        );

   -- Clock process definitions
   clk_process :process
   begin
	-- a+b
		mode <= '0';
		opsel <= "000";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;	
	-- a-b'
		mode <= '0';
		opsel <= "001";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a
		mode <= '0';
		opsel <= "010";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a+b'+1
		mode <= '0';
		opsel <= "011";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a+1
		mode <= '0';
		opsel <= "100";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a-1
		mode <= '0';
		opsel <= "101";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a+b+1
		mode <= '0';
		opsel <= "110";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a AND b
		mode <= '1';
		opsel <= "000";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a OR b
		mode <= '1';
		opsel <= "001";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a XOR b
		mode <= '1';
		opsel <= "010";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- a'
		mode <= '1';
		opsel <= "011";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
	-- shift left a
		mode <= '1';
		opsel <= "101";
		a <= '0';
		b <= '0';
		wait for  clk_period/2;
		a <= '0';
		b <= '1';
		wait for  clk_period/2;
		a <= '1';
		b <= '0';
		wait for  clk_period/2;
		a <= '1';
		b <= '1';
		wait for  clk_period/2;
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
