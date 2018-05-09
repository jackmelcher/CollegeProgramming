;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Jun 20 2015) (MINGW64)
; This file was generated Sat Apr 30 00:33:42 2016
;--------------------------------------------------------
	.module assignment3
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Main
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _cursorOrDisplayShift_PARM_2
	.globl _cursorOrDisplayShift_PARM_1
	.globl _displayOnOffControl_PARM_3
	.globl _displayOnOffControl_PARM_2
	.globl _displayOnOffControl_PARM_1
	.globl _returnHome
	.globl _entryModeSet
	.globl _displayOnOffControl
	.globl _cursorOrDisplayShift
	.globl _functionSet
	.globl _clearDisplay
	.globl _setDdRamAddress
	.globl _sendChar
	.globl _sendString
	.globl _delay
	.globl _big_delay
	.globl _keypad
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_Main_digits_a_1_13:
	.ds 10
_Main_number_a_1_13:
	.ds 2
_Main_numberOfDigitsA_1_13:
	.ds 2
_Main_digits_b_1_13:
	.ds 10
_Main_number_b_1_13:
	.ds 2
_Main_numberOfDigitsB_1_13:
	.ds 2
_Main_digit_1_13:
	.ds 2
_Main_check_1_13:
	.ds 2
_Main_i_1_13:
	.ds 2
_Main_sum_1_13:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_keypad_keypad_1_53:
	.ds 12
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
_displayOnOffControl_PARM_1:
	.ds 1
_displayOnOffControl_PARM_2:
	.ds 1
_displayOnOffControl_PARM_3:
	.ds 1
_cursorOrDisplayShift_PARM_1:
	.ds 1
_cursorOrDisplayShift_PARM_2:
	.ds 1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'Main'
;------------------------------------------------------------
;key                       Allocated to registers r3 
;digits_a                  Allocated with name '_Main_digits_a_1_13'
;number_a                  Allocated with name '_Main_number_a_1_13'
;numberOfDigitsA           Allocated with name '_Main_numberOfDigitsA_1_13'
;digits_b                  Allocated with name '_Main_digits_b_1_13'
;number_b                  Allocated with name '_Main_number_b_1_13'
;numberOfDigitsB           Allocated with name '_Main_numberOfDigitsB_1_13'
;digit                     Allocated with name '_Main_digit_1_13'
;check                     Allocated with name '_Main_check_1_13'
;i                         Allocated with name '_Main_i_1_13'
;j                         Allocated to registers r4 r6 
;sum_check                 Allocated to registers r4 r5 
;sum_digit                 Allocated to registers r6 r7 
;sum                       Allocated with name '_Main_sum_1_13'
;------------------------------------------------------------
;	assignment3.c:45: void Main(void) {
;	-----------------------------------------
;	 function Main
;	-----------------------------------------
_Main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	assignment3.c:47: unsigned int digits_a[5] = {0, 0, 0, 0, 0}, number_a = 0, numberOfDigitsA = 0;
	clr	a
	mov	(_Main_digits_a_1_13 + 0),a
	mov	(_Main_digits_a_1_13 + 1),a
	mov	((_Main_digits_a_1_13 + 0x0002) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0002) + 1),a
	mov	((_Main_digits_a_1_13 + 0x0004) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0004) + 1),a
	mov	((_Main_digits_a_1_13 + 0x0006) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0006) + 1),a
	mov	((_Main_digits_a_1_13 + 0x0008) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0008) + 1),a
	mov	_Main_numberOfDigitsA_1_13,a
	mov	(_Main_numberOfDigitsA_1_13 + 1),a
;	assignment3.c:48: unsigned int digits_b[5] = {0, 0, 0, 0, 0}, number_b = 0, numberOfDigitsB = 0;
	mov	(_Main_digits_b_1_13 + 0),a
	mov	(_Main_digits_b_1_13 + 1),a
	mov	((_Main_digits_b_1_13 + 0x0002) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0002) + 1),a
	mov	((_Main_digits_b_1_13 + 0x0004) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0004) + 1),a
	mov	((_Main_digits_b_1_13 + 0x0006) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0006) + 1),a
	mov	((_Main_digits_b_1_13 + 0x0008) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0008) + 1),a
	mov	_Main_numberOfDigitsB_1_13,a
	mov	(_Main_numberOfDigitsB_1_13 + 1),a
;	assignment3.c:53: functionSet();
	lcall	_functionSet
;	assignment3.c:54: entryModeSet(); // increment and no shift
	lcall	_entryModeSet
;	assignment3.c:55: displayOnOffControl(1, 1, 1); // display on, cursor on and blinking on
	setb	_displayOnOffControl_PARM_1
	setb	_displayOnOffControl_PARM_2
	setb	_displayOnOffControl_PARM_3
	lcall	_displayOnOffControl
