--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   23:13:45 02/07/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw3/assignment3_67574625/alu_32bit_testbench.vhd
-- Project Name:  assignment3_67574625
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: alu_32bit
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

ENTITY alu_32bit_testbench IS
END alu_32bit_testbench;
 
ARCHITECTURE behavior OF alu_32bit_testbench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT alu_32bit
    PORT(
         A : IN  std_logic_vector(31 downto 0);
         B : IN  std_logic_vector(31 downto 0);
         cin : INOUT  std_logic;
         opsel : IN  std_logic_vector(2 downto 0);
         mode : IN  std_logic;
         cout : OUT  std_logic;
         output : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(31 downto 0) := (others => '0');
   signal B : std_logic_vector(31 downto 0) := (others => '0');
	signal cin : std_logic;
   signal opsel : std_logic_vector(2 downto 0) := (others => '0');
   signal mode : std_logic := '0';

 	--Outputs
   signal cout : std_logic;
   signal output : std_logic_vector(31 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: alu_32bit PORT MAP (
          A => A,
          B => B,
          cin => cin,
          opsel => opsel,
          mode => mode,
          cout => cout,
          output => output
        );

   -- Clock process definitions
   clk_process :process
   begin
-- a+b
		mode <= '0';
		opsel <= "000";
		a <= "00111011010101010011010101000101";
		b <= "10101110010001110101001001010100";
		wait for  clk_period/2;	
	-- a-b'
		mode <= '0';
		opsel <= "001";
		wait for  clk_period/2;
	-- a
		mode <= '0';
		opsel <= "010";
		wait for  clk_period/2;
	-- a+b'+1
		mode <= '0';
		opsel <= "011";
		wait for  clk_period/2;
	-- a+1
		mode <= '0';
		opsel <= "100";
		wait for  clk_period/2;
	-- a-1
		mode <= '0';
		opsel <= "101";
		wait for  clk_period/2;
	-- a+b+1
		mode <= '0';
		opsel <= "110";
		wait for  clk_period/2;
	-- a AND b
		mode <= '1';
		opsel <= "000";
		wait for  clk_period/2;
	-- a OR b
		mode <= '1';
		opsel <= "001";
		wait for  clk_period/2;
	-- a XOR b
		mode <= '1';
		opsel <= "010";
		wait for  clk_period/2;
	-- a'
		mode <= '1';
		opsel <= "011";
		wait for  clk_period/2;
	-- shift left a
		mode <= '1';
		opsel <= "101";
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
