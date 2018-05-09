;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Jun 20 2015) (MINGW64)
; This file was generated Mon May 16 01:39:24 2016
;--------------------------------------------------------
	.module assignment4
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _NumToChar_PARM_2
	.globl _int1_isr
	.globl _int0_isr
	.globl __sdcc_gsinit_startup
	.globl _main
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
	.globl _year
	.globl _day
	.globl _month
	.globl _second
	.globl _minute
	.globl _hour
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
	.globl _timer_delay
	.globl _NumToChar
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
	.area REG_BANK_1	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_hour	=	0x007a
_minute	=	0x007b
_second	=	0x007c
_month	=	0x007d
_day	=	0x007e
_year	=	0x007f
_main_hours_1_15:
	.ds 2
_main_minutes_1_15:
	.ds 2
_main_seconds_1_15:
	.ds 2
_main_months_1_15:
	.ds 2
_main_days_1_15:
	.ds 2
_main_years_1_15:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_keypad_keypad_1_51:
	.ds 12
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_NumToChar_PARM_2:
	.ds 3
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

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
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	ljmp	_int0_isr
	.ds	5
	reti
	.ds	7
	ljmp	_int1_isr
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;hours                     Allocated with name '_main_hours_1_15'
;minutes                   Allocated with name '_main_minutes_1_15'
;seconds                   Allocated with name '_main_seconds_1_15'
;months                    Allocated with name '_main_months_1_15'
;days                      Allocated with name '_main_days_1_15'
;years                     Allocated with name '_main_years_1_15'
;------------------------------------------------------------
;	assignment4.c:62: void main(void) {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	assignment4.c:69: unsigned char hours[2] = { 0, 0 }, minutes[2] = { 0, 0 }, seconds[2] = { 0, 0 };
	mov	_main_hours_1_15,#0x00
	mov	(_main_hours_1_15 + 0x0001),#0x00
	mov	_main_minutes_1_15,#0x00
	mov	(_main_minutes_1_15 + 0x0001),#0x00
	mov	_main_seconds_1_15,#0x00
	mov	(_main_seconds_1_15 + 0x0001),#0x00
;	assignment4.c:70: unsigned char months[2] = { 0, 0 }, days[2] = { 0, 0 }, years[2] = { 0, 0 };
	mov	_main_months_1_15,#0x00
	mov	(_main_months_1_15 + 0x0001),#0x00
	mov	_main_days_1_15,#0x00
	mov	(_main_days_1_15 + 0x0001),#0x00
	mov	_main_years_1_15,#0x00
	mov	(_main_years_1_15 + 0x0001),#0x00
;	assignment4.c:73: hour = 0;
	mov	_hour,#0x00
;	assignment4.c:74: minute = 0;
	mov	_minute,#0x00
;	assignment4.c:75: second = 0;
	mov	_second,#0x00
;	assignment4.c:76: month = 1;
	mov	_month,#0x01
;	assignment4.c:77: day = 1;
	mov	_day,#0x01
;	assignment4.c:78: year = 0;
	mov	_year,#0x00
;	assignment4.c:80: IT0 = 1;   // make INT0 to edge triggered
	setb	_IT0
;	assignment4.c:81: IT1 = 1;   // make INT1 to edge triggered
	setb	_IT1
;	assignment4.c:82: IE = 0x85;  //enable external interrupt0 and external interrupt1
	mov	_IE,#0x85
;	assignment4.c:85: functionSet();
	lcall	_functionSet
;	assignment4.c:86: entryModeSet(); // increment and no shift
	lcall	_entryModeSet
;	assignment4.c:87: displayOnOffControl(1, 1, 1); // display on, cursor on and blinking on
	setb	_displayOnOffControl_PARM_1
	setb	_displayOnOffControl_PARM_2
	setb	_displayOnOffControl_PARM_3
	lcall	_displayOnOffControl
;	assignment4.c:90: sendString("00:00:00");
	mov	dptr,#___str_0
	mov	b,#0x80
	lcall	_sendString
;	assignment4.c:91: setDdRamAddress(0x40); // set address to start of second line
	mov	dpl,#0x40
	lcall	_setDdRamAddress
;	assignment4.c:92: sendString("01-01-00");
	mov	dptr,#___str_1
	mov	b,#0x80
	lcall	_sendString
;	assignment4.c:94: while (1) {
00127$:
;	assignment4.c:96: timer_delay();
	lcall	_timer_delay
;	assignment4.c:99: second++;
	inc	_second
;	assignment4.c:100: if (second == 60) {
	mov	a,#0x3C
	cjne	a,_second,00102$
;	assignment4.c:101: minute++;
	inc	_minute
;	assignment4.c:102: second = 0;
	mov	_second,#0x00
00102$:
;	assignment4.c:104: if (minute == 60) {
	mov	a,#0x3C
	cjne	a,_minute,00104$
;	assignment4.c:105: hour++;
	inc	_hour
;	assignment4.c:106: minute = 0;
	mov	_minute,#0x00
00104$:
;	assignment4.c:108: if (hour == 24) {
	mov	a,#0x18
	cjne	a,_hour,00106$
;	assignment4.c:109: hour = 0;
	mov	_hour,#0x00
;	assignment4.c:110: day++;
	inc	_day
00106$:
;	assignment4.c:112: if (month == 2) {
	mov	a,#0x02
	cjne	a,_month,00120$
;	assignment4.c:113: if (day > 28) {
	mov	a,_day
	add	a,#0xff - 0x1C
	jnc	00121$
;	assignment4.c:114: month++;
	inc	_month
;	assignment4.c:115: day = 1;
	mov	_day,#0x01
	sjmp	00121$
00120$:
;	assignment4.c:118: else if (month == 4 || month == 6 || month == 9 || month == 11) {
	mov	a,#0x04
	cjne	a,_month,00179$
	sjmp	00113$
00179$:
	mov	a,#0x06
	cjne	a,_month,00180$
	sjmp	00113$
00180$:
	mov	a,#0x09
	cjne	a,_month,00181$
	sjmp	00113$
00181$:
	mov	a,#0x0B
	cjne	a,_month,00114$
00113$:
;	assignment4.c:119: if (day > 30) {
	mov	a,_day
	add	a,#0xff - 0x1E
	jnc	00121$
;	assignment4.c:120: month++;
	inc	_month
;	assignment4.c:121: day = 1;
	mov	_day,#0x01
	sjmp	00121$
00114$:
;	assignment4.c:125: if (day > 31) {
	mov	a,_day
	add	a,#0xff - 0x1F
	jnc	00121$
;	assignment4.c:126: month++;
	inc	_month
;	assignment4.c:127: day = 1;
	mov	_day,#0x01
00121$:
;	assignment4.c:130: if (month == 13) {
	mov	a,#0x0D
	cjne	a,_month,00123$
;	assignment4.c:131: year++;
	inc	_year
;	assignment4.c:132: month = 1;
	mov	_month,#0x01
00123$:
;	assignment4.c:134: if (year == 100) {
	mov	a,#0x64
	cjne	a,_year,00125$
;	assignment4.c:135: year = 0;
	mov	_year,#0x00
00125$:
;	assignment4.c:140: NumToChar(second, seconds);
	mov	_NumToChar_PARM_2,#_main_seconds_1_15
	mov	(_NumToChar_PARM_2 + 1),#0x00
	mov	(_NumToChar_PARM_2 + 2),#0x40
	mov	dpl,_second
	lcall	_NumToChar
;	assignment4.c:141: NumToChar(minute, minutes);
	mov	_NumToChar_PARM_2,#_main_minutes_1_15
	mov	(_NumToChar_PARM_2 + 1),#0x00
	mov	(_NumToChar_PARM_2 + 2),#0x40
	mov	dpl,_minute
	lcall	_NumToChar
;	assignment4.c:142: NumToChar(hour, hours);
	mov	_NumToChar_PARM_2,#_main_hours_1_15
	mov	(_NumToChar_PARM_2 + 1),#0x00
	mov	(_NumToChar_PARM_2 + 2),#0x40
	mov	dpl,_hour
	lcall	_NumToChar
;	assignment4.c:143: NumToChar(day, days);
	mov	_NumToChar_PARM_2,#_main_days_1_15
	mov	(_NumToChar_PARM_2 + 1),#0x00
	mov	(_NumToChar_PARM_2 + 2),#0x40
	mov	dpl,_day
	lcall	_NumToChar
;	assignment4.c:144: NumToChar(month, months);
	mov	_NumToChar_PARM_2,#_main_months_1_15
	mov	(_NumToChar_PARM_2 + 1),#0x00
	mov	(_NumToChar_PARM_2 + 2),#0x40
	mov	dpl,_month
	lcall	_NumToChar
;	assignment4.c:145: NumToChar(year, years);
	mov	_NumToChar_PARM_2,#_main_years_1_15
	mov	(_NumToChar_PARM_2 + 1),#0x00
	mov	(_NumToChar_PARM_2 + 2),#0x40
	mov	dpl,_year
	lcall	_NumToChar
;	assignment4.c:148: setDdRamAddress(0x00);
	mov	dpl,#0x00
	lcall	_setDdRamAddress
;	assignment4.c:149: sendChar(hours[0]);
	mov	dpl,_main_hours_1_15
	lcall	_sendChar
;	assignment4.c:150: sendChar(hours[1]);
	mov	dpl,(_main_hours_1_15 + 0x0001)
	lcall	_sendChar
;	assignment4.c:151: sendChar(':');
	mov	dpl,#0x3A
	lcall	_sendChar
;	assignment4.c:152: sendChar(minutes[0]);
	mov	dpl,_main_minutes_1_15
	lcall	_sendChar
;	assignment4.c:153: sendChar(minutes[1]);
	mov	dpl,(_main_minutes_1_15 + 0x0001)
	lcall	_sendChar
;	assignment4.c:154: sendChar(':');
	mov	dpl,#0x3A
	lcall	_sendChar
;	assignment4.c:155: sendChar(seconds[0]);
	mov	dpl,_main_seconds_1_15
	lcall	_sendChar
;	assignment4.c:156: sendChar(seconds[1]);
	mov	dpl,(_main_seconds_1_15 + 0x0001)
	lcall	_sendChar
;	assignment4.c:158: setDdRamAddress(0x40);
	mov	dpl,#0x40
	lcall	_setDdRamAddress
;	assignment4.c:159: sendChar(months[0]);
	mov	dpl,_main_months_1_15
	lcall	_sendChar
;	assignment4.c:160: sendChar(months[1]);
	mov	dpl,(_main_months_1_15 + 0x0001)
	lcall	_sendChar
;	assignment4.c:161: sendChar('-');
	mov	dpl,#0x2D
	lcall	_sendChar
;	assignment4.c:162: sendChar(days[0]);
	mov	dpl,_main_days_1_15
	lcall	_sendChar
;	assignment4.c:163: sendChar(days[1]);
	mov	dpl,(_main_days_1_15 + 0x0001)
	lcall	_sendChar
;	assignment4.c:164: sendChar('-');
	mov	dpl,#0x2D
	lcall	_sendChar
;	assignment4.c:165: sendChar(years[0]);
	mov	dpl,_main_years_1_15
	lcall	_sendChar
;	assignment4.c:166: sendChar(years[1]);
	mov	dpl,(_main_years_1_15 + 0x0001)
	lcall	_sendChar
	ljmp	00127$
;------------------------------------------------------------
;Allocation info for local variables in function 'returnHome'
;------------------------------------------------------------
;	assignment4.c:173: void returnHome(void) {
;	-----------------------------------------
;	 function returnHome
;	-----------------------------------------
_returnHome:
;	assignment4.c:174: RS = 0;
	clr	_P2_1
;	assignment4.c:175: P1 = 0x02; // LCD command to return home (the first location of the first lcd line)
	mov	_P1,#0x02
;	assignment4.c:176: E = 1;
	setb	_P2_0
;	assignment4.c:177: E = 0;
	clr	_P2_0
;	assignment4.c:178: big_delay(); // This operation needs a bigger delay
	ljmp	_big_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'entryModeSet'
;------------------------------------------------------------
;	assignment4.c:181: void entryModeSet() {
;	-----------------------------------------
;	 function entryModeSet
;	-----------------------------------------
_entryModeSet:
;	assignment4.c:182: RS = 0;
	clr	_P2_1
;	assignment4.c:183: P1 = 0x06;
	mov	_P1,#0x06
;	assignment4.c:184: E = 1;
	setb	_P2_0
;	assignment4.c:185: E = 0;
	clr	_P2_0
;	assignment4.c:186: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'displayOnOffControl'
;------------------------------------------------------------
;	assignment4.c:189: void displayOnOffControl(__bit display, __bit cursor, __bit blinking) {
;	-----------------------------------------
;	 function displayOnOffControl
;	-----------------------------------------
_displayOnOffControl:
;	assignment4.c:190: P1_7 = 0;
	clr	_P1_7
;	assignment4.c:191: P1_6 = 0;
	clr	_P1_6
;	assignment4.c:192: P1_5 = 0;
	clr	_P1_5
;	assignment4.c:193: P1_4 = 0;
	clr	_P1_4
;	assignment4.c:194: P1_3 = 1;
	setb	_P1_3
;	assignment4.c:195: P1_2 = display;
	mov	c,_displayOnOffControl_PARM_1
	mov	_P1_2,c
;	assignment4.c:196: P1_1 = cursor;
	mov	c,_displayOnOffControl_PARM_2
	mov	_P1_1,c
;	assignment4.c:197: P1_0 = blinking;
	mov	c,_displayOnOffControl_PARM_3
	mov	_P1_0,c
;	assignment4.c:198: E = 1;
	setb	_P2_0
;	assignment4.c:199: E = 0;
	clr	_P2_0
;	assignment4.c:200: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'cursorOrDisplayShift'
;------------------------------------------------------------
;	assignment4.c:203: void cursorOrDisplayShift(__bit sc, __bit rl) {
;	-----------------------------------------
;	 function cursorOrDisplayShift
;	-----------------------------------------
_cursorOrDisplayShift:
;	assignment4.c:204: RS = 0;
	clr	_P2_1
;	assignment4.c:205: P1_7 = 0;
	clr	_P1_7
;	assignment4.c:206: P1_6 = 0;
	clr	_P1_6
;	assignment4.c:207: P1_5 = 0;
	clr	_P1_5
;	assignment4.c:208: P1_4 = 1;
	setb	_P1_4
;	assignment4.c:209: P1_3 = sc;
	mov	c,_cursorOrDisplayShift_PARM_1
	mov	_P1_3,c
;	assignment4.c:210: P1_2 = rl;
	mov	c,_cursorOrDisplayShift_PARM_2
	mov	_P1_2,c
;	assignment4.c:211: P1_1 = 0;
	clr	_P1_1
;	assignment4.c:212: P1_0 = 0;
	clr	_P1_0
;	assignment4.c:213: E = 1;
	setb	_P2_0
;	assignment4.c:214: E = 0;
	clr	_P2_0
;	assignment4.c:215: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'functionSet'
;------------------------------------------------------------
;	assignment4.c:218: void functionSet(void) {
;	-----------------------------------------
;	 function functionSet
;	-----------------------------------------
_functionSet:
;	assignment4.c:219: RS = 0;
	clr	_P2_1
;	assignment4.c:220: P1 = 0x38; // 8-bit mode, 2 lines LCD
	mov	_P1,#0x38
;	assignment4.c:221: E = 1;
	setb	_P2_0
;	assignment4.c:222: E = 0;
	clr	_P2_0
;	assignment4.c:223: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'clearDisplay'
;------------------------------------------------------------
;	assignment4.c:226: void clearDisplay(void) {
;	-----------------------------------------
;	 function clearDisplay
;	-----------------------------------------
_clearDisplay:
;	assignment4.c:227: RS = 0;
	clr	_P2_1
;	assignment4.c:228: P1 = 0x01; // command to clear LCD and return the cursor to the home position
	mov	_P1,#0x01
;	assignment4.c:229: E = 1;
	setb	_P2_0
;	assignment4.c:230: E = 0;
	clr	_P2_0
;	assignment4.c:231: big_delay(); // This operation needs a bigger delay
	ljmp	_big_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'setDdRamAddress'
;------------------------------------------------------------
;address                   Allocated to registers r7 
;------------------------------------------------------------
;	assignment4.c:234: void setDdRamAddress(char address) {  // Determine the place to place the next character - First LCD location address in 00h for line 1 and 40h for line 2
;	-----------------------------------------
;	 function setDdRamAddress
;	-----------------------------------------
_setDdRamAddress:
	mov	r7,dpl
;	assignment4.c:235: RS = 0;
	clr	_P2_1
;	assignment4.c:236: P1 = address | 0x80;  // set the MSB to detect that this is an address
	mov	a,#0x80
	orl	a,r7
	mov	_P1,a
;	assignment4.c:237: E = 1;
	setb	_P2_0
;	assignment4.c:238: E = 0;
	clr	_P2_0
;	assignment4.c:239: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'sendChar'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
;	assignment4.c:244: void sendChar(char c) {  // Function to send one character to be displayed on the LCD
;	-----------------------------------------
;	 function sendChar
;	-----------------------------------------
_sendChar:
	mov	r7,dpl
;	assignment4.c:245: RS = 1;
	setb	_P2_1
;	assignment4.c:246: P1 = c;
	mov	_P1,r7
;	assignment4.c:247: E = 1;
	setb	_P2_0
;	assignment4.c:248: E = 0;
	clr	_P2_0
;	assignment4.c:249: delay();
	ljmp	_delay
;------------------------------------------------------------
;Allocation info for local variables in function 'sendString'
;------------------------------------------------------------
;str                       Allocated to registers 
;c                         Allocated to registers r3 
;------------------------------------------------------------
;	assignment4.c:252: void sendString(char* str) {  // Function to send a string of characters to be displayed on the lCD
;	-----------------------------------------
;	 function sendString
;	-----------------------------------------
_sendString:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	assignment4.c:254: while (c = *str++) {
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
;	assignment4.c:255: sendChar(c);
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
;	assignment4.c:259: void delay(void) {
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
;	assignment4.c:261: for (c = 0; c < 50; c++);
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
;	assignment4.c:264: void big_delay(void) {
;	-----------------------------------------
;	 function big_delay
;	-----------------------------------------
_big_delay:
;	assignment4.c:266: for (c = 0; c < 255; c++);
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
;keypad                    Allocated with name '_keypad_keypad_1_51'
;i                         Allocated to registers r5 
;gotkey                    Allocated to registers r7 
;------------------------------------------------------------
;	assignment4.c:270: void keypad(void) {
;	-----------------------------------------
;	 function keypad
;	-----------------------------------------
_keypad:
;	assignment4.c:273: unsigned char keypad[4][3] = {   // This array contains the ASCII of the keypad keys
	mov	_keypad_keypad_1_51,#0x33
	mov	(_keypad_keypad_1_51 + 0x0001),#0x32
	mov	(_keypad_keypad_1_51 + 0x0002),#0x31
	mov	(_keypad_keypad_1_51 + 0x0003),#0x36
	mov	(_keypad_keypad_1_51 + 0x0004),#0x35
	mov	(_keypad_keypad_1_51 + 0x0005),#0x34
	mov	(_keypad_keypad_1_51 + 0x0006),#0x39
	mov	(_keypad_keypad_1_51 + 0x0007),#0x38
	mov	(_keypad_keypad_1_51 + 0x0008),#0x37
	mov	(_keypad_keypad_1_51 + 0x0009),#0x23
	mov	(_keypad_keypad_1_51 + 0x000a),#0x30
	mov	(_keypad_keypad_1_51 + 0x000b),#0x2A
;	assignment4.c:280: unsigned char gotkey = 0;
	mov	r7,#0x00
;	assignment4.c:281: while (1) {
00107$:
;	assignment4.c:282: row = 0xf7;  // The first row (connected to P0.3) will be zero
	mov	r6,#0xF7
;	assignment4.c:284: for (i = 0; i<4; ++i) { // loop over the 4 rows
	mov	r5,#0x00
	mov	r4,#0x00
00109$:
;	assignment4.c:286: P0 = 0xff;     // Initialize the 4 rows to '1' and set the column ports to inputs
	mov	_P0,#0xFF
;	assignment4.c:287: P0 = P0 & row; // clear one row at a time
	mov	a,r6
	anl	_P0,a
;	assignment4.c:288: col = P0 & 0x70;  // Read the 3 columns
	mov	a,#0x70
	anl	a,_P0
	mov	r3,a
;	assignment4.c:289: if (col != 0x70) { // If any column is zero i.e. a key is pressed
	cjne	r3,#0x70,00125$
	sjmp	00102$
00125$:
;	assignment4.c:290: col = (~col) & 0x70;  // because the selected column returns zero
	mov	a,r3
	cpl	a
	mov	r2,a
	mov	a,#0x70
	anl	a,r2
;	assignment4.c:291: col = col >> 5;       // The column variable now contain the number of the selected column
	swap	a
	rr	a
	anl	a,#0x07
	mov	r3,a
;	assignment4.c:292: gotkey = keypad[i][col]; // Get the ASCII of the corresponding pressed key
	mov	a,r5
	mov	b,#0x03
	mul	ab
	add	a,#_keypad_keypad_1_51
	mov	r2,a
	add	a,r3
	mov	r1,a
	mov	ar7,@r1
;	assignment4.c:293: break;  // Since a key was detected -> Exit the for loop
	sjmp	00103$
00102$:
;	assignment4.c:295: row = row >> 1;   // No key is detected yet, try the next row
	mov	a,r6
	clr	c
	rrc	a
	mov	r6,a
;	assignment4.c:296: row = row | 0xf0; // Only one of the least 4 significant bits is '0' at a time 
	orl	ar6,#0xF0
;	assignment4.c:284: for (i = 0; i<4; ++i) { // loop over the 4 rows
	inc	r4
	mov	ar5,r4
	cjne	r4,#0x04,00126$
00126$:
	jc	00109$
00103$:
;	assignment4.c:300: if (gotkey != 0) { break; }  // Since a key was detected -> exit the while loop
	mov	a,r7
	jz	00107$
;	assignment4.c:304: P1 = gotkey;  // Send the detected key to the output
	mov	_P1,r7
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'timer_delay'
;------------------------------------------------------------
;a                         Allocated to registers r7 
;------------------------------------------------------------
;	assignment4.c:310: void timer_delay(void) {
;	-----------------------------------------
;	 function timer_delay
;	-----------------------------------------
_timer_delay:
;	assignment4.c:313: TMOD = 0x01;
	mov	_TMOD,#0x01
;	assignment4.c:314: while (a != 0) {
	mov	r7,#0x14
00104$:
	mov	a,r7
	jz	00107$
;	assignment4.c:315: TL0 = 0xAF;
	mov	_TL0,#0xAF
;	assignment4.c:316: TH0 = 0x3C;
	mov	_TH0,#0x3C
;	assignment4.c:317: TR0 = 1;
	setb	_TR0
;	assignment4.c:318: while (!TF0);
00101$:
	jnb	_TF0,00101$
;	assignment4.c:319: TR0 = 0;
	clr	_TR0
;	assignment4.c:320: TF0 = 0;
	clr	_TF0
;	assignment4.c:321: a = a - 1;
	dec	r7
	sjmp	00104$
00107$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'NumToChar'
;------------------------------------------------------------
;nums                      Allocated with name '_NumToChar_PARM_2'
;num                       Allocated to registers r7 
;------------------------------------------------------------
;	assignment4.c:328: void NumToChar(unsigned char num, unsigned char nums[2]) {
;	-----------------------------------------
;	 function NumToChar
;	-----------------------------------------
_NumToChar:
	mov	r7,dpl
;	assignment4.c:331: nums[0] = (num/10) + '0';
	mov	r4,_NumToChar_PARM_2
	mov	r5,(_NumToChar_PARM_2 + 1)
	mov	r6,(_NumToChar_PARM_2 + 2)
	mov	b,#0x0A
	mov	a,r7
	div	ab
	add	a,#0x30
	mov	r3,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrput
;	assignment4.c:334: nums[1] = (num%10) + '0';
	inc	r4
	cjne	r4,#0x00,00103$
	inc	r5
00103$:
	mov	b,#0x0A
	mov	a,r7
	div	ab
	mov	r7,b
	mov	a,#0x30
	add	a,r7
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	ljmp	__gptrput
;------------------------------------------------------------
;Allocation info for local variables in function '_sdcc_gsinit_startup'
;------------------------------------------------------------
;	assignment4.c:338: void _sdcc_gsinit_startup(void) {
;	-----------------------------------------
;	 function _sdcc_gsinit_startup
;	-----------------------------------------
__sdcc_gsinit_startup:
;	assignment4.c:342: __endasm;
	mov sp, #0x5F
;	assignment4.c:343: main();
	ljmp	_main
;------------------------------------------------------------
;Allocation info for local variables in function 'int0_isr'
;------------------------------------------------------------
;count                     Allocated to registers r7 
;------------------------------------------------------------
;	assignment4.c:349: void int0_isr(void) __interrupt(0) __using(1) {
;	-----------------------------------------
;	 function int0_isr
;	-----------------------------------------
_int0_isr:
	ar7 = 0x0F
	ar6 = 0x0E
	ar5 = 0x0D
	ar4 = 0x0C
	ar3 = 0x0B
	ar2 = 0x0A
	ar1 = 0x09
	ar0 = 0x08
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x08
;	assignment4.c:350: char count = 0;
	mov	r7,#0x00
;	assignment4.c:352: setDdRamAddress(count);
	mov	dpl,#0x00
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:354: while (SW0 == 0) {
00139$:
	jnb	_P3_2,00204$
	ljmp	00142$
00204$:
;	assignment4.c:357: keypad();
	push	ar7
	mov	psw,#0x00
	lcall	_keypad
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:362: if (P1 == '*') {
	mov	a,#0x2A
	cjne	a,_P1,00137$
;	assignment4.c:363: count--;
	dec	r7
;	assignment4.c:364: if (count < 0) {
	mov	a,r7
	jnb	acc.7,00102$
;	assignment4.c:365: count = 7;
	mov	r7,#0x07
00102$:
;	assignment4.c:367: if (count == 2) {
	cjne	r7,#0x02,00104$
;	assignment4.c:368: count = 1;
	mov	r7,#0x01
00104$:
;	assignment4.c:370: if (count == 5) {
	cjne	r7,#0x05,00106$
;	assignment4.c:371: count = 4;
	mov	r7,#0x04
00106$:
;	assignment4.c:373: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
	sjmp	00139$
00137$:
;	assignment4.c:376: else if (P1 == '#') {
	mov	a,#0x23
	cjne	a,_P1,00134$
;	assignment4.c:377: count++;
	inc	r7
;	assignment4.c:378: if (count > 7) {
	clr	c
	mov	a,#(0x07 ^ 0x80)
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00108$
;	assignment4.c:379: count = 0;
	mov	r7,#0x00
00108$:
;	assignment4.c:381: if (count == 2) {
	cjne	r7,#0x02,00110$
;	assignment4.c:382: count = 3;
	mov	r7,#0x03
00110$:
;	assignment4.c:384: if (count == 5) {
	cjne	r7,#0x05,00112$
;	assignment4.c:385: count = 6;
	mov	r7,#0x06
00112$:
;	assignment4.c:387: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
	sjmp	00139$
00134$:
;	assignment4.c:391: switch (count) {
	cjne	r7,#0x00,00219$
	sjmp	00113$
00219$:
	cjne	r7,#0x01,00220$
	sjmp	00117$
00220$:
	cjne	r7,#0x03,00221$
	ljmp	00122$
00221$:
	cjne	r7,#0x04,00222$
	ljmp	00126$
00222$:
	cjne	r7,#0x06,00223$
	ljmp	00127$
00223$:
	cjne	r7,#0x07,00224$
	ljmp	00131$
00224$:
	ljmp	00139$
;	assignment4.c:393: case 0:
00113$:
;	assignment4.c:394: if (P1 > '2') {
	mov	a,_P1
	add	a,#0xff - 0x32
	jnc	00225$
	ljmp	00139$
00225$:
;	assignment4.c:398: hour = (P1 - '0') * 10;
	mov	a,_P1
	add	a,#0xD0
	mov	b,#0x0A
	mul	ab
	mov	_hour,a
;	assignment4.c:399: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:400: count++;
	inc	r7
;	assignment4.c:401: sendChar('0');
	mov	dpl,#0x30
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:402: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:403: break;
	ljmp	00139$
;	assignment4.c:405: case 1:
00117$:
;	assignment4.c:406: if (P1 > '3' && hour >= 20) {
	mov	a,_P1
	add	a,#0xff - 0x33
	jnc	00119$
	mov	a,#0x100 - 0x14
	add	a,_hour
	jnc	00227$
	ljmp	00139$
00227$:
;	assignment4.c:407: break;
00119$:
;	assignment4.c:410: hour /= 10;
	mov	b,#0x0A
	mov	a,_hour
	div	ab
	mov	_hour,a
;	assignment4.c:411: hour *= 10;
	mov	a,_hour
	mov	b,#0x0A
	mul	ab
	mov	_hour,a
;	assignment4.c:412: hour += (P1 - '0');
	mov	a,_P1
	add	a,#0xD0
	mov	r5,_hour
	add	a,r5
	mov	_hour,a
;	assignment4.c:413: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:414: count += 2;
	inc	r7
	inc	r7
;	assignment4.c:415: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:416: break;
	ljmp	00139$
;	assignment4.c:419: case 3:
00122$:
;	assignment4.c:420: if (P1 > '5') {
	mov	a,_P1
	add	a,#0xff - 0x35
	jnc	00228$
	ljmp	00139$
00228$:
;	assignment4.c:424: minute = (P1 - '0') * 10;
	mov	a,_P1
	add	a,#0xD0
	mov	b,#0x0A
	mul	ab
	mov	_minute,a
;	assignment4.c:425: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:426: count++;
	inc	r7
;	assignment4.c:427: sendChar('0');
	mov	dpl,#0x30
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:428: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:429: break;
	ljmp	00139$
;	assignment4.c:431: case 4:
00126$:
;	assignment4.c:432: minute /= 10;
	mov	b,#0x0A
	mov	a,_minute
	div	ab
	mov	_minute,a
;	assignment4.c:433: minute *= 10;
	mov	a,_minute
	mov	b,#0x0A
	mul	ab
	mov	_minute,a
;	assignment4.c:434: minute += (P1 - '0');
	mov	a,_P1
	add	a,#0xD0
	mov	r5,_minute
	add	a,r5
	mov	_minute,a
;	assignment4.c:435: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:436: count += 2;
	inc	r7
	inc	r7
;	assignment4.c:437: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:438: break;
	ljmp	00139$
;	assignment4.c:440: case 6:
00127$:
;	assignment4.c:441: if (P1 > '5') {
	mov	a,_P1
	add	a,#0xff - 0x35
	jnc	00229$
	ljmp	00139$
00229$:
;	assignment4.c:445: second = (P1 - '0') * 10;
	mov	a,_P1
	add	a,#0xD0
	mov	b,#0x0A
	mul	ab
	mov	_second,a
;	assignment4.c:446: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:447: count++;
	inc	r7
;	assignment4.c:448: sendChar('0');
	mov	dpl,#0x30
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:449: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:450: break;
	ljmp	00139$
;	assignment4.c:452: case 7:
00131$:
;	assignment4.c:453: second /= 10;
	mov	b,#0x0A
	mov	a,_second
	div	ab
	mov	_second,a
;	assignment4.c:454: second *= 10;
	mov	a,_second
	mov	b,#0x0A
	mul	ab
	mov	_second,a
;	assignment4.c:455: second += (P1 - '0');
	mov	a,_P1
	add	a,#0xD0
	mov	r5,_second
	add	a,r5
	mov	_second,a
;	assignment4.c:456: sendChar(P1);
	mov	dpl,_P1
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
;	assignment4.c:457: count = 0;
	mov	r7,#0x00
;	assignment4.c:458: setDdRamAddress(count);
	mov	dpl,#0x00
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:460: }
	ljmp	00139$
00142$:
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'int1_isr'
;------------------------------------------------------------
;count                     Allocated to registers r7 
;------------------------------------------------------------
;	assignment4.c:468: void int1_isr(void) __interrupt(2) __using(1) {
;	-----------------------------------------
;	 function int1_isr
;	-----------------------------------------
_int1_isr:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x08
;	assignment4.c:470: char count = 0x40;
	mov	r7,#0x40
;	assignment4.c:472: setDdRamAddress(count);
	mov	dpl,#0x40
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:474: while (SW1 == 0) {
00171$:
	jnb	_P3_3,00287$
	ljmp	00174$
00287$:
;	assignment4.c:477: keypad();
	push	ar7
	mov	psw,#0x00
	lcall	_keypad
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:482: if (P1 == '*') {
	mov	a,#0x2A
	cjne	a,_P1,00169$
;	assignment4.c:483: count--;
	dec	r7
;	assignment4.c:484: if (count < 0x40) {
	clr	c
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0xc0
	jnc	00102$
;	assignment4.c:485: count = 0x47;
	mov	r7,#0x47
00102$:
;	assignment4.c:487: if (count == 0x42) {
	cjne	r7,#0x42,00104$
;	assignment4.c:488: count = 0x41;
	mov	r7,#0x41
00104$:
;	assignment4.c:490: if (count == 0x45) {
	cjne	r7,#0x45,00106$
;	assignment4.c:491: count = 0x44;
	mov	r7,#0x44
00106$:
;	assignment4.c:493: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
	sjmp	00171$
00169$:
;	assignment4.c:496: else if (P1 == '#') {
	mov	a,#0x23
	cjne	a,_P1,00166$
;	assignment4.c:497: count++;
	inc	r7
;	assignment4.c:498: if (count > 0x47) {
	clr	c
	mov	a,#(0x47 ^ 0x80)
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00108$
;	assignment4.c:499: count = 0x40;
	mov	r7,#0x40
00108$:
;	assignment4.c:501: if (count == 0x42) {
	cjne	r7,#0x42,00110$
;	assignment4.c:502: count = 0x43;
	mov	r7,#0x43
00110$:
;	assignment4.c:504: if (count == 0x45) {
	cjne	r7,#0x45,00112$
;	assignment4.c:505: count = 0x46;
	mov	r7,#0x46
00112$:
;	assignment4.c:507: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
	sjmp	00171$
00166$:
;	assignment4.c:511: switch (count) {
	cjne	r7,#0x40,00302$
	sjmp	00113$
00302$:
	cjne	r7,#0x41,00303$
	ljmp	00119$
00303$:
	cjne	r7,#0x43,00304$
	ljmp	00127$
00304$:
	cjne	r7,#0x44,00305$
	ljmp	00136$
00305$:
	cjne	r7,#0x46,00306$
	ljmp	00162$
00306$:
	cjne	r7,#0x47,00307$
	ljmp	00163$
00307$:
	ljmp	00171$
;	assignment4.c:513: case 0x40:
00113$:
;	assignment4.c:514: if (P1 > '1') {
	mov	a,_P1
	add	a,#0xff - 0x31
	jnc	00308$
	ljmp	00171$
00308$:
;	assignment4.c:517: if (P1 == '0') {
	mov	a,#0x30
	cjne	a,_P1,00117$
;	assignment4.c:518: month = 1;
	mov	_month,#0x01
;	assignment4.c:519: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:520: count++;
	inc	r7
;	assignment4.c:521: sendChar('1');
	mov	dpl,#0x31
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
;	assignment4.c:523: setDdRamAddress(0x43);
	mov	dpl,#0x43
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
;	assignment4.c:524: sendChar('0');
	mov	dpl,#0x30
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
;	assignment4.c:525: sendChar('1');
	mov	dpl,#0x31
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:526: day = 1;
	mov	_day,#0x01
;	assignment4.c:528: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:529: break;				
	ljmp	00171$
00117$:
;	assignment4.c:532: month = (P1 - '0') * 10;
	mov	a,_P1
	add	a,#0xD0
	mov	b,#0x0A
	mul	ab
	mov	_month,a
;	assignment4.c:533: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:534: count++;
	inc	r7
;	assignment4.c:535: sendChar('0');
	mov	dpl,#0x30
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
;	assignment4.c:537: setDdRamAddress(0x43);
	mov	dpl,#0x43
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
;	assignment4.c:538: sendChar('0');
	mov	dpl,#0x30
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
;	assignment4.c:539: sendChar('1');
	mov	dpl,#0x31
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:540: day = 1;
	mov	_day,#0x01
;	assignment4.c:542: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:543: break;
	ljmp	00171$
;	assignment4.c:546: case 0x41:
00119$:
;	assignment4.c:547: if (month >= 10 && P1 > '2') {
	mov	a,#0x100 - 0x0A
	add	a,_month
	jnc	00121$
	mov	a,_P1
	add	a,#0xff - 0x32
	jnc	00312$
	ljmp	00171$
00312$:
;	assignment4.c:548: break;
00121$:
;	assignment4.c:550: if (P1 == '0' && month < 10) {
	mov	a,#0x30
	cjne	a,_P1,00124$
	mov	a,#0x100 - 0x0A
	add	a,_month
	jc	00315$
	ljmp	00171$
00315$:
;	assignment4.c:551: break;
00124$:
;	assignment4.c:554: month /= 10;
	mov	b,#0x0A
	mov	a,_month
	div	ab
	mov	_month,a
;	assignment4.c:555: month *= 10;
	mov	a,_month
	mov	b,#0x0A
	mul	ab
	mov	_month,a
;	assignment4.c:556: month += (P1 - '0');
	mov	a,_P1
	add	a,#0xD0
	mov	r5,_month
	add	a,r5
	mov	_month,a
;	assignment4.c:557: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:558: count += 2;
	inc	r7
	inc	r7
;	assignment4.c:560: setDdRamAddress(0x43);
	mov	dpl,#0x43
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
;	assignment4.c:561: sendChar('0');
	mov	dpl,#0x30
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
;	assignment4.c:562: sendChar('1');
	mov	dpl,#0x31
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:563: day = 1;
	mov	_day,#0x01
;	assignment4.c:565: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:566: break;
	ljmp	00171$
;	assignment4.c:569: case 0x43:
00127$:
;	assignment4.c:570: if (P1 > '3') {
	mov	a,_P1
	add	a,#0xff - 0x33
	jnc	00316$
	ljmp	00171$
00316$:
;	assignment4.c:573: if (P1 > '2' && month == 2) {
	mov	a,_P1
	add	a,#0xff - 0x32
	jnc	00131$
	mov	a,#0x02
	cjne	a,_month,00318$
	ljmp	00171$
00318$:
;	assignment4.c:574: break;
00131$:
;	assignment4.c:576: if (P1 == '0') {
	mov	a,#0x30
	cjne	a,_P1,00134$
;	assignment4.c:577: day = 1;
	mov	_day,#0x01
;	assignment4.c:578: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:579: count++;
	inc	r7
;	assignment4.c:580: sendChar('1');
	mov	dpl,#0x31
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:581: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:582: break;
	ljmp	00171$
00134$:
;	assignment4.c:585: day = (P1 - '0') * 10;
	mov	a,_P1
	add	a,#0xD0
	mov	b,#0x0A
	mul	ab
	mov	_day,a
;	assignment4.c:586: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:587: count++;
	inc	r7
;	assignment4.c:588: sendChar('0');
	mov	dpl,#0x30
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:589: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:590: break;
	ljmp	00171$
;	assignment4.c:593: case 0x44:
00136$:
;	assignment4.c:594: if (day >= 30 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && P1 > '1') {
	mov	a,#0x100 - 0x1E
	add	a,_day
	jnc	00138$
	mov	a,#0x01
	cjne	a,_month,00322$
	sjmp	00146$
00322$:
	mov	a,#0x03
	cjne	a,_month,00323$
	sjmp	00146$
00323$:
	mov	a,#0x05
	cjne	a,_month,00324$
	sjmp	00146$
00324$:
	mov	a,#0x07
	cjne	a,_month,00325$
	sjmp	00146$
00325$:
	mov	a,#0x08
	cjne	a,_month,00326$
	sjmp	00146$
00326$:
	mov	a,#0x0A
	cjne	a,_month,00327$
	sjmp	00146$
00327$:
	mov	a,#0x0C
	cjne	a,_month,00138$
00146$:
	mov	a,_P1
	add	a,#0xff - 0x31
	jnc	00330$
	ljmp	00171$
00330$:
;	assignment4.c:595: break;
00138$:
;	assignment4.c:597: if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11) && P1 > '0') {
	mov	a,#0x1E
	cjne	a,_day,00148$
	mov	a,#0x04
	cjne	a,_month,00333$
	sjmp	00153$
00333$:
	mov	a,#0x06
	cjne	a,_month,00334$
	sjmp	00153$
00334$:
	mov	a,#0x09
	cjne	a,_month,00335$
	sjmp	00153$
00335$:
	mov	a,#0x0B
	cjne	a,_month,00148$
00153$:
	mov	a,_P1
	add	a,#0xff - 0x30
	jnc	00338$
	ljmp	00171$
00338$:
;	assignment4.c:598: break;
00148$:
;	assignment4.c:600: if (day >= 20 && month == 2 && P1 > '8') {
	mov	a,#0x100 - 0x14
	add	a,_day
	jnc	00155$
	mov	a,#0x02
	cjne	a,_month,00155$
	mov	a,_P1
	add	a,#0xff - 0x38
	jnc	00342$
	ljmp	00171$
00342$:
;	assignment4.c:601: break;
00155$:
;	assignment4.c:603: if (P1 == '0' && day < 10) {
	mov	a,#0x30
	cjne	a,_P1,00159$
	mov	a,#0x100 - 0x0A
	add	a,_day
	jc	00345$
	ljmp	00171$
00345$:
;	assignment4.c:604: break;
00159$:
;	assignment4.c:607: day /= 10;
	mov	b,#0x0A
	mov	a,_day
	div	ab
	mov	_day,a
;	assignment4.c:608: day *= 10;
	mov	a,_day
	mov	b,#0x0A
	mul	ab
	mov	_day,a
;	assignment4.c:609: day += (P1 - '0');
	mov	a,_P1
	add	a,#0xD0
	mov	r5,_day
	add	a,r5
	mov	_day,a
;	assignment4.c:610: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:611: count += 2;
	inc	r7
	inc	r7
;	assignment4.c:612: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:613: break;
	ljmp	00171$
;	assignment4.c:617: case 0x46:
00162$:
;	assignment4.c:618: year = (P1 - '0') * 10;
	mov	a,_P1
	add	a,#0xD0
	mov	b,#0x0A
	mul	ab
	mov	_year,a
;	assignment4.c:619: sendChar(P1);
	mov	dpl,_P1
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:620: count++;
	inc	r7
;	assignment4.c:621: sendChar('0');
	mov	dpl,#0x30
	push	ar7
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:622: setDdRamAddress(count);
	mov	dpl,r7
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:623: break;
	ljmp	00171$
;	assignment4.c:625: case 0x47:
00163$:
;	assignment4.c:626: year /= 10;
	mov	b,#0x0A
	mov	a,_year
	div	ab
	mov	_year,a
;	assignment4.c:627: year *= 10;
	mov	a,_year
	mov	b,#0x0A
	mul	ab
	mov	_year,a
;	assignment4.c:628: year += (P1 - '0');
	mov	a,_P1
	add	a,#0xD0
	mov	r5,_year
	add	a,r5
	mov	_year,a
;	assignment4.c:629: sendChar(P1);
	mov	dpl,_P1
	mov	psw,#0x00
	lcall	_sendChar
	mov	psw,#0x08
;	assignment4.c:630: count = 0x40;
	mov	r7,#0x40
;	assignment4.c:631: setDdRamAddress(count);
	mov	dpl,#0x40
	push	ar7
	mov	psw,#0x00
	lcall	_setDdRamAddress
	mov	psw,#0x08
	pop	ar7
;	assignment4.c:633: }
	ljmp	00171$
00174$:
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_0:
	.ascii "00:00:00"
	.db 0x00
___str_1:
	.ascii "01-01-00"
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
