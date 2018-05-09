                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Jun 20 2015) (MINGW64)
                                      4 ; This file was generated Mon May 16 01:39:24 2016
                                      5 ;--------------------------------------------------------
                                      6 	.module assignment4
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _NumToChar_PARM_2
                                     13 	.globl _int1_isr
                                     14 	.globl _int0_isr
                                     15 	.globl __sdcc_gsinit_startup
                                     16 	.globl _main
                                     17 	.globl _CY
                                     18 	.globl _AC
                                     19 	.globl _F0
                                     20 	.globl _RS1
                                     21 	.globl _RS0
                                     22 	.globl _OV
                                     23 	.globl _F1
                                     24 	.globl _P
                                     25 	.globl _PS
                                     26 	.globl _PT1
                                     27 	.globl _PX1
                                     28 	.globl _PT0
                                     29 	.globl _PX0
                                     30 	.globl _RD
                                     31 	.globl _WR
                                     32 	.globl _T1
                                     33 	.globl _T0
                                     34 	.globl _INT1
                                     35 	.globl _INT0
                                     36 	.globl _TXD
                                     37 	.globl _RXD
                                     38 	.globl _P3_7
                                     39 	.globl _P3_6
                                     40 	.globl _P3_5
                                     41 	.globl _P3_4
                                     42 	.globl _P3_3
                                     43 	.globl _P3_2
                                     44 	.globl _P3_1
                                     45 	.globl _P3_0
                                     46 	.globl _EA
                                     47 	.globl _ES
                                     48 	.globl _ET1
                                     49 	.globl _EX1
                                     50 	.globl _ET0
                                     51 	.globl _EX0
                                     52 	.globl _P2_7
                                     53 	.globl _P2_6
                                     54 	.globl _P2_5
                                     55 	.globl _P2_4
                                     56 	.globl _P2_3
                                     57 	.globl _P2_2
                                     58 	.globl _P2_1
                                     59 	.globl _P2_0
                                     60 	.globl _SM0
                                     61 	.globl _SM1
                                     62 	.globl _SM2
                                     63 	.globl _REN
                                     64 	.globl _TB8
                                     65 	.globl _RB8
                                     66 	.globl _TI
                                     67 	.globl _RI
                                     68 	.globl _P1_7
                                     69 	.globl _P1_6
                                     70 	.globl _P1_5
                                     71 	.globl _P1_4
                                     72 	.globl _P1_3
                                     73 	.globl _P1_2
                                     74 	.globl _P1_1
                                     75 	.globl _P1_0
                                     76 	.globl _TF1
                                     77 	.globl _TR1
                                     78 	.globl _TF0
                                     79 	.globl _TR0
                                     80 	.globl _IE1
                                     81 	.globl _IT1
                                     82 	.globl _IE0
                                     83 	.globl _IT0
                                     84 	.globl _P0_7
                                     85 	.globl _P0_6
                                     86 	.globl _P0_5
                                     87 	.globl _P0_4
                                     88 	.globl _P0_3
                                     89 	.globl _P0_2
                                     90 	.globl _P0_1
                                     91 	.globl _P0_0
                                     92 	.globl _B
                                     93 	.globl _ACC
                                     94 	.globl _PSW
                                     95 	.globl _IP
                                     96 	.globl _P3
                                     97 	.globl _IE
                                     98 	.globl _P2
                                     99 	.globl _SBUF
                                    100 	.globl _SCON
                                    101 	.globl _P1
                                    102 	.globl _TH1
                                    103 	.globl _TH0
                                    104 	.globl _TL1
                                    105 	.globl _TL0
                                    106 	.globl _TMOD
                                    107 	.globl _TCON
                                    108 	.globl _PCON
                                    109 	.globl _DPH
                                    110 	.globl _DPL
                                    111 	.globl _SP
                                    112 	.globl _P0
                                    113 	.globl _cursorOrDisplayShift_PARM_2
                                    114 	.globl _cursorOrDisplayShift_PARM_1
                                    115 	.globl _displayOnOffControl_PARM_3
                                    116 	.globl _displayOnOffControl_PARM_2
                                    117 	.globl _displayOnOffControl_PARM_1
                                    118 	.globl _year
                                    119 	.globl _day
                                    120 	.globl _month
                                    121 	.globl _second
                                    122 	.globl _minute
                                    123 	.globl _hour
                                    124 	.globl _returnHome
                                    125 	.globl _entryModeSet
                                    126 	.globl _displayOnOffControl
                                    127 	.globl _cursorOrDisplayShift
                                    128 	.globl _functionSet
                                    129 	.globl _clearDisplay
                                    130 	.globl _setDdRamAddress
                                    131 	.globl _sendChar
                                    132 	.globl _sendString
                                    133 	.globl _delay
                                    134 	.globl _big_delay
                                    135 	.globl _keypad
                                    136 	.globl _timer_delay
                                    137 	.globl _NumToChar
                                    138 ;--------------------------------------------------------
                                    139 ; special function registers
                                    140 ;--------------------------------------------------------
                                    141 	.area RSEG    (ABS,DATA)
      000000                        142 	.org 0x0000
                           000080   143 _P0	=	0x0080
                           000081   144 _SP	=	0x0081
                           000082   145 _DPL	=	0x0082
                           000083   146 _DPH	=	0x0083
                           000087   147 _PCON	=	0x0087
                           000088   148 _TCON	=	0x0088
                           000089   149 _TMOD	=	0x0089
                           00008A   150 _TL0	=	0x008a
                           00008B   151 _TL1	=	0x008b
                           00008C   152 _TH0	=	0x008c
                           00008D   153 _TH1	=	0x008d
                           000090   154 _P1	=	0x0090
                           000098   155 _SCON	=	0x0098
                           000099   156 _SBUF	=	0x0099
                           0000A0   157 _P2	=	0x00a0
                           0000A8   158 _IE	=	0x00a8
                           0000B0   159 _P3	=	0x00b0
                           0000B8   160 _IP	=	0x00b8
                           0000D0   161 _PSW	=	0x00d0
                           0000E0   162 _ACC	=	0x00e0
                           0000F0   163 _B	=	0x00f0
                                    164 ;--------------------------------------------------------
                                    165 ; special function bits
                                    166 ;--------------------------------------------------------
                                    167 	.area RSEG    (ABS,DATA)
      000000                        168 	.org 0x0000
                           000080   169 _P0_0	=	0x0080
                           000081   170 _P0_1	=	0x0081
                           000082   171 _P0_2	=	0x0082
                           000083   172 _P0_3	=	0x0083
                           000084   173 _P0_4	=	0x0084
                           000085   174 _P0_5	=	0x0085
                           000086   175 _P0_6	=	0x0086
                           000087   176 _P0_7	=	0x0087
                           000088   177 _IT0	=	0x0088
                           000089   178 _IE0	=	0x0089
                           00008A   179 _IT1	=	0x008a
                           00008B   180 _IE1	=	0x008b
                           00008C   181 _TR0	=	0x008c
                           00008D   182 _TF0	=	0x008d
                           00008E   183 _TR1	=	0x008e
                           00008F   184 _TF1	=	0x008f
                           000090   185 _P1_0	=	0x0090
                           000091   186 _P1_1	=	0x0091
                           000092   187 _P1_2	=	0x0092
                           000093   188 _P1_3	=	0x0093
                           000094   189 _P1_4	=	0x0094
                           000095   190 _P1_5	=	0x0095
                           000096   191 _P1_6	=	0x0096
                           000097   192 _P1_7	=	0x0097
                           000098   193 _RI	=	0x0098
                           000099   194 _TI	=	0x0099
                           00009A   195 _RB8	=	0x009a
                           00009B   196 _TB8	=	0x009b
                           00009C   197 _REN	=	0x009c
                           00009D   198 _SM2	=	0x009d
                           00009E   199 _SM1	=	0x009e
                           00009F   200 _SM0	=	0x009f
                           0000A0   201 _P2_0	=	0x00a0
                           0000A1   202 _P2_1	=	0x00a1
                           0000A2   203 _P2_2	=	0x00a2
                           0000A3   204 _P2_3	=	0x00a3
                           0000A4   205 _P2_4	=	0x00a4
                           0000A5   206 _P2_5	=	0x00a5
                           0000A6   207 _P2_6	=	0x00a6
                           0000A7   208 _P2_7	=	0x00a7
                           0000A8   209 _EX0	=	0x00a8
                           0000A9   210 _ET0	=	0x00a9
                           0000AA   211 _EX1	=	0x00aa
                           0000AB   212 _ET1	=	0x00ab
                           0000AC   213 _ES	=	0x00ac
                           0000AF   214 _EA	=	0x00af
                           0000B0   215 _P3_0	=	0x00b0
                           0000B1   216 _P3_1	=	0x00b1
                           0000B2   217 _P3_2	=	0x00b2
                           0000B3   218 _P3_3	=	0x00b3
                           0000B4   219 _P3_4	=	0x00b4
                           0000B5   220 _P3_5	=	0x00b5
                           0000B6   221 _P3_6	=	0x00b6
                           0000B7   222 _P3_7	=	0x00b7
                           0000B0   223 _RXD	=	0x00b0
                           0000B1   224 _TXD	=	0x00b1
                           0000B2   225 _INT0	=	0x00b2
                           0000B3   226 _INT1	=	0x00b3
                           0000B4   227 _T0	=	0x00b4
                           0000B5   228 _T1	=	0x00b5
                           0000B6   229 _WR	=	0x00b6
                           0000B7   230 _RD	=	0x00b7
                           0000B8   231 _PX0	=	0x00b8
                           0000B9   232 _PT0	=	0x00b9
                           0000BA   233 _PX1	=	0x00ba
                           0000BB   234 _PT1	=	0x00bb
                           0000BC   235 _PS	=	0x00bc
                           0000D0   236 _P	=	0x00d0
                           0000D1   237 _F1	=	0x00d1
                           0000D2   238 _OV	=	0x00d2
                           0000D3   239 _RS0	=	0x00d3
                           0000D4   240 _RS1	=	0x00d4
                           0000D5   241 _F0	=	0x00d5
                           0000D6   242 _AC	=	0x00d6
                           0000D7   243 _CY	=	0x00d7
                                    244 ;--------------------------------------------------------
                                    245 ; overlayable register banks
                                    246 ;--------------------------------------------------------
                                    247 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        248 	.ds 8
                                    249 	.area REG_BANK_1	(REL,OVR,DATA)
      000008                        250 	.ds 8
                                    251 ;--------------------------------------------------------
                                    252 ; overlayable bit register bank
                                    253 ;--------------------------------------------------------
                                    254 	.area BIT_BANK	(REL,OVR,DATA)
      000021                        255 bits:
      000021                        256 	.ds 1
                           008000   257 	b0 = bits[0]
                           008100   258 	b1 = bits[1]
                           008200   259 	b2 = bits[2]
                           008300   260 	b3 = bits[3]
                           008400   261 	b4 = bits[4]
                           008500   262 	b5 = bits[5]
                           008600   263 	b6 = bits[6]
                           008700   264 	b7 = bits[7]
                                    265 ;--------------------------------------------------------
                                    266 ; internal ram data
                                    267 ;--------------------------------------------------------
                                    268 	.area DSEG    (DATA)
                           00007A   269 _hour	=	0x007a
                           00007B   270 _minute	=	0x007b
                           00007C   271 _second	=	0x007c
                           00007D   272 _month	=	0x007d
                           00007E   273 _day	=	0x007e
                           00007F   274 _year	=	0x007f
      000030                        275 _main_hours_1_15:
      000030                        276 	.ds 2
      000032                        277 _main_minutes_1_15:
      000032                        278 	.ds 2
      000034                        279 _main_seconds_1_15:
      000034                        280 	.ds 2
      000036                        281 _main_months_1_15:
      000036                        282 	.ds 2
      000038                        283 _main_days_1_15:
      000038                        284 	.ds 2
      00003A                        285 _main_years_1_15:
      00003A                        286 	.ds 2
                                    287 ;--------------------------------------------------------
                                    288 ; overlayable items in internal ram 
                                    289 ;--------------------------------------------------------
                                    290 	.area	OSEG    (OVR,DATA)
                                    291 	.area	OSEG    (OVR,DATA)
                                    292 	.area	OSEG    (OVR,DATA)
      00003C                        293 _keypad_keypad_1_51:
      00003C                        294 	.ds 12
                                    295 	.area	OSEG    (OVR,DATA)
                                    296 	.area	OSEG    (OVR,DATA)
      00003C                        297 _NumToChar_PARM_2:
      00003C                        298 	.ds 3
                                    299 ;--------------------------------------------------------
                                    300 ; Stack segment in internal ram 
                                    301 ;--------------------------------------------------------
                                    302 	.area	SSEG
      000048                        303 __start__stack:
      000048                        304 	.ds	1
                                    305 
                                    306 ;--------------------------------------------------------
                                    307 ; indirectly addressable internal ram data
                                    308 ;--------------------------------------------------------
                                    309 	.area ISEG    (DATA)
                                    310 ;--------------------------------------------------------
                                    311 ; absolute internal ram data
                                    312 ;--------------------------------------------------------
                                    313 	.area IABS    (ABS,DATA)
                                    314 	.area IABS    (ABS,DATA)
                                    315 ;--------------------------------------------------------
                                    316 ; bit data
                                    317 ;--------------------------------------------------------
                                    318 	.area BSEG    (BIT)
      000000                        319 _displayOnOffControl_PARM_1:
      000000                        320 	.ds 1
      000001                        321 _displayOnOffControl_PARM_2:
      000001                        322 	.ds 1
      000002                        323 _displayOnOffControl_PARM_3:
      000002                        324 	.ds 1
      000003                        325 _cursorOrDisplayShift_PARM_1:
      000003                        326 	.ds 1
      000004                        327 _cursorOrDisplayShift_PARM_2:
      000004                        328 	.ds 1
                                    329 ;--------------------------------------------------------
                                    330 ; paged external ram data
                                    331 ;--------------------------------------------------------
                                    332 	.area PSEG    (PAG,XDATA)
                                    333 ;--------------------------------------------------------
                                    334 ; external ram data
                                    335 ;--------------------------------------------------------
                                    336 	.area XSEG    (XDATA)
                                    337 ;--------------------------------------------------------
                                    338 ; absolute external ram data
                                    339 ;--------------------------------------------------------
                                    340 	.area XABS    (ABS,XDATA)
                                    341 ;--------------------------------------------------------
                                    342 ; external initialized ram data
                                    343 ;--------------------------------------------------------
                                    344 	.area XISEG   (XDATA)
                                    345 	.area HOME    (CODE)
                                    346 	.area GSINIT0 (CODE)
                                    347 	.area GSINIT1 (CODE)
                                    348 	.area GSINIT2 (CODE)
                                    349 	.area GSINIT3 (CODE)
                                    350 	.area GSINIT4 (CODE)
                                    351 	.area GSINIT5 (CODE)
                                    352 	.area GSINIT  (CODE)
                                    353 	.area GSFINAL (CODE)
                                    354 	.area CSEG    (CODE)
                                    355 ;--------------------------------------------------------
                                    356 ; interrupt vector 
                                    357 ;--------------------------------------------------------
                                    358 	.area HOME    (CODE)
      000000                        359 __interrupt_vect:
      000000 02 03 8B         [24]  360 	ljmp	__sdcc_gsinit_startup
      000003 02 03 91         [24]  361 	ljmp	_int0_isr
      000006                        362 	.ds	5
      00000B 32               [24]  363 	reti
      00000C                        364 	.ds	7
      000013 02 06 02         [24]  365 	ljmp	_int1_isr
                                    366 ;--------------------------------------------------------
                                    367 ; global & static initialisations
                                    368 ;--------------------------------------------------------
                                    369 	.area HOME    (CODE)
                                    370 	.area GSINIT  (CODE)
                                    371 	.area GSFINAL (CODE)
                                    372 	.area GSINIT  (CODE)
                                    373 	.globl __sdcc_gsinit_startup
                                    374 	.globl __sdcc_program_startup
                                    375 	.globl __start__stack
                                    376 	.globl __mcs51_genXINIT
                                    377 	.globl __mcs51_genXRAMCLEAR
                                    378 	.globl __mcs51_genRAMCLEAR
                                    379 	.area GSFINAL (CODE)
      000065 02 00 16         [24]  380 	ljmp	__sdcc_program_startup
                                    381 ;--------------------------------------------------------
                                    382 ; Home
                                    383 ;--------------------------------------------------------
                                    384 	.area HOME    (CODE)
                                    385 	.area HOME    (CODE)
      000016                        386 __sdcc_program_startup:
      000016 02 00 68         [24]  387 	ljmp	_main
                                    388 ;	return from main will return to caller
                                    389 ;--------------------------------------------------------
                                    390 ; code
                                    391 ;--------------------------------------------------------
                                    392 	.area CSEG    (CODE)
                                    393 ;------------------------------------------------------------
                                    394 ;Allocation info for local variables in function 'main'
                                    395 ;------------------------------------------------------------
                                    396 ;hours                     Allocated with name '_main_hours_1_15'
                                    397 ;minutes                   Allocated with name '_main_minutes_1_15'
                                    398 ;seconds                   Allocated with name '_main_seconds_1_15'
                                    399 ;months                    Allocated with name '_main_months_1_15'
                                    400 ;days                      Allocated with name '_main_days_1_15'
                                    401 ;years                     Allocated with name '_main_years_1_15'
                                    402 ;------------------------------------------------------------
                                    403 ;	assignment4.c:62: void main(void) {
                                    404 ;	-----------------------------------------
                                    405 ;	 function main
                                    406 ;	-----------------------------------------
      000068                        407 _main:
                           000007   408 	ar7 = 0x07
                           000006   409 	ar6 = 0x06
                           000005   410 	ar5 = 0x05
                           000004   411 	ar4 = 0x04
                           000003   412 	ar3 = 0x03
                           000002   413 	ar2 = 0x02
                           000001   414 	ar1 = 0x01
                           000000   415 	ar0 = 0x00
                                    416 ;	assignment4.c:69: unsigned char hours[2] = { 0, 0 }, minutes[2] = { 0, 0 }, seconds[2] = { 0, 0 };
      000068 75 30 00         [24]  417 	mov	_main_hours_1_15,#0x00
      00006B 75 31 00         [24]  418 	mov	(_main_hours_1_15 + 0x0001),#0x00
      00006E 75 32 00         [24]  419 	mov	_main_minutes_1_15,#0x00
      000071 75 33 00         [24]  420 	mov	(_main_minutes_1_15 + 0x0001),#0x00
      000074 75 34 00         [24]  421 	mov	_main_seconds_1_15,#0x00
      000077 75 35 00         [24]  422 	mov	(_main_seconds_1_15 + 0x0001),#0x00
                                    423 ;	assignment4.c:70: unsigned char months[2] = { 0, 0 }, days[2] = { 0, 0 }, years[2] = { 0, 0 };
      00007A 75 36 00         [24]  424 	mov	_main_months_1_15,#0x00
      00007D 75 37 00         [24]  425 	mov	(_main_months_1_15 + 0x0001),#0x00
      000080 75 38 00         [24]  426 	mov	_main_days_1_15,#0x00
      000083 75 39 00         [24]  427 	mov	(_main_days_1_15 + 0x0001),#0x00
      000086 75 3A 00         [24]  428 	mov	_main_years_1_15,#0x00
      000089 75 3B 00         [24]  429 	mov	(_main_years_1_15 + 0x0001),#0x00
                                    430 ;	assignment4.c:73: hour = 0;
      00008C 75 7A 00         [24]  431 	mov	_hour,#0x00
                                    432 ;	assignment4.c:74: minute = 0;
      00008F 75 7B 00         [24]  433 	mov	_minute,#0x00
                                    434 ;	assignment4.c:75: second = 0;
      000092 75 7C 00         [24]  435 	mov	_second,#0x00
                                    436 ;	assignment4.c:76: month = 1;
      000095 75 7D 01         [24]  437 	mov	_month,#0x01
                                    438 ;	assignment4.c:77: day = 1;
      000098 75 7E 01         [24]  439 	mov	_day,#0x01
                                    440 ;	assignment4.c:78: year = 0;
      00009B 75 7F 00         [24]  441 	mov	_year,#0x00
                                    442 ;	assignment4.c:80: IT0 = 1;   // make INT0 to edge triggered
      00009E D2 88            [12]  443 	setb	_IT0
                                    444 ;	assignment4.c:81: IT1 = 1;   // make INT1 to edge triggered
      0000A0 D2 8A            [12]  445 	setb	_IT1
                                    446 ;	assignment4.c:82: IE = 0x85;  //enable external interrupt0 and external interrupt1
      0000A2 75 A8 85         [24]  447 	mov	_IE,#0x85
                                    448 ;	assignment4.c:85: functionSet();
      0000A5 12 02 60         [24]  449 	lcall	_functionSet
                                    450 ;	assignment4.c:86: entryModeSet(); // increment and no shift
      0000A8 12 02 1A         [24]  451 	lcall	_entryModeSet
                                    452 ;	assignment4.c:87: displayOnOffControl(1, 1, 1); // display on, cursor on and blinking on
      0000AB D2 00            [12]  453 	setb	_displayOnOffControl_PARM_1
      0000AD D2 01            [12]  454 	setb	_displayOnOffControl_PARM_2
      0000AF D2 02            [12]  455 	setb	_displayOnOffControl_PARM_3
      0000B1 12 02 26         [24]  456 	lcall	_displayOnOffControl
                                    457 ;	assignment4.c:90: sendString("00:00:00");
      0000B4 90 0A 39         [24]  458 	mov	dptr,#___str_0
      0000B7 75 F0 80         [24]  459 	mov	b,#0x80
      0000BA 12 02 95         [24]  460 	lcall	_sendString
                                    461 ;	assignment4.c:91: setDdRamAddress(0x40); // set address to start of second line
      0000BD 75 82 40         [24]  462 	mov	dpl,#0x40
      0000C0 12 02 78         [24]  463 	lcall	_setDdRamAddress
                                    464 ;	assignment4.c:92: sendString("01-01-00");
      0000C3 90 0A 42         [24]  465 	mov	dptr,#___str_1
      0000C6 75 F0 80         [24]  466 	mov	b,#0x80
      0000C9 12 02 95         [24]  467 	lcall	_sendString
                                    468 ;	assignment4.c:94: while (1) {
      0000CC                        469 00127$:
                                    470 ;	assignment4.c:96: timer_delay();
      0000CC 12 03 3F         [24]  471 	lcall	_timer_delay
                                    472 ;	assignment4.c:99: second++;
      0000CF 05 7C            [12]  473 	inc	_second
                                    474 ;	assignment4.c:100: if (second == 60) {
      0000D1 74 3C            [12]  475 	mov	a,#0x3C
      0000D3 B5 7C 05         [24]  476 	cjne	a,_second,00102$
                                    477 ;	assignment4.c:101: minute++;
      0000D6 05 7B            [12]  478 	inc	_minute
                                    479 ;	assignment4.c:102: second = 0;
      0000D8 75 7C 00         [24]  480 	mov	_second,#0x00
      0000DB                        481 00102$:
                                    482 ;	assignment4.c:104: if (minute == 60) {
      0000DB 74 3C            [12]  483 	mov	a,#0x3C
      0000DD B5 7B 05         [24]  484 	cjne	a,_minute,00104$
                                    485 ;	assignment4.c:105: hour++;
      0000E0 05 7A            [12]  486 	inc	_hour
                                    487 ;	assignment4.c:106: minute = 0;
      0000E2 75 7B 00         [24]  488 	mov	_minute,#0x00
      0000E5                        489 00104$:
                                    490 ;	assignment4.c:108: if (hour == 24) {
      0000E5 74 18            [12]  491 	mov	a,#0x18
      0000E7 B5 7A 05         [24]  492 	cjne	a,_hour,00106$
                                    493 ;	assignment4.c:109: hour = 0;
      0000EA 75 7A 00         [24]  494 	mov	_hour,#0x00
                                    495 ;	assignment4.c:110: day++;
      0000ED 05 7E            [12]  496 	inc	_day
      0000EF                        497 00106$:
                                    498 ;	assignment4.c:112: if (month == 2) {
      0000EF 74 02            [12]  499 	mov	a,#0x02
      0000F1 B5 7D 0D         [24]  500 	cjne	a,_month,00120$
                                    501 ;	assignment4.c:113: if (day > 28) {
      0000F4 E5 7E            [12]  502 	mov	a,_day
      0000F6 24 E3            [12]  503 	add	a,#0xff - 0x1C
      0000F8 50 39            [24]  504 	jnc	00121$
                                    505 ;	assignment4.c:114: month++;
      0000FA 05 7D            [12]  506 	inc	_month
                                    507 ;	assignment4.c:115: day = 1;
      0000FC 75 7E 01         [24]  508 	mov	_day,#0x01
      0000FF 80 32            [24]  509 	sjmp	00121$
      000101                        510 00120$:
                                    511 ;	assignment4.c:118: else if (month == 4 || month == 6 || month == 9 || month == 11) {
      000101 74 04            [12]  512 	mov	a,#0x04
      000103 B5 7D 02         [24]  513 	cjne	a,_month,00179$
      000106 80 13            [24]  514 	sjmp	00113$
      000108                        515 00179$:
      000108 74 06            [12]  516 	mov	a,#0x06
      00010A B5 7D 02         [24]  517 	cjne	a,_month,00180$
      00010D 80 0C            [24]  518 	sjmp	00113$
      00010F                        519 00180$:
      00010F 74 09            [12]  520 	mov	a,#0x09
      000111 B5 7D 02         [24]  521 	cjne	a,_month,00181$
      000114 80 05            [24]  522 	sjmp	00113$
      000116                        523 00181$:
      000116 74 0B            [12]  524 	mov	a,#0x0B
      000118 B5 7D 0D         [24]  525 	cjne	a,_month,00114$
      00011B                        526 00113$:
                                    527 ;	assignment4.c:119: if (day > 30) {
      00011B E5 7E            [12]  528 	mov	a,_day
      00011D 24 E1            [12]  529 	add	a,#0xff - 0x1E
      00011F 50 12            [24]  530 	jnc	00121$
                                    531 ;	assignment4.c:120: month++;
      000121 05 7D            [12]  532 	inc	_month
                                    533 ;	assignment4.c:121: day = 1;
      000123 75 7E 01         [24]  534 	mov	_day,#0x01
      000126 80 0B            [24]  535 	sjmp	00121$
      000128                        536 00114$:
                                    537 ;	assignment4.c:125: if (day > 31) {
      000128 E5 7E            [12]  538 	mov	a,_day
      00012A 24 E0            [12]  539 	add	a,#0xff - 0x1F
      00012C 50 05            [24]  540 	jnc	00121$
                                    541 ;	assignment4.c:126: month++;
      00012E 05 7D            [12]  542 	inc	_month
                                    543 ;	assignment4.c:127: day = 1;
      000130 75 7E 01         [24]  544 	mov	_day,#0x01
      000133                        545 00121$:
                                    546 ;	assignment4.c:130: if (month == 13) {
      000133 74 0D            [12]  547 	mov	a,#0x0D
      000135 B5 7D 05         [24]  548 	cjne	a,_month,00123$
                                    549 ;	assignment4.c:131: year++;
      000138 05 7F            [12]  550 	inc	_year
                                    551 ;	assignment4.c:132: month = 1;
      00013A 75 7D 01         [24]  552 	mov	_month,#0x01
      00013D                        553 00123$:
                                    554 ;	assignment4.c:134: if (year == 100) {
      00013D 74 64            [12]  555 	mov	a,#0x64
      00013F B5 7F 03         [24]  556 	cjne	a,_year,00125$
                                    557 ;	assignment4.c:135: year = 0;
      000142 75 7F 00         [24]  558 	mov	_year,#0x00
      000145                        559 00125$:
                                    560 ;	assignment4.c:140: NumToChar(second, seconds);
      000145 75 3C 34         [24]  561 	mov	_NumToChar_PARM_2,#_main_seconds_1_15
      000148 75 3D 00         [24]  562 	mov	(_NumToChar_PARM_2 + 1),#0x00
      00014B 75 3E 40         [24]  563 	mov	(_NumToChar_PARM_2 + 2),#0x40
      00014E 85 7C 82         [24]  564 	mov	dpl,_second
      000151 12 03 5A         [24]  565 	lcall	_NumToChar
                                    566 ;	assignment4.c:141: NumToChar(minute, minutes);
      000154 75 3C 32         [24]  567 	mov	_NumToChar_PARM_2,#_main_minutes_1_15
      000157 75 3D 00         [24]  568 	mov	(_NumToChar_PARM_2 + 1),#0x00
      00015A 75 3E 40         [24]  569 	mov	(_NumToChar_PARM_2 + 2),#0x40
      00015D 85 7B 82         [24]  570 	mov	dpl,_minute
      000160 12 03 5A         [24]  571 	lcall	_NumToChar
                                    572 ;	assignment4.c:142: NumToChar(hour, hours);
      000163 75 3C 30         [24]  573 	mov	_NumToChar_PARM_2,#_main_hours_1_15
      000166 75 3D 00         [24]  574 	mov	(_NumToChar_PARM_2 + 1),#0x00
      000169 75 3E 40         [24]  575 	mov	(_NumToChar_PARM_2 + 2),#0x40
      00016C 85 7A 82         [24]  576 	mov	dpl,_hour
      00016F 12 03 5A         [24]  577 	lcall	_NumToChar
                                    578 ;	assignment4.c:143: NumToChar(day, days);
      000172 75 3C 38         [24]  579 	mov	_NumToChar_PARM_2,#_main_days_1_15
      000175 75 3D 00         [24]  580 	mov	(_NumToChar_PARM_2 + 1),#0x00
      000178 75 3E 40         [24]  581 	mov	(_NumToChar_PARM_2 + 2),#0x40
      00017B 85 7E 82         [24]  582 	mov	dpl,_day
      00017E 12 03 5A         [24]  583 	lcall	_NumToChar
                                    584 ;	assignment4.c:144: NumToChar(month, months);
      000181 75 3C 36         [24]  585 	mov	_NumToChar_PARM_2,#_main_months_1_15
      000184 75 3D 00         [24]  586 	mov	(_NumToChar_PARM_2 + 1),#0x00
      000187 75 3E 40         [24]  587 	mov	(_NumToChar_PARM_2 + 2),#0x40
      00018A 85 7D 82         [24]  588 	mov	dpl,_month
      00018D 12 03 5A         [24]  589 	lcall	_NumToChar
                                    590 ;	assignment4.c:145: NumToChar(year, years);
      000190 75 3C 3A         [24]  591 	mov	_NumToChar_PARM_2,#_main_years_1_15
      000193 75 3D 00         [24]  592 	mov	(_NumToChar_PARM_2 + 1),#0x00
      000196 75 3E 40         [24]  593 	mov	(_NumToChar_PARM_2 + 2),#0x40
      000199 85 7F 82         [24]  594 	mov	dpl,_year
      00019C 12 03 5A         [24]  595 	lcall	_NumToChar
                                    596 ;	assignment4.c:148: setDdRamAddress(0x00);
      00019F 75 82 00         [24]  597 	mov	dpl,#0x00
      0001A2 12 02 78         [24]  598 	lcall	_setDdRamAddress
                                    599 ;	assignment4.c:149: sendChar(hours[0]);
      0001A5 85 30 82         [24]  600 	mov	dpl,_main_hours_1_15
      0001A8 12 02 88         [24]  601 	lcall	_sendChar
                                    602 ;	assignment4.c:150: sendChar(hours[1]);
      0001AB 85 31 82         [24]  603 	mov	dpl,(_main_hours_1_15 + 0x0001)
      0001AE 12 02 88         [24]  604 	lcall	_sendChar
                                    605 ;	assignment4.c:151: sendChar(':');
      0001B1 75 82 3A         [24]  606 	mov	dpl,#0x3A
      0001B4 12 02 88         [24]  607 	lcall	_sendChar
                                    608 ;	assignment4.c:152: sendChar(minutes[0]);
      0001B7 85 32 82         [24]  609 	mov	dpl,_main_minutes_1_15
      0001BA 12 02 88         [24]  610 	lcall	_sendChar
                                    611 ;	assignment4.c:153: sendChar(minutes[1]);
      0001BD 85 33 82         [24]  612 	mov	dpl,(_main_minutes_1_15 + 0x0001)
      0001C0 12 02 88         [24]  613 	lcall	_sendChar
                                    614 ;	assignment4.c:154: sendChar(':');
      0001C3 75 82 3A         [24]  615 	mov	dpl,#0x3A
      0001C6 12 02 88         [24]  616 	lcall	_sendChar
                                    617 ;	assignment4.c:155: sendChar(seconds[0]);
      0001C9 85 34 82         [24]  618 	mov	dpl,_main_seconds_1_15
      0001CC 12 02 88         [24]  619 	lcall	_sendChar
                                    620 ;	assignment4.c:156: sendChar(seconds[1]);
      0001CF 85 35 82         [24]  621 	mov	dpl,(_main_seconds_1_15 + 0x0001)
      0001D2 12 02 88         [24]  622 	lcall	_sendChar
                                    623 ;	assignment4.c:158: setDdRamAddress(0x40);
      0001D5 75 82 40         [24]  624 	mov	dpl,#0x40
      0001D8 12 02 78         [24]  625 	lcall	_setDdRamAddress
                                    626 ;	assignment4.c:159: sendChar(months[0]);
      0001DB 85 36 82         [24]  627 	mov	dpl,_main_months_1_15
      0001DE 12 02 88         [24]  628 	lcall	_sendChar
                                    629 ;	assignment4.c:160: sendChar(months[1]);
      0001E1 85 37 82         [24]  630 	mov	dpl,(_main_months_1_15 + 0x0001)
      0001E4 12 02 88         [24]  631 	lcall	_sendChar
                                    632 ;	assignment4.c:161: sendChar('-');
      0001E7 75 82 2D         [24]  633 	mov	dpl,#0x2D
      0001EA 12 02 88         [24]  634 	lcall	_sendChar
                                    635 ;	assignment4.c:162: sendChar(days[0]);
      0001ED 85 38 82         [24]  636 	mov	dpl,_main_days_1_15
      0001F0 12 02 88         [24]  637 	lcall	_sendChar
                                    638 ;	assignment4.c:163: sendChar(days[1]);
      0001F3 85 39 82         [24]  639 	mov	dpl,(_main_days_1_15 + 0x0001)
      0001F6 12 02 88         [24]  640 	lcall	_sendChar
                                    641 ;	assignment4.c:164: sendChar('-');
      0001F9 75 82 2D         [24]  642 	mov	dpl,#0x2D
      0001FC 12 02 88         [24]  643 	lcall	_sendChar
                                    644 ;	assignment4.c:165: sendChar(years[0]);
      0001FF 85 3A 82         [24]  645 	mov	dpl,_main_years_1_15
      000202 12 02 88         [24]  646 	lcall	_sendChar
                                    647 ;	assignment4.c:166: sendChar(years[1]);
      000205 85 3B 82         [24]  648 	mov	dpl,(_main_years_1_15 + 0x0001)
      000208 12 02 88         [24]  649 	lcall	_sendChar
      00020B 02 00 CC         [24]  650 	ljmp	00127$
                                    651 ;------------------------------------------------------------
                                    652 ;Allocation info for local variables in function 'returnHome'
                                    653 ;------------------------------------------------------------
                                    654 ;	assignment4.c:173: void returnHome(void) {
                                    655 ;	-----------------------------------------
                                    656 ;	 function returnHome
                                    657 ;	-----------------------------------------
      00020E                        658 _returnHome:
                                    659 ;	assignment4.c:174: RS = 0;
      00020E C2 A1            [12]  660 	clr	_P2_1
                                    661 ;	assignment4.c:175: P1 = 0x02; // LCD command to return home (the first location of the first lcd line)
      000210 75 90 02         [24]  662 	mov	_P1,#0x02
                                    663 ;	assignment4.c:176: E = 1;
      000213 D2 A0            [12]  664 	setb	_P2_0
                                    665 ;	assignment4.c:177: E = 0;
      000215 C2 A0            [12]  666 	clr	_P2_0
                                    667 ;	assignment4.c:178: big_delay(); // This operation needs a bigger delay
      000217 02 02 CB         [24]  668 	ljmp	_big_delay
                                    669 ;------------------------------------------------------------
                                    670 ;Allocation info for local variables in function 'entryModeSet'
                                    671 ;------------------------------------------------------------
                                    672 ;	assignment4.c:181: void entryModeSet() {
                                    673 ;	-----------------------------------------
                                    674 ;	 function entryModeSet
                                    675 ;	-----------------------------------------
      00021A                        676 _entryModeSet:
                                    677 ;	assignment4.c:182: RS = 0;
      00021A C2 A1            [12]  678 	clr	_P2_1
                                    679 ;	assignment4.c:183: P1 = 0x06;
      00021C 75 90 06         [24]  680 	mov	_P1,#0x06
                                    681 ;	assignment4.c:184: E = 1;
      00021F D2 A0            [12]  682 	setb	_P2_0
                                    683 ;	assignment4.c:185: E = 0;
      000221 C2 A0            [12]  684 	clr	_P2_0
                                    685 ;	assignment4.c:186: delay();
      000223 02 02 C2         [24]  686 	ljmp	_delay
                                    687 ;------------------------------------------------------------
                                    688 ;Allocation info for local variables in function 'displayOnOffControl'
                                    689 ;------------------------------------------------------------
                                    690 ;	assignment4.c:189: void displayOnOffControl(__bit display, __bit cursor, __bit blinking) {
                                    691 ;	-----------------------------------------
                                    692 ;	 function displayOnOffControl
                                    693 ;	-----------------------------------------
      000226                        694 _displayOnOffControl:
                                    695 ;	assignment4.c:190: P1_7 = 0;
      000226 C2 97            [12]  696 	clr	_P1_7
                                    697 ;	assignment4.c:191: P1_6 = 0;
      000228 C2 96            [12]  698 	clr	_P1_6
                                    699 ;	assignment4.c:192: P1_5 = 0;
      00022A C2 95            [12]  700 	clr	_P1_5
                                    701 ;	assignment4.c:193: P1_4 = 0;
      00022C C2 94            [12]  702 	clr	_P1_4
                                    703 ;	assignment4.c:194: P1_3 = 1;
      00022E D2 93            [12]  704 	setb	_P1_3
                                    705 ;	assignment4.c:195: P1_2 = display;
      000230 A2 00            [12]  706 	mov	c,_displayOnOffControl_PARM_1
      000232 92 92            [24]  707 	mov	_P1_2,c
                                    708 ;	assignment4.c:196: P1_1 = cursor;
      000234 A2 01            [12]  709 	mov	c,_displayOnOffControl_PARM_2
      000236 92 91            [24]  710 	mov	_P1_1,c
                                    711 ;	assignment4.c:197: P1_0 = blinking;
      000238 A2 02            [12]  712 	mov	c,_displayOnOffControl_PARM_3
      00023A 92 90            [24]  713 	mov	_P1_0,c
                                    714 ;	assignment4.c:198: E = 1;
      00023C D2 A0            [12]  715 	setb	_P2_0
                                    716 ;	assignment4.c:199: E = 0;
      00023E C2 A0            [12]  717 	clr	_P2_0
                                    718 ;	assignment4.c:200: delay();
      000240 02 02 C2         [24]  719 	ljmp	_delay
                                    720 ;------------------------------------------------------------
                                    721 ;Allocation info for local variables in function 'cursorOrDisplayShift'
                                    722 ;------------------------------------------------------------
                                    723 ;	assignment4.c:203: void cursorOrDisplayShift(__bit sc, __bit rl) {
                                    724 ;	-----------------------------------------
                                    725 ;	 function cursorOrDisplayShift
                                    726 ;	-----------------------------------------
      000243                        727 _cursorOrDisplayShift:
                                    728 ;	assignment4.c:204: RS = 0;
      000243 C2 A1            [12]  729 	clr	_P2_1
                                    730 ;	assignment4.c:205: P1_7 = 0;
      000245 C2 97            [12]  731 	clr	_P1_7
                                    732 ;	assignment4.c:206: P1_6 = 0;
      000247 C2 96            [12]  733 	clr	_P1_6
                                    734 ;	assignment4.c:207: P1_5 = 0;
      000249 C2 95            [12]  735 	clr	_P1_5
                                    736 ;	assignment4.c:208: P1_4 = 1;
      00024B D2 94            [12]  737 	setb	_P1_4
                                    738 ;	assignment4.c:209: P1_3 = sc;
      00024D A2 03            [12]  739 	mov	c,_cursorOrDisplayShift_PARM_1
      00024F 92 93            [24]  740 	mov	_P1_3,c
                                    741 ;	assignment4.c:210: P1_2 = rl;
      000251 A2 04            [12]  742 	mov	c,_cursorOrDisplayShift_PARM_2
      000253 92 92            [24]  743 	mov	_P1_2,c
                                    744 ;	assignment4.c:211: P1_1 = 0;
      000255 C2 91            [12]  745 	clr	_P1_1
                                    746 ;	assignment4.c:212: P1_0 = 0;
      000257 C2 90            [12]  747 	clr	_P1_0
                                    748 ;	assignment4.c:213: E = 1;
      000259 D2 A0            [12]  749 	setb	_P2_0
                                    750 ;	assignment4.c:214: E = 0;
      00025B C2 A0            [12]  751 	clr	_P2_0
                                    752 ;	assignment4.c:215: delay();
      00025D 02 02 C2         [24]  753 	ljmp	_delay
                                    754 ;------------------------------------------------------------
                                    755 ;Allocation info for local variables in function 'functionSet'
                                    756 ;------------------------------------------------------------
                                    757 ;	assignment4.c:218: void functionSet(void) {
                                    758 ;	-----------------------------------------
                                    759 ;	 function functionSet
                                    760 ;	-----------------------------------------
      000260                        761 _functionSet:
                                    762 ;	assignment4.c:219: RS = 0;
      000260 C2 A1            [12]  763 	clr	_P2_1
                                    764 ;	assignment4.c:220: P1 = 0x38; // 8-bit mode, 2 lines LCD
      000262 75 90 38         [24]  765 	mov	_P1,#0x38
                                    766 ;	assignment4.c:221: E = 1;
      000265 D2 A0            [12]  767 	setb	_P2_0
                                    768 ;	assignment4.c:222: E = 0;
      000267 C2 A0            [12]  769 	clr	_P2_0
                                    770 ;	assignment4.c:223: delay();
      000269 02 02 C2         [24]  771 	ljmp	_delay
                                    772 ;------------------------------------------------------------
                                    773 ;Allocation info for local variables in function 'clearDisplay'
                                    774 ;------------------------------------------------------------
                                    775 ;	assignment4.c:226: void clearDisplay(void) {
                                    776 ;	-----------------------------------------
                                    777 ;	 function clearDisplay
                                    778 ;	-----------------------------------------
      00026C                        779 _clearDisplay:
                                    780 ;	assignment4.c:227: RS = 0;
      00026C C2 A1            [12]  781 	clr	_P2_1
                                    782 ;	assignment4.c:228: P1 = 0x01; // command to clear LCD and return the cursor to the home position
      00026E 75 90 01         [24]  783 	mov	_P1,#0x01
                                    784 ;	assignment4.c:229: E = 1;
      000271 D2 A0            [12]  785 	setb	_P2_0
                                    786 ;	assignment4.c:230: E = 0;
      000273 C2 A0            [12]  787 	clr	_P2_0
                                    788 ;	assignment4.c:231: big_delay(); // This operation needs a bigger delay
      000275 02 02 CB         [24]  789 	ljmp	_big_delay
                                    790 ;------------------------------------------------------------
                                    791 ;Allocation info for local variables in function 'setDdRamAddress'
                                    792 ;------------------------------------------------------------
                                    793 ;address                   Allocated to registers r7 
                                    794 ;------------------------------------------------------------
                                    795 ;	assignment4.c:234: void setDdRamAddress(char address) {  // Determine the place to place the next character - First LCD location address in 00h for line 1 and 40h for line 2
                                    796 ;	-----------------------------------------
                                    797 ;	 function setDdRamAddress
                                    798 ;	-----------------------------------------
      000278                        799 _setDdRamAddress:
      000278 AF 82            [24]  800 	mov	r7,dpl
                                    801 ;	assignment4.c:235: RS = 0;
      00027A C2 A1            [12]  802 	clr	_P2_1
                                    803 ;	assignment4.c:236: P1 = address | 0x80;  // set the MSB to detect that this is an address
      00027C 74 80            [12]  804 	mov	a,#0x80
      00027E 4F               [12]  805 	orl	a,r7
      00027F F5 90            [12]  806 	mov	_P1,a
                                    807 ;	assignment4.c:237: E = 1;
      000281 D2 A0            [12]  808 	setb	_P2_0
                                    809 ;	assignment4.c:238: E = 0;
      000283 C2 A0            [12]  810 	clr	_P2_0
                                    811 ;	assignment4.c:239: delay();
      000285 02 02 C2         [24]  812 	ljmp	_delay
                                    813 ;------------------------------------------------------------
                                    814 ;Allocation info for local variables in function 'sendChar'
                                    815 ;------------------------------------------------------------
                                    816 ;c                         Allocated to registers r7 
                                    817 ;------------------------------------------------------------
                                    818 ;	assignment4.c:244: void sendChar(char c) {  // Function to send one character to be displayed on the LCD
                                    819 ;	-----------------------------------------
                                    820 ;	 function sendChar
                                    821 ;	-----------------------------------------
      000288                        822 _sendChar:
      000288 AF 82            [24]  823 	mov	r7,dpl
                                    824 ;	assignment4.c:245: RS = 1;
      00028A D2 A1            [12]  825 	setb	_P2_1
                                    826 ;	assignment4.c:246: P1 = c;
      00028C 8F 90            [24]  827 	mov	_P1,r7
                                    828 ;	assignment4.c:247: E = 1;
      00028E D2 A0            [12]  829 	setb	_P2_0
                                    830 ;	assignment4.c:248: E = 0;
      000290 C2 A0            [12]  831 	clr	_P2_0
                                    832 ;	assignment4.c:249: delay();
      000292 02 02 C2         [24]  833 	ljmp	_delay
                                    834 ;------------------------------------------------------------
                                    835 ;Allocation info for local variables in function 'sendString'
                                    836 ;------------------------------------------------------------
                                    837 ;str                       Allocated to registers 
                                    838 ;c                         Allocated to registers r3 
                                    839 ;------------------------------------------------------------
                                    840 ;	assignment4.c:252: void sendString(char* str) {  // Function to send a string of characters to be displayed on the lCD
                                    841 ;	-----------------------------------------
                                    842 ;	 function sendString
                                    843 ;	-----------------------------------------
      000295                        844 _sendString:
      000295 AD 82            [24]  845 	mov	r5,dpl
      000297 AE 83            [24]  846 	mov	r6,dph
      000299 AF F0            [24]  847 	mov	r7,b
                                    848 ;	assignment4.c:254: while (c = *str++) {
      00029B                        849 00101$:
      00029B 8D 82            [24]  850 	mov	dpl,r5
      00029D 8E 83            [24]  851 	mov	dph,r6
      00029F 8F F0            [24]  852 	mov	b,r7
      0002A1 12 0A 1D         [24]  853 	lcall	__gptrget
      0002A4 FC               [12]  854 	mov	r4,a
      0002A5 A3               [24]  855 	inc	dptr
      0002A6 AD 82            [24]  856 	mov	r5,dpl
      0002A8 AE 83            [24]  857 	mov	r6,dph
      0002AA EC               [12]  858 	mov	a,r4
      0002AB FB               [12]  859 	mov	r3,a
      0002AC 60 13            [24]  860 	jz	00104$
                                    861 ;	assignment4.c:255: sendChar(c);
      0002AE 8B 82            [24]  862 	mov	dpl,r3
      0002B0 C0 07            [24]  863 	push	ar7
      0002B2 C0 06            [24]  864 	push	ar6
      0002B4 C0 05            [24]  865 	push	ar5
      0002B6 12 02 88         [24]  866 	lcall	_sendChar
      0002B9 D0 05            [24]  867 	pop	ar5
      0002BB D0 06            [24]  868 	pop	ar6
      0002BD D0 07            [24]  869 	pop	ar7
      0002BF 80 DA            [24]  870 	sjmp	00101$
      0002C1                        871 00104$:
      0002C1 22               [24]  872 	ret
                                    873 ;------------------------------------------------------------
                                    874 ;Allocation info for local variables in function 'delay'
                                    875 ;------------------------------------------------------------
                                    876 ;c                         Allocated to registers r7 
                                    877 ;------------------------------------------------------------
                                    878 ;	assignment4.c:259: void delay(void) {
                                    879 ;	-----------------------------------------
                                    880 ;	 function delay
                                    881 ;	-----------------------------------------
      0002C2                        882 _delay:
                                    883 ;	assignment4.c:261: for (c = 0; c < 50; c++);
      0002C2 7F 32            [12]  884 	mov	r7,#0x32
      0002C4                        885 00104$:
      0002C4 EF               [12]  886 	mov	a,r7
      0002C5 14               [12]  887 	dec	a
      0002C6 FE               [12]  888 	mov	r6,a
      0002C7 FF               [12]  889 	mov	r7,a
      0002C8 70 FA            [24]  890 	jnz	00104$
      0002CA 22               [24]  891 	ret
                                    892 ;------------------------------------------------------------
                                    893 ;Allocation info for local variables in function 'big_delay'
                                    894 ;------------------------------------------------------------
                                    895 ;c                         Allocated to registers r7 
                                    896 ;------------------------------------------------------------
                                    897 ;	assignment4.c:264: void big_delay(void) {
                                    898 ;	-----------------------------------------
                                    899 ;	 function big_delay
                                    900 ;	-----------------------------------------
      0002CB                        901 _big_delay:
                                    902 ;	assignment4.c:266: for (c = 0; c < 255; c++);
      0002CB 7F FF            [12]  903 	mov	r7,#0xFF
      0002CD                        904 00104$:
      0002CD 8F 06            [24]  905 	mov	ar6,r7
      0002CF 1E               [12]  906 	dec	r6
      0002D0 EE               [12]  907 	mov	a,r6
      0002D1 FF               [12]  908 	mov	r7,a
      0002D2 70 F9            [24]  909 	jnz	00104$
      0002D4 22               [24]  910 	ret
                                    911 ;------------------------------------------------------------
                                    912 ;Allocation info for local variables in function 'keypad'
                                    913 ;------------------------------------------------------------
                                    914 ;row                       Allocated to registers r6 
                                    915 ;col                       Allocated to registers r3 
                                    916 ;keypad                    Allocated with name '_keypad_keypad_1_51'
                                    917 ;i                         Allocated to registers r5 
                                    918 ;gotkey                    Allocated to registers r7 
                                    919 ;------------------------------------------------------------
                                    920 ;	assignment4.c:270: void keypad(void) {
                                    921 ;	-----------------------------------------
                                    922 ;	 function keypad
                                    923 ;	-----------------------------------------
      0002D5                        924 _keypad:
                                    925 ;	assignment4.c:273: unsigned char keypad[4][3] = {   // This array contains the ASCII of the keypad keys
      0002D5 75 3C 33         [24]  926 	mov	_keypad_keypad_1_51,#0x33
      0002D8 75 3D 32         [24]  927 	mov	(_keypad_keypad_1_51 + 0x0001),#0x32
      0002DB 75 3E 31         [24]  928 	mov	(_keypad_keypad_1_51 + 0x0002),#0x31
      0002DE 75 3F 36         [24]  929 	mov	(_keypad_keypad_1_51 + 0x0003),#0x36
      0002E1 75 40 35         [24]  930 	mov	(_keypad_keypad_1_51 + 0x0004),#0x35
      0002E4 75 41 34         [24]  931 	mov	(_keypad_keypad_1_51 + 0x0005),#0x34
      0002E7 75 42 39         [24]  932 	mov	(_keypad_keypad_1_51 + 0x0006),#0x39
      0002EA 75 43 38         [24]  933 	mov	(_keypad_keypad_1_51 + 0x0007),#0x38
      0002ED 75 44 37         [24]  934 	mov	(_keypad_keypad_1_51 + 0x0008),#0x37
      0002F0 75 45 23         [24]  935 	mov	(_keypad_keypad_1_51 + 0x0009),#0x23
      0002F3 75 46 30         [24]  936 	mov	(_keypad_keypad_1_51 + 0x000a),#0x30
      0002F6 75 47 2A         [24]  937 	mov	(_keypad_keypad_1_51 + 0x000b),#0x2A
                                    938 ;	assignment4.c:280: unsigned char gotkey = 0;
      0002F9 7F 00            [12]  939 	mov	r7,#0x00
                                    940 ;	assignment4.c:281: while (1) {
      0002FB                        941 00107$:
                                    942 ;	assignment4.c:282: row = 0xf7;  // The first row (connected to P0.3) will be zero
      0002FB 7E F7            [12]  943 	mov	r6,#0xF7
                                    944 ;	assignment4.c:284: for (i = 0; i<4; ++i) { // loop over the 4 rows
      0002FD 7D 00            [12]  945 	mov	r5,#0x00
      0002FF 7C 00            [12]  946 	mov	r4,#0x00
      000301                        947 00109$:
                                    948 ;	assignment4.c:286: P0 = 0xff;     // Initialize the 4 rows to '1' and set the column ports to inputs
      000301 75 80 FF         [24]  949 	mov	_P0,#0xFF
                                    950 ;	assignment4.c:287: P0 = P0 & row; // clear one row at a time
      000304 EE               [12]  951 	mov	a,r6
      000305 52 80            [12]  952 	anl	_P0,a
                                    953 ;	assignment4.c:288: col = P0 & 0x70;  // Read the 3 columns
      000307 74 70            [12]  954 	mov	a,#0x70
      000309 55 80            [12]  955 	anl	a,_P0
      00030B FB               [12]  956 	mov	r3,a
                                    957 ;	assignment4.c:289: if (col != 0x70) { // If any column is zero i.e. a key is pressed
      00030C BB 70 02         [24]  958 	cjne	r3,#0x70,00125$
      00030F 80 19            [24]  959 	sjmp	00102$
      000311                        960 00125$:
                                    961 ;	assignment4.c:290: col = (~col) & 0x70;  // because the selected column returns zero
      000311 EB               [12]  962 	mov	a,r3
      000312 F4               [12]  963 	cpl	a
      000313 FA               [12]  964 	mov	r2,a
      000314 74 70            [12]  965 	mov	a,#0x70
      000316 5A               [12]  966 	anl	a,r2
                                    967 ;	assignment4.c:291: col = col >> 5;       // The column variable now contain the number of the selected column
      000317 C4               [12]  968 	swap	a
      000318 03               [12]  969 	rr	a
      000319 54 07            [12]  970 	anl	a,#0x07
      00031B FB               [12]  971 	mov	r3,a
                                    972 ;	assignment4.c:292: gotkey = keypad[i][col]; // Get the ASCII of the corresponding pressed key
      00031C ED               [12]  973 	mov	a,r5
      00031D 75 F0 03         [24]  974 	mov	b,#0x03
      000320 A4               [48]  975 	mul	ab
      000321 24 3C            [12]  976 	add	a,#_keypad_keypad_1_51
      000323 FA               [12]  977 	mov	r2,a
      000324 2B               [12]  978 	add	a,r3
      000325 F9               [12]  979 	mov	r1,a
      000326 87 07            [24]  980 	mov	ar7,@r1
                                    981 ;	assignment4.c:293: break;  // Since a key was detected -> Exit the for loop
      000328 80 0F            [24]  982 	sjmp	00103$
      00032A                        983 00102$:
                                    984 ;	assignment4.c:295: row = row >> 1;   // No key is detected yet, try the next row
      00032A EE               [12]  985 	mov	a,r6
      00032B C3               [12]  986 	clr	c
      00032C 13               [12]  987 	rrc	a
      00032D FE               [12]  988 	mov	r6,a
                                    989 ;	assignment4.c:296: row = row | 0xf0; // Only one of the least 4 significant bits is '0' at a time 
      00032E 43 06 F0         [24]  990 	orl	ar6,#0xF0
                                    991 ;	assignment4.c:284: for (i = 0; i<4; ++i) { // loop over the 4 rows
      000331 0C               [12]  992 	inc	r4
      000332 8C 05            [24]  993 	mov	ar5,r4
      000334 BC 04 00         [24]  994 	cjne	r4,#0x04,00126$
      000337                        995 00126$:
      000337 40 C8            [24]  996 	jc	00109$
      000339                        997 00103$:
                                    998 ;	assignment4.c:300: if (gotkey != 0) { break; }  // Since a key was detected -> exit the while loop
      000339 EF               [12]  999 	mov	a,r7
      00033A 60 BF            [24] 1000 	jz	00107$
                                   1001 ;	assignment4.c:304: P1 = gotkey;  // Send the detected key to the output
      00033C 8F 90            [24] 1002 	mov	_P1,r7
      00033E 22               [24] 1003 	ret
                                   1004 ;------------------------------------------------------------
                                   1005 ;Allocation info for local variables in function 'timer_delay'
                                   1006 ;------------------------------------------------------------
                                   1007 ;a                         Allocated to registers r7 
                                   1008 ;------------------------------------------------------------
                                   1009 ;	assignment4.c:310: void timer_delay(void) {
                                   1010 ;	-----------------------------------------
                                   1011 ;	 function timer_delay
                                   1012 ;	-----------------------------------------
      00033F                       1013 _timer_delay:
                                   1014 ;	assignment4.c:313: TMOD = 0x01;
      00033F 75 89 01         [24] 1015 	mov	_TMOD,#0x01
                                   1016 ;	assignment4.c:314: while (a != 0) {
      000342 7F 14            [12] 1017 	mov	r7,#0x14
      000344                       1018 00104$:
      000344 EF               [12] 1019 	mov	a,r7
      000345 60 12            [24] 1020 	jz	00107$
                                   1021 ;	assignment4.c:315: TL0 = 0xAF;
      000347 75 8A AF         [24] 1022 	mov	_TL0,#0xAF
                                   1023 ;	assignment4.c:316: TH0 = 0x3C;
      00034A 75 8C 3C         [24] 1024 	mov	_TH0,#0x3C
                                   1025 ;	assignment4.c:317: TR0 = 1;
      00034D D2 8C            [12] 1026 	setb	_TR0
                                   1027 ;	assignment4.c:318: while (!TF0);
      00034F                       1028 00101$:
      00034F 30 8D FD         [24] 1029 	jnb	_TF0,00101$
                                   1030 ;	assignment4.c:319: TR0 = 0;
      000352 C2 8C            [12] 1031 	clr	_TR0
                                   1032 ;	assignment4.c:320: TF0 = 0;
      000354 C2 8D            [12] 1033 	clr	_TF0
                                   1034 ;	assignment4.c:321: a = a - 1;
      000356 1F               [12] 1035 	dec	r7
      000357 80 EB            [24] 1036 	sjmp	00104$
      000359                       1037 00107$:
      000359 22               [24] 1038 	ret
                                   1039 ;------------------------------------------------------------
                                   1040 ;Allocation info for local variables in function 'NumToChar'
                                   1041 ;------------------------------------------------------------
                                   1042 ;nums                      Allocated with name '_NumToChar_PARM_2'
                                   1043 ;num                       Allocated to registers r7 
                                   1044 ;------------------------------------------------------------
                                   1045 ;	assignment4.c:328: void NumToChar(unsigned char num, unsigned char nums[2]) {
                                   1046 ;	-----------------------------------------
                                   1047 ;	 function NumToChar
                                   1048 ;	-----------------------------------------
      00035A                       1049 _NumToChar:
      00035A AF 82            [24] 1050 	mov	r7,dpl
                                   1051 ;	assignment4.c:331: nums[0] = (num/10) + '0';
      00035C AC 3C            [24] 1052 	mov	r4,_NumToChar_PARM_2
      00035E AD 3D            [24] 1053 	mov	r5,(_NumToChar_PARM_2 + 1)
      000360 AE 3E            [24] 1054 	mov	r6,(_NumToChar_PARM_2 + 2)
      000362 75 F0 0A         [24] 1055 	mov	b,#0x0A
      000365 EF               [12] 1056 	mov	a,r7
      000366 84               [48] 1057 	div	ab
      000367 24 30            [12] 1058 	add	a,#0x30
      000369 FB               [12] 1059 	mov	r3,a
      00036A 8C 82            [24] 1060 	mov	dpl,r4
      00036C 8D 83            [24] 1061 	mov	dph,r5
      00036E 8E F0            [24] 1062 	mov	b,r6
      000370 12 0A 02         [24] 1063 	lcall	__gptrput
                                   1064 ;	assignment4.c:334: nums[1] = (num%10) + '0';
      000373 0C               [12] 1065 	inc	r4
      000374 BC 00 01         [24] 1066 	cjne	r4,#0x00,00103$
      000377 0D               [12] 1067 	inc	r5
      000378                       1068 00103$:
      000378 75 F0 0A         [24] 1069 	mov	b,#0x0A
      00037B EF               [12] 1070 	mov	a,r7
      00037C 84               [48] 1071 	div	ab
      00037D AF F0            [24] 1072 	mov	r7,b
      00037F 74 30            [12] 1073 	mov	a,#0x30
      000381 2F               [12] 1074 	add	a,r7
      000382 8C 82            [24] 1075 	mov	dpl,r4
      000384 8D 83            [24] 1076 	mov	dph,r5
      000386 8E F0            [24] 1077 	mov	b,r6
      000388 02 0A 02         [24] 1078 	ljmp	__gptrput
                                   1079 ;------------------------------------------------------------
                                   1080 ;Allocation info for local variables in function '_sdcc_gsinit_startup'
                                   1081 ;------------------------------------------------------------
                                   1082 ;	assignment4.c:338: void _sdcc_gsinit_startup(void) {
                                   1083 ;	-----------------------------------------
                                   1084 ;	 function _sdcc_gsinit_startup
                                   1085 ;	-----------------------------------------
      00038B                       1086 __sdcc_gsinit_startup:
                                   1087 ;	assignment4.c:342: __endasm;
      00038B 75 81 5F         [24] 1088 	mov sp, #0x5F
                                   1089 ;	assignment4.c:343: main();
      00038E 02 00 68         [24] 1090 	ljmp	_main
                                   1091 ;------------------------------------------------------------
                                   1092 ;Allocation info for local variables in function 'int0_isr'
                                   1093 ;------------------------------------------------------------
                                   1094 ;count                     Allocated to registers r7 
                                   1095 ;------------------------------------------------------------
                                   1096 ;	assignment4.c:349: void int0_isr(void) __interrupt(0) __using(1) {
                                   1097 ;	-----------------------------------------
                                   1098 ;	 function int0_isr
                                   1099 ;	-----------------------------------------
      000391                       1100 _int0_isr:
                           00000F  1101 	ar7 = 0x0F
                           00000E  1102 	ar6 = 0x0E
                           00000D  1103 	ar5 = 0x0D
                           00000C  1104 	ar4 = 0x0C
                           00000B  1105 	ar3 = 0x0B
                           00000A  1106 	ar2 = 0x0A
                           000009  1107 	ar1 = 0x09
                           000008  1108 	ar0 = 0x08
      000391 C0 21            [24] 1109 	push	bits
      000393 C0 E0            [24] 1110 	push	acc
      000395 C0 F0            [24] 1111 	push	b
      000397 C0 82            [24] 1112 	push	dpl
      000399 C0 83            [24] 1113 	push	dph
      00039B C0 07            [24] 1114 	push	(0+7)
      00039D C0 06            [24] 1115 	push	(0+6)
      00039F C0 05            [24] 1116 	push	(0+5)
      0003A1 C0 04            [24] 1117 	push	(0+4)
      0003A3 C0 03            [24] 1118 	push	(0+3)
      0003A5 C0 02            [24] 1119 	push	(0+2)
      0003A7 C0 01            [24] 1120 	push	(0+1)
      0003A9 C0 00            [24] 1121 	push	(0+0)
      0003AB C0 D0            [24] 1122 	push	psw
      0003AD 75 D0 08         [24] 1123 	mov	psw,#0x08
                                   1124 ;	assignment4.c:350: char count = 0;
      0003B0 7F 00            [12] 1125 	mov	r7,#0x00
                                   1126 ;	assignment4.c:352: setDdRamAddress(count);
      0003B2 75 82 00         [24] 1127 	mov	dpl,#0x00
      0003B5 C0 0F            [24] 1128 	push	ar7
      0003B7 75 D0 00         [24] 1129 	mov	psw,#0x00
      0003BA 12 02 78         [24] 1130 	lcall	_setDdRamAddress
      0003BD 75 D0 08         [24] 1131 	mov	psw,#0x08
      0003C0 D0 0F            [24] 1132 	pop	ar7
                                   1133 ;	assignment4.c:354: while (SW0 == 0) {
      0003C2                       1134 00139$:
      0003C2 30 B2 03         [24] 1135 	jnb	_P3_2,00204$
      0003C5 02 05 E5         [24] 1136 	ljmp	00142$
      0003C8                       1137 00204$:
                                   1138 ;	assignment4.c:357: keypad();
      0003C8 C0 0F            [24] 1139 	push	ar7
      0003CA 75 D0 00         [24] 1140 	mov	psw,#0x00
      0003CD 12 02 D5         [24] 1141 	lcall	_keypad
      0003D0 75 D0 08         [24] 1142 	mov	psw,#0x08
      0003D3 D0 0F            [24] 1143 	pop	ar7
                                   1144 ;	assignment4.c:362: if (P1 == '*') {
      0003D5 74 2A            [12] 1145 	mov	a,#0x2A
      0003D7 B5 90 22         [24] 1146 	cjne	a,_P1,00137$
                                   1147 ;	assignment4.c:363: count--;
      0003DA 1F               [12] 1148 	dec	r7
                                   1149 ;	assignment4.c:364: if (count < 0) {
      0003DB EF               [12] 1150 	mov	a,r7
      0003DC 30 E7 02         [24] 1151 	jnb	acc.7,00102$
                                   1152 ;	assignment4.c:365: count = 7;
      0003DF 7F 07            [12] 1153 	mov	r7,#0x07
      0003E1                       1154 00102$:
                                   1155 ;	assignment4.c:367: if (count == 2) {
      0003E1 BF 02 02         [24] 1156 	cjne	r7,#0x02,00104$
                                   1157 ;	assignment4.c:368: count = 1;
      0003E4 7F 01            [12] 1158 	mov	r7,#0x01
      0003E6                       1159 00104$:
                                   1160 ;	assignment4.c:370: if (count == 5) {
      0003E6 BF 05 02         [24] 1161 	cjne	r7,#0x05,00106$
                                   1162 ;	assignment4.c:371: count = 4;
      0003E9 7F 04            [12] 1163 	mov	r7,#0x04
      0003EB                       1164 00106$:
                                   1165 ;	assignment4.c:373: setDdRamAddress(count);
      0003EB 8F 82            [24] 1166 	mov	dpl,r7
      0003ED C0 0F            [24] 1167 	push	ar7
      0003EF 75 D0 00         [24] 1168 	mov	psw,#0x00
      0003F2 12 02 78         [24] 1169 	lcall	_setDdRamAddress
      0003F5 75 D0 08         [24] 1170 	mov	psw,#0x08
      0003F8 D0 0F            [24] 1171 	pop	ar7
      0003FA 80 C6            [24] 1172 	sjmp	00139$
      0003FC                       1173 00137$:
                                   1174 ;	assignment4.c:376: else if (P1 == '#') {
      0003FC 74 23            [12] 1175 	mov	a,#0x23
      0003FE B5 90 2A         [24] 1176 	cjne	a,_P1,00134$
                                   1177 ;	assignment4.c:377: count++;
      000401 0F               [12] 1178 	inc	r7
                                   1179 ;	assignment4.c:378: if (count > 7) {
      000402 C3               [12] 1180 	clr	c
      000403 74 87            [12] 1181 	mov	a,#(0x07 ^ 0x80)
      000405 8F F0            [24] 1182 	mov	b,r7
      000407 63 F0 80         [24] 1183 	xrl	b,#0x80
      00040A 95 F0            [12] 1184 	subb	a,b
      00040C 50 02            [24] 1185 	jnc	00108$
                                   1186 ;	assignment4.c:379: count = 0;
      00040E 7F 00            [12] 1187 	mov	r7,#0x00
      000410                       1188 00108$:
                                   1189 ;	assignment4.c:381: if (count == 2) {
      000410 BF 02 02         [24] 1190 	cjne	r7,#0x02,00110$
                                   1191 ;	assignment4.c:382: count = 3;
      000413 7F 03            [12] 1192 	mov	r7,#0x03
      000415                       1193 00110$:
                                   1194 ;	assignment4.c:384: if (count == 5) {
      000415 BF 05 02         [24] 1195 	cjne	r7,#0x05,00112$
                                   1196 ;	assignment4.c:385: count = 6;
      000418 7F 06            [12] 1197 	mov	r7,#0x06
      00041A                       1198 00112$:
                                   1199 ;	assignment4.c:387: setDdRamAddress(count);
      00041A 8F 82            [24] 1200 	mov	dpl,r7
      00041C C0 0F            [24] 1201 	push	ar7
      00041E 75 D0 00         [24] 1202 	mov	psw,#0x00
      000421 12 02 78         [24] 1203 	lcall	_setDdRamAddress
      000424 75 D0 08         [24] 1204 	mov	psw,#0x08
      000427 D0 0F            [24] 1205 	pop	ar7
      000429 80 97            [24] 1206 	sjmp	00139$
      00042B                       1207 00134$:
                                   1208 ;	assignment4.c:391: switch (count) {
      00042B BF 00 02         [24] 1209 	cjne	r7,#0x00,00219$
      00042E 80 20            [24] 1210 	sjmp	00113$
      000430                       1211 00219$:
      000430 BF 01 02         [24] 1212 	cjne	r7,#0x01,00220$
      000433 80 61            [24] 1213 	sjmp	00117$
      000435                       1214 00220$:
      000435 BF 03 03         [24] 1215 	cjne	r7,#0x03,00221$
      000438 02 04 E2         [24] 1216 	ljmp	00122$
      00043B                       1217 00221$:
      00043B BF 04 03         [24] 1218 	cjne	r7,#0x04,00222$
      00043E 02 05 28         [24] 1219 	ljmp	00126$
      000441                       1220 00222$:
      000441 BF 06 03         [24] 1221 	cjne	r7,#0x06,00223$
      000444 02 05 65         [24] 1222 	ljmp	00127$
      000447                       1223 00223$:
      000447 BF 07 03         [24] 1224 	cjne	r7,#0x07,00224$
      00044A 02 05 AB         [24] 1225 	ljmp	00131$
      00044D                       1226 00224$:
      00044D 02 03 C2         [24] 1227 	ljmp	00139$
                                   1228 ;	assignment4.c:393: case 0:
      000450                       1229 00113$:
                                   1230 ;	assignment4.c:394: if (P1 > '2') {
      000450 E5 90            [12] 1231 	mov	a,_P1
      000452 24 CD            [12] 1232 	add	a,#0xff - 0x32
      000454 50 03            [24] 1233 	jnc	00225$
      000456 02 03 C2         [24] 1234 	ljmp	00139$
      000459                       1235 00225$:
                                   1236 ;	assignment4.c:398: hour = (P1 - '0') * 10;
      000459 E5 90            [12] 1237 	mov	a,_P1
      00045B 24 D0            [12] 1238 	add	a,#0xD0
      00045D 75 F0 0A         [24] 1239 	mov	b,#0x0A
      000460 A4               [48] 1240 	mul	ab
      000461 F5 7A            [12] 1241 	mov	_hour,a
                                   1242 ;	assignment4.c:399: sendChar(P1);
      000463 85 90 82         [24] 1243 	mov	dpl,_P1
      000466 C0 0F            [24] 1244 	push	ar7
      000468 75 D0 00         [24] 1245 	mov	psw,#0x00
      00046B 12 02 88         [24] 1246 	lcall	_sendChar
      00046E 75 D0 08         [24] 1247 	mov	psw,#0x08
      000471 D0 0F            [24] 1248 	pop	ar7
                                   1249 ;	assignment4.c:400: count++;
      000473 0F               [12] 1250 	inc	r7
                                   1251 ;	assignment4.c:401: sendChar('0');
      000474 75 82 30         [24] 1252 	mov	dpl,#0x30
      000477 C0 0F            [24] 1253 	push	ar7
      000479 75 D0 00         [24] 1254 	mov	psw,#0x00
      00047C 12 02 88         [24] 1255 	lcall	_sendChar
      00047F 75 D0 08         [24] 1256 	mov	psw,#0x08
      000482 D0 0F            [24] 1257 	pop	ar7
                                   1258 ;	assignment4.c:402: setDdRamAddress(count);
      000484 8F 82            [24] 1259 	mov	dpl,r7
      000486 C0 0F            [24] 1260 	push	ar7
      000488 75 D0 00         [24] 1261 	mov	psw,#0x00
      00048B 12 02 78         [24] 1262 	lcall	_setDdRamAddress
      00048E 75 D0 08         [24] 1263 	mov	psw,#0x08
      000491 D0 0F            [24] 1264 	pop	ar7
                                   1265 ;	assignment4.c:403: break;
      000493 02 03 C2         [24] 1266 	ljmp	00139$
                                   1267 ;	assignment4.c:405: case 1:
      000496                       1268 00117$:
                                   1269 ;	assignment4.c:406: if (P1 > '3' && hour >= 20) {
      000496 E5 90            [12] 1270 	mov	a,_P1
      000498 24 CC            [12] 1271 	add	a,#0xff - 0x33
      00049A 50 09            [24] 1272 	jnc	00119$
      00049C 74 EC            [12] 1273 	mov	a,#0x100 - 0x14
      00049E 25 7A            [12] 1274 	add	a,_hour
      0004A0 50 03            [24] 1275 	jnc	00227$
      0004A2 02 03 C2         [24] 1276 	ljmp	00139$
      0004A5                       1277 00227$:
                                   1278 ;	assignment4.c:407: break;
      0004A5                       1279 00119$:
                                   1280 ;	assignment4.c:410: hour /= 10;
      0004A5 75 F0 0A         [24] 1281 	mov	b,#0x0A
      0004A8 E5 7A            [12] 1282 	mov	a,_hour
      0004AA 84               [48] 1283 	div	ab
      0004AB F5 7A            [12] 1284 	mov	_hour,a
                                   1285 ;	assignment4.c:411: hour *= 10;
      0004AD E5 7A            [12] 1286 	mov	a,_hour
      0004AF 75 F0 0A         [24] 1287 	mov	b,#0x0A
      0004B2 A4               [48] 1288 	mul	ab
      0004B3 F5 7A            [12] 1289 	mov	_hour,a
                                   1290 ;	assignment4.c:412: hour += (P1 - '0');
      0004B5 E5 90            [12] 1291 	mov	a,_P1
      0004B7 24 D0            [12] 1292 	add	a,#0xD0
      0004B9 AD 7A            [24] 1293 	mov	r5,_hour
      0004BB 2D               [12] 1294 	add	a,r5
      0004BC F5 7A            [12] 1295 	mov	_hour,a
                                   1296 ;	assignment4.c:413: sendChar(P1);
      0004BE 85 90 82         [24] 1297 	mov	dpl,_P1
      0004C1 C0 0F            [24] 1298 	push	ar7
      0004C3 75 D0 00         [24] 1299 	mov	psw,#0x00
      0004C6 12 02 88         [24] 1300 	lcall	_sendChar
      0004C9 75 D0 08         [24] 1301 	mov	psw,#0x08
      0004CC D0 0F            [24] 1302 	pop	ar7
                                   1303 ;	assignment4.c:414: count += 2;
      0004CE 0F               [12] 1304 	inc	r7
      0004CF 0F               [12] 1305 	inc	r7
                                   1306 ;	assignment4.c:415: setDdRamAddress(count);
      0004D0 8F 82            [24] 1307 	mov	dpl,r7
      0004D2 C0 0F            [24] 1308 	push	ar7
      0004D4 75 D0 00         [24] 1309 	mov	psw,#0x00
      0004D7 12 02 78         [24] 1310 	lcall	_setDdRamAddress
      0004DA 75 D0 08         [24] 1311 	mov	psw,#0x08
      0004DD D0 0F            [24] 1312 	pop	ar7
                                   1313 ;	assignment4.c:416: break;
      0004DF 02 03 C2         [24] 1314 	ljmp	00139$
                                   1315 ;	assignment4.c:419: case 3:
      0004E2                       1316 00122$:
                                   1317 ;	assignment4.c:420: if (P1 > '5') {
      0004E2 E5 90            [12] 1318 	mov	a,_P1
      0004E4 24 CA            [12] 1319 	add	a,#0xff - 0x35
      0004E6 50 03            [24] 1320 	jnc	00228$
      0004E8 02 03 C2         [24] 1321 	ljmp	00139$
      0004EB                       1322 00228$:
                                   1323 ;	assignment4.c:424: minute = (P1 - '0') * 10;
      0004EB E5 90            [12] 1324 	mov	a,_P1
      0004ED 24 D0            [12] 1325 	add	a,#0xD0
      0004EF 75 F0 0A         [24] 1326 	mov	b,#0x0A
      0004F2 A4               [48] 1327 	mul	ab
      0004F3 F5 7B            [12] 1328 	mov	_minute,a
                                   1329 ;	assignment4.c:425: sendChar(P1);
      0004F5 85 90 82         [24] 1330 	mov	dpl,_P1
      0004F8 C0 0F            [24] 1331 	push	ar7
      0004FA 75 D0 00         [24] 1332 	mov	psw,#0x00
      0004FD 12 02 88         [24] 1333 	lcall	_sendChar
      000500 75 D0 08         [24] 1334 	mov	psw,#0x08
      000503 D0 0F            [24] 1335 	pop	ar7
                                   1336 ;	assignment4.c:426: count++;
      000505 0F               [12] 1337 	inc	r7
                                   1338 ;	assignment4.c:427: sendChar('0');
      000506 75 82 30         [24] 1339 	mov	dpl,#0x30
      000509 C0 0F            [24] 1340 	push	ar7
      00050B 75 D0 00         [24] 1341 	mov	psw,#0x00
      00050E 12 02 88         [24] 1342 	lcall	_sendChar
      000511 75 D0 08         [24] 1343 	mov	psw,#0x08
      000514 D0 0F            [24] 1344 	pop	ar7
                                   1345 ;	assignment4.c:428: setDdRamAddress(count);
      000516 8F 82            [24] 1346 	mov	dpl,r7
      000518 C0 0F            [24] 1347 	push	ar7
      00051A 75 D0 00         [24] 1348 	mov	psw,#0x00
      00051D 12 02 78         [24] 1349 	lcall	_setDdRamAddress
      000520 75 D0 08         [24] 1350 	mov	psw,#0x08
      000523 D0 0F            [24] 1351 	pop	ar7
                                   1352 ;	assignment4.c:429: break;
      000525 02 03 C2         [24] 1353 	ljmp	00139$
                                   1354 ;	assignment4.c:431: case 4:
      000528                       1355 00126$:
                                   1356 ;	assignment4.c:432: minute /= 10;
      000528 75 F0 0A         [24] 1357 	mov	b,#0x0A
      00052B E5 7B            [12] 1358 	mov	a,_minute
      00052D 84               [48] 1359 	div	ab
      00052E F5 7B            [12] 1360 	mov	_minute,a
                                   1361 ;	assignment4.c:433: minute *= 10;
      000530 E5 7B            [12] 1362 	mov	a,_minute
      000532 75 F0 0A         [24] 1363 	mov	b,#0x0A
      000535 A4               [48] 1364 	mul	ab
      000536 F5 7B            [12] 1365 	mov	_minute,a
                                   1366 ;	assignment4.c:434: minute += (P1 - '0');
      000538 E5 90            [12] 1367 	mov	a,_P1
      00053A 24 D0            [12] 1368 	add	a,#0xD0
      00053C AD 7B            [24] 1369 	mov	r5,_minute
      00053E 2D               [12] 1370 	add	a,r5
      00053F F5 7B            [12] 1371 	mov	_minute,a
                                   1372 ;	assignment4.c:435: sendChar(P1);
      000541 85 90 82         [24] 1373 	mov	dpl,_P1
      000544 C0 0F            [24] 1374 	push	ar7
      000546 75 D0 00         [24] 1375 	mov	psw,#0x00
      000549 12 02 88         [24] 1376 	lcall	_sendChar
      00054C 75 D0 08         [24] 1377 	mov	psw,#0x08
      00054F D0 0F            [24] 1378 	pop	ar7
                                   1379 ;	assignment4.c:436: count += 2;
      000551 0F               [12] 1380 	inc	r7
      000552 0F               [12] 1381 	inc	r7
                                   1382 ;	assignment4.c:437: setDdRamAddress(count);
      000553 8F 82            [24] 1383 	mov	dpl,r7
      000555 C0 0F            [24] 1384 	push	ar7
      000557 75 D0 00         [24] 1385 	mov	psw,#0x00
      00055A 12 02 78         [24] 1386 	lcall	_setDdRamAddress
      00055D 75 D0 08         [24] 1387 	mov	psw,#0x08
      000560 D0 0F            [24] 1388 	pop	ar7
                                   1389 ;	assignment4.c:438: break;
      000562 02 03 C2         [24] 1390 	ljmp	00139$
                                   1391 ;	assignment4.c:440: case 6:
      000565                       1392 00127$:
                                   1393 ;	assignment4.c:441: if (P1 > '5') {
      000565 E5 90            [12] 1394 	mov	a,_P1
      000567 24 CA            [12] 1395 	add	a,#0xff - 0x35
      000569 50 03            [24] 1396 	jnc	00229$
      00056B 02 03 C2         [24] 1397 	ljmp	00139$
      00056E                       1398 00229$:
                                   1399 ;	assignment4.c:445: second = (P1 - '0') * 10;
      00056E E5 90            [12] 1400 	mov	a,_P1
      000570 24 D0            [12] 1401 	add	a,#0xD0
      000572 75 F0 0A         [24] 1402 	mov	b,#0x0A
      000575 A4               [48] 1403 	mul	ab
      000576 F5 7C            [12] 1404 	mov	_second,a
                                   1405 ;	assignment4.c:446: sendChar(P1);
      000578 85 90 82         [24] 1406 	mov	dpl,_P1
      00057B C0 0F            [24] 1407 	push	ar7
      00057D 75 D0 00         [24] 1408 	mov	psw,#0x00
      000580 12 02 88         [24] 1409 	lcall	_sendChar
      000583 75 D0 08         [24] 1410 	mov	psw,#0x08
      000586 D0 0F            [24] 1411 	pop	ar7
                                   1412 ;	assignment4.c:447: count++;
      000588 0F               [12] 1413 	inc	r7
                                   1414 ;	assignment4.c:448: sendChar('0');
      000589 75 82 30         [24] 1415 	mov	dpl,#0x30
      00058C C0 0F            [24] 1416 	push	ar7
      00058E 75 D0 00         [24] 1417 	mov	psw,#0x00
      000591 12 02 88         [24] 1418 	lcall	_sendChar
      000594 75 D0 08         [24] 1419 	mov	psw,#0x08
      000597 D0 0F            [24] 1420 	pop	ar7
                                   1421 ;	assignment4.c:449: setDdRamAddress(count);
      000599 8F 82            [24] 1422 	mov	dpl,r7
      00059B C0 0F            [24] 1423 	push	ar7
      00059D 75 D0 00         [24] 1424 	mov	psw,#0x00
      0005A0 12 02 78         [24] 1425 	lcall	_setDdRamAddress
      0005A3 75 D0 08         [24] 1426 	mov	psw,#0x08
      0005A6 D0 0F            [24] 1427 	pop	ar7
                                   1428 ;	assignment4.c:450: break;
      0005A8 02 03 C2         [24] 1429 	ljmp	00139$
                                   1430 ;	assignment4.c:452: case 7:
      0005AB                       1431 00131$:
                                   1432 ;	assignment4.c:453: second /= 10;
      0005AB 75 F0 0A         [24] 1433 	mov	b,#0x0A
      0005AE E5 7C            [12] 1434 	mov	a,_second
      0005B0 84               [48] 1435 	div	ab
      0005B1 F5 7C            [12] 1436 	mov	_second,a
                                   1437 ;	assignment4.c:454: second *= 10;
      0005B3 E5 7C            [12] 1438 	mov	a,_second
      0005B5 75 F0 0A         [24] 1439 	mov	b,#0x0A
      0005B8 A4               [48] 1440 	mul	ab
      0005B9 F5 7C            [12] 1441 	mov	_second,a
                                   1442 ;	assignment4.c:455: second += (P1 - '0');
      0005BB E5 90            [12] 1443 	mov	a,_P1
      0005BD 24 D0            [12] 1444 	add	a,#0xD0
      0005BF AD 7C            [24] 1445 	mov	r5,_second
      0005C1 2D               [12] 1446 	add	a,r5
      0005C2 F5 7C            [12] 1447 	mov	_second,a
                                   1448 ;	assignment4.c:456: sendChar(P1);
      0005C4 85 90 82         [24] 1449 	mov	dpl,_P1
      0005C7 75 D0 00         [24] 1450 	mov	psw,#0x00
      0005CA 12 02 88         [24] 1451 	lcall	_sendChar
      0005CD 75 D0 08         [24] 1452 	mov	psw,#0x08
                                   1453 ;	assignment4.c:457: count = 0;
      0005D0 7F 00            [12] 1454 	mov	r7,#0x00
                                   1455 ;	assignment4.c:458: setDdRamAddress(count);
      0005D2 75 82 00         [24] 1456 	mov	dpl,#0x00
      0005D5 C0 0F            [24] 1457 	push	ar7
      0005D7 75 D0 00         [24] 1458 	mov	psw,#0x00
      0005DA 12 02 78         [24] 1459 	lcall	_setDdRamAddress
      0005DD 75 D0 08         [24] 1460 	mov	psw,#0x08
      0005E0 D0 0F            [24] 1461 	pop	ar7
                                   1462 ;	assignment4.c:460: }
      0005E2 02 03 C2         [24] 1463 	ljmp	00139$
      0005E5                       1464 00142$:
      0005E5 D0 D0            [24] 1465 	pop	psw
      0005E7 D0 00            [24] 1466 	pop	(0+0)
      0005E9 D0 01            [24] 1467 	pop	(0+1)
      0005EB D0 02            [24] 1468 	pop	(0+2)
      0005ED D0 03            [24] 1469 	pop	(0+3)
      0005EF D0 04            [24] 1470 	pop	(0+4)
      0005F1 D0 05            [24] 1471 	pop	(0+5)
      0005F3 D0 06            [24] 1472 	pop	(0+6)
      0005F5 D0 07            [24] 1473 	pop	(0+7)
      0005F7 D0 83            [24] 1474 	pop	dph
      0005F9 D0 82            [24] 1475 	pop	dpl
      0005FB D0 F0            [24] 1476 	pop	b
      0005FD D0 E0            [24] 1477 	pop	acc
      0005FF D0 21            [24] 1478 	pop	bits
      000601 32               [24] 1479 	reti
                                   1480 ;------------------------------------------------------------
                                   1481 ;Allocation info for local variables in function 'int1_isr'
                                   1482 ;------------------------------------------------------------
                                   1483 ;count                     Allocated to registers r7 
                                   1484 ;------------------------------------------------------------
                                   1485 ;	assignment4.c:468: void int1_isr(void) __interrupt(2) __using(1) {
                                   1486 ;	-----------------------------------------
                                   1487 ;	 function int1_isr
                                   1488 ;	-----------------------------------------
      000602                       1489 _int1_isr:
      000602 C0 21            [24] 1490 	push	bits
      000604 C0 E0            [24] 1491 	push	acc
      000606 C0 F0            [24] 1492 	push	b
      000608 C0 82            [24] 1493 	push	dpl
      00060A C0 83            [24] 1494 	push	dph
      00060C C0 07            [24] 1495 	push	(0+7)
      00060E C0 06            [24] 1496 	push	(0+6)
      000610 C0 05            [24] 1497 	push	(0+5)
      000612 C0 04            [24] 1498 	push	(0+4)
      000614 C0 03            [24] 1499 	push	(0+3)
      000616 C0 02            [24] 1500 	push	(0+2)
      000618 C0 01            [24] 1501 	push	(0+1)
      00061A C0 00            [24] 1502 	push	(0+0)
      00061C C0 D0            [24] 1503 	push	psw
      00061E 75 D0 08         [24] 1504 	mov	psw,#0x08
                                   1505 ;	assignment4.c:470: char count = 0x40;
      000621 7F 40            [12] 1506 	mov	r7,#0x40
                                   1507 ;	assignment4.c:472: setDdRamAddress(count);
      000623 75 82 40         [24] 1508 	mov	dpl,#0x40
      000626 C0 0F            [24] 1509 	push	ar7
      000628 75 D0 00         [24] 1510 	mov	psw,#0x00
      00062B 12 02 78         [24] 1511 	lcall	_setDdRamAddress
      00062E 75 D0 08         [24] 1512 	mov	psw,#0x08
      000631 D0 0F            [24] 1513 	pop	ar7
                                   1514 ;	assignment4.c:474: while (SW1 == 0) {
      000633                       1515 00171$:
      000633 30 B3 03         [24] 1516 	jnb	_P3_3,00287$
      000636 02 09 E5         [24] 1517 	ljmp	00174$
      000639                       1518 00287$:
                                   1519 ;	assignment4.c:477: keypad();
      000639 C0 0F            [24] 1520 	push	ar7
      00063B 75 D0 00         [24] 1521 	mov	psw,#0x00
      00063E 12 02 D5         [24] 1522 	lcall	_keypad
      000641 75 D0 08         [24] 1523 	mov	psw,#0x08
      000644 D0 0F            [24] 1524 	pop	ar7
                                   1525 ;	assignment4.c:482: if (P1 == '*') {
      000646 74 2A            [12] 1526 	mov	a,#0x2A
      000648 B5 90 26         [24] 1527 	cjne	a,_P1,00169$
                                   1528 ;	assignment4.c:483: count--;
      00064B 1F               [12] 1529 	dec	r7
                                   1530 ;	assignment4.c:484: if (count < 0x40) {
      00064C C3               [12] 1531 	clr	c
      00064D EF               [12] 1532 	mov	a,r7
      00064E 64 80            [12] 1533 	xrl	a,#0x80
      000650 94 C0            [12] 1534 	subb	a,#0xc0
      000652 50 02            [24] 1535 	jnc	00102$
                                   1536 ;	assignment4.c:485: count = 0x47;
      000654 7F 47            [12] 1537 	mov	r7,#0x47
      000656                       1538 00102$:
                                   1539 ;	assignment4.c:487: if (count == 0x42) {
      000656 BF 42 02         [24] 1540 	cjne	r7,#0x42,00104$
                                   1541 ;	assignment4.c:488: count = 0x41;
      000659 7F 41            [12] 1542 	mov	r7,#0x41
      00065B                       1543 00104$:
                                   1544 ;	assignment4.c:490: if (count == 0x45) {
      00065B BF 45 02         [24] 1545 	cjne	r7,#0x45,00106$
                                   1546 ;	assignment4.c:491: count = 0x44;
      00065E 7F 44            [12] 1547 	mov	r7,#0x44
      000660                       1548 00106$:
                                   1549 ;	assignment4.c:493: setDdRamAddress(count);
      000660 8F 82            [24] 1550 	mov	dpl,r7
      000662 C0 0F            [24] 1551 	push	ar7
      000664 75 D0 00         [24] 1552 	mov	psw,#0x00
      000667 12 02 78         [24] 1553 	lcall	_setDdRamAddress
      00066A 75 D0 08         [24] 1554 	mov	psw,#0x08
      00066D D0 0F            [24] 1555 	pop	ar7
      00066F 80 C2            [24] 1556 	sjmp	00171$
      000671                       1557 00169$:
                                   1558 ;	assignment4.c:496: else if (P1 == '#') {
      000671 74 23            [12] 1559 	mov	a,#0x23
      000673 B5 90 2A         [24] 1560 	cjne	a,_P1,00166$
                                   1561 ;	assignment4.c:497: count++;
      000676 0F               [12] 1562 	inc	r7
                                   1563 ;	assignment4.c:498: if (count > 0x47) {
      000677 C3               [12] 1564 	clr	c
      000678 74 C7            [12] 1565 	mov	a,#(0x47 ^ 0x80)
      00067A 8F F0            [24] 1566 	mov	b,r7
      00067C 63 F0 80         [24] 1567 	xrl	b,#0x80
      00067F 95 F0            [12] 1568 	subb	a,b
      000681 50 02            [24] 1569 	jnc	00108$
                                   1570 ;	assignment4.c:499: count = 0x40;
      000683 7F 40            [12] 1571 	mov	r7,#0x40
      000685                       1572 00108$:
                                   1573 ;	assignment4.c:501: if (count == 0x42) {
      000685 BF 42 02         [24] 1574 	cjne	r7,#0x42,00110$
                                   1575 ;	assignment4.c:502: count = 0x43;
      000688 7F 43            [12] 1576 	mov	r7,#0x43
      00068A                       1577 00110$:
                                   1578 ;	assignment4.c:504: if (count == 0x45) {
      00068A BF 45 02         [24] 1579 	cjne	r7,#0x45,00112$
                                   1580 ;	assignment4.c:505: count = 0x46;
      00068D 7F 46            [12] 1581 	mov	r7,#0x46
      00068F                       1582 00112$:
                                   1583 ;	assignment4.c:507: setDdRamAddress(count);
      00068F 8F 82            [24] 1584 	mov	dpl,r7
      000691 C0 0F            [24] 1585 	push	ar7
      000693 75 D0 00         [24] 1586 	mov	psw,#0x00
      000696 12 02 78         [24] 1587 	lcall	_setDdRamAddress
      000699 75 D0 08         [24] 1588 	mov	psw,#0x08
      00069C D0 0F            [24] 1589 	pop	ar7
      00069E 80 93            [24] 1590 	sjmp	00171$
      0006A0                       1591 00166$:
                                   1592 ;	assignment4.c:511: switch (count) {
      0006A0 BF 40 02         [24] 1593 	cjne	r7,#0x40,00302$
      0006A3 80 21            [24] 1594 	sjmp	00113$
      0006A5                       1595 00302$:
      0006A5 BF 41 03         [24] 1596 	cjne	r7,#0x41,00303$
      0006A8 02 07 95         [24] 1597 	ljmp	00119$
      0006AB                       1598 00303$:
      0006AB BF 43 03         [24] 1599 	cjne	r7,#0x43,00304$
      0006AE 02 08 1A         [24] 1600 	ljmp	00127$
      0006B1                       1601 00304$:
      0006B1 BF 44 03         [24] 1602 	cjne	r7,#0x44,00305$
      0006B4 02 08 A9         [24] 1603 	ljmp	00136$
      0006B7                       1604 00305$:
      0006B7 BF 46 03         [24] 1605 	cjne	r7,#0x46,00306$
      0006BA 02 09 6E         [24] 1606 	ljmp	00162$
      0006BD                       1607 00306$:
      0006BD BF 47 03         [24] 1608 	cjne	r7,#0x47,00307$
      0006C0 02 09 AB         [24] 1609 	ljmp	00163$
      0006C3                       1610 00307$:
      0006C3 02 06 33         [24] 1611 	ljmp	00171$
                                   1612 ;	assignment4.c:513: case 0x40:
      0006C6                       1613 00113$:
                                   1614 ;	assignment4.c:514: if (P1 > '1') {
      0006C6 E5 90            [12] 1615 	mov	a,_P1
      0006C8 24 CE            [12] 1616 	add	a,#0xff - 0x31
      0006CA 50 03            [24] 1617 	jnc	00308$
      0006CC 02 06 33         [24] 1618 	ljmp	00171$
      0006CF                       1619 00308$:
                                   1620 ;	assignment4.c:517: if (P1 == '0') {
      0006CF 74 30            [12] 1621 	mov	a,#0x30
      0006D1 B5 90 5D         [24] 1622 	cjne	a,_P1,00117$
                                   1623 ;	assignment4.c:518: month = 1;
      0006D4 75 7D 01         [24] 1624 	mov	_month,#0x01
                                   1625 ;	assignment4.c:519: sendChar(P1);
      0006D7 85 90 82         [24] 1626 	mov	dpl,_P1
      0006DA C0 0F            [24] 1627 	push	ar7
      0006DC 75 D0 00         [24] 1628 	mov	psw,#0x00
      0006DF 12 02 88         [24] 1629 	lcall	_sendChar
      0006E2 75 D0 08         [24] 1630 	mov	psw,#0x08
      0006E5 D0 0F            [24] 1631 	pop	ar7
                                   1632 ;	assignment4.c:520: count++;
      0006E7 0F               [12] 1633 	inc	r7
                                   1634 ;	assignment4.c:521: sendChar('1');
      0006E8 75 82 31         [24] 1635 	mov	dpl,#0x31
      0006EB C0 0F            [24] 1636 	push	ar7
      0006ED 75 D0 00         [24] 1637 	mov	psw,#0x00
      0006F0 12 02 88         [24] 1638 	lcall	_sendChar
      0006F3 75 D0 08         [24] 1639 	mov	psw,#0x08
                                   1640 ;	assignment4.c:523: setDdRamAddress(0x43);
      0006F6 75 82 43         [24] 1641 	mov	dpl,#0x43
      0006F9 75 D0 00         [24] 1642 	mov	psw,#0x00
      0006FC 12 02 78         [24] 1643 	lcall	_setDdRamAddress
      0006FF 75 D0 08         [24] 1644 	mov	psw,#0x08
                                   1645 ;	assignment4.c:524: sendChar('0');
      000702 75 82 30         [24] 1646 	mov	dpl,#0x30
      000705 75 D0 00         [24] 1647 	mov	psw,#0x00
      000708 12 02 88         [24] 1648 	lcall	_sendChar
      00070B 75 D0 08         [24] 1649 	mov	psw,#0x08
                                   1650 ;	assignment4.c:525: sendChar('1');
      00070E 75 82 31         [24] 1651 	mov	dpl,#0x31
      000711 75 D0 00         [24] 1652 	mov	psw,#0x00
      000714 12 02 88         [24] 1653 	lcall	_sendChar
      000717 75 D0 08         [24] 1654 	mov	psw,#0x08
      00071A D0 0F            [24] 1655 	pop	ar7
                                   1656 ;	assignment4.c:526: day = 1;
      00071C 75 7E 01         [24] 1657 	mov	_day,#0x01
                                   1658 ;	assignment4.c:528: setDdRamAddress(count);
      00071F 8F 82            [24] 1659 	mov	dpl,r7
      000721 C0 0F            [24] 1660 	push	ar7
      000723 75 D0 00         [24] 1661 	mov	psw,#0x00
      000726 12 02 78         [24] 1662 	lcall	_setDdRamAddress
      000729 75 D0 08         [24] 1663 	mov	psw,#0x08
      00072C D0 0F            [24] 1664 	pop	ar7
                                   1665 ;	assignment4.c:529: break;				
      00072E 02 06 33         [24] 1666 	ljmp	00171$
      000731                       1667 00117$:
                                   1668 ;	assignment4.c:532: month = (P1 - '0') * 10;
      000731 E5 90            [12] 1669 	mov	a,_P1
      000733 24 D0            [12] 1670 	add	a,#0xD0
      000735 75 F0 0A         [24] 1671 	mov	b,#0x0A
      000738 A4               [48] 1672 	mul	ab
      000739 F5 7D            [12] 1673 	mov	_month,a
                                   1674 ;	assignment4.c:533: sendChar(P1);
      00073B 85 90 82         [24] 1675 	mov	dpl,_P1
      00073E C0 0F            [24] 1676 	push	ar7
      000740 75 D0 00         [24] 1677 	mov	psw,#0x00
      000743 12 02 88         [24] 1678 	lcall	_sendChar
      000746 75 D0 08         [24] 1679 	mov	psw,#0x08
      000749 D0 0F            [24] 1680 	pop	ar7
                                   1681 ;	assignment4.c:534: count++;
      00074B 0F               [12] 1682 	inc	r7
                                   1683 ;	assignment4.c:535: sendChar('0');
      00074C 75 82 30         [24] 1684 	mov	dpl,#0x30
      00074F C0 0F            [24] 1685 	push	ar7
      000751 75 D0 00         [24] 1686 	mov	psw,#0x00
      000754 12 02 88         [24] 1687 	lcall	_sendChar
      000757 75 D0 08         [24] 1688 	mov	psw,#0x08
                                   1689 ;	assignment4.c:537: setDdRamAddress(0x43);
      00075A 75 82 43         [24] 1690 	mov	dpl,#0x43
      00075D 75 D0 00         [24] 1691 	mov	psw,#0x00
      000760 12 02 78         [24] 1692 	lcall	_setDdRamAddress
      000763 75 D0 08         [24] 1693 	mov	psw,#0x08
                                   1694 ;	assignment4.c:538: sendChar('0');
      000766 75 82 30         [24] 1695 	mov	dpl,#0x30
      000769 75 D0 00         [24] 1696 	mov	psw,#0x00
      00076C 12 02 88         [24] 1697 	lcall	_sendChar
      00076F 75 D0 08         [24] 1698 	mov	psw,#0x08
                                   1699 ;	assignment4.c:539: sendChar('1');
      000772 75 82 31         [24] 1700 	mov	dpl,#0x31
      000775 75 D0 00         [24] 1701 	mov	psw,#0x00
      000778 12 02 88         [24] 1702 	lcall	_sendChar
      00077B 75 D0 08         [24] 1703 	mov	psw,#0x08
      00077E D0 0F            [24] 1704 	pop	ar7
                                   1705 ;	assignment4.c:540: day = 1;
      000780 75 7E 01         [24] 1706 	mov	_day,#0x01
                                   1707 ;	assignment4.c:542: setDdRamAddress(count);
      000783 8F 82            [24] 1708 	mov	dpl,r7
      000785 C0 0F            [24] 1709 	push	ar7
      000787 75 D0 00         [24] 1710 	mov	psw,#0x00
      00078A 12 02 78         [24] 1711 	lcall	_setDdRamAddress
      00078D 75 D0 08         [24] 1712 	mov	psw,#0x08
      000790 D0 0F            [24] 1713 	pop	ar7
                                   1714 ;	assignment4.c:543: break;
      000792 02 06 33         [24] 1715 	ljmp	00171$
                                   1716 ;	assignment4.c:546: case 0x41:
      000795                       1717 00119$:
                                   1718 ;	assignment4.c:547: if (month >= 10 && P1 > '2') {
      000795 74 F6            [12] 1719 	mov	a,#0x100 - 0x0A
      000797 25 7D            [12] 1720 	add	a,_month
      000799 50 09            [24] 1721 	jnc	00121$
      00079B E5 90            [12] 1722 	mov	a,_P1
      00079D 24 CD            [12] 1723 	add	a,#0xff - 0x32
      00079F 50 03            [24] 1724 	jnc	00312$
      0007A1 02 06 33         [24] 1725 	ljmp	00171$
      0007A4                       1726 00312$:
                                   1727 ;	assignment4.c:548: break;
      0007A4                       1728 00121$:
                                   1729 ;	assignment4.c:550: if (P1 == '0' && month < 10) {
      0007A4 74 30            [12] 1730 	mov	a,#0x30
      0007A6 B5 90 09         [24] 1731 	cjne	a,_P1,00124$
      0007A9 74 F6            [12] 1732 	mov	a,#0x100 - 0x0A
      0007AB 25 7D            [12] 1733 	add	a,_month
      0007AD 40 03            [24] 1734 	jc	00315$
      0007AF 02 06 33         [24] 1735 	ljmp	00171$
      0007B2                       1736 00315$:
                                   1737 ;	assignment4.c:551: break;
      0007B2                       1738 00124$:
                                   1739 ;	assignment4.c:554: month /= 10;
      0007B2 75 F0 0A         [24] 1740 	mov	b,#0x0A
      0007B5 E5 7D            [12] 1741 	mov	a,_month
      0007B7 84               [48] 1742 	div	ab
      0007B8 F5 7D            [12] 1743 	mov	_month,a
                                   1744 ;	assignment4.c:555: month *= 10;
      0007BA E5 7D            [12] 1745 	mov	a,_month
      0007BC 75 F0 0A         [24] 1746 	mov	b,#0x0A
      0007BF A4               [48] 1747 	mul	ab
      0007C0 F5 7D            [12] 1748 	mov	_month,a
                                   1749 ;	assignment4.c:556: month += (P1 - '0');
      0007C2 E5 90            [12] 1750 	mov	a,_P1
      0007C4 24 D0            [12] 1751 	add	a,#0xD0
      0007C6 AD 7D            [24] 1752 	mov	r5,_month
      0007C8 2D               [12] 1753 	add	a,r5
      0007C9 F5 7D            [12] 1754 	mov	_month,a
                                   1755 ;	assignment4.c:557: sendChar(P1);
      0007CB 85 90 82         [24] 1756 	mov	dpl,_P1
      0007CE C0 0F            [24] 1757 	push	ar7
      0007D0 75 D0 00         [24] 1758 	mov	psw,#0x00
      0007D3 12 02 88         [24] 1759 	lcall	_sendChar
      0007D6 75 D0 08         [24] 1760 	mov	psw,#0x08
      0007D9 D0 0F            [24] 1761 	pop	ar7
                                   1762 ;	assignment4.c:558: count += 2;
      0007DB 0F               [12] 1763 	inc	r7
      0007DC 0F               [12] 1764 	inc	r7
                                   1765 ;	assignment4.c:560: setDdRamAddress(0x43);
      0007DD 75 82 43         [24] 1766 	mov	dpl,#0x43
      0007E0 C0 0F            [24] 1767 	push	ar7
      0007E2 75 D0 00         [24] 1768 	mov	psw,#0x00
      0007E5 12 02 78         [24] 1769 	lcall	_setDdRamAddress
      0007E8 75 D0 08         [24] 1770 	mov	psw,#0x08
                                   1771 ;	assignment4.c:561: sendChar('0');
      0007EB 75 82 30         [24] 1772 	mov	dpl,#0x30
      0007EE 75 D0 00         [24] 1773 	mov	psw,#0x00
      0007F1 12 02 88         [24] 1774 	lcall	_sendChar
      0007F4 75 D0 08         [24] 1775 	mov	psw,#0x08
                                   1776 ;	assignment4.c:562: sendChar('1');
      0007F7 75 82 31         [24] 1777 	mov	dpl,#0x31
      0007FA 75 D0 00         [24] 1778 	mov	psw,#0x00
      0007FD 12 02 88         [24] 1779 	lcall	_sendChar
      000800 75 D0 08         [24] 1780 	mov	psw,#0x08
      000803 D0 0F            [24] 1781 	pop	ar7
                                   1782 ;	assignment4.c:563: day = 1;
      000805 75 7E 01         [24] 1783 	mov	_day,#0x01
                                   1784 ;	assignment4.c:565: setDdRamAddress(count);
      000808 8F 82            [24] 1785 	mov	dpl,r7
      00080A C0 0F            [24] 1786 	push	ar7
      00080C 75 D0 00         [24] 1787 	mov	psw,#0x00
      00080F 12 02 78         [24] 1788 	lcall	_setDdRamAddress
      000812 75 D0 08         [24] 1789 	mov	psw,#0x08
      000815 D0 0F            [24] 1790 	pop	ar7
                                   1791 ;	assignment4.c:566: break;
      000817 02 06 33         [24] 1792 	ljmp	00171$
                                   1793 ;	assignment4.c:569: case 0x43:
      00081A                       1794 00127$:
                                   1795 ;	assignment4.c:570: if (P1 > '3') {
      00081A E5 90            [12] 1796 	mov	a,_P1
      00081C 24 CC            [12] 1797 	add	a,#0xff - 0x33
      00081E 50 03            [24] 1798 	jnc	00316$
      000820 02 06 33         [24] 1799 	ljmp	00171$
      000823                       1800 00316$:
                                   1801 ;	assignment4.c:573: if (P1 > '2' && month == 2) {
      000823 E5 90            [12] 1802 	mov	a,_P1
      000825 24 CD            [12] 1803 	add	a,#0xff - 0x32
      000827 50 08            [24] 1804 	jnc	00131$
      000829 74 02            [12] 1805 	mov	a,#0x02
      00082B B5 7D 03         [24] 1806 	cjne	a,_month,00318$
      00082E 02 06 33         [24] 1807 	ljmp	00171$
      000831                       1808 00318$:
                                   1809 ;	assignment4.c:574: break;
      000831                       1810 00131$:
                                   1811 ;	assignment4.c:576: if (P1 == '0') {
      000831 74 30            [12] 1812 	mov	a,#0x30
      000833 B5 90 36         [24] 1813 	cjne	a,_P1,00134$
                                   1814 ;	assignment4.c:577: day = 1;
      000836 75 7E 01         [24] 1815 	mov	_day,#0x01
                                   1816 ;	assignment4.c:578: sendChar(P1);
      000839 85 90 82         [24] 1817 	mov	dpl,_P1
      00083C C0 0F            [24] 1818 	push	ar7
      00083E 75 D0 00         [24] 1819 	mov	psw,#0x00
      000841 12 02 88         [24] 1820 	lcall	_sendChar
      000844 75 D0 08         [24] 1821 	mov	psw,#0x08
      000847 D0 0F            [24] 1822 	pop	ar7
                                   1823 ;	assignment4.c:579: count++;
      000849 0F               [12] 1824 	inc	r7
                                   1825 ;	assignment4.c:580: sendChar('1');
      00084A 75 82 31         [24] 1826 	mov	dpl,#0x31
      00084D C0 0F            [24] 1827 	push	ar7
      00084F 75 D0 00         [24] 1828 	mov	psw,#0x00
      000852 12 02 88         [24] 1829 	lcall	_sendChar
      000855 75 D0 08         [24] 1830 	mov	psw,#0x08
      000858 D0 0F            [24] 1831 	pop	ar7
                                   1832 ;	assignment4.c:581: setDdRamAddress(count);
      00085A 8F 82            [24] 1833 	mov	dpl,r7
      00085C C0 0F            [24] 1834 	push	ar7
      00085E 75 D0 00         [24] 1835 	mov	psw,#0x00
      000861 12 02 78         [24] 1836 	lcall	_setDdRamAddress
      000864 75 D0 08         [24] 1837 	mov	psw,#0x08
      000867 D0 0F            [24] 1838 	pop	ar7
                                   1839 ;	assignment4.c:582: break;
      000869 02 06 33         [24] 1840 	ljmp	00171$
      00086C                       1841 00134$:
                                   1842 ;	assignment4.c:585: day = (P1 - '0') * 10;
      00086C E5 90            [12] 1843 	mov	a,_P1
      00086E 24 D0            [12] 1844 	add	a,#0xD0
      000870 75 F0 0A         [24] 1845 	mov	b,#0x0A
      000873 A4               [48] 1846 	mul	ab
      000874 F5 7E            [12] 1847 	mov	_day,a
                                   1848 ;	assignment4.c:586: sendChar(P1);
      000876 85 90 82         [24] 1849 	mov	dpl,_P1
      000879 C0 0F            [24] 1850 	push	ar7
      00087B 75 D0 00         [24] 1851 	mov	psw,#0x00
      00087E 12 02 88         [24] 1852 	lcall	_sendChar
      000881 75 D0 08         [24] 1853 	mov	psw,#0x08
      000884 D0 0F            [24] 1854 	pop	ar7
                                   1855 ;	assignment4.c:587: count++;
      000886 0F               [12] 1856 	inc	r7
                                   1857 ;	assignment4.c:588: sendChar('0');
      000887 75 82 30         [24] 1858 	mov	dpl,#0x30
      00088A C0 0F            [24] 1859 	push	ar7
      00088C 75 D0 00         [24] 1860 	mov	psw,#0x00
      00088F 12 02 88         [24] 1861 	lcall	_sendChar
      000892 75 D0 08         [24] 1862 	mov	psw,#0x08
      000895 D0 0F            [24] 1863 	pop	ar7
                                   1864 ;	assignment4.c:589: setDdRamAddress(count);
      000897 8F 82            [24] 1865 	mov	dpl,r7
      000899 C0 0F            [24] 1866 	push	ar7
      00089B 75 D0 00         [24] 1867 	mov	psw,#0x00
      00089E 12 02 78         [24] 1868 	lcall	_setDdRamAddress
      0008A1 75 D0 08         [24] 1869 	mov	psw,#0x08
      0008A4 D0 0F            [24] 1870 	pop	ar7
                                   1871 ;	assignment4.c:590: break;
      0008A6 02 06 33         [24] 1872 	ljmp	00171$
                                   1873 ;	assignment4.c:593: case 0x44:
      0008A9                       1874 00136$:
                                   1875 ;	assignment4.c:594: if (day >= 30 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && P1 > '1') {
      0008A9 74 E2            [12] 1876 	mov	a,#0x100 - 0x1E
      0008AB 25 7E            [12] 1877 	add	a,_day
      0008AD 50 38            [24] 1878 	jnc	00138$
      0008AF 74 01            [12] 1879 	mov	a,#0x01
      0008B1 B5 7D 02         [24] 1880 	cjne	a,_month,00322$
      0008B4 80 28            [24] 1881 	sjmp	00146$
      0008B6                       1882 00322$:
      0008B6 74 03            [12] 1883 	mov	a,#0x03
      0008B8 B5 7D 02         [24] 1884 	cjne	a,_month,00323$
      0008BB 80 21            [24] 1885 	sjmp	00146$
      0008BD                       1886 00323$:
      0008BD 74 05            [12] 1887 	mov	a,#0x05
      0008BF B5 7D 02         [24] 1888 	cjne	a,_month,00324$
      0008C2 80 1A            [24] 1889 	sjmp	00146$
      0008C4                       1890 00324$:
      0008C4 74 07            [12] 1891 	mov	a,#0x07
      0008C6 B5 7D 02         [24] 1892 	cjne	a,_month,00325$
      0008C9 80 13            [24] 1893 	sjmp	00146$
      0008CB                       1894 00325$:
      0008CB 74 08            [12] 1895 	mov	a,#0x08
      0008CD B5 7D 02         [24] 1896 	cjne	a,_month,00326$
      0008D0 80 0C            [24] 1897 	sjmp	00146$
      0008D2                       1898 00326$:
      0008D2 74 0A            [12] 1899 	mov	a,#0x0A
      0008D4 B5 7D 02         [24] 1900 	cjne	a,_month,00327$
      0008D7 80 05            [24] 1901 	sjmp	00146$
      0008D9                       1902 00327$:
      0008D9 74 0C            [12] 1903 	mov	a,#0x0C
      0008DB B5 7D 09         [24] 1904 	cjne	a,_month,00138$
      0008DE                       1905 00146$:
      0008DE E5 90            [12] 1906 	mov	a,_P1
      0008E0 24 CE            [12] 1907 	add	a,#0xff - 0x31
      0008E2 50 03            [24] 1908 	jnc	00330$
      0008E4 02 06 33         [24] 1909 	ljmp	00171$
      0008E7                       1910 00330$:
                                   1911 ;	assignment4.c:595: break;
      0008E7                       1912 00138$:
                                   1913 ;	assignment4.c:597: if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11) && P1 > '0') {
      0008E7 74 1E            [12] 1914 	mov	a,#0x1E
      0008E9 B5 7E 23         [24] 1915 	cjne	a,_day,00148$
      0008EC 74 04            [12] 1916 	mov	a,#0x04
      0008EE B5 7D 02         [24] 1917 	cjne	a,_month,00333$
      0008F1 80 13            [24] 1918 	sjmp	00153$
      0008F3                       1919 00333$:
      0008F3 74 06            [12] 1920 	mov	a,#0x06
      0008F5 B5 7D 02         [24] 1921 	cjne	a,_month,00334$
      0008F8 80 0C            [24] 1922 	sjmp	00153$
      0008FA                       1923 00334$:
      0008FA 74 09            [12] 1924 	mov	a,#0x09
      0008FC B5 7D 02         [24] 1925 	cjne	a,_month,00335$
      0008FF 80 05            [24] 1926 	sjmp	00153$
      000901                       1927 00335$:
      000901 74 0B            [12] 1928 	mov	a,#0x0B
      000903 B5 7D 09         [24] 1929 	cjne	a,_month,00148$
      000906                       1930 00153$:
      000906 E5 90            [12] 1931 	mov	a,_P1
      000908 24 CF            [12] 1932 	add	a,#0xff - 0x30
      00090A 50 03            [24] 1933 	jnc	00338$
      00090C 02 06 33         [24] 1934 	ljmp	00171$
      00090F                       1935 00338$:
                                   1936 ;	assignment4.c:598: break;
      00090F                       1937 00148$:
                                   1938 ;	assignment4.c:600: if (day >= 20 && month == 2 && P1 > '8') {
      00090F 74 EC            [12] 1939 	mov	a,#0x100 - 0x14
      000911 25 7E            [12] 1940 	add	a,_day
      000913 50 0E            [24] 1941 	jnc	00155$
      000915 74 02            [12] 1942 	mov	a,#0x02
      000917 B5 7D 09         [24] 1943 	cjne	a,_month,00155$
      00091A E5 90            [12] 1944 	mov	a,_P1
      00091C 24 C7            [12] 1945 	add	a,#0xff - 0x38
      00091E 50 03            [24] 1946 	jnc	00342$
      000920 02 06 33         [24] 1947 	ljmp	00171$
      000923                       1948 00342$:
                                   1949 ;	assignment4.c:601: break;
      000923                       1950 00155$:
                                   1951 ;	assignment4.c:603: if (P1 == '0' && day < 10) {
      000923 74 30            [12] 1952 	mov	a,#0x30
      000925 B5 90 09         [24] 1953 	cjne	a,_P1,00159$
      000928 74 F6            [12] 1954 	mov	a,#0x100 - 0x0A
      00092A 25 7E            [12] 1955 	add	a,_day
      00092C 40 03            [24] 1956 	jc	00345$
      00092E 02 06 33         [24] 1957 	ljmp	00171$
      000931                       1958 00345$:
                                   1959 ;	assignment4.c:604: break;
      000931                       1960 00159$:
                                   1961 ;	assignment4.c:607: day /= 10;
      000931 75 F0 0A         [24] 1962 	mov	b,#0x0A
      000934 E5 7E            [12] 1963 	mov	a,_day
      000936 84               [48] 1964 	div	ab
      000937 F5 7E            [12] 1965 	mov	_day,a
                                   1966 ;	assignment4.c:608: day *= 10;
      000939 E5 7E            [12] 1967 	mov	a,_day
      00093B 75 F0 0A         [24] 1968 	mov	b,#0x0A
      00093E A4               [48] 1969 	mul	ab
      00093F F5 7E            [12] 1970 	mov	_day,a
                                   1971 ;	assignment4.c:609: day += (P1 - '0');
      000941 E5 90            [12] 1972 	mov	a,_P1
      000943 24 D0            [12] 1973 	add	a,#0xD0
      000945 AD 7E            [24] 1974 	mov	r5,_day
      000947 2D               [12] 1975 	add	a,r5
      000948 F5 7E            [12] 1976 	mov	_day,a
                                   1977 ;	assignment4.c:610: sendChar(P1);
      00094A 85 90 82         [24] 1978 	mov	dpl,_P1
      00094D C0 0F            [24] 1979 	push	ar7
      00094F 75 D0 00         [24] 1980 	mov	psw,#0x00
      000952 12 02 88         [24] 1981 	lcall	_sendChar
      000955 75 D0 08         [24] 1982 	mov	psw,#0x08
      000958 D0 0F            [24] 1983 	pop	ar7
                                   1984 ;	assignment4.c:611: count += 2;
      00095A 0F               [12] 1985 	inc	r7
      00095B 0F               [12] 1986 	inc	r7
                                   1987 ;	assignment4.c:612: setDdRamAddress(count);
      00095C 8F 82            [24] 1988 	mov	dpl,r7
      00095E C0 0F            [24] 1989 	push	ar7
      000960 75 D0 00         [24] 1990 	mov	psw,#0x00
      000963 12 02 78         [24] 1991 	lcall	_setDdRamAddress
      000966 75 D0 08         [24] 1992 	mov	psw,#0x08
      000969 D0 0F            [24] 1993 	pop	ar7
                                   1994 ;	assignment4.c:613: break;
      00096B 02 06 33         [24] 1995 	ljmp	00171$
                                   1996 ;	assignment4.c:617: case 0x46:
      00096E                       1997 00162$:
                                   1998 ;	assignment4.c:618: year = (P1 - '0') * 10;
      00096E E5 90            [12] 1999 	mov	a,_P1
      000970 24 D0            [12] 2000 	add	a,#0xD0
      000972 75 F0 0A         [24] 2001 	mov	b,#0x0A
      000975 A4               [48] 2002 	mul	ab
      000976 F5 7F            [12] 2003 	mov	_year,a
                                   2004 ;	assignment4.c:619: sendChar(P1);
      000978 85 90 82         [24] 2005 	mov	dpl,_P1
      00097B C0 0F            [24] 2006 	push	ar7
      00097D 75 D0 00         [24] 2007 	mov	psw,#0x00
      000980 12 02 88         [24] 2008 	lcall	_sendChar
      000983 75 D0 08         [24] 2009 	mov	psw,#0x08
      000986 D0 0F            [24] 2010 	pop	ar7
                                   2011 ;	assignment4.c:620: count++;
      000988 0F               [12] 2012 	inc	r7
                                   2013 ;	assignment4.c:621: sendChar('0');
      000989 75 82 30         [24] 2014 	mov	dpl,#0x30
      00098C C0 0F            [24] 2015 	push	ar7
      00098E 75 D0 00         [24] 2016 	mov	psw,#0x00
      000991 12 02 88         [24] 2017 	lcall	_sendChar
      000994 75 D0 08         [24] 2018 	mov	psw,#0x08
      000997 D0 0F            [24] 2019 	pop	ar7
                                   2020 ;	assignment4.c:622: setDdRamAddress(count);
      000999 8F 82            [24] 2021 	mov	dpl,r7
      00099B C0 0F            [24] 2022 	push	ar7
      00099D 75 D0 00         [24] 2023 	mov	psw,#0x00
      0009A0 12 02 78         [24] 2024 	lcall	_setDdRamAddress
      0009A3 75 D0 08         [24] 2025 	mov	psw,#0x08
      0009A6 D0 0F            [24] 2026 	pop	ar7
                                   2027 ;	assignment4.c:623: break;
      0009A8 02 06 33         [24] 2028 	ljmp	00171$
                                   2029 ;	assignment4.c:625: case 0x47:
      0009AB                       2030 00163$:
                                   2031 ;	assignment4.c:626: year /= 10;
      0009AB 75 F0 0A         [24] 2032 	mov	b,#0x0A
      0009AE E5 7F            [12] 2033 	mov	a,_year
      0009B0 84               [48] 2034 	div	ab
      0009B1 F5 7F            [12] 2035 	mov	_year,a
                                   2036 ;	assignment4.c:627: year *= 10;
      0009B3 E5 7F            [12] 2037 	mov	a,_year
      0009B5 75 F0 0A         [24] 2038 	mov	b,#0x0A
      0009B8 A4               [48] 2039 	mul	ab
      0009B9 F5 7F            [12] 2040 	mov	_year,a
                                   2041 ;	assignment4.c:628: year += (P1 - '0');
      0009BB E5 90            [12] 2042 	mov	a,_P1
      0009BD 24 D0            [12] 2043 	add	a,#0xD0
      0009BF AD 7F            [24] 2044 	mov	r5,_year
      0009C1 2D               [12] 2045 	add	a,r5
      0009C2 F5 7F            [12] 2046 	mov	_year,a
                                   2047 ;	assignment4.c:629: sendChar(P1);
      0009C4 85 90 82         [24] 2048 	mov	dpl,_P1
      0009C7 75 D0 00         [24] 2049 	mov	psw,#0x00
      0009CA 12 02 88         [24] 2050 	lcall	_sendChar
      0009CD 75 D0 08         [24] 2051 	mov	psw,#0x08
                                   2052 ;	assignment4.c:630: count = 0x40;
      0009D0 7F 40            [12] 2053 	mov	r7,#0x40
                                   2054 ;	assignment4.c:631: setDdRamAddress(count);
      0009D2 75 82 40         [24] 2055 	mov	dpl,#0x40
      0009D5 C0 0F            [24] 2056 	push	ar7
      0009D7 75 D0 00         [24] 2057 	mov	psw,#0x00
      0009DA 12 02 78         [24] 2058 	lcall	_setDdRamAddress
      0009DD 75 D0 08         [24] 2059 	mov	psw,#0x08
      0009E0 D0 0F            [24] 2060 	pop	ar7
                                   2061 ;	assignment4.c:633: }
      0009E2 02 06 33         [24] 2062 	ljmp	00171$
      0009E5                       2063 00174$:
      0009E5 D0 D0            [24] 2064 	pop	psw
      0009E7 D0 00            [24] 2065 	pop	(0+0)
      0009E9 D0 01            [24] 2066 	pop	(0+1)
      0009EB D0 02            [24] 2067 	pop	(0+2)
      0009ED D0 03            [24] 2068 	pop	(0+3)
      0009EF D0 04            [24] 2069 	pop	(0+4)
      0009F1 D0 05            [24] 2070 	pop	(0+5)
      0009F3 D0 06            [24] 2071 	pop	(0+6)
      0009F5 D0 07            [24] 2072 	pop	(0+7)
      0009F7 D0 83            [24] 2073 	pop	dph
      0009F9 D0 82            [24] 2074 	pop	dpl
      0009FB D0 F0            [24] 2075 	pop	b
      0009FD D0 E0            [24] 2076 	pop	acc
      0009FF D0 21            [24] 2077 	pop	bits
      000A01 32               [24] 2078 	reti
                                   2079 	.area CSEG    (CODE)
                                   2080 	.area CONST   (CODE)
      000A39                       2081 ___str_0:
      000A39 30 30 3A 30 30 3A 30  2082 	.ascii "00:00:00"
             30
      000A41 00                    2083 	.db 0x00
      000A42                       2084 ___str_1:
      000A42 30 31 2D 30 31 2D 30  2085 	.ascii "01-01-00"
             30
      000A4A 00                    2086 	.db 0x00
                                   2087 	.area XINIT   (CODE)
                                   2088 	.area CABS    (ABS,CODE)
