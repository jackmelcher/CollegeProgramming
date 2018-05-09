--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:46:02 02/15/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw4/assignment4_67574625/testbench_counter.vhd
-- Project Name:  assignment4_67574625
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: assignment4_67574625_counter
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
 
ENTITY testbench_counter IS
END testbench_counter;
 
ARCHITECTURE behavior OF testbench_counter IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT assignment4_67574625_counter
    PORT(
         clk : IN  std_logic;
         rst_s : IN  std_logic;
         asc : IN  std_logic;
         preload : IN  std_logic;
         din : IN  std_logic_vector(31 downto 0);
         dout : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst_s : std_logic := '0';
   signal asc : std_logic := '0';
   signal preload : std_logic := '0';
   signal din : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal dout : std_logic_vector(31 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: assignment4_67574625_counter PORT MAP (
          clk => clk,
          rst_s => rst_s,
          asc => asc,
          preload => preload,
          din => din,
          dout => dout
        );

   -- Clock process definitions
   clk_process :process
   begin
		--reset the counter
		din <= "01011100001101010100011001100110";
		rst_s <= '0';
		asc <= '1';
		clk <= '0';
		wait for clk_period/2;
		rst_s <= '1';
		clk <= '1';
		wait for clk_period/2;
		rst_s <= '0';
		-- Increment
		preload <= '0';
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
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Decrement
		asc <= '0';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		preload <= '0';
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
		-- Load and Increment
		preload <= '1';
		din <= "01011100001101010100011001100110";
		asc <= '1';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		preload <= '0';
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
		-- Load greatest value and Increment
		preload <= '1';
		din <= "01111111111111111111111111111111";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		preload <= '0';
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
		-- Load and Decrement
		preload <= '1';
		din <= "00011100001101010100011001100110";
		asc <= '0';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		preload <= '0';
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
		-- Load zero and Decrement
		preload <= '1';
		din <= "00000000000000000000000000000000";
		asc <= '0';
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		preload <= '0';
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
