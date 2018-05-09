--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   20:13:26 02/17/2015
-- Design Name:   
-- Module Name:   C:/Users/Jack/Desktop/EECS 31L/hw4/assignment4_67574625/testbench_registerfile.vhd
-- Project Name:  assignment4_67574625
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: assignment4_67574625_registerfile
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
 
ENTITY testbench_registerfile IS
END testbench_registerfile;
 
ARCHITECTURE behavior OF testbench_registerfile IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT assignment4_67574625_registerfile
    PORT(
         clk : IN  std_logic;
         rst_s : IN  std_logic;
         we : IN  std_logic;
         raddr_1 : IN  std_logic_vector(2 downto 0);
         raddr_2 : IN  std_logic_vector(2 downto 0);
         waddr : IN  std_logic_vector(2 downto 0);
         rdata_1 : OUT  std_logic_vector(31 downto 0);
         rdata_2 : OUT  std_logic_vector(31 downto 0);
         wdata : IN  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst_s : std_logic := '0';
   signal we : std_logic := '0';
   signal raddr_1 : std_logic_vector(2 downto 0) := (others => '0');
   signal raddr_2 : std_logic_vector(2 downto 0) := (others => '0');
   signal waddr : std_logic_vector(2 downto 0) := (others => '0');
   signal wdata : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal rdata_1 : std_logic_vector(31 downto 0);
   signal rdata_2 : std_logic_vector(31 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: assignment4_67574625_registerfile PORT MAP (
          clk => clk,
          rst_s => rst_s,
          we => we,
          raddr_1 => raddr_1,
          raddr_2 => raddr_2,
          waddr => waddr,
          rdata_1 => rdata_1,
          rdata_2 => rdata_2,
          wdata => wdata
        );

   -- Clock process definitions
   clk_process :process
   begin
		--Reset register file
		rst_s <= '1';
		we <= '1';
		raddr_1 <= "001";
		raddr_2 <= "010";
		waddr <= "001";
		wdata <= "01011100001101010100011001100110";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		rst_s <= '0';
		-- Read from addr 1 and 2
		-- Write to addr 1
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Write to addr 2
		waddr <= "010";
		wdata <= "10101010101110100101010110001101";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Read from addr 3 and 4
		raddr_1 <= "011";
		raddr_2 <= "100";
		-- Write to addr 3
		waddr <= "011";
		wdata <= "01010101011011010101010010101011";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Write to addr 4
		waddr <= "100";
		wdata <= "10101000111101011001010110100101";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Disable writing
		we <= '0';
		-- Write to addr 5
		waddr <= "101";
		wdata <= "10101010001011111101001010101010";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Enable writing
		we <= '1';
		-- Read from addr 5 and 6
		raddr_1 <= "101";
		raddr_2 <= "110";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Write to addr 6
		waddr <= "110";
		wdata <= "10100101011110010010101011100001";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Read from addr 7 and 0
		raddr_1 <= "111";
		raddr_2 <= "000";
		-- Write to addr 7
		waddr <= "111";
		wdata <= "01010110111001001010100001101010";
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
		-- Write to addr 0
		waddr <= "000";
		wdata <= "10101001101010100101010110101100";
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
