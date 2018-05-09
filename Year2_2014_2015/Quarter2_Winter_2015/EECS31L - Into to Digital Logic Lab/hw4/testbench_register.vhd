--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:22:23 02/16/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw4/assignment4_67574625/testbench_register.vhd
-- Project Name:  assignment4_67574625
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: assignment4_67574625_register
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
 
ENTITY testbench_register IS
END testbench_register;
 
ARCHITECTURE behavior OF testbench_register IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT assignment4_67574625_register
    PORT(
         clk : IN  std_logic;
         rst_a : IN  std_logic;
         rst_s : IN  std_logic;
         inc : IN  std_logic;
         we : IN  std_logic;
         din : IN  std_logic_vector(31 downto 0);
         dout : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst_a : std_logic := '0';
   signal rst_s : std_logic := '0';
   signal inc : std_logic := '0';
   signal we : std_logic := '0';
   signal din : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal dout : std_logic_vector(31 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: assignment4_67574625_register PORT MAP (
          clk => clk,
          rst_a => rst_a,
          rst_s => rst_s,
          inc => inc,
          we => we,
          din => din,
          dout => dout
        );

   -- Clock process definitions
   clk_process :process
   begin
		-- asynchronous reset
		clk <= '0';
		rst_a <= '1';
		rst_s <= '0';
		inc <= '0';
		din <= "01011100001101010100011001100110";
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		rst_a <= '0';
		
		-- Load
		we <= '1';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		
		-- Increment
		inc <= '1';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		
		-- write enable off
		we <= '0';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		
		-- synchronous reset
		rst_s <= '1';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		rst_s <= '0';
		-- Load
		we <= '1';
		inc <= '0';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		
		-- Increment
		inc <= '1';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
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

      wait;
   end process;

END;
