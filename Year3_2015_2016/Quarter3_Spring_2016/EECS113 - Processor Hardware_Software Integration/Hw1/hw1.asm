;; hw1.asm
;; Jack Melcher
;; 67574625
;; 4/10/2016
;; Put status of your code here: it works. No bugs
           ORG 0H
           SJMP  main

max:  ;; parameters a, b are in R0, R1;
      ;; return value should be in accumulator A
      ;; compare R0 and R1 (by subtraction, SUBB)
	MOV A, R0
	CLR C
	SUBB A, R1
      ;; if R0 larger (check carry/borrow bit)
      ;; jump (JC? JNC?) to copy R0's value into A,
	MOV C, ACC.7
	JC Else
      ;; return (RET)
	MOV A, R0
	RET
Else: ;; else copy R1's value into A,
      ;; return
	MOV A, R1
	RET
      ;; declare your own labels as needed.

main:  ;; use R2 as the variable t, initialize to 0
	MOV R2, #0
       ;; put test parameters into R0 and R1
	MOV R0, #1
	MOV R1, #2
       ;; call the max subroutine
	ACALL  max
       ;; compare return value (A) with answer
       ;; if not the same (JZ? JNZ?), jump to Error
	CJNE A, #2, Error
       ;; otherwise, increment R2, continue testing
	INC R2
       ;;....

	MOV R0, #2
	MOV R1, #1
	ACALL  max
	CJNE A, #2, Error
	INC R2

	MOV R0, #-3
	MOV R1, #-4
	ACALL  max
	CJNE A, #-3, Error
	INC R2

	MOV R0, #-4
	MOV R1, #-3
	ACALL  max
	CJNE A, #-3, Error
	INC R2

	MOV R0, #4
	MOV R1, #-3
	ACALL  max
	CJNE A, #4, Error
	INC R2

	MOV R0, #-3
	MOV R1, #4
	ACALL  max
	CJNE A, #4, Error
	INC R2

Success:
        SJMP  Success
Error:
        SJMP  Error
        END