	.ORIG x3000	;Jack Melcher
	LD R5,ASCII	;SID: 67574625
	LD R6,NEGASCII	;EECS 20 Lab4
	LD R4,UPPER
RESET	LEA R0,MESG1
	TRAP x22
	TRAP x20	;Enter number between 1 and 8, or 0
	TRAP x21	;echo what number entered
	ADD R1,R0,R6	;convert ascii to decimal
	Brp NEXT	;if 1-8, proceed to conversion
	Brz EXIT	;if 0, branch to exit program
NEXT	LD R0,NEWLINE	;print newline
	TRAP x21
	LEA R0,MESG2
	TRAP x22
	TRAP x20	;Enter a lowercase letter
	TRAP x21	;echo what letter entered
	AND R2,R2,#0
	ADD R2,R0,R4
	AND R0,R0,#0
	LD R0,NEWLINE	;print newline
	TRAP x21
	ADD R0,R2,#0
LOOP	TRAP x21
	ADD R1,R1,-1
	Brp LOOP
	LD R0,NEWLINE
	TRAP x21
	Br RESET
EXIT	LD R0,NEWLINE	;print newline
	TRAP x21
	LEA R0,MESG3
	TRAP x22
	HALT
MESG1	.STRINGZ "Enter a number between 1 and 8, type 0 to exit: "
MESG2	.STRINGZ "Enter a lower case letter: "
MESG3	.STRINGZ "Bye"
UPPER	.FILL -32	;convert lowercase to uppercase
ASCII	.FILL 48	;convert decimal to ascii
NEGASCII .FILL -48	;convert ascii to decimal
NEWLINE	.FILL x000A	;value for newline in ascii
	.END