;	assignment3.c:61: while (1) {
00118$:
;	assignment3.c:64: keypad();
	lcall	_keypad
;	assignment3.c:65: key = P1;
	mov	r3,_P1
;	assignment3.c:67: if (key == '+') {
	cjne	r3,#0x2B,00102$
;	assignment3.c:69: sendChar(key);
	mov	dpl,r3
	lcall	_sendChar
;	assignment3.c:70: break;
	ljmp	00119$
00102$:
;	assignment3.c:74: if (numberOfDigitsA < 5) {
	clr	c
	mov	a,_Main_numberOfDigitsA_1_13
	subb	a,#0x05
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	subb	a,#0x00
	jnc	00118$
;	assignment3.c:75: switch (key) {
	cjne	r3,#0x30,00245$
00245$:
	jnc	00246$
	ljmp	00114$
00246$:
	mov	a,r3
	add	a,#0xff - 0x39
	jnc	00247$
	ljmp	00114$
00247$:
	mov	a,r3
	add	a,#0xD0
	mov	r2,a
	add	a,#(00248$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r2
	add	a,#(00249$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00248$:
	.db	00103$
	.db	00104$
	.db	00105$
	.db	00106$
	.db	00107$
	.db	00108$
	.db	00109$
	.db	00110$
	.db	00111$
	.db	00112$
00249$:
	.db	00103$>>8
	.db	00104$>>8
	.db	00105$>>8
	.db	00106$>>8
	.db	00107$>>8
	.db	00108$>>8
	.db	00109$>>8
	.db	00110$>>8
	.db	00111$>>8
	.db	00112$>>8
;	assignment3.c:76: case '0':
00103$:
;	assignment3.c:77: digits_a[numberOfDigitsA] = 0;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r2,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r2
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:78: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsA_1_13,00250$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
00250$:
;	assignment3.c:79: break;
	ljmp	00114$
;	assignment3.c:80: case '1':
00104$:
;	assignment3.c:81: digits_a[numberOfDigitsA] = 1;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x01
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:82: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsA_1_13,00251$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
00251$:
;	assignment3.c:83: break;
	ljmp	00114$
;	assignment3.c:84: case '2':
00105$:
;	assignment3.c:85: digits_a[numberOfDigitsA] = 2;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x02
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:86: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsA_1_13,00252$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
00252$:
;	assignment3.c:87: break;
	ljmp	00114$
;	assignment3.c:88: case '3':
00106$:
;	assignment3.c:89: digits_a[numberOfDigitsA] = 3;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x03
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:90: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsA_1_13,00253$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
00253$:
;	assignment3.c:91: break;
	ljmp	00114$
;	assignment3.c:92: case '4':
00107$:
;	assignment3.c:93: digits_a[numberOfDigitsA] = 4;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x04
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:94: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsA_1_13,00254$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
00254$:
;	assignment3.c:95: break;
	ljmp	00114$
;	assignment3.c:96: case '5':
00108$:
;	assignment3.c:97: digits_a[numberOfDigitsA] = 5;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x05
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:98: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
;	assignment3.c:99: break;
;	assignment3.c:100: case '6':
	cjne	a,_Main_numberOfDigitsA_1_13,00114$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
	sjmp	00114$
00109$:
;	assignment3.c:101: digits_a[numberOfDigitsA] = 6;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x06
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:102: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
;	assignment3.c:103: break;
;	assignment3.c:104: case '7':
	cjne	a,_Main_numberOfDigitsA_1_13,00114$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
	sjmp	00114$
00110$:
;	assignment3.c:105: digits_a[numberOfDigitsA] = 7;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x07
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:106: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
;	assignment3.c:107: break;
;	assignment3.c:108: case '8':
	cjne	a,_Main_numberOfDigitsA_1_13,00114$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
	sjmp	00114$
00111$:
;	assignment3.c:109: digits_a[numberOfDigitsA] = 8;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x08
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:110: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
;	assignment3.c:111: break;
;	assignment3.c:112: case '9':
	cjne	a,_Main_numberOfDigitsA_1_13,00114$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
	sjmp	00114$
00112$:
;	assignment3.c:113: digits_a[numberOfDigitsA] = 9;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,_Main_numberOfDigitsA_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_a_1_13
	mov	r0,a
	mov	@r0,#0x09
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:114: numberOfDigitsA++;
	inc	_Main_numberOfDigitsA_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsA_1_13,00259$
	inc	(_Main_numberOfDigitsA_1_13 + 1)
00259$:
;	assignment3.c:118: }
00114$:
;	assignment3.c:120: sendChar(key);
	mov	dpl,r3
	lcall	_sendChar
	ljmp	00118$
00119$:
;	assignment3.c:126: number_a = 0;
	clr	a
	mov	_Main_number_a_1_13,a
	mov	(_Main_number_a_1_13 + 1),a
;	assignment3.c:127: check = numberOfDigitsA - 1;
	mov	a,_Main_numberOfDigitsA_1_13
	add	a,#0xFF
	mov	_Main_check_1_13,a
	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
	addc	a,#0xFF
	mov	(_Main_check_1_13 + 1),a
;	assignment3.c:129: for (i = 0; i < numberOfDigitsA; i++) {
	mov	r2,_Main_check_1_13
	mov	r7,(_Main_check_1_13 + 1)
	clr	a
	mov	_Main_i_1_13,a
	mov	(_Main_i_1_13 + 1),a
00156$:
	mov	r4,_Main_i_1_13
	mov	r6,(_Main_i_1_13 + 1)
	clr	c
	mov	a,r4
	subb	a,_Main_numberOfDigitsA_1_13
	mov	a,r6
	subb	a,(_Main_numberOfDigitsA_1_13 + 1)
	jc	00260$
	ljmp	00139$
00260$:
;	assignment3.c:130: digit = 1;
	mov	_Main_digit_1_13,#0x01
	mov	(_Main_digit_1_13 + 1),#0x00
;	assignment3.c:131: for (j = 0; j < check; j++) {
	mov	r4,#0x00
	mov	r6,#0x00
00153$:
	clr	c
	mov	a,r4
	subb	a,r2
	mov	a,r6
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00120$
;	assignment3.c:132: digit *= 10;
	mov	__mulint_PARM_2,_Main_digit_1_13
	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
	mov	dptr,#0x000A
	push	ar7
	push	ar6
	push	ar4
	push	ar2
	lcall	__mulint
	mov	_Main_digit_1_13,dpl
	mov	(_Main_digit_1_13 + 1),dph
	pop	ar2
	pop	ar4
	pop	ar6
	pop	ar7
;	assignment3.c:131: for (j = 0; j < check; j++) {
	inc	r4
	cjne	r4,#0x00,00153$
	inc	r6
	sjmp	00153$
00120$:
;	assignment3.c:134: number_a += digits_a[i] * digit;
	mov	a,_Main_i_1_13
	add	a,_Main_i_1_13
	mov	r5,a
	mov	a,(_Main_i_1_13 + 1)
	rlc	a
	mov	a,r5
	add	a,#_Main_digits_a_1_13
	mov	r1,a
	mov	dpl,@r1
	inc	r1
	mov	dph,@r1
	dec	r1
	mov	__mulint_PARM_2,_Main_digit_1_13
	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
	push	ar7
	push	ar2
	lcall	__mulint
	mov	r5,dpl
	mov	r6,dph
	pop	ar2
	pop	ar7
	mov	a,r5
	add	a,_Main_number_a_1_13
	mov	_Main_number_a_1_13,a
	mov	a,r6
	addc	a,(_Main_number_a_1_13 + 1)
	mov	(_Main_number_a_1_13 + 1),a
;	assignment3.c:135: check--;
	dec	r2
	cjne	r2,#0xFF,00263$
	dec	r7
00263$:
;	assignment3.c:129: for (i = 0; i < numberOfDigitsA; i++) {
	inc	_Main_i_1_13
	clr	a
	cjne	a,_Main_i_1_13,00264$
	inc	(_Main_i_1_13 + 1)
00264$:
	ljmp	00156$
;	assignment3.c:139: while (1) {
00139$:
;	assignment3.c:142: keypad();
	lcall	_keypad
;	assignment3.c:143: key = P1;
	mov	r3,_P1
;	assignment3.c:145: if (key == '=') {
	cjne	r3,#0x3D,00123$
;	assignment3.c:147: sendChar(key);
	mov	dpl,r3
	lcall	_sendChar
;	assignment3.c:148: break;
	ljmp	00140$
00123$:
;	assignment3.c:152: if (numberOfDigitsB < 5) {
	clr	c
	mov	a,_Main_numberOfDigitsB_1_13
	subb	a,#0x05
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	subb	a,#0x00
	jnc	00139$
;	assignment3.c:153: switch (key) {
	cjne	r3,#0x30,00268$
00268$:
	jnc	00269$
	ljmp	00135$
00269$:
	mov	a,r3
	add	a,#0xff - 0x39
	jnc	00270$
	ljmp	00135$
00270$:
	mov	a,r3
	add	a,#0xD0
	mov	r7,a
	add	a,#(00271$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00272$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00271$:
	.db	00124$
	.db	00125$
	.db	00126$
	.db	00127$
	.db	00128$
	.db	00129$
	.db	00130$
	.db	00131$
	.db	00132$
	.db	00133$
00272$:
	.db	00124$>>8
	.db	00125$>>8
	.db	00126$>>8
	.db	00127$>>8
	.db	00128$>>8
	.db	00129$>>8
	.db	00130$>>8
	.db	00131$>>8
	.db	00132$>>8
	.db	00133$>>8
;	assignment3.c:154: case '0':
00124$:
;	assignment3.c:155: digits_b[numberOfDigitsB] = 0;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:156: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsB_1_13,00273$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
00273$:
;	assignment3.c:157: break;
	ljmp	00135$
;	assignment3.c:158: case '1':
00125$:
;	assignment3.c:159: digits_b[numberOfDigitsB] = 1;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x01
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:160: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsB_1_13,00274$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
00274$:
;	assignment3.c:161: break;
	ljmp	00135$
;	assignment3.c:162: case '2':
00126$:
;	assignment3.c:163: digits_b[numberOfDigitsB] = 2;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x02
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:164: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsB_1_13,00275$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
00275$:
;	assignment3.c:165: break;
	ljmp	00135$
;	assignment3.c:166: case '3':
00127$:
;	assignment3.c:167: digits_b[numberOfDigitsB] = 3;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x03
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:168: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsB_1_13,00276$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
00276$:
;	assignment3.c:169: break;
	ljmp	00135$
;	assignment3.c:170: case '4':
00128$:
;	assignment3.c:171: digits_b[numberOfDigitsB] = 4;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x04
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:172: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsB_1_13,00277$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
00277$:
;	assignment3.c:173: break;
	ljmp	00135$
;	assignment3.c:174: case '5':
00129$:
;	assignment3.c:175: digits_b[numberOfDigitsB] = 5;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x05
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:176: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
;	assignment3.c:177: break;
;	assignment3.c:178: case '6':
	cjne	a,_Main_numberOfDigitsB_1_13,00135$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
	sjmp	00135$
00130$:
;	assignment3.c:179: digits_b[numberOfDigitsB] = 6;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x06
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:180: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
;	assignment3.c:181: break;
;	assignment3.c:182: case '7':
	cjne	a,_Main_numberOfDigitsB_1_13,00135$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
	sjmp	00135$
00131$:
;	assignment3.c:183: digits_b[numberOfDigitsB] = 7;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x07
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:184: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
;	assignment3.c:185: break;
;	assignment3.c:186: case '8':
	cjne	a,_Main_numberOfDigitsB_1_13,00135$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
	sjmp	00135$
00132$:
;	assignment3.c:187: digits_b[numberOfDigitsB] = 8;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x08
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:188: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
;	assignment3.c:189: break;
;	assignment3.c:190: case '9':
	cjne	a,_Main_numberOfDigitsB_1_13,00135$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
	sjmp	00135$
00133$:
;	assignment3.c:191: digits_b[numberOfDigitsB] = 9;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,_Main_numberOfDigitsB_1_13
	mov	r6,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	rlc	a
	mov	r7,a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r0,a
	mov	@r0,#0x09
	inc	r0
	mov	@r0,#0x00
;	assignment3.c:192: numberOfDigitsB++;
	inc	_Main_numberOfDigitsB_1_13
	clr	a
	cjne	a,_Main_numberOfDigitsB_1_13,00282$
	inc	(_Main_numberOfDigitsB_1_13 + 1)
00282$:
;	assignment3.c:196: }
00135$:
;	assignment3.c:198: sendChar(key);
	mov	dpl,r3
	lcall	_sendChar
	ljmp	00139$
00140$:
;	assignment3.c:204: number_b = 0;
	clr	a
	mov	_Main_number_b_1_13,a
	mov	(_Main_number_b_1_13 + 1),a
;	assignment3.c:205: check = numberOfDigitsB - 1;
	mov	a,_Main_numberOfDigitsB_1_13
	add	a,#0xFF
	mov	r4,a
	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
	addc	a,#0xFF
	mov	r5,a
;	assignment3.c:207: for (i = 0; i < numberOfDigitsB; i++) {
	clr	a
	mov	_Main_i_1_13,a
	mov	(_Main_i_1_13 + 1),a
00162$:
	mov	r6,_Main_i_1_13
	mov	r7,(_Main_i_1_13 + 1)
	clr	c
	mov	a,r6
	subb	a,_Main_numberOfDigitsB_1_13
	mov	a,r7
	subb	a,(_Main_numberOfDigitsB_1_13 + 1)
	jc	00283$
	ljmp	00142$
00283$:
;	assignment3.c:208: digit = 1;
	mov	_Main_digit_1_13,#0x01
	mov	(_Main_digit_1_13 + 1),#0x00
;	assignment3.c:209: for (j = 0; j < check; j++) {
	mov	r6,#0x00
	mov	r7,#0x00
00159$:
	clr	c
	mov	a,r6
	subb	a,r4
	mov	a,r7
	xrl	a,#0x80
	mov	b,r5
	xrl	b,#0x80
	subb	a,b
	jnc	00141$
;	assignment3.c:210: digit *= 10;
	mov	__mulint_PARM_2,_Main_digit_1_13
	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
	mov	dptr,#0x000A
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	__mulint
	mov	_Main_digit_1_13,dpl
	mov	(_Main_digit_1_13 + 1),dph
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	assignment3.c:209: for (j = 0; j < check; j++) {
	inc	r6
	cjne	r6,#0x00,00159$
	inc	r7
	sjmp	00159$
00141$:
;	assignment3.c:212: number_b += digits_b[i] * digit;
	mov	a,_Main_i_1_13
	add	a,_Main_i_1_13
	mov	r6,a
	mov	a,(_Main_i_1_13 + 1)
	rlc	a
	mov	a,r6
	add	a,#_Main_digits_b_1_13
	mov	r1,a
	mov	dpl,@r1
	inc	r1
	mov	dph,@r1
	dec	r1
	mov	__mulint_PARM_2,_Main_digit_1_13
	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
	push	ar5
	push	ar4
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	pop	ar4
	pop	ar5
	mov	a,r6
	add	a,_Main_number_b_1_13
	mov	_Main_number_b_1_13,a
	mov	a,r7
	addc	a,(_Main_number_b_1_13 + 1)
	mov	(_Main_number_b_1_13 + 1),a
;	assignment3.c:213: check--;
	dec	r4
	cjne	r4,#0xFF,00286$
	dec	r5
00286$:
;	assignment3.c:207: for (i = 0; i < numberOfDigitsB; i++) {
	inc	_Main_i_1_13
	clr	a
	cjne	a,_Main_i_1_13,00287$
	inc	(_Main_i_1_13 + 1)
00287$:
	ljmp	00162$
00142$:
;	assignment3.c:217: sum = number_a + number_b;
	mov	a,_Main_number_b_1_13
	add	a,_Main_number_a_1_13
	mov	_Main_sum_1_13,a
	mov	a,(_Main_number_b_1_13 + 1)
	addc	a,(_Main_number_a_1_13 + 1)
	mov	(_Main_sum_1_13 + 1),a
;	assignment3.c:219: digit = 10000;
	mov	_Main_digit_1_13,#0x10
	mov	(_Main_digit_1_13 + 1),#0x27
;	assignment3.c:221: for (i = 0; i < 5; i++) {
	clr	a
	mov	r4,a
	mov	r5,a
	mov	_Main_i_1_13,a
	mov	(_Main_i_1_13 + 1),a
00164$:
;	assignment3.c:222: sum_digit = sum / digit;
	mov	__divuint_PARM_2,_Main_digit_1_13
	mov	(__divuint_PARM_2 + 1),(_Main_digit_1_13 + 1)
	mov	dpl,_Main_sum_1_13
	mov	dph,(_Main_sum_1_13 + 1)
	push	ar5
	push	ar4
	lcall	__divuint
	mov	r6,dpl
	mov	r7,dph
	pop	ar4
	pop	ar5
;	assignment3.c:224: if (sum_check == 0 && sum_digit != 0) {
	mov	a,r4
	orl	a,r5
	jnz	00144$
	mov	a,r6
	orl	a,r7
	jz	00144$
;	assignment3.c:225: sum_check++;
	inc	r4
	cjne	r4,#0x00,00290$
	inc	r5
00290$:
00144$:
;	assignment3.c:227: if (sum_check > 0) {
	clr	c
	clr	a
	subb	a,r4
	mov	a,#(0x00 ^ 0x80)
	mov	b,r5
	xrl	b,#0x80
	subb	a,b
	jnc	00147$
;	assignment3.c:228: key = (sum_digit % 10) + '0';
	mov	__modsint_PARM_2,#0x0A
	mov	(__modsint_PARM_2 + 1),#0x00
	mov	dpl,r6
	mov	dph,r7
	push	ar5
	push	ar4
	lcall	__modsint
	mov	r6,dpl
	mov	a,#0x30
	add	a,r6
;	assignment3.c:231: sendChar(key);
	mov	dpl,a
	lcall	_sendChar
	pop	ar4
	pop	ar5
00147$:
;	assignment3.c:233: digit /= 10;
	mov	__divsint_PARM_2,#0x0A
	mov	(__divsint_PARM_2 + 1),#0x00
	mov	dpl,_Main_digit_1_13
	mov	dph,(_Main_digit_1_13 + 1)
	push	ar5
	push	ar4
	lcall	__divsint
	mov	_Main_digit_1_13,dpl
	mov	(_Main_digit_1_13 + 1),dph
	pop	ar4
	pop	ar5
;	assignment3.c:221: for (i = 0; i < 5; i++) {
	inc	_Main_i_1_13
	clr	a
	cjne	a,_Main_i_1_13,00292$
	inc	(_Main_i_1_13 + 1)
00292$:
	clr	c
	mov	a,_Main_i_1_13
	subb	a,#0x05
	mov	a,(_Main_i_1_13 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00293$
	ljmp	00164$
00293$:
;	assignment3.c:237: keypad();
	lcall	_keypad
;	assignment3.c:238: clearDisplay();
	lcall	_clearDisplay
;	assignment3.c:240: digits_a[0] = 0;
	clr	a
	mov	(_Main_digits_a_1_13 + 0),a
	mov	(_Main_digits_a_1_13 + 1),a
;	assignment3.c:241: digits_a[1] = 0;
	mov	((_Main_digits_a_1_13 + 0x0002) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0002) + 1),a
;	assignment3.c:242: digits_a[2] = 0;
	mov	((_Main_digits_a_1_13 + 0x0004) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0004) + 1),a
;	assignment3.c:243: digits_a[3] = 0;
	mov	((_Main_digits_a_1_13 + 0x0006) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0006) + 1),a
;	assignment3.c:244: digits_a[4] = 0;
	mov	((_Main_digits_a_1_13 + 0x0008) + 0),a
	mov	((_Main_digits_a_1_13 + 0x0008) + 1),a
;	assignment3.c:246: numberOfDigitsA = 0;
	mov	_Main_numberOfDigitsA_1_13,a
	mov	(_Main_numberOfDigitsA_1_13 + 1),a
;	assignment3.c:247: digits_b[0] = 0;
	mov	(_Main_digits_b_1_13 + 0),a
	mov	(_Main_digits_b_1_13 + 1),a
;	assignment3.c:248: digits_b[1] = 0;
	mov	((_Main_digits_b_1_13 + 0x0002) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0002) + 1),a
;	assignment3.c:249: digits_b[2] = 0;
	mov	((_Main_digits_b_1_13 + 0x0004) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0004) + 1),a
;	assignment3.c:250: digits_b[3] = 0;
	mov	((_Main_digits_b_1_13 + 0x0006) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0006) + 1),a
;	assignment3.c:251: digits_b[4] = 0;
	mov	((_Main_digits_b_1_13 + 0x0008) + 0),a
	mov	((_Main_digits_b_1_13 + 0x0008) + 1),a
;	assignment3.c:253: numberOfDigitsB = 0;
	mov	_Main_numberOfDigitsB_1_13,a
	mov	(_Main_numberOfDigitsB_1_13 + 1),a
	ljmp	00118$
;------------------------------------------------------------
;Allocation info for local variables in function 'returnHome'
;------------------------------------------------------------
;	assignment3.c:260: void returnHome(void) {
;	-----------------------------------------
;	 function returnHome
;	-----------------------------------------
_returnHome:
;	assignment3.c:261: RS = 0;
	clr	_P3_3
;	assignment3.c:262: P1 = 0x02; // LCD command to return home (the first location of the first lcd line)
	mov	_P1,#0x02
;	assignment3.c:263: E = 1;
	setb	_P3_2
;	assignment3.c:264: E = 0;
	clr	_P3_2
;	assignment3.c:265: big_delay(); // This operation needs a bigger delay
	ljmp	_big_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'entryModeSet'
;------------------------------------------------------------
;	assignment3.c:268: void entryModeSet() {
;	-----------------------------------------
;	 function entryModeSet
;	-----------------------------------------
_entryModeSet:
;	assignment3.c:269: RS = 0;
	clr	_P3_3
;	assignment3.c:270: P1 = 0x06;
	mov	_P1,#0x06
;	assignment3.c:271: E = 1;
	setb	_P3_2
;	assignment3.c:272: E = 0;
	clr	_P3_2
;	assignment3.c:273: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'displayOnOffControl'
;------------------------------------------------------------
;	assignment3.c:276: void displayOnOffControl(__bit display, __bit cursor, __bit blinking) {
;	-----------------------------------------
;	 function displayOnOffControl
;	-----------------------------------------
_displayOnOffControl:
;	assignment3.c:277: P1_7 = 0;
	clr	_P1_7
;	assignment3.c:278: P1_6 = 0;
	clr	_P1_6
;	assignment3.c:279: P1_5 = 0;
	clr	_P1_5
;	assignment3.c:280: P1_4 = 0;
	clr	_P1_4
;	assignment3.c:281: P1_3 = 1;
	setb	_P1_3
;	assignment3.c:282: P1_2 = display;
	mov	c,_displayOnOffControl_PARM_1
	mov	_P1_2,c
;	assignment3.c:283: P1_1 = cursor;
	mov	c,_displayOnOffControl_PARM_2
	mov	_P1_1,c
;	assignment3.c:284: P1_0 = blinking;
	mov	c,_displayOnOffControl_PARM_3
	mov	_P1_0,c
;	assignment3.c:285: E = 1;
	setb	_P3_2
;	assignment3.c:286: E = 0;
	clr	_P3_2
;	assignment3.c:287: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'cursorOrDisplayShift'
;------------------------------------------------------------
;	assignment3.c:290: void cursorOrDisplayShift(__bit sc, __bit rl) {
;	-----------------------------------------
;	 function cursorOrDisplayShift
;	-----------------------------------------
_cursorOrDisplayShift:
;	assignment3.c:291: RS = 0;
	clr	_P3_3
;	assignment3.c:292: P1_7 = 0;
	clr	_P1_7
;	assignment3.c:293: P1_6 = 0;
	clr	_P1_6
;	assignment3.c:294: P1_5 = 0;
	clr	_P1_5
;	assignment3.c:295: P1_4 = 1;
	setb	_P1_4
;	assignment3.c:296: P1_3 = sc;
	mov	c,_cursorOrDisplayShift_PARM_1
	mov	_P1_3,c
;	assignment3.c:297: P1_2 = rl;
	mov	c,_cursorOrDisplayShift_PARM_2
	mov	_P1_2,c
;	assignment3.c:298: P1_1 = 0;
	clr	_P1_1
;	assignment3.c:299: P1_0 = 0;
	clr	_P1_0
;	assignment3.c:300: E = 1;
	setb	_P3_2
;	assignment3.c:301: E = 0;
	clr	_P3_2
;	assignment3.c:302: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'functionSet'
;------------------------------------------------------------
;	assignment3.c:305: void functionSet(void) {
;	-----------------------------------------
;	 function functionSet
;	-----------------------------------------
_functionSet:
;	assignment3.c:306: RS = 0;
	clr	_P3_3
;	assignment3.c:307: P1 = 0x38; // 8-bit mode, 2 lines LCD
	mov	_P1,#0x38
;	assignment3.c:308: E = 1;
	setb	_P3_2
;	assignment3.c:309: E = 0;
	clr	_P3_2
;	assignment3.c:310: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'clearDisplay'
;------------------------------------------------------------
;	assignment3.c:313: void clearDisplay(void) {
;	-----------------------------------------
;	 function clearDisplay
;	-----------------------------------------
_clearDisplay:
;	assignment3.c:314: RS = 0;
	clr	_P3_3
;	assignment3.c:315: P1 = 0x01; // command to clear LCD and return the cursor to the home position
	mov	_P1,#0x01
;	assignment3.c:316: E = 1;
	setb	_P3_2
;	assignment3.c:317: E = 0;
	clr	_P3_2
;	assignment3.c:318: big_delay(); // This operation needs a bigger delay
	ljmp	_big_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'setDdRamAddress'
;------------------------------------------------------------
;address                   Allocated to registers r7 
;------------------------------------------------------------
;	assignment3.c:321: void setDdRamAddress(char address) {  // Determine the place to place the next character - First LCD location address in 00h for line 1 and 40h for line 2
;	-----------------------------------------
;	 function setDdRamAddress
;	-----------------------------------------
_setDdRamAddress:
	mov	r7,dpl
;	assignment3.c:322: RS = 0;
	clr	_P3_3
;	assignment3.c:323: P1 = address | 0x80;  // set the MSB to detect that this is an address
	mov	a,#0x80
	orl	a,r7
	mov	_P1,a
;	assignment3.c:324: E = 1;
	setb	_P3_2
;	assignment3.c:325: E = 0;
	clr	_P3_2
;	assignment3.c:326: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'sendChar'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
;	assignment3.c:331: void sendChar(char c) {  // Function to send one character to be displayed on the LCD
;	-----------------------------------------
;	 function sendChar
;	-----------------------------------------
_sendChar:
	mov	r7,dpl
;	assignment3.c:332: RS = 1;
	setb	_P3_3
;	assignment3.c:333: P1 = c;
	mov	_P1,r7
;	assignment3.c:334: E = 1;
	setb	_P3_2
;	assignment3.c:335: E = 0;
	clr	_P3_2
;	assignment3.c:336: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'sendString'
;------------------------------------------------------------
;str                       Allocated to registers 
;c                         Allocated to registers r3 
;------------------------------------------------------------
;	assignment3.c:339: void sendString(char* str) {  // Function to send a string of characters to be displayed on the lCD
;	-----------------------------------------
;	 function sendString
;	-----------------------------------------
_sendString:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	assignment3.c:341: while (c = *str++) {
00101$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	mov	r5,dpl
	mov	r6,dph
	mov	a,r4
	mov	r3,a
	jz	00104$
;	assignment3.c:342: sendChar(c);
	mov	dpl,r3
	push	ar7
	push	ar6
	push	ar5
	lcall	_sendChar
	pop	ar5
	pop	ar6
	pop	ar7
	sjmp	00101$
00104$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
;	assignment3.c:346: void delay(void) {
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
;	assignment3.c:348: for (c = 0; c < 50; c++);
	mov	r7,#0x32
00104$:
	mov	a,r7
	dec	a
	mov	r6,a
	mov	r7,a
	jnz	00104$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'big_delay'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
;	assignment3.c:351: void big_delay(void) {
;	-----------------------------------------
;	 function big_delay
;	-----------------------------------------
_big_delay:
;	assignment3.c:353: for (c = 0; c < 255; c++);
	mov	r7,#0xFF
00104$:
	mov	ar6,r7
	dec	r6
	mov	a,r6
	mov	r7,a
	jnz	00104$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'keypad'
;------------------------------------------------------------
;row                       Allocated to registers r6 
;col                       Allocated to registers r3 
;keypad                    Allocated with name '_keypad_keypad_1_53'
;i                         Allocated to registers r5 
;gotkey                    Allocated to registers r7 
;------------------------------------------------------------
;	assignment3.c:357: void keypad(void) {
;	-----------------------------------------
;	 function keypad
;	-----------------------------------------
_keypad:
;	assignment3.c:360: unsigned char keypad[4][3] = {   // This array contains the ASCII of the keypad keys
	mov	_keypad_keypad_1_53,#0x33
	mov	(_keypad_keypad_1_53 + 0x0001),#0x32
	mov	(_keypad_keypad_1_53 + 0x0002),#0x31
	mov	(_keypad_keypad_1_53 + 0x0003),#0x36
	mov	(_keypad_keypad_1_53 + 0x0004),#0x35
	mov	(_keypad_keypad_1_53 + 0x0005),#0x34
	mov	(_keypad_keypad_1_53 + 0x0006),#0x39
	mov	(_keypad_keypad_1_53 + 0x0007),#0x38
	mov	(_keypad_keypad_1_53 + 0x0008),#0x37
	mov	(_keypad_keypad_1_53 + 0x0009),#0x3D
	mov	(_keypad_keypad_1_53 + 0x000a),#0x30
	mov	(_keypad_keypad_1_53 + 0x000b),#0x2B
;	assignment3.c:367: unsigned char gotkey = 0;
	mov	r7,#0x00
;	assignment3.c:368: while(1){
00107$:
;	assignment3.c:369: row = 0xf7;  // The first row (connected to P0.3) will be zero
	mov	r6,#0xF7
;	assignment3.c:371: for (i=0;i<4;++i){ // loop over the 4 rows
	mov	r5,#0x00
	mov	r4,#0x00
00109$:
;	assignment3.c:373: P0 = 0xff;     // Initialize the 4 rows to '1' and set the column ports to inputs
	mov	_P0,#0xFF
;	assignment3.c:374: P0 = P0 & row; // clear one row at a time
	mov	a,r6
	anl	_P0,a
;	assignment3.c:375: col = P0 & 0x70;  // Read the 3 columns
	mov	a,#0x70
	anl	a,_P0
	mov	r3,a
;	assignment3.c:376: if (col != 0x70){ // If any column is zero i.e. a key is pressed
	cjne	r3,#0x70,00125$
	sjmp	00102$
00125$:
;	assignment3.c:377: col = (~col) & 0x70;  // because the selected column returns zero
	mov	a,r3
	cpl	a
	mov	r2,a
	mov	a,#0x70
	anl	a,r2
;	assignment3.c:378: col = col >> 5;       // The column variable now contain the number of the selected column
	swap	a
	rr	a
	anl	a,#0x07
	mov	r3,a
;	assignment3.c:379: gotkey = keypad[i][col]; // Get the ASCII of the corresponding pressed key
	mov	a,r5
	mov	b,#0x03
	mul	ab
	add	a,#_keypad_keypad_1_53
	mov	r2,a
	add	a,r3
	mov	r1,a
	mov	ar7,@r1
;	assignment3.c:380: break;  // Since a key was detected -> Exit the for loop
	sjmp	00103$
00102$:
;	assignment3.c:382: row = row >> 1;   // No key is detected yet, try the next row
	mov	a,r6
	clr	c
	rrc	a
	mov	r6,a
;	assignment3.c:383: row = row | 0xf0; // Only one of the least 4 significant bits is '0' at a time 
	orl	ar6,#0xF0
;	assignment3.c:371: for (i=0;i<4;++i){ // loop over the 4 rows
	inc	r4
	mov	ar5,r4
	cjne	r4,#0x04,00126$
00126$:
	jc	00109$
00103$:
;	assignment3.c:387: if (gotkey != 0){break;}  // Since a key was detected -> exit the while loop
	mov	a,r7
	jz	00107$
;	assignment3.c:391: P1 = gotkey;  // Send the detected key to the output
	mov	_P1,r7
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
