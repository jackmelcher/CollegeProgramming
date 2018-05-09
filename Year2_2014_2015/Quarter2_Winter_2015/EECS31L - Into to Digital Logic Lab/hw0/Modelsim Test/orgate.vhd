library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
ENTITY orgate IS
 PORT ( IN1 : in STD_LOGIC; -- OR gate input
 IN2 : in STD_LOGIC; -- OR gate input
 OUT1 : out STD_LOGIC); -- OR gate output
END orgate;
ARCHITECTURE Behavioral of orgate IS
BEGIN
 OUT1 <= IN1 or IN2; -- 2 input OR gate
END Behavioral; 