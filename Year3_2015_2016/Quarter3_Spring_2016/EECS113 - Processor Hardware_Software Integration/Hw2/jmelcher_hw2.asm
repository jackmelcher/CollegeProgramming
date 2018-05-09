;;Jack Melcher
;;67574625
;;4/16/2016
;;Status of Code: Works. No Bugs

;; Template for hw2.asm

;; Put status of your code here: does it work? has bugs? etc

;; If it doesn't work, what do you think is wrong with it?

ORG 0H
           SJMP  MAIN

STRING1:  DB "your test string" ;; string data

DB 0  ;; Null termination

STRING1LEN: DB 16  ;; String length follows the null

STRING2:  DB  "hello world"

DB 0  ;; Null termination

STRING2LEN: DB 11  ;; String length follows the null

STRING3:  DB  "assembly"

DB 0  ;; Null termination

STRING3LEN: DB 8  ;; String length follows the null

STRING4:  DB  "code"

DB 0  ;; Null termination

STRING4LEN: DB 4  ;; String length follows the null

STRCPY:

;; The caller passes source string pointer in DPTR (in ROM).

;; The caller passes destination string pointer in R0 (in RAM).

;; The caller expects return value in accumulator A

;; DPTR and R0 should not be modified.

;; This function may safely use R1 without saving

;; Initialize the len variable
	
;; Load each character from source string's memory.

;; Q: Which memory? MOV? MOVX? MOVC?

;; Check to make sure it is not the null character

;; If it is null, return the len in A; otherwise, increment count and save the character to the corresponding RAM location.

;; Declare your own labels as needed.

	MOV R0, #30H	;;R0 contains address of ram
	MOV R1, #0	;;R1 is len

CHECK:	MOV A, R1	;;mov R1 into Acc
	MOVC A, @A+DPTR	;;mov content of Acc+dptr into Acc
	CJNE A, #0, LOOP;;compare for terminating character
	JMP EXIT

LOOP:	MOV @R0, A	;;copy Acc into addrs of R0
	INC R1		;;increment len
	INC R0		;;increment R0 addr location
	JMP CHECK	;;go back to check

EXIT:	MOV A, R1	;;place len into Acc
	RET		;;return

STRCMP:

	MOV R3, #0
	MOV R0, #30H

LOOP2:	MOV A, R3
	MOVC A, @A+DPTR
	CLR C
	SUBB A,@R0
	CJNE A, #0, ERROR
	INC R3
	INC R0
	DJNZ R1, LOOP2
	
	RET


TESTSTRING:

;; The purpose is to call STRCPY, fetch the answer

;; (which follows the string data; e.g., STRING1LEN)

;; and compare if they are the same.

;; If the length is different from the expected length

;; then jump to ERROR.

;; Else Compare the copied data with the original (loop over length)

;; If one character does not match

;; then jump to ERROR. 

;; Otherwise, increment the global variable t

;; to advance to the next test case

;; You can use CALL  pseudocinstruction, and the

;; assembler automatically selects ACALL or LCALL

;; You may trash registers R3 without saving.
	
	CALL STRCPY

	INC A		;;move to STRING#LEN
	MOVC A, @A+DPTR	;;mov content of Acc+dptr into Acc (get STRING#LEN)
	CLR C
	SUBB A, R1
	CJNE A, #0, ERROR ;;Check is string#len is correct

	CALL STRCMP


	INC R2
	RET

MAIN:

;; Use R2 as the variable t, initialize to 0
	MOV R2, #0

;; Load the address of STRING1 to DPTR
	MOV DPTR, #STRING1

;; Call TESTSTRING
	CALL TESTSTRING

;; Load the address of STRING2 to DPTR
	MOV DPTR, #STRING2

;; Call TESTSTRING
	CALL TESTSTRING

;; Load the address of STRING3 to DPTR
	MOV DPTR, #STRING3

;; Call TESTSTRING
	CALL TESTSTRING

;; Load the address of STRING4 to DPTR
	MOV DPTR, #STRING4

;; Call TESTSTRING
	CALL TESTSTRING

SUCCESS: SJMP SUCCESS

ERROR: SJMP ERROR

END