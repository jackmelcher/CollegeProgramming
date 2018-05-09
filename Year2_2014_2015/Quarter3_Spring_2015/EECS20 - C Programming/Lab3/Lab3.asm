	.ORIG x3000		;Jack Melcher 67574625
	LD R6, ASCII		;EECS 20 Lab 3
	LD R5, NEGASCII		;4/23/2015

MENU	AND R1,R1,x0		;Clear R1
	
	LEA R0, MESG1		;print menu on console
	TRAP x22
	TRAP x20		;get select value
	ADD R0,R0,R5 		;convert digit from ascii to decimal
	ADD R0,R0,-2
	Brn Input1		;Convert to Fahrenheit
	Brz Input2		;No conversion, Celsius
	Brp Input3		;Exit program

Input1	LEA R0, MESG2		;print menu on console
	TRAP x22
	TRAP x20		;get single digit user input in ascii and put in R0
	TRAP x21
	ADD R1,R0,x0 		;store digit of R0 into R1, R1 will always hold temp in Celsius
	ADD R1,R1,R5 		;convert digit from ascii to decimal
	
	ADD R2,R1,x0 		;store initial value of R1 in R2 so multiplication can be done
	AND R4,R4,x0		;Clear R4
	ADD R4,R4,8		;use R4 as a counter for multiplication
Loop1	ADD R2,R2,R1 		;Loop to multiply R1 by 9
	ADD R4,R4,-1
	Brp Loop1

	AND R3,R3,x0		;Clear R3 so it can be used to as the quotient of the division
Loop2	ADD R3,R3,1		;Loop to divide R2 by 5
	ADD R2,R2,-5		
	Brn NEG			;if result is negative,break from loop and decrement R3
	Brz ZERO		;if result is zero, break from loop
	Brp Loop2
NEG	ADD R3,R3,-1
ZERO	ADD R2,R3,x0		;store result of division in R2
	
	LD R4,FF		;Load 32 into R4
	ADD R2,R2,R4 		;add R1 with 32, Value of Fahrenheit obtained

	LD R4,STORE
	STR R2,R4,0		;Store Fahrenheit in Memory at address x3100
	LDR R2,R4,0		;Load Fahrenheit value from x3100

	LD R0, NEWLINE
	TRAP x21 		;print R0 on console
	AND R0,R0,x0		;Clear R0
	LEA R0, MESG3
	TRAP x22

	AND R3,R3,x0		;Clear R3
	ADD R3,R3,R2		;Store R2 in R3 so R3 can help in converting R2 to ascii
	AND R4,R4,x0		;Clear R4
Loop3	ADD R4,R4,1		;Loop to divide R3 by 10, R4 is quotient
	ADD R3,R3,-10		
	Brn NEG1		;if result is negative,break from loop and decrement R2
	Brz ZERO1		;if result is zero, break from loop
	Brp Loop3
NEG1	ADD R4,R4,-1
ZERO1	ADD R3,R4,x0		;store result of division in R3, R3 is first digit
	AND R0,R0,x0		;Clear R0
	ADD R0,R3,R6		;print first digit on console
	TRAP x21

	AND R3,R3,x0		;Clear R3
	ADD R0,R0,R5		;Get back decimal value of first digit
	ADD R3,R0,0		;Store R0 in R3

	AND R4,R4,x0		;Clear R4
	ADD R4,R4,9		;use R4 as a counter for multiplication
Loop4	ADD R3,R3,R0 		;Loop to multiply R1 by 10
	ADD R4,R4,-1
	Brp Loop4

	NOT R3,R3		;Convert into negative then add with R2
	ADD R3,R3,1
	ADD R3,R2,R3
	AND R0,R0,x0		;Clear R0
	ADD R0,R3,R6 		;convert decimal to ascii
	TRAP x21 		;print second digit to console
	
	LD R0, NEWLINE
	TRAP x21 		;print R0 on console
	BR MENU

Input2	LEA R0, MESG2		;print menu on console
	TRAP x22
	TRAP x20		;get single digit user input in ascii and put in R0
	TRAP x21
	
	ADD R1,R0,x0 		;store digit of R0 into R1, R1 will always hold temp in Celsius
	ADD R1,R1,R5 		;convert digit from ascii to decimal
	AND R0,R0,x0		;Clear R0
	
	LD R0, NEWLINE
	TRAP x21 		;print R0 on console

	LEA R0, MESG4		;print Celsius
	TRAP x22
	AND R0,R0,x0		;Clear R0
	ADD R0,R1,R6 		;convert decimal to ascii and store in R0
	TRAP x21 		;print R0 on console, Celsius value
	
	LD R0, NEWLINE
	TRAP x21 		;print R0 on console
	BR MENU

Input3  LEA R0, MESG5
	TRAP x22
	HALT 			;end of program

ASCII	.FILL 48		;used to convert decimal to ascii
NEGASCII .FILL -48		;used to convert ascii to decimal
STORE	.FILL x3100
FF	.FILL 32 		;used to add 32
MESG1	.STRINGZ "Enter 1 for converting to the Fahrenheit, or 2 for no conversion, or 3 for exit."
MESG2	.STRINGZ "Enter the temperature in Celsius:"
MESG3	.STRINGZ "Fahrenheit is:"
MESG4	.STRINGZ "Celsius is:"
MESG5	.STRINGZ "Have a nice day"
NEWLINE	.FILL  x000A		;ASCII for newline
	.END