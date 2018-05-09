                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Jun 20 2015) (MINGW64)
                                      4 ; This file was generated Sat Apr 30 00:33:42 2016
                                      5 ;--------------------------------------------------------
                                      6 	.module assignment3
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _Main
                                     13 	.globl _CY
                                     14 	.globl _AC
                                     15 	.globl _F0
                                     16 	.globl _RS1
                                     17 	.globl _RS0
                                     18 	.globl _OV
                                     19 	.globl _F1
                                     20 	.globl _P
                                     21 	.globl _PS
                                     22 	.globl _PT1
                                     23 	.globl _PX1
                                     24 	.globl _PT0
                                     25 	.globl _PX0
                                     26 	.globl _RD
                                     27 	.globl _WR
                                     28 	.globl _T1
                                     29 	.globl _T0
                                     30 	.globl _INT1
                                     31 	.globl _INT0
                                     32 	.globl _TXD
                                     33 	.globl _RXD
                                     34 	.globl _P3_7
                                     35 	.globl _P3_6
                                     36 	.globl _P3_5
                                     37 	.globl _P3_4
                                     38 	.globl _P3_3
                                     39 	.globl _P3_2
                                     40 	.globl _P3_1
                                     41 	.globl _P3_0
                                     42 	.globl _EA
                                     43 	.globl _ES
                                     44 	.globl _ET1
                                     45 	.globl _EX1
                                     46 	.globl _ET0
                                     47 	.globl _EX0
                                     48 	.globl _P2_7
                                     49 	.globl _P2_6
                                     50 	.globl _P2_5
                                     51 	.globl _P2_4
                                     52 	.globl _P2_3
                                     53 	.globl _P2_2
                                     54 	.globl _P2_1
                                     55 	.globl _P2_0
                                     56 	.globl _SM0
                                     57 	.globl _SM1
                                     58 	.globl _SM2
                                     59 	.globl _REN
                                     60 	.globl _TB8
                                     61 	.globl _RB8
                                     62 	.globl _TI
                                     63 	.globl _RI
                                     64 	.globl _P1_7
                                     65 	.globl _P1_6
                                     66 	.globl _P1_5
                                     67 	.globl _P1_4
                                     68 	.globl _P1_3
                                     69 	.globl _P1_2
                                     70 	.globl _P1_1
                                     71 	.globl _P1_0
                                     72 	.globl _TF1
                                     73 	.globl _TR1
                                     74 	.globl _TF0
                                     75 	.globl _TR0
                                     76 	.globl _IE1
                                     77 	.globl _IT1
                                     78 	.globl _IE0
                                     79 	.globl _IT0
                                     80 	.globl _P0_7
                                     81 	.globl _P0_6
                                     82 	.globl _P0_5
                                     83 	.globl _P0_4
                                     84 	.globl _P0_3
                                     85 	.globl _P0_2
                                     86 	.globl _P0_1
                                     87 	.globl _P0_0
                                     88 	.globl _B
                                     89 	.globl _ACC
                                     90 	.globl _PSW
                                     91 	.globl _IP
                                     92 	.globl _P3
                                     93 	.globl _IE
                                     94 	.globl _P2
                                     95 	.globl _SBUF
                                     96 	.globl _SCON
                                     97 	.globl _P1
                                     98 	.globl _TH1
                                     99 	.globl _TH0
                                    100 	.globl _TL1
                                    101 	.globl _TL0
                                    102 	.globl _TMOD
                                    103 	.globl _TCON
                                    104 	.globl _PCON
                                    105 	.globl _DPH
                                    106 	.globl _DPL
                                    107 	.globl _SP
                                    108 	.globl _P0
                                    109 	.globl _cursorOrDisplayShift_PARM_2
                                    110 	.globl _cursorOrDisplayShift_PARM_1
                                    111 	.globl _displayOnOffControl_PARM_3
                                    112 	.globl _displayOnOffControl_PARM_2
                                    113 	.globl _displayOnOffControl_PARM_1
                                    114 	.globl _returnHome
                                    115 	.globl _entryModeSet
                                    116 	.globl _displayOnOffControl
                                    117 	.globl _cursorOrDisplayShift
                                    118 	.globl _functionSet
                                    119 	.globl _clearDisplay
                                    120 	.globl _setDdRamAddress
                                    121 	.globl _sendChar
                                    122 	.globl _sendString
                                    123 	.globl _delay
                                    124 	.globl _big_delay
                                    125 	.globl _keypad
                                    126 ;--------------------------------------------------------
                                    127 ; special function registers
                                    128 ;--------------------------------------------------------
                                    129 	.area RSEG    (ABS,DATA)
      000000                        130 	.org 0x0000
                           000080   131 _P0	=	0x0080
                           000081   132 _SP	=	0x0081
                           000082   133 _DPL	=	0x0082
                           000083   134 _DPH	=	0x0083
                           000087   135 _PCON	=	0x0087
                           000088   136 _TCON	=	0x0088
                           000089   137 _TMOD	=	0x0089
                           00008A   138 _TL0	=	0x008a
                           00008B   139 _TL1	=	0x008b
                           00008C   140 _TH0	=	0x008c
                           00008D   141 _TH1	=	0x008d
                           000090   142 _P1	=	0x0090
                           000098   143 _SCON	=	0x0098
                           000099   144 _SBUF	=	0x0099
                           0000A0   145 _P2	=	0x00a0
                           0000A8   146 _IE	=	0x00a8
                           0000B0   147 _P3	=	0x00b0
                           0000B8   148 _IP	=	0x00b8
                           0000D0   149 _PSW	=	0x00d0
                           0000E0   150 _ACC	=	0x00e0
                           0000F0   151 _B	=	0x00f0
                                    152 ;--------------------------------------------------------
                                    153 ; special function bits
                                    154 ;--------------------------------------------------------
                                    155 	.area RSEG    (ABS,DATA)
      000000                        156 	.org 0x0000
                           000080   157 _P0_0	=	0x0080
                           000081   158 _P0_1	=	0x0081
                           000082   159 _P0_2	=	0x0082
                           000083   160 _P0_3	=	0x0083
                           000084   161 _P0_4	=	0x0084
                           000085   162 _P0_5	=	0x0085
                           000086   163 _P0_6	=	0x0086
                           000087   164 _P0_7	=	0x0087
                           000088   165 _IT0	=	0x0088
                           000089   166 _IE0	=	0x0089
                           00008A   167 _IT1	=	0x008a
                           00008B   168 _IE1	=	0x008b
                           00008C   169 _TR0	=	0x008c
                           00008D   170 _TF0	=	0x008d
                           00008E   171 _TR1	=	0x008e
                           00008F   172 _TF1	=	0x008f
                           000090   173 _P1_0	=	0x0090
                           000091   174 _P1_1	=	0x0091
                           000092   175 _P1_2	=	0x0092
                           000093   176 _P1_3	=	0x0093
                           000094   177 _P1_4	=	0x0094
                           000095   178 _P1_5	=	0x0095
                           000096   179 _P1_6	=	0x0096
                           000097   180 _P1_7	=	0x0097
                           000098   181 _RI	=	0x0098
                           000099   182 _TI	=	0x0099
                           00009A   183 _RB8	=	0x009a
                           00009B   184 _TB8	=	0x009b
                           00009C   185 _REN	=	0x009c
                           00009D   186 _SM2	=	0x009d
                           00009E   187 _SM1	=	0x009e
                           00009F   188 _SM0	=	0x009f
                           0000A0   189 _P2_0	=	0x00a0
                           0000A1   190 _P2_1	=	0x00a1
                           0000A2   191 _P2_2	=	0x00a2
                           0000A3   192 _P2_3	=	0x00a3
                           0000A4   193 _P2_4	=	0x00a4
                           0000A5   194 _P2_5	=	0x00a5
                           0000A6   195 _P2_6	=	0x00a6
                           0000A7   196 _P2_7	=	0x00a7
                           0000A8   197 _EX0	=	0x00a8
                           0000A9   198 _ET0	=	0x00a9
                           0000AA   199 _EX1	=	0x00aa
                           0000AB   200 _ET1	=	0x00ab
                           0000AC   201 _ES	=	0x00ac
                           0000AF   202 _EA	=	0x00af
                           0000B0   203 _P3_0	=	0x00b0
                           0000B1   204 _P3_1	=	0x00b1
                           0000B2   205 _P3_2	=	0x00b2
                           0000B3   206 _P3_3	=	0x00b3
                           0000B4   207 _P3_4	=	0x00b4
                           0000B5   208 _P3_5	=	0x00b5
                           0000B6   209 _P3_6	=	0x00b6
                           0000B7   210 _P3_7	=	0x00b7
                           0000B0   211 _RXD	=	0x00b0
                           0000B1   212 _TXD	=	0x00b1
                           0000B2   213 _INT0	=	0x00b2
                           0000B3   214 _INT1	=	0x00b3
                           0000B4   215 _T0	=	0x00b4
                           0000B5   216 _T1	=	0x00b5
                           0000B6   217 _WR	=	0x00b6
                           0000B7   218 _RD	=	0x00b7
                           0000B8   219 _PX0	=	0x00b8
                           0000B9   220 _PT0	=	0x00b9
                           0000BA   221 _PX1	=	0x00ba
                           0000BB   222 _PT1	=	0x00bb
                           0000BC   223 _PS	=	0x00bc
                           0000D0   224 _P	=	0x00d0
                           0000D1   225 _F1	=	0x00d1
                           0000D2   226 _OV	=	0x00d2
                           0000D3   227 _RS0	=	0x00d3
                           0000D4   228 _RS1	=	0x00d4
                           0000D5   229 _F0	=	0x00d5
                           0000D6   230 _AC	=	0x00d6
                           0000D7   231 _CY	=	0x00d7
                                    232 ;--------------------------------------------------------
                                    233 ; overlayable register banks
                                    234 ;--------------------------------------------------------
                                    235 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        236 	.ds 8
                                    237 ;--------------------------------------------------------
                                    238 ; internal ram data
                                    239 ;--------------------------------------------------------
                                    240 	.area DSEG    (DATA)
      000030                        241 _Main_digits_a_1_13:
      000030                        242 	.ds 10
      00003A                        243 _Main_number_a_1_13:
      00003A                        244 	.ds 2
      00003C                        245 _Main_numberOfDigitsA_1_13:
      00003C                        246 	.ds 2
      00003E                        247 _Main_digits_b_1_13:
      00003E                        248 	.ds 10
      000048                        249 _Main_number_b_1_13:
      000048                        250 	.ds 2
      00004A                        251 _Main_numberOfDigitsB_1_13:
      00004A                        252 	.ds 2
      00004C                        253 _Main_digit_1_13:
      00004C                        254 	.ds 2
      00004E                        255 _Main_check_1_13:
      00004E                        256 	.ds 2
      000050                        257 _Main_i_1_13:
      000050                        258 	.ds 2
      000052                        259 _Main_sum_1_13:
      000052                        260 	.ds 2
                                    261 ;--------------------------------------------------------
                                    262 ; overlayable items in internal ram 
                                    263 ;--------------------------------------------------------
                                    264 	.area	OSEG    (OVR,DATA)
                                    265 	.area	OSEG    (OVR,DATA)
                                    266 	.area	OSEG    (OVR,DATA)
      000054                        267 _keypad_keypad_1_53:
      000054                        268 	.ds 12
                                    269 ;--------------------------------------------------------
                                    270 ; indirectly addressable internal ram data
                                    271 ;--------------------------------------------------------
                                    272 	.area ISEG    (DATA)
                                    273 ;--------------------------------------------------------
                                    274 ; absolute internal ram data
                                    275 ;--------------------------------------------------------
                                    276 	.area IABS    (ABS,DATA)
                                    277 	.area IABS    (ABS,DATA)
                                    278 ;--------------------------------------------------------
                                    279 ; bit data
                                    280 ;--------------------------------------------------------
                                    281 	.area BSEG    (BIT)
      000000                        282 _displayOnOffControl_PARM_1:
      000000                        283 	.ds 1
      000001                        284 _displayOnOffControl_PARM_2:
      000001                        285 	.ds 1
      000002                        286 _displayOnOffControl_PARM_3:
      000002                        287 	.ds 1
      000003                        288 _cursorOrDisplayShift_PARM_1:
      000003                        289 	.ds 1
      000004                        290 _cursorOrDisplayShift_PARM_2:
      000004                        291 	.ds 1
                                    292 ;--------------------------------------------------------
                                    293 ; paged external ram data
                                    294 ;--------------------------------------------------------
                                    295 	.area PSEG    (PAG,XDATA)
                                    296 ;--------------------------------------------------------
                                    297 ; external ram data
                                    298 ;--------------------------------------------------------
                                    299 	.area XSEG    (XDATA)
                                    300 ;--------------------------------------------------------
                                    301 ; absolute external ram data
                                    302 ;--------------------------------------------------------
                                    303 	.area XABS    (ABS,XDATA)
                                    304 ;--------------------------------------------------------
                                    305 ; external initialized ram data
                                    306 ;--------------------------------------------------------
                                    307 	.area XISEG   (XDATA)
                                    308 	.area HOME    (CODE)
                                    309 	.area GSINIT0 (CODE)
                                    310 	.area GSINIT1 (CODE)
                                    311 	.area GSINIT2 (CODE)
                                    312 	.area GSINIT3 (CODE)
                                    313 	.area GSINIT4 (CODE)
                                    314 	.area GSINIT5 (CODE)
                                    315 	.area GSINIT  (CODE)
                                    316 	.area GSFINAL (CODE)
                                    317 	.area CSEG    (CODE)
                                    318 ;--------------------------------------------------------
                                    319 ; global & static initialisations
                                    320 ;--------------------------------------------------------
                                    321 	.area HOME    (CODE)
                                    322 	.area GSINIT  (CODE)
                                    323 	.area GSFINAL (CODE)
                                    324 	.area GSINIT  (CODE)
                                    325 ;--------------------------------------------------------
                                    326 ; Home
                                    327 ;--------------------------------------------------------
                                    328 	.area HOME    (CODE)
                                    329 	.area HOME    (CODE)
                                    330 ;--------------------------------------------------------
                                    331 ; code
                                    332 ;--------------------------------------------------------
                                    333 	.area CSEG    (CODE)
                                    334 ;------------------------------------------------------------
                                    335 ;Allocation info for local variables in function 'Main'
                                    336 ;------------------------------------------------------------
                                    337 ;key                       Allocated to registers r3 
                                    338 ;digits_a                  Allocated with name '_Main_digits_a_1_13'
                                    339 ;number_a                  Allocated with name '_Main_number_a_1_13'
                                    340 ;numberOfDigitsA           Allocated with name '_Main_numberOfDigitsA_1_13'
                                    341 ;digits_b                  Allocated with name '_Main_digits_b_1_13'
                                    342 ;number_b                  Allocated with name '_Main_number_b_1_13'
                                    343 ;numberOfDigitsB           Allocated with name '_Main_numberOfDigitsB_1_13'
                                    344 ;digit                     Allocated with name '_Main_digit_1_13'
                                    345 ;check                     Allocated with name '_Main_check_1_13'
                                    346 ;i                         Allocated with name '_Main_i_1_13'
                                    347 ;j                         Allocated to registers r4 r6 
                                    348 ;sum_check                 Allocated to registers r4 r5 
                                    349 ;sum_digit                 Allocated to registers r6 r7 
                                    350 ;sum                       Allocated with name '_Main_sum_1_13'
                                    351 ;------------------------------------------------------------
                                    352 ;	assignment3.c:45: void Main(void) {
                                    353 ;	-----------------------------------------
                                    354 ;	 function Main
                                    355 ;	-----------------------------------------
      000000                        356 _Main:
                           000007   357 	ar7 = 0x07
                           000006   358 	ar6 = 0x06
                           000005   359 	ar5 = 0x05
                           000004   360 	ar4 = 0x04
                           000003   361 	ar3 = 0x03
                           000002   362 	ar2 = 0x02
                           000001   363 	ar1 = 0x01
                           000000   364 	ar0 = 0x00
                                    365 ;	assignment3.c:47: unsigned int digits_a[5] = {0, 0, 0, 0, 0}, number_a = 0, numberOfDigitsA = 0;
      000000 E4               [12]  366 	clr	a
      000001 F5 30            [12]  367 	mov	(_Main_digits_a_1_13 + 0),a
      000003 F5 31            [12]  368 	mov	(_Main_digits_a_1_13 + 1),a
      000005 F5 32            [12]  369 	mov	((_Main_digits_a_1_13 + 0x0002) + 0),a
      000007 F5 33            [12]  370 	mov	((_Main_digits_a_1_13 + 0x0002) + 1),a
      000009 F5 34            [12]  371 	mov	((_Main_digits_a_1_13 + 0x0004) + 0),a
      00000B F5 35            [12]  372 	mov	((_Main_digits_a_1_13 + 0x0004) + 1),a
      00000D F5 36            [12]  373 	mov	((_Main_digits_a_1_13 + 0x0006) + 0),a
      00000F F5 37            [12]  374 	mov	((_Main_digits_a_1_13 + 0x0006) + 1),a
      000011 F5 38            [12]  375 	mov	((_Main_digits_a_1_13 + 0x0008) + 0),a
      000013 F5 39            [12]  376 	mov	((_Main_digits_a_1_13 + 0x0008) + 1),a
      000015 F5 3C            [12]  377 	mov	_Main_numberOfDigitsA_1_13,a
      000017 F5 3D            [12]  378 	mov	(_Main_numberOfDigitsA_1_13 + 1),a
                                    379 ;	assignment3.c:48: unsigned int digits_b[5] = {0, 0, 0, 0, 0}, number_b = 0, numberOfDigitsB = 0;
      000019 F5 3E            [12]  380 	mov	(_Main_digits_b_1_13 + 0),a
      00001B F5 3F            [12]  381 	mov	(_Main_digits_b_1_13 + 1),a
      00001D F5 40            [12]  382 	mov	((_Main_digits_b_1_13 + 0x0002) + 0),a
      00001F F5 41            [12]  383 	mov	((_Main_digits_b_1_13 + 0x0002) + 1),a
      000021 F5 42            [12]  384 	mov	((_Main_digits_b_1_13 + 0x0004) + 0),a
      000023 F5 43            [12]  385 	mov	((_Main_digits_b_1_13 + 0x0004) + 1),a
      000025 F5 44            [12]  386 	mov	((_Main_digits_b_1_13 + 0x0006) + 0),a
      000027 F5 45            [12]  387 	mov	((_Main_digits_b_1_13 + 0x0006) + 1),a
      000029 F5 46            [12]  388 	mov	((_Main_digits_b_1_13 + 0x0008) + 0),a
      00002B F5 47            [12]  389 	mov	((_Main_digits_b_1_13 + 0x0008) + 1),a
      00002D F5 4A            [12]  390 	mov	_Main_numberOfDigitsB_1_13,a
      00002F F5 4B            [12]  391 	mov	(_Main_numberOfDigitsB_1_13 + 1),a
                                    392 ;	assignment3.c:53: functionSet();
      000031 12 05 A9         [24]  393 	lcall	_functionSet
                                    394 ;	assignment3.c:54: entryModeSet(); // increment and no shift
      000034 12 05 63         [24]  395 	lcall	_entryModeSet
                                    396 ;	assignment3.c:55: displayOnOffControl(1, 1, 1); // display on, cursor on and blinking on
      000037 D2 00            [12]  397 	setb	_displayOnOffControl_PARM_1
      000039 D2 01            [12]  398 	setb	_displayOnOffControl_PARM_2
      00003B D2 02            [12]  399 	setb	_displayOnOffControl_PARM_3
      00003D 12 05 6F         [24]  400 	lcall	_displayOnOffControl
                                    401 ;	assignment3.c:61: while (1) {
      000040                        402 00118$:
                                    403 ;	assignment3.c:64: keypad();
      000040 12 06 1E         [24]  404 	lcall	_keypad
                                    405 ;	assignment3.c:65: key = P1;
      000043 AB 90            [24]  406 	mov	r3,_P1
                                    407 ;	assignment3.c:67: if (key == '+') {
      000045 BB 2B 08         [24]  408 	cjne	r3,#0x2B,00102$
                                    409 ;	assignment3.c:69: sendChar(key);
      000048 8B 82            [24]  410 	mov	dpl,r3
      00004A 12 05 D1         [24]  411 	lcall	_sendChar
                                    412 ;	assignment3.c:70: break;
      00004D 02 01 B3         [24]  413 	ljmp	00119$
      000050                        414 00102$:
                                    415 ;	assignment3.c:74: if (numberOfDigitsA < 5) {
      000050 C3               [12]  416 	clr	c
      000051 E5 3C            [12]  417 	mov	a,_Main_numberOfDigitsA_1_13
      000053 94 05            [12]  418 	subb	a,#0x05
      000055 E5 3D            [12]  419 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      000057 94 00            [12]  420 	subb	a,#0x00
      000059 50 E5            [24]  421 	jnc	00118$
                                    422 ;	assignment3.c:75: switch (key) {
      00005B BB 30 00         [24]  423 	cjne	r3,#0x30,00245$
      00005E                        424 00245$:
      00005E 50 03            [24]  425 	jnc	00246$
      000060 02 01 AB         [24]  426 	ljmp	00114$
      000063                        427 00246$:
      000063 EB               [12]  428 	mov	a,r3
      000064 24 C6            [12]  429 	add	a,#0xff - 0x39
      000066 50 03            [24]  430 	jnc	00247$
      000068 02 01 AB         [24]  431 	ljmp	00114$
      00006B                        432 00247$:
      00006B EB               [12]  433 	mov	a,r3
      00006C 24 D0            [12]  434 	add	a,#0xD0
      00006E FA               [12]  435 	mov	r2,a
      00006F 24 0A            [12]  436 	add	a,#(00248$-3-.)
      000071 83               [24]  437 	movc	a,@a+pc
      000072 F5 82            [12]  438 	mov	dpl,a
      000074 EA               [12]  439 	mov	a,r2
      000075 24 0E            [12]  440 	add	a,#(00249$-3-.)
      000077 83               [24]  441 	movc	a,@a+pc
      000078 F5 83            [12]  442 	mov	dph,a
      00007A E4               [12]  443 	clr	a
      00007B 73               [24]  444 	jmp	@a+dptr
      00007C                        445 00248$:
      00007C 90                     446 	.db	00103$
      00007D AD                     447 	.db	00104$
      00007E CA                     448 	.db	00105$
      00007F E7                     449 	.db	00106$
      000080 04                     450 	.db	00107$
      000081 21                     451 	.db	00108$
      000082 3D                     452 	.db	00109$
      000083 59                     453 	.db	00110$
      000084 75                     454 	.db	00111$
      000085 91                     455 	.db	00112$
      000086                        456 00249$:
      000086 00                     457 	.db	00103$>>8
      000087 00                     458 	.db	00104$>>8
      000088 00                     459 	.db	00105$>>8
      000089 00                     460 	.db	00106$>>8
      00008A 01                     461 	.db	00107$>>8
      00008B 01                     462 	.db	00108$>>8
      00008C 01                     463 	.db	00109$>>8
      00008D 01                     464 	.db	00110$>>8
      00008E 01                     465 	.db	00111$>>8
      00008F 01                     466 	.db	00112$>>8
                                    467 ;	assignment3.c:76: case '0':
      000090                        468 00103$:
                                    469 ;	assignment3.c:77: digits_a[numberOfDigitsA] = 0;
      000090 E5 3C            [12]  470 	mov	a,_Main_numberOfDigitsA_1_13
      000092 25 3C            [12]  471 	add	a,_Main_numberOfDigitsA_1_13
      000094 FA               [12]  472 	mov	r2,a
      000095 E5 3D            [12]  473 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      000097 33               [12]  474 	rlc	a
      000098 FF               [12]  475 	mov	r7,a
      000099 EA               [12]  476 	mov	a,r2
      00009A 24 30            [12]  477 	add	a,#_Main_digits_a_1_13
      00009C F8               [12]  478 	mov	r0,a
      00009D 76 00            [12]  479 	mov	@r0,#0x00
      00009F 08               [12]  480 	inc	r0
      0000A0 76 00            [12]  481 	mov	@r0,#0x00
                                    482 ;	assignment3.c:78: numberOfDigitsA++;
      0000A2 05 3C            [12]  483 	inc	_Main_numberOfDigitsA_1_13
      0000A4 E4               [12]  484 	clr	a
      0000A5 B5 3C 02         [24]  485 	cjne	a,_Main_numberOfDigitsA_1_13,00250$
      0000A8 05 3D            [12]  486 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      0000AA                        487 00250$:
                                    488 ;	assignment3.c:79: break;
      0000AA 02 01 AB         [24]  489 	ljmp	00114$
                                    490 ;	assignment3.c:80: case '1':
      0000AD                        491 00104$:
                                    492 ;	assignment3.c:81: digits_a[numberOfDigitsA] = 1;
      0000AD E5 3C            [12]  493 	mov	a,_Main_numberOfDigitsA_1_13
      0000AF 25 3C            [12]  494 	add	a,_Main_numberOfDigitsA_1_13
      0000B1 FE               [12]  495 	mov	r6,a
      0000B2 E5 3D            [12]  496 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      0000B4 33               [12]  497 	rlc	a
      0000B5 FF               [12]  498 	mov	r7,a
      0000B6 EE               [12]  499 	mov	a,r6
      0000B7 24 30            [12]  500 	add	a,#_Main_digits_a_1_13
      0000B9 F8               [12]  501 	mov	r0,a
      0000BA 76 01            [12]  502 	mov	@r0,#0x01
      0000BC 08               [12]  503 	inc	r0
      0000BD 76 00            [12]  504 	mov	@r0,#0x00
                                    505 ;	assignment3.c:82: numberOfDigitsA++;
      0000BF 05 3C            [12]  506 	inc	_Main_numberOfDigitsA_1_13
      0000C1 E4               [12]  507 	clr	a
      0000C2 B5 3C 02         [24]  508 	cjne	a,_Main_numberOfDigitsA_1_13,00251$
      0000C5 05 3D            [12]  509 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      0000C7                        510 00251$:
                                    511 ;	assignment3.c:83: break;
      0000C7 02 01 AB         [24]  512 	ljmp	00114$
                                    513 ;	assignment3.c:84: case '2':
      0000CA                        514 00105$:
                                    515 ;	assignment3.c:85: digits_a[numberOfDigitsA] = 2;
      0000CA E5 3C            [12]  516 	mov	a,_Main_numberOfDigitsA_1_13
      0000CC 25 3C            [12]  517 	add	a,_Main_numberOfDigitsA_1_13
      0000CE FE               [12]  518 	mov	r6,a
      0000CF E5 3D            [12]  519 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      0000D1 33               [12]  520 	rlc	a
      0000D2 FF               [12]  521 	mov	r7,a
      0000D3 EE               [12]  522 	mov	a,r6
      0000D4 24 30            [12]  523 	add	a,#_Main_digits_a_1_13
      0000D6 F8               [12]  524 	mov	r0,a
      0000D7 76 02            [12]  525 	mov	@r0,#0x02
      0000D9 08               [12]  526 	inc	r0
      0000DA 76 00            [12]  527 	mov	@r0,#0x00
                                    528 ;	assignment3.c:86: numberOfDigitsA++;
      0000DC 05 3C            [12]  529 	inc	_Main_numberOfDigitsA_1_13
      0000DE E4               [12]  530 	clr	a
      0000DF B5 3C 02         [24]  531 	cjne	a,_Main_numberOfDigitsA_1_13,00252$
      0000E2 05 3D            [12]  532 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      0000E4                        533 00252$:
                                    534 ;	assignment3.c:87: break;
      0000E4 02 01 AB         [24]  535 	ljmp	00114$
                                    536 ;	assignment3.c:88: case '3':
      0000E7                        537 00106$:
                                    538 ;	assignment3.c:89: digits_a[numberOfDigitsA] = 3;
      0000E7 E5 3C            [12]  539 	mov	a,_Main_numberOfDigitsA_1_13
      0000E9 25 3C            [12]  540 	add	a,_Main_numberOfDigitsA_1_13
      0000EB FE               [12]  541 	mov	r6,a
      0000EC E5 3D            [12]  542 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      0000EE 33               [12]  543 	rlc	a
      0000EF FF               [12]  544 	mov	r7,a
      0000F0 EE               [12]  545 	mov	a,r6
      0000F1 24 30            [12]  546 	add	a,#_Main_digits_a_1_13
      0000F3 F8               [12]  547 	mov	r0,a
      0000F4 76 03            [12]  548 	mov	@r0,#0x03
      0000F6 08               [12]  549 	inc	r0
      0000F7 76 00            [12]  550 	mov	@r0,#0x00
                                    551 ;	assignment3.c:90: numberOfDigitsA++;
      0000F9 05 3C            [12]  552 	inc	_Main_numberOfDigitsA_1_13
      0000FB E4               [12]  553 	clr	a
      0000FC B5 3C 02         [24]  554 	cjne	a,_Main_numberOfDigitsA_1_13,00253$
      0000FF 05 3D            [12]  555 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      000101                        556 00253$:
                                    557 ;	assignment3.c:91: break;
      000101 02 01 AB         [24]  558 	ljmp	00114$
                                    559 ;	assignment3.c:92: case '4':
      000104                        560 00107$:
                                    561 ;	assignment3.c:93: digits_a[numberOfDigitsA] = 4;
      000104 E5 3C            [12]  562 	mov	a,_Main_numberOfDigitsA_1_13
      000106 25 3C            [12]  563 	add	a,_Main_numberOfDigitsA_1_13
      000108 FE               [12]  564 	mov	r6,a
      000109 E5 3D            [12]  565 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      00010B 33               [12]  566 	rlc	a
      00010C FF               [12]  567 	mov	r7,a
      00010D EE               [12]  568 	mov	a,r6
      00010E 24 30            [12]  569 	add	a,#_Main_digits_a_1_13
      000110 F8               [12]  570 	mov	r0,a
      000111 76 04            [12]  571 	mov	@r0,#0x04
      000113 08               [12]  572 	inc	r0
      000114 76 00            [12]  573 	mov	@r0,#0x00
                                    574 ;	assignment3.c:94: numberOfDigitsA++;
      000116 05 3C            [12]  575 	inc	_Main_numberOfDigitsA_1_13
      000118 E4               [12]  576 	clr	a
      000119 B5 3C 02         [24]  577 	cjne	a,_Main_numberOfDigitsA_1_13,00254$
      00011C 05 3D            [12]  578 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      00011E                        579 00254$:
                                    580 ;	assignment3.c:95: break;
      00011E 02 01 AB         [24]  581 	ljmp	00114$
                                    582 ;	assignment3.c:96: case '5':
      000121                        583 00108$:
                                    584 ;	assignment3.c:97: digits_a[numberOfDigitsA] = 5;
      000121 E5 3C            [12]  585 	mov	a,_Main_numberOfDigitsA_1_13
      000123 25 3C            [12]  586 	add	a,_Main_numberOfDigitsA_1_13
      000125 FE               [12]  587 	mov	r6,a
      000126 E5 3D            [12]  588 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      000128 33               [12]  589 	rlc	a
      000129 FF               [12]  590 	mov	r7,a
      00012A EE               [12]  591 	mov	a,r6
      00012B 24 30            [12]  592 	add	a,#_Main_digits_a_1_13
      00012D F8               [12]  593 	mov	r0,a
      00012E 76 05            [12]  594 	mov	@r0,#0x05
      000130 08               [12]  595 	inc	r0
      000131 76 00            [12]  596 	mov	@r0,#0x00
                                    597 ;	assignment3.c:98: numberOfDigitsA++;
      000133 05 3C            [12]  598 	inc	_Main_numberOfDigitsA_1_13
      000135 E4               [12]  599 	clr	a
                                    600 ;	assignment3.c:99: break;
                                    601 ;	assignment3.c:100: case '6':
      000136 B5 3C 72         [24]  602 	cjne	a,_Main_numberOfDigitsA_1_13,00114$
      000139 05 3D            [12]  603 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      00013B 80 6E            [24]  604 	sjmp	00114$
      00013D                        605 00109$:
                                    606 ;	assignment3.c:101: digits_a[numberOfDigitsA] = 6;
      00013D E5 3C            [12]  607 	mov	a,_Main_numberOfDigitsA_1_13
      00013F 25 3C            [12]  608 	add	a,_Main_numberOfDigitsA_1_13
      000141 FE               [12]  609 	mov	r6,a
      000142 E5 3D            [12]  610 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      000144 33               [12]  611 	rlc	a
      000145 FF               [12]  612 	mov	r7,a
      000146 EE               [12]  613 	mov	a,r6
      000147 24 30            [12]  614 	add	a,#_Main_digits_a_1_13
      000149 F8               [12]  615 	mov	r0,a
      00014A 76 06            [12]  616 	mov	@r0,#0x06
      00014C 08               [12]  617 	inc	r0
      00014D 76 00            [12]  618 	mov	@r0,#0x00
                                    619 ;	assignment3.c:102: numberOfDigitsA++;
      00014F 05 3C            [12]  620 	inc	_Main_numberOfDigitsA_1_13
      000151 E4               [12]  621 	clr	a
                                    622 ;	assignment3.c:103: break;
                                    623 ;	assignment3.c:104: case '7':
      000152 B5 3C 56         [24]  624 	cjne	a,_Main_numberOfDigitsA_1_13,00114$
      000155 05 3D            [12]  625 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      000157 80 52            [24]  626 	sjmp	00114$
      000159                        627 00110$:
                                    628 ;	assignment3.c:105: digits_a[numberOfDigitsA] = 7;
      000159 E5 3C            [12]  629 	mov	a,_Main_numberOfDigitsA_1_13
      00015B 25 3C            [12]  630 	add	a,_Main_numberOfDigitsA_1_13
      00015D FE               [12]  631 	mov	r6,a
      00015E E5 3D            [12]  632 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      000160 33               [12]  633 	rlc	a
      000161 FF               [12]  634 	mov	r7,a
      000162 EE               [12]  635 	mov	a,r6
      000163 24 30            [12]  636 	add	a,#_Main_digits_a_1_13
      000165 F8               [12]  637 	mov	r0,a
      000166 76 07            [12]  638 	mov	@r0,#0x07
      000168 08               [12]  639 	inc	r0
      000169 76 00            [12]  640 	mov	@r0,#0x00
                                    641 ;	assignment3.c:106: numberOfDigitsA++;
      00016B 05 3C            [12]  642 	inc	_Main_numberOfDigitsA_1_13
      00016D E4               [12]  643 	clr	a
                                    644 ;	assignment3.c:107: break;
                                    645 ;	assignment3.c:108: case '8':
      00016E B5 3C 3A         [24]  646 	cjne	a,_Main_numberOfDigitsA_1_13,00114$
      000171 05 3D            [12]  647 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      000173 80 36            [24]  648 	sjmp	00114$
      000175                        649 00111$:
                                    650 ;	assignment3.c:109: digits_a[numberOfDigitsA] = 8;
      000175 E5 3C            [12]  651 	mov	a,_Main_numberOfDigitsA_1_13
      000177 25 3C            [12]  652 	add	a,_Main_numberOfDigitsA_1_13
      000179 FE               [12]  653 	mov	r6,a
      00017A E5 3D            [12]  654 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      00017C 33               [12]  655 	rlc	a
      00017D FF               [12]  656 	mov	r7,a
      00017E EE               [12]  657 	mov	a,r6
      00017F 24 30            [12]  658 	add	a,#_Main_digits_a_1_13
      000181 F8               [12]  659 	mov	r0,a
      000182 76 08            [12]  660 	mov	@r0,#0x08
      000184 08               [12]  661 	inc	r0
      000185 76 00            [12]  662 	mov	@r0,#0x00
                                    663 ;	assignment3.c:110: numberOfDigitsA++;
      000187 05 3C            [12]  664 	inc	_Main_numberOfDigitsA_1_13
      000189 E4               [12]  665 	clr	a
                                    666 ;	assignment3.c:111: break;
                                    667 ;	assignment3.c:112: case '9':
      00018A B5 3C 1E         [24]  668 	cjne	a,_Main_numberOfDigitsA_1_13,00114$
      00018D 05 3D            [12]  669 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      00018F 80 1A            [24]  670 	sjmp	00114$
      000191                        671 00112$:
                                    672 ;	assignment3.c:113: digits_a[numberOfDigitsA] = 9;
      000191 E5 3C            [12]  673 	mov	a,_Main_numberOfDigitsA_1_13
      000193 25 3C            [12]  674 	add	a,_Main_numberOfDigitsA_1_13
      000195 FE               [12]  675 	mov	r6,a
      000196 E5 3D            [12]  676 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      000198 33               [12]  677 	rlc	a
      000199 FF               [12]  678 	mov	r7,a
      00019A EE               [12]  679 	mov	a,r6
      00019B 24 30            [12]  680 	add	a,#_Main_digits_a_1_13
      00019D F8               [12]  681 	mov	r0,a
      00019E 76 09            [12]  682 	mov	@r0,#0x09
      0001A0 08               [12]  683 	inc	r0
      0001A1 76 00            [12]  684 	mov	@r0,#0x00
                                    685 ;	assignment3.c:114: numberOfDigitsA++;
      0001A3 05 3C            [12]  686 	inc	_Main_numberOfDigitsA_1_13
      0001A5 E4               [12]  687 	clr	a
      0001A6 B5 3C 02         [24]  688 	cjne	a,_Main_numberOfDigitsA_1_13,00259$
      0001A9 05 3D            [12]  689 	inc	(_Main_numberOfDigitsA_1_13 + 1)
      0001AB                        690 00259$:
                                    691 ;	assignment3.c:118: }
      0001AB                        692 00114$:
                                    693 ;	assignment3.c:120: sendChar(key);
      0001AB 8B 82            [24]  694 	mov	dpl,r3
      0001AD 12 05 D1         [24]  695 	lcall	_sendChar
      0001B0 02 00 40         [24]  696 	ljmp	00118$
      0001B3                        697 00119$:
                                    698 ;	assignment3.c:126: number_a = 0;
      0001B3 E4               [12]  699 	clr	a
      0001B4 F5 3A            [12]  700 	mov	_Main_number_a_1_13,a
      0001B6 F5 3B            [12]  701 	mov	(_Main_number_a_1_13 + 1),a
                                    702 ;	assignment3.c:127: check = numberOfDigitsA - 1;
      0001B8 E5 3C            [12]  703 	mov	a,_Main_numberOfDigitsA_1_13
      0001BA 24 FF            [12]  704 	add	a,#0xFF
      0001BC F5 4E            [12]  705 	mov	_Main_check_1_13,a
      0001BE E5 3D            [12]  706 	mov	a,(_Main_numberOfDigitsA_1_13 + 1)
      0001C0 34 FF            [12]  707 	addc	a,#0xFF
      0001C2 F5 4F            [12]  708 	mov	(_Main_check_1_13 + 1),a
                                    709 ;	assignment3.c:129: for (i = 0; i < numberOfDigitsA; i++) {
      0001C4 AA 4E            [24]  710 	mov	r2,_Main_check_1_13
      0001C6 AF 4F            [24]  711 	mov	r7,(_Main_check_1_13 + 1)
      0001C8 E4               [12]  712 	clr	a
      0001C9 F5 50            [12]  713 	mov	_Main_i_1_13,a
      0001CB F5 51            [12]  714 	mov	(_Main_i_1_13 + 1),a
      0001CD                        715 00156$:
      0001CD AC 50            [24]  716 	mov	r4,_Main_i_1_13
      0001CF AE 51            [24]  717 	mov	r6,(_Main_i_1_13 + 1)
      0001D1 C3               [12]  718 	clr	c
      0001D2 EC               [12]  719 	mov	a,r4
      0001D3 95 3C            [12]  720 	subb	a,_Main_numberOfDigitsA_1_13
      0001D5 EE               [12]  721 	mov	a,r6
      0001D6 95 3D            [12]  722 	subb	a,(_Main_numberOfDigitsA_1_13 + 1)
      0001D8 40 03            [24]  723 	jc	00260$
      0001DA 02 02 60         [24]  724 	ljmp	00139$
      0001DD                        725 00260$:
                                    726 ;	assignment3.c:130: digit = 1;
      0001DD 75 4C 01         [24]  727 	mov	_Main_digit_1_13,#0x01
      0001E0 75 4D 00         [24]  728 	mov	(_Main_digit_1_13 + 1),#0x00
                                    729 ;	assignment3.c:131: for (j = 0; j < check; j++) {
      0001E3 7C 00            [12]  730 	mov	r4,#0x00
      0001E5 7E 00            [12]  731 	mov	r6,#0x00
      0001E7                        732 00153$:
      0001E7 C3               [12]  733 	clr	c
      0001E8 EC               [12]  734 	mov	a,r4
      0001E9 9A               [12]  735 	subb	a,r2
      0001EA EE               [12]  736 	mov	a,r6
      0001EB 64 80            [12]  737 	xrl	a,#0x80
      0001ED 8F F0            [24]  738 	mov	b,r7
      0001EF 63 F0 80         [24]  739 	xrl	b,#0x80
      0001F2 95 F0            [12]  740 	subb	a,b
      0001F4 50 29            [24]  741 	jnc	00120$
                                    742 ;	assignment3.c:132: digit *= 10;
      0001F6 85 4C 54         [24]  743 	mov	__mulint_PARM_2,_Main_digit_1_13
      0001F9 85 4D 55         [24]  744 	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
      0001FC 90 00 0A         [24]  745 	mov	dptr,#0x000A
      0001FF C0 07            [24]  746 	push	ar7
      000201 C0 06            [24]  747 	push	ar6
      000203 C0 04            [24]  748 	push	ar4
      000205 C0 02            [24]  749 	push	ar2
      000207 12 06 B1         [24]  750 	lcall	__mulint
      00020A 85 82 4C         [24]  751 	mov	_Main_digit_1_13,dpl
      00020D 85 83 4D         [24]  752 	mov	(_Main_digit_1_13 + 1),dph
      000210 D0 02            [24]  753 	pop	ar2
      000212 D0 04            [24]  754 	pop	ar4
      000214 D0 06            [24]  755 	pop	ar6
      000216 D0 07            [24]  756 	pop	ar7
                                    757 ;	assignment3.c:131: for (j = 0; j < check; j++) {
      000218 0C               [12]  758 	inc	r4
      000219 BC 00 CB         [24]  759 	cjne	r4,#0x00,00153$
      00021C 0E               [12]  760 	inc	r6
      00021D 80 C8            [24]  761 	sjmp	00153$
      00021F                        762 00120$:
                                    763 ;	assignment3.c:134: number_a += digits_a[i] * digit;
      00021F E5 50            [12]  764 	mov	a,_Main_i_1_13
      000221 25 50            [12]  765 	add	a,_Main_i_1_13
      000223 FD               [12]  766 	mov	r5,a
      000224 E5 51            [12]  767 	mov	a,(_Main_i_1_13 + 1)
      000226 33               [12]  768 	rlc	a
      000227 ED               [12]  769 	mov	a,r5
      000228 24 30            [12]  770 	add	a,#_Main_digits_a_1_13
      00022A F9               [12]  771 	mov	r1,a
      00022B 87 82            [24]  772 	mov	dpl,@r1
      00022D 09               [12]  773 	inc	r1
      00022E 87 83            [24]  774 	mov	dph,@r1
      000230 19               [12]  775 	dec	r1
      000231 85 4C 54         [24]  776 	mov	__mulint_PARM_2,_Main_digit_1_13
      000234 85 4D 55         [24]  777 	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
      000237 C0 07            [24]  778 	push	ar7
      000239 C0 02            [24]  779 	push	ar2
      00023B 12 06 B1         [24]  780 	lcall	__mulint
      00023E AD 82            [24]  781 	mov	r5,dpl
      000240 AE 83            [24]  782 	mov	r6,dph
      000242 D0 02            [24]  783 	pop	ar2
      000244 D0 07            [24]  784 	pop	ar7
      000246 ED               [12]  785 	mov	a,r5
      000247 25 3A            [12]  786 	add	a,_Main_number_a_1_13
      000249 F5 3A            [12]  787 	mov	_Main_number_a_1_13,a
      00024B EE               [12]  788 	mov	a,r6
      00024C 35 3B            [12]  789 	addc	a,(_Main_number_a_1_13 + 1)
      00024E F5 3B            [12]  790 	mov	(_Main_number_a_1_13 + 1),a
                                    791 ;	assignment3.c:135: check--;
      000250 1A               [12]  792 	dec	r2
      000251 BA FF 01         [24]  793 	cjne	r2,#0xFF,00263$
      000254 1F               [12]  794 	dec	r7
      000255                        795 00263$:
                                    796 ;	assignment3.c:129: for (i = 0; i < numberOfDigitsA; i++) {
      000255 05 50            [12]  797 	inc	_Main_i_1_13
      000257 E4               [12]  798 	clr	a
      000258 B5 50 02         [24]  799 	cjne	a,_Main_i_1_13,00264$
      00025B 05 51            [12]  800 	inc	(_Main_i_1_13 + 1)
      00025D                        801 00264$:
      00025D 02 01 CD         [24]  802 	ljmp	00156$
                                    803 ;	assignment3.c:139: while (1) {
      000260                        804 00139$:
                                    805 ;	assignment3.c:142: keypad();
      000260 12 06 1E         [24]  806 	lcall	_keypad
                                    807 ;	assignment3.c:143: key = P1;
      000263 AB 90            [24]  808 	mov	r3,_P1
                                    809 ;	assignment3.c:145: if (key == '=') {
      000265 BB 3D 08         [24]  810 	cjne	r3,#0x3D,00123$
                                    811 ;	assignment3.c:147: sendChar(key);
      000268 8B 82            [24]  812 	mov	dpl,r3
      00026A 12 05 D1         [24]  813 	lcall	_sendChar
                                    814 ;	assignment3.c:148: break;
      00026D 02 03 D3         [24]  815 	ljmp	00140$
      000270                        816 00123$:
                                    817 ;	assignment3.c:152: if (numberOfDigitsB < 5) {
      000270 C3               [12]  818 	clr	c
      000271 E5 4A            [12]  819 	mov	a,_Main_numberOfDigitsB_1_13
      000273 94 05            [12]  820 	subb	a,#0x05
      000275 E5 4B            [12]  821 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      000277 94 00            [12]  822 	subb	a,#0x00
      000279 50 E5            [24]  823 	jnc	00139$
                                    824 ;	assignment3.c:153: switch (key) {
      00027B BB 30 00         [24]  825 	cjne	r3,#0x30,00268$
      00027E                        826 00268$:
      00027E 50 03            [24]  827 	jnc	00269$
      000280 02 03 CB         [24]  828 	ljmp	00135$
      000283                        829 00269$:
      000283 EB               [12]  830 	mov	a,r3
      000284 24 C6            [12]  831 	add	a,#0xff - 0x39
      000286 50 03            [24]  832 	jnc	00270$
      000288 02 03 CB         [24]  833 	ljmp	00135$
      00028B                        834 00270$:
      00028B EB               [12]  835 	mov	a,r3
      00028C 24 D0            [12]  836 	add	a,#0xD0
      00028E FF               [12]  837 	mov	r7,a
      00028F 24 0A            [12]  838 	add	a,#(00271$-3-.)
      000291 83               [24]  839 	movc	a,@a+pc
      000292 F5 82            [12]  840 	mov	dpl,a
      000294 EF               [12]  841 	mov	a,r7
      000295 24 0E            [12]  842 	add	a,#(00272$-3-.)
      000297 83               [24]  843 	movc	a,@a+pc
      000298 F5 83            [12]  844 	mov	dph,a
      00029A E4               [12]  845 	clr	a
      00029B 73               [24]  846 	jmp	@a+dptr
      00029C                        847 00271$:
      00029C B0                     848 	.db	00124$
      00029D CD                     849 	.db	00125$
      00029E EA                     850 	.db	00126$
      00029F 07                     851 	.db	00127$
      0002A0 24                     852 	.db	00128$
      0002A1 41                     853 	.db	00129$
      0002A2 5D                     854 	.db	00130$
      0002A3 79                     855 	.db	00131$
      0002A4 95                     856 	.db	00132$
      0002A5 B1                     857 	.db	00133$
      0002A6                        858 00272$:
      0002A6 02                     859 	.db	00124$>>8
      0002A7 02                     860 	.db	00125$>>8
      0002A8 02                     861 	.db	00126$>>8
      0002A9 03                     862 	.db	00127$>>8
      0002AA 03                     863 	.db	00128$>>8
      0002AB 03                     864 	.db	00129$>>8
      0002AC 03                     865 	.db	00130$>>8
      0002AD 03                     866 	.db	00131$>>8
      0002AE 03                     867 	.db	00132$>>8
      0002AF 03                     868 	.db	00133$>>8
                                    869 ;	assignment3.c:154: case '0':
      0002B0                        870 00124$:
                                    871 ;	assignment3.c:155: digits_b[numberOfDigitsB] = 0;
      0002B0 E5 4A            [12]  872 	mov	a,_Main_numberOfDigitsB_1_13
      0002B2 25 4A            [12]  873 	add	a,_Main_numberOfDigitsB_1_13
      0002B4 FE               [12]  874 	mov	r6,a
      0002B5 E5 4B            [12]  875 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      0002B7 33               [12]  876 	rlc	a
      0002B8 FF               [12]  877 	mov	r7,a
      0002B9 EE               [12]  878 	mov	a,r6
      0002BA 24 3E            [12]  879 	add	a,#_Main_digits_b_1_13
      0002BC F8               [12]  880 	mov	r0,a
      0002BD 76 00            [12]  881 	mov	@r0,#0x00
      0002BF 08               [12]  882 	inc	r0
      0002C0 76 00            [12]  883 	mov	@r0,#0x00
                                    884 ;	assignment3.c:156: numberOfDigitsB++;
      0002C2 05 4A            [12]  885 	inc	_Main_numberOfDigitsB_1_13
      0002C4 E4               [12]  886 	clr	a
      0002C5 B5 4A 02         [24]  887 	cjne	a,_Main_numberOfDigitsB_1_13,00273$
      0002C8 05 4B            [12]  888 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      0002CA                        889 00273$:
                                    890 ;	assignment3.c:157: break;
      0002CA 02 03 CB         [24]  891 	ljmp	00135$
                                    892 ;	assignment3.c:158: case '1':
      0002CD                        893 00125$:
                                    894 ;	assignment3.c:159: digits_b[numberOfDigitsB] = 1;
      0002CD E5 4A            [12]  895 	mov	a,_Main_numberOfDigitsB_1_13
      0002CF 25 4A            [12]  896 	add	a,_Main_numberOfDigitsB_1_13
      0002D1 FE               [12]  897 	mov	r6,a
      0002D2 E5 4B            [12]  898 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      0002D4 33               [12]  899 	rlc	a
      0002D5 FF               [12]  900 	mov	r7,a
      0002D6 EE               [12]  901 	mov	a,r6
      0002D7 24 3E            [12]  902 	add	a,#_Main_digits_b_1_13
      0002D9 F8               [12]  903 	mov	r0,a
      0002DA 76 01            [12]  904 	mov	@r0,#0x01
      0002DC 08               [12]  905 	inc	r0
      0002DD 76 00            [12]  906 	mov	@r0,#0x00
                                    907 ;	assignment3.c:160: numberOfDigitsB++;
      0002DF 05 4A            [12]  908 	inc	_Main_numberOfDigitsB_1_13
      0002E1 E4               [12]  909 	clr	a
      0002E2 B5 4A 02         [24]  910 	cjne	a,_Main_numberOfDigitsB_1_13,00274$
      0002E5 05 4B            [12]  911 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      0002E7                        912 00274$:
                                    913 ;	assignment3.c:161: break;
      0002E7 02 03 CB         [24]  914 	ljmp	00135$
                                    915 ;	assignment3.c:162: case '2':
      0002EA                        916 00126$:
                                    917 ;	assignment3.c:163: digits_b[numberOfDigitsB] = 2;
      0002EA E5 4A            [12]  918 	mov	a,_Main_numberOfDigitsB_1_13
      0002EC 25 4A            [12]  919 	add	a,_Main_numberOfDigitsB_1_13
      0002EE FE               [12]  920 	mov	r6,a
      0002EF E5 4B            [12]  921 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      0002F1 33               [12]  922 	rlc	a
      0002F2 FF               [12]  923 	mov	r7,a
      0002F3 EE               [12]  924 	mov	a,r6
      0002F4 24 3E            [12]  925 	add	a,#_Main_digits_b_1_13
      0002F6 F8               [12]  926 	mov	r0,a
      0002F7 76 02            [12]  927 	mov	@r0,#0x02
      0002F9 08               [12]  928 	inc	r0
      0002FA 76 00            [12]  929 	mov	@r0,#0x00
                                    930 ;	assignment3.c:164: numberOfDigitsB++;
      0002FC 05 4A            [12]  931 	inc	_Main_numberOfDigitsB_1_13
      0002FE E4               [12]  932 	clr	a
      0002FF B5 4A 02         [24]  933 	cjne	a,_Main_numberOfDigitsB_1_13,00275$
      000302 05 4B            [12]  934 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      000304                        935 00275$:
                                    936 ;	assignment3.c:165: break;
      000304 02 03 CB         [24]  937 	ljmp	00135$
                                    938 ;	assignment3.c:166: case '3':
      000307                        939 00127$:
                                    940 ;	assignment3.c:167: digits_b[numberOfDigitsB] = 3;
      000307 E5 4A            [12]  941 	mov	a,_Main_numberOfDigitsB_1_13
      000309 25 4A            [12]  942 	add	a,_Main_numberOfDigitsB_1_13
      00030B FE               [12]  943 	mov	r6,a
      00030C E5 4B            [12]  944 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      00030E 33               [12]  945 	rlc	a
      00030F FF               [12]  946 	mov	r7,a
      000310 EE               [12]  947 	mov	a,r6
      000311 24 3E            [12]  948 	add	a,#_Main_digits_b_1_13
      000313 F8               [12]  949 	mov	r0,a
      000314 76 03            [12]  950 	mov	@r0,#0x03
      000316 08               [12]  951 	inc	r0
      000317 76 00            [12]  952 	mov	@r0,#0x00
                                    953 ;	assignment3.c:168: numberOfDigitsB++;
      000319 05 4A            [12]  954 	inc	_Main_numberOfDigitsB_1_13
      00031B E4               [12]  955 	clr	a
      00031C B5 4A 02         [24]  956 	cjne	a,_Main_numberOfDigitsB_1_13,00276$
      00031F 05 4B            [12]  957 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      000321                        958 00276$:
                                    959 ;	assignment3.c:169: break;
      000321 02 03 CB         [24]  960 	ljmp	00135$
                                    961 ;	assignment3.c:170: case '4':
      000324                        962 00128$:
                                    963 ;	assignment3.c:171: digits_b[numberOfDigitsB] = 4;
      000324 E5 4A            [12]  964 	mov	a,_Main_numberOfDigitsB_1_13
      000326 25 4A            [12]  965 	add	a,_Main_numberOfDigitsB_1_13
      000328 FE               [12]  966 	mov	r6,a
      000329 E5 4B            [12]  967 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      00032B 33               [12]  968 	rlc	a
      00032C FF               [12]  969 	mov	r7,a
      00032D EE               [12]  970 	mov	a,r6
      00032E 24 3E            [12]  971 	add	a,#_Main_digits_b_1_13
      000330 F8               [12]  972 	mov	r0,a
      000331 76 04            [12]  973 	mov	@r0,#0x04
      000333 08               [12]  974 	inc	r0
      000334 76 00            [12]  975 	mov	@r0,#0x00
                                    976 ;	assignment3.c:172: numberOfDigitsB++;
      000336 05 4A            [12]  977 	inc	_Main_numberOfDigitsB_1_13
      000338 E4               [12]  978 	clr	a
      000339 B5 4A 02         [24]  979 	cjne	a,_Main_numberOfDigitsB_1_13,00277$
      00033C 05 4B            [12]  980 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      00033E                        981 00277$:
                                    982 ;	assignment3.c:173: break;
      00033E 02 03 CB         [24]  983 	ljmp	00135$
                                    984 ;	assignment3.c:174: case '5':
      000341                        985 00129$:
                                    986 ;	assignment3.c:175: digits_b[numberOfDigitsB] = 5;
      000341 E5 4A            [12]  987 	mov	a,_Main_numberOfDigitsB_1_13
      000343 25 4A            [12]  988 	add	a,_Main_numberOfDigitsB_1_13
      000345 FE               [12]  989 	mov	r6,a
      000346 E5 4B            [12]  990 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      000348 33               [12]  991 	rlc	a
      000349 FF               [12]  992 	mov	r7,a
      00034A EE               [12]  993 	mov	a,r6
      00034B 24 3E            [12]  994 	add	a,#_Main_digits_b_1_13
      00034D F8               [12]  995 	mov	r0,a
      00034E 76 05            [12]  996 	mov	@r0,#0x05
      000350 08               [12]  997 	inc	r0
      000351 76 00            [12]  998 	mov	@r0,#0x00
                                    999 ;	assignment3.c:176: numberOfDigitsB++;
      000353 05 4A            [12] 1000 	inc	_Main_numberOfDigitsB_1_13
      000355 E4               [12] 1001 	clr	a
                                   1002 ;	assignment3.c:177: break;
                                   1003 ;	assignment3.c:178: case '6':
      000356 B5 4A 72         [24] 1004 	cjne	a,_Main_numberOfDigitsB_1_13,00135$
      000359 05 4B            [12] 1005 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      00035B 80 6E            [24] 1006 	sjmp	00135$
      00035D                       1007 00130$:
                                   1008 ;	assignment3.c:179: digits_b[numberOfDigitsB] = 6;
      00035D E5 4A            [12] 1009 	mov	a,_Main_numberOfDigitsB_1_13
      00035F 25 4A            [12] 1010 	add	a,_Main_numberOfDigitsB_1_13
      000361 FE               [12] 1011 	mov	r6,a
      000362 E5 4B            [12] 1012 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      000364 33               [12] 1013 	rlc	a
      000365 FF               [12] 1014 	mov	r7,a
      000366 EE               [12] 1015 	mov	a,r6
      000367 24 3E            [12] 1016 	add	a,#_Main_digits_b_1_13
      000369 F8               [12] 1017 	mov	r0,a
      00036A 76 06            [12] 1018 	mov	@r0,#0x06
      00036C 08               [12] 1019 	inc	r0
      00036D 76 00            [12] 1020 	mov	@r0,#0x00
                                   1021 ;	assignment3.c:180: numberOfDigitsB++;
      00036F 05 4A            [12] 1022 	inc	_Main_numberOfDigitsB_1_13
      000371 E4               [12] 1023 	clr	a
                                   1024 ;	assignment3.c:181: break;
                                   1025 ;	assignment3.c:182: case '7':
      000372 B5 4A 56         [24] 1026 	cjne	a,_Main_numberOfDigitsB_1_13,00135$
      000375 05 4B            [12] 1027 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      000377 80 52            [24] 1028 	sjmp	00135$
      000379                       1029 00131$:
                                   1030 ;	assignment3.c:183: digits_b[numberOfDigitsB] = 7;
      000379 E5 4A            [12] 1031 	mov	a,_Main_numberOfDigitsB_1_13
      00037B 25 4A            [12] 1032 	add	a,_Main_numberOfDigitsB_1_13
      00037D FE               [12] 1033 	mov	r6,a
      00037E E5 4B            [12] 1034 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      000380 33               [12] 1035 	rlc	a
      000381 FF               [12] 1036 	mov	r7,a
      000382 EE               [12] 1037 	mov	a,r6
      000383 24 3E            [12] 1038 	add	a,#_Main_digits_b_1_13
      000385 F8               [12] 1039 	mov	r0,a
      000386 76 07            [12] 1040 	mov	@r0,#0x07
      000388 08               [12] 1041 	inc	r0
      000389 76 00            [12] 1042 	mov	@r0,#0x00
                                   1043 ;	assignment3.c:184: numberOfDigitsB++;
      00038B 05 4A            [12] 1044 	inc	_Main_numberOfDigitsB_1_13
      00038D E4               [12] 1045 	clr	a
                                   1046 ;	assignment3.c:185: break;
                                   1047 ;	assignment3.c:186: case '8':
      00038E B5 4A 3A         [24] 1048 	cjne	a,_Main_numberOfDigitsB_1_13,00135$
      000391 05 4B            [12] 1049 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      000393 80 36            [24] 1050 	sjmp	00135$
      000395                       1051 00132$:
                                   1052 ;	assignment3.c:187: digits_b[numberOfDigitsB] = 8;
      000395 E5 4A            [12] 1053 	mov	a,_Main_numberOfDigitsB_1_13
      000397 25 4A            [12] 1054 	add	a,_Main_numberOfDigitsB_1_13
      000399 FE               [12] 1055 	mov	r6,a
      00039A E5 4B            [12] 1056 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      00039C 33               [12] 1057 	rlc	a
      00039D FF               [12] 1058 	mov	r7,a
      00039E EE               [12] 1059 	mov	a,r6
      00039F 24 3E            [12] 1060 	add	a,#_Main_digits_b_1_13
      0003A1 F8               [12] 1061 	mov	r0,a
      0003A2 76 08            [12] 1062 	mov	@r0,#0x08
      0003A4 08               [12] 1063 	inc	r0
      0003A5 76 00            [12] 1064 	mov	@r0,#0x00
                                   1065 ;	assignment3.c:188: numberOfDigitsB++;
      0003A7 05 4A            [12] 1066 	inc	_Main_numberOfDigitsB_1_13
      0003A9 E4               [12] 1067 	clr	a
                                   1068 ;	assignment3.c:189: break;
                                   1069 ;	assignment3.c:190: case '9':
      0003AA B5 4A 1E         [24] 1070 	cjne	a,_Main_numberOfDigitsB_1_13,00135$
      0003AD 05 4B            [12] 1071 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      0003AF 80 1A            [24] 1072 	sjmp	00135$
      0003B1                       1073 00133$:
                                   1074 ;	assignment3.c:191: digits_b[numberOfDigitsB] = 9;
      0003B1 E5 4A            [12] 1075 	mov	a,_Main_numberOfDigitsB_1_13
      0003B3 25 4A            [12] 1076 	add	a,_Main_numberOfDigitsB_1_13
      0003B5 FE               [12] 1077 	mov	r6,a
      0003B6 E5 4B            [12] 1078 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      0003B8 33               [12] 1079 	rlc	a
      0003B9 FF               [12] 1080 	mov	r7,a
      0003BA EE               [12] 1081 	mov	a,r6
      0003BB 24 3E            [12] 1082 	add	a,#_Main_digits_b_1_13
      0003BD F8               [12] 1083 	mov	r0,a
      0003BE 76 09            [12] 1084 	mov	@r0,#0x09
      0003C0 08               [12] 1085 	inc	r0
      0003C1 76 00            [12] 1086 	mov	@r0,#0x00
                                   1087 ;	assignment3.c:192: numberOfDigitsB++;
      0003C3 05 4A            [12] 1088 	inc	_Main_numberOfDigitsB_1_13
      0003C5 E4               [12] 1089 	clr	a
      0003C6 B5 4A 02         [24] 1090 	cjne	a,_Main_numberOfDigitsB_1_13,00282$
      0003C9 05 4B            [12] 1091 	inc	(_Main_numberOfDigitsB_1_13 + 1)
      0003CB                       1092 00282$:
                                   1093 ;	assignment3.c:196: }
      0003CB                       1094 00135$:
                                   1095 ;	assignment3.c:198: sendChar(key);
      0003CB 8B 82            [24] 1096 	mov	dpl,r3
      0003CD 12 05 D1         [24] 1097 	lcall	_sendChar
      0003D0 02 02 60         [24] 1098 	ljmp	00139$
      0003D3                       1099 00140$:
                                   1100 ;	assignment3.c:204: number_b = 0;
      0003D3 E4               [12] 1101 	clr	a
      0003D4 F5 48            [12] 1102 	mov	_Main_number_b_1_13,a
      0003D6 F5 49            [12] 1103 	mov	(_Main_number_b_1_13 + 1),a
                                   1104 ;	assignment3.c:205: check = numberOfDigitsB - 1;
      0003D8 E5 4A            [12] 1105 	mov	a,_Main_numberOfDigitsB_1_13
      0003DA 24 FF            [12] 1106 	add	a,#0xFF
      0003DC FC               [12] 1107 	mov	r4,a
      0003DD E5 4B            [12] 1108 	mov	a,(_Main_numberOfDigitsB_1_13 + 1)
      0003DF 34 FF            [12] 1109 	addc	a,#0xFF
      0003E1 FD               [12] 1110 	mov	r5,a
                                   1111 ;	assignment3.c:207: for (i = 0; i < numberOfDigitsB; i++) {
      0003E2 E4               [12] 1112 	clr	a
      0003E3 F5 50            [12] 1113 	mov	_Main_i_1_13,a
      0003E5 F5 51            [12] 1114 	mov	(_Main_i_1_13 + 1),a
      0003E7                       1115 00162$:
      0003E7 AE 50            [24] 1116 	mov	r6,_Main_i_1_13
      0003E9 AF 51            [24] 1117 	mov	r7,(_Main_i_1_13 + 1)
      0003EB C3               [12] 1118 	clr	c
      0003EC EE               [12] 1119 	mov	a,r6
      0003ED 95 4A            [12] 1120 	subb	a,_Main_numberOfDigitsB_1_13
      0003EF EF               [12] 1121 	mov	a,r7
      0003F0 95 4B            [12] 1122 	subb	a,(_Main_numberOfDigitsB_1_13 + 1)
      0003F2 40 03            [24] 1123 	jc	00283$
      0003F4 02 04 7A         [24] 1124 	ljmp	00142$
      0003F7                       1125 00283$:
                                   1126 ;	assignment3.c:208: digit = 1;
      0003F7 75 4C 01         [24] 1127 	mov	_Main_digit_1_13,#0x01
      0003FA 75 4D 00         [24] 1128 	mov	(_Main_digit_1_13 + 1),#0x00
                                   1129 ;	assignment3.c:209: for (j = 0; j < check; j++) {
      0003FD 7E 00            [12] 1130 	mov	r6,#0x00
      0003FF 7F 00            [12] 1131 	mov	r7,#0x00
      000401                       1132 00159$:
      000401 C3               [12] 1133 	clr	c
      000402 EE               [12] 1134 	mov	a,r6
      000403 9C               [12] 1135 	subb	a,r4
      000404 EF               [12] 1136 	mov	a,r7
      000405 64 80            [12] 1137 	xrl	a,#0x80
      000407 8D F0            [24] 1138 	mov	b,r5
      000409 63 F0 80         [24] 1139 	xrl	b,#0x80
      00040C 95 F0            [12] 1140 	subb	a,b
      00040E 50 29            [24] 1141 	jnc	00141$
                                   1142 ;	assignment3.c:210: digit *= 10;
      000410 85 4C 54         [24] 1143 	mov	__mulint_PARM_2,_Main_digit_1_13
      000413 85 4D 55         [24] 1144 	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
      000416 90 00 0A         [24] 1145 	mov	dptr,#0x000A
      000419 C0 07            [24] 1146 	push	ar7
      00041B C0 06            [24] 1147 	push	ar6
      00041D C0 05            [24] 1148 	push	ar5
      00041F C0 04            [24] 1149 	push	ar4
      000421 12 06 B1         [24] 1150 	lcall	__mulint
      000424 85 82 4C         [24] 1151 	mov	_Main_digit_1_13,dpl
      000427 85 83 4D         [24] 1152 	mov	(_Main_digit_1_13 + 1),dph
      00042A D0 04            [24] 1153 	pop	ar4
      00042C D0 05            [24] 1154 	pop	ar5
      00042E D0 06            [24] 1155 	pop	ar6
      000430 D0 07            [24] 1156 	pop	ar7
                                   1157 ;	assignment3.c:209: for (j = 0; j < check; j++) {
      000432 0E               [12] 1158 	inc	r6
      000433 BE 00 CB         [24] 1159 	cjne	r6,#0x00,00159$
      000436 0F               [12] 1160 	inc	r7
      000437 80 C8            [24] 1161 	sjmp	00159$
      000439                       1162 00141$:
                                   1163 ;	assignment3.c:212: number_b += digits_b[i] * digit;
      000439 E5 50            [12] 1164 	mov	a,_Main_i_1_13
      00043B 25 50            [12] 1165 	add	a,_Main_i_1_13
      00043D FE               [12] 1166 	mov	r6,a
      00043E E5 51            [12] 1167 	mov	a,(_Main_i_1_13 + 1)
      000440 33               [12] 1168 	rlc	a
      000441 EE               [12] 1169 	mov	a,r6
      000442 24 3E            [12] 1170 	add	a,#_Main_digits_b_1_13
      000444 F9               [12] 1171 	mov	r1,a
      000445 87 82            [24] 1172 	mov	dpl,@r1
      000447 09               [12] 1173 	inc	r1
      000448 87 83            [24] 1174 	mov	dph,@r1
      00044A 19               [12] 1175 	dec	r1
      00044B 85 4C 54         [24] 1176 	mov	__mulint_PARM_2,_Main_digit_1_13
      00044E 85 4D 55         [24] 1177 	mov	(__mulint_PARM_2 + 1),(_Main_digit_1_13 + 1)
      000451 C0 05            [24] 1178 	push	ar5
      000453 C0 04            [24] 1179 	push	ar4
      000455 12 06 B1         [24] 1180 	lcall	__mulint
      000458 AE 82            [24] 1181 	mov	r6,dpl
      00045A AF 83            [24] 1182 	mov	r7,dph
      00045C D0 04            [24] 1183 	pop	ar4
      00045E D0 05            [24] 1184 	pop	ar5
      000460 EE               [12] 1185 	mov	a,r6
      000461 25 48            [12] 1186 	add	a,_Main_number_b_1_13
      000463 F5 48            [12] 1187 	mov	_Main_number_b_1_13,a
      000465 EF               [12] 1188 	mov	a,r7
      000466 35 49            [12] 1189 	addc	a,(_Main_number_b_1_13 + 1)
      000468 F5 49            [12] 1190 	mov	(_Main_number_b_1_13 + 1),a
                                   1191 ;	assignment3.c:213: check--;
      00046A 1C               [12] 1192 	dec	r4
      00046B BC FF 01         [24] 1193 	cjne	r4,#0xFF,00286$
      00046E 1D               [12] 1194 	dec	r5
      00046F                       1195 00286$:
                                   1196 ;	assignment3.c:207: for (i = 0; i < numberOfDigitsB; i++) {
      00046F 05 50            [12] 1197 	inc	_Main_i_1_13
      000471 E4               [12] 1198 	clr	a
      000472 B5 50 02         [24] 1199 	cjne	a,_Main_i_1_13,00287$
      000475 05 51            [12] 1200 	inc	(_Main_i_1_13 + 1)
      000477                       1201 00287$:
      000477 02 03 E7         [24] 1202 	ljmp	00162$
      00047A                       1203 00142$:
                                   1204 ;	assignment3.c:217: sum = number_a + number_b;
      00047A E5 48            [12] 1205 	mov	a,_Main_number_b_1_13
      00047C 25 3A            [12] 1206 	add	a,_Main_number_a_1_13
      00047E F5 52            [12] 1207 	mov	_Main_sum_1_13,a
      000480 E5 49            [12] 1208 	mov	a,(_Main_number_b_1_13 + 1)
      000482 35 3B            [12] 1209 	addc	a,(_Main_number_a_1_13 + 1)
      000484 F5 53            [12] 1210 	mov	(_Main_sum_1_13 + 1),a
                                   1211 ;	assignment3.c:219: digit = 10000;
      000486 75 4C 10         [24] 1212 	mov	_Main_digit_1_13,#0x10
      000489 75 4D 27         [24] 1213 	mov	(_Main_digit_1_13 + 1),#0x27
                                   1214 ;	assignment3.c:221: for (i = 0; i < 5; i++) {
      00048C E4               [12] 1215 	clr	a
      00048D FC               [12] 1216 	mov	r4,a
      00048E FD               [12] 1217 	mov	r5,a
      00048F F5 50            [12] 1218 	mov	_Main_i_1_13,a
      000491 F5 51            [12] 1219 	mov	(_Main_i_1_13 + 1),a
      000493                       1220 00164$:
                                   1221 ;	assignment3.c:222: sum_digit = sum / digit;
      000493 85 4C 54         [24] 1222 	mov	__divuint_PARM_2,_Main_digit_1_13
      000496 85 4D 55         [24] 1223 	mov	(__divuint_PARM_2 + 1),(_Main_digit_1_13 + 1)
      000499 85 52 82         [24] 1224 	mov	dpl,_Main_sum_1_13
      00049C 85 53 83         [24] 1225 	mov	dph,(_Main_sum_1_13 + 1)
      00049F C0 05            [24] 1226 	push	ar5
      0004A1 C0 04            [24] 1227 	push	ar4
      0004A3 12 06 88         [24] 1228 	lcall	__divuint
      0004A6 AE 82            [24] 1229 	mov	r6,dpl
      0004A8 AF 83            [24] 1230 	mov	r7,dph
      0004AA D0 04            [24] 1231 	pop	ar4
      0004AC D0 05            [24] 1232 	pop	ar5
                                   1233 ;	assignment3.c:224: if (sum_check == 0 && sum_digit != 0) {
      0004AE EC               [12] 1234 	mov	a,r4
      0004AF 4D               [12] 1235 	orl	a,r5
      0004B0 70 09            [24] 1236 	jnz	00144$
      0004B2 EE               [12] 1237 	mov	a,r6
      0004B3 4F               [12] 1238 	orl	a,r7
      0004B4 60 05            [24] 1239 	jz	00144$
                                   1240 ;	assignment3.c:225: sum_check++;
      0004B6 0C               [12] 1241 	inc	r4
      0004B7 BC 00 01         [24] 1242 	cjne	r4,#0x00,00290$
      0004BA 0D               [12] 1243 	inc	r5
      0004BB                       1244 00290$:
      0004BB                       1245 00144$:
                                   1246 ;	assignment3.c:227: if (sum_check > 0) {
      0004BB C3               [12] 1247 	clr	c
      0004BC E4               [12] 1248 	clr	a
      0004BD 9C               [12] 1249 	subb	a,r4
      0004BE 74 80            [12] 1250 	mov	a,#(0x00 ^ 0x80)
      0004C0 8D F0            [24] 1251 	mov	b,r5
      0004C2 63 F0 80         [24] 1252 	xrl	b,#0x80
      0004C5 95 F0            [12] 1253 	subb	a,b
      0004C7 50 1F            [24] 1254 	jnc	00147$
                                   1255 ;	assignment3.c:228: key = (sum_digit % 10) + '0';
      0004C9 75 54 0A         [24] 1256 	mov	__modsint_PARM_2,#0x0A
      0004CC 75 55 00         [24] 1257 	mov	(__modsint_PARM_2 + 1),#0x00
      0004CF 8E 82            [24] 1258 	mov	dpl,r6
      0004D1 8F 83            [24] 1259 	mov	dph,r7
      0004D3 C0 05            [24] 1260 	push	ar5
      0004D5 C0 04            [24] 1261 	push	ar4
      0004D7 12 07 37         [24] 1262 	lcall	__modsint
      0004DA AE 82            [24] 1263 	mov	r6,dpl
      0004DC 74 30            [12] 1264 	mov	a,#0x30
      0004DE 2E               [12] 1265 	add	a,r6
                                   1266 ;	assignment3.c:231: sendChar(key);
      0004DF F5 82            [12] 1267 	mov	dpl,a
      0004E1 12 05 D1         [24] 1268 	lcall	_sendChar
      0004E4 D0 04            [24] 1269 	pop	ar4
      0004E6 D0 05            [24] 1270 	pop	ar5
      0004E8                       1271 00147$:
                                   1272 ;	assignment3.c:233: digit /= 10;
      0004E8 75 54 0A         [24] 1273 	mov	__divsint_PARM_2,#0x0A
      0004EB 75 55 00         [24] 1274 	mov	(__divsint_PARM_2 + 1),#0x00
      0004EE 85 4C 82         [24] 1275 	mov	dpl,_Main_digit_1_13
      0004F1 85 4D 83         [24] 1276 	mov	dph,(_Main_digit_1_13 + 1)
      0004F4 C0 05            [24] 1277 	push	ar5
      0004F6 C0 04            [24] 1278 	push	ar4
      0004F8 12 07 6D         [24] 1279 	lcall	__divsint
      0004FB 85 82 4C         [24] 1280 	mov	_Main_digit_1_13,dpl
      0004FE 85 83 4D         [24] 1281 	mov	(_Main_digit_1_13 + 1),dph
      000501 D0 04            [24] 1282 	pop	ar4
      000503 D0 05            [24] 1283 	pop	ar5
                                   1284 ;	assignment3.c:221: for (i = 0; i < 5; i++) {
      000505 05 50            [12] 1285 	inc	_Main_i_1_13
      000507 E4               [12] 1286 	clr	a
      000508 B5 50 02         [24] 1287 	cjne	a,_Main_i_1_13,00292$
      00050B 05 51            [12] 1288 	inc	(_Main_i_1_13 + 1)
      00050D                       1289 00292$:
      00050D C3               [12] 1290 	clr	c
      00050E E5 50            [12] 1291 	mov	a,_Main_i_1_13
      000510 94 05            [12] 1292 	subb	a,#0x05
      000512 E5 51            [12] 1293 	mov	a,(_Main_i_1_13 + 1)
      000514 64 80            [12] 1294 	xrl	a,#0x80
      000516 94 80            [12] 1295 	subb	a,#0x80
      000518 50 03            [24] 1296 	jnc	00293$
      00051A 02 04 93         [24] 1297 	ljmp	00164$
      00051D                       1298 00293$:
                                   1299 ;	assignment3.c:237: keypad();
      00051D 12 06 1E         [24] 1300 	lcall	_keypad
                                   1301 ;	assignment3.c:238: clearDisplay();
      000520 12 05 B5         [24] 1302 	lcall	_clearDisplay
                                   1303 ;	assignment3.c:240: digits_a[0] = 0;
      000523 E4               [12] 1304 	clr	a
      000524 F5 30            [12] 1305 	mov	(_Main_digits_a_1_13 + 0),a
      000526 F5 31            [12] 1306 	mov	(_Main_digits_a_1_13 + 1),a
                                   1307 ;	assignment3.c:241: digits_a[1] = 0;
      000528 F5 32            [12] 1308 	mov	((_Main_digits_a_1_13 + 0x0002) + 0),a
      00052A F5 33            [12] 1309 	mov	((_Main_digits_a_1_13 + 0x0002) + 1),a
                                   1310 ;	assignment3.c:242: digits_a[2] = 0;
      00052C F5 34            [12] 1311 	mov	((_Main_digits_a_1_13 + 0x0004) + 0),a
      00052E F5 35            [12] 1312 	mov	((_Main_digits_a_1_13 + 0x0004) + 1),a
                                   1313 ;	assignment3.c:243: digits_a[3] = 0;
      000530 F5 36            [12] 1314 	mov	((_Main_digits_a_1_13 + 0x0006) + 0),a
      000532 F5 37            [12] 1315 	mov	((_Main_digits_a_1_13 + 0x0006) + 1),a
                                   1316 ;	assignment3.c:244: digits_a[4] = 0;
      000534 F5 38            [12] 1317 	mov	((_Main_digits_a_1_13 + 0x0008) + 0),a
      000536 F5 39            [12] 1318 	mov	((_Main_digits_a_1_13 + 0x0008) + 1),a
                                   1319 ;	assignment3.c:246: numberOfDigitsA = 0;
      000538 F5 3C            [12] 1320 	mov	_Main_numberOfDigitsA_1_13,a
      00053A F5 3D            [12] 1321 	mov	(_Main_numberOfDigitsA_1_13 + 1),a
                                   1322 ;	assignment3.c:247: digits_b[0] = 0;
      00053C F5 3E            [12] 1323 	mov	(_Main_digits_b_1_13 + 0),a
      00053E F5 3F            [12] 1324 	mov	(_Main_digits_b_1_13 + 1),a
                                   1325 ;	assignment3.c:248: digits_b[1] = 0;
      000540 F5 40            [12] 1326 	mov	((_Main_digits_b_1_13 + 0x0002) + 0),a
      000542 F5 41            [12] 1327 	mov	((_Main_digits_b_1_13 + 0x0002) + 1),a
                                   1328 ;	assignment3.c:249: digits_b[2] = 0;
      000544 F5 42            [12] 1329 	mov	((_Main_digits_b_1_13 + 0x0004) + 0),a
      000546 F5 43            [12] 1330 	mov	((_Main_digits_b_1_13 + 0x0004) + 1),a
                                   1331 ;	assignment3.c:250: digits_b[3] = 0;
      000548 F5 44            [12] 1332 	mov	((_Main_digits_b_1_13 + 0x0006) + 0),a
      00054A F5 45            [12] 1333 	mov	((_Main_digits_b_1_13 + 0x0006) + 1),a
                                   1334 ;	assignment3.c:251: digits_b[4] = 0;
      00054C F5 46            [12] 1335 	mov	((_Main_digits_b_1_13 + 0x0008) + 0),a
      00054E F5 47            [12] 1336 	mov	((_Main_digits_b_1_13 + 0x0008) + 1),a
                                   1337 ;	assignment3.c:253: numberOfDigitsB = 0;
      000550 F5 4A            [12] 1338 	mov	_Main_numberOfDigitsB_1_13,a
      000552 F5 4B            [12] 1339 	mov	(_Main_numberOfDigitsB_1_13 + 1),a
      000554 02 00 40         [24] 1340 	ljmp	00118$
                                   1341 ;------------------------------------------------------------
                                   1342 ;Allocation info for local variables in function 'returnHome'
                                   1343 ;------------------------------------------------------------
                                   1344 ;	assignment3.c:260: void returnHome(void) {
                                   1345 ;	-----------------------------------------
                                   1346 ;	 function returnHome
                                   1347 ;	-----------------------------------------
      000557                       1348 _returnHome:
                                   1349 ;	assignment3.c:261: RS = 0;
      000557 C2 B3            [12] 1350 	clr	_P3_3
                                   1351 ;	assignment3.c:262: P1 = 0x02; // LCD command to return home (the first location of the first lcd line)
      000559 75 90 02         [24] 1352 	mov	_P1,#0x02
                                   1353 ;	assignment3.c:263: E = 1;
      00055C D2 B2            [12] 1354 	setb	_P3_2
                                   1355 ;	assignment3.c:264: E = 0;
      00055E C2 B2            [12] 1356 	clr	_P3_2
                                   1357 ;	assignment3.c:265: big_delay(); // This operation needs a bigger delay
      000560 02 06 14         [24] 1358 	ljmp	_big_delay
                                   1359 ;------------------------------------------------------------
                                   1360 ;Allocation info for local variables in function 'entryModeSet'
                                   1361 ;------------------------------------------------------------
                                   1362 ;	assignment3.c:268: void entryModeSet() {
                                   1363 ;	-----------------------------------------
                                   1364 ;	 function entryModeSet
                                   1365 ;	-----------------------------------------
      000563                       1366 _entryModeSet:
                                   1367 ;	assignment3.c:269: RS = 0;
      000563 C2 B3            [12] 1368 	clr	_P3_3
                                   1369 ;	assignment3.c:270: P1 = 0x06;
      000565 75 90 06         [24] 1370 	mov	_P1,#0x06
                                   1371 ;	assignment3.c:271: E = 1;
      000568 D2 B2            [12] 1372 	setb	_P3_2
                                   1373 ;	assignment3.c:272: E = 0;
      00056A C2 B2            [12] 1374 	clr	_P3_2
                                   1375 ;	assignment3.c:273: delay();
      00056C 02 06 0B         [24] 1376 	ljmp	_delay
                                   1377 ;------------------------------------------------------------
                                   1378 ;Allocation info for local variables in function 'displayOnOffControl'
                                   1379 ;------------------------------------------------------------
                                   1380 ;	assignment3.c:276: void displayOnOffControl(__bit display, __bit cursor, __bit blinking) {
                                   1381 ;	-----------------------------------------
                                   1382 ;	 function displayOnOffControl
                                   1383 ;	-----------------------------------------
      00056F                       1384 _displayOnOffControl:
                                   1385 ;	assignment3.c:277: P1_7 = 0;
      00056F C2 97            [12] 1386 	clr	_P1_7
                                   1387 ;	assignment3.c:278: P1_6 = 0;
      000571 C2 96            [12] 1388 	clr	_P1_6
                                   1389 ;	assignment3.c:279: P1_5 = 0;
      000573 C2 95            [12] 1390 	clr	_P1_5
                                   1391 ;	assignment3.c:280: P1_4 = 0;
      000575 C2 94            [12] 1392 	clr	_P1_4
                                   1393 ;	assignment3.c:281: P1_3 = 1;
      000577 D2 93            [12] 1394 	setb	_P1_3
                                   1395 ;	assignment3.c:282: P1_2 = display;
      000579 A2 00            [12] 1396 	mov	c,_displayOnOffControl_PARM_1
      00057B 92 92            [24] 1397 	mov	_P1_2,c
                                   1398 ;	assignment3.c:283: P1_1 = cursor;
      00057D A2 01            [12] 1399 	mov	c,_displayOnOffControl_PARM_2
      00057F 92 91            [24] 1400 	mov	_P1_1,c
                                   1401 ;	assignment3.c:284: P1_0 = blinking;
      000581 A2 02            [12] 1402 	mov	c,_displayOnOffControl_PARM_3
      000583 92 90            [24] 1403 	mov	_P1_0,c
                                   1404 ;	assignment3.c:285: E = 1;
      000585 D2 B2            [12] 1405 	setb	_P3_2
                                   1406 ;	assignment3.c:286: E = 0;
      000587 C2 B2            [12] 1407 	clr	_P3_2
                                   1408 ;	assignment3.c:287: delay();
      000589 02 06 0B         [24] 1409 	ljmp	_delay
                                   1410 ;------------------------------------------------------------
                                   1411 ;Allocation info for local variables in function 'cursorOrDisplayShift'
                                   1412 ;------------------------------------------------------------
                                   1413 ;	assignment3.c:290: void cursorOrDisplayShift(__bit sc, __bit rl) {
                                   1414 ;	-----------------------------------------
                                   1415 ;	 function cursorOrDisplayShift
                                   1416 ;	-----------------------------------------
      00058C                       1417 _cursorOrDisplayShift:
                                   1418 ;	assignment3.c:291: RS = 0;
      00058C C2 B3            [12] 1419 	clr	_P3_3
                                   1420 ;	assignment3.c:292: P1_7 = 0;
      00058E C2 97            [12] 1421 	clr	_P1_7
                                   1422 ;	assignment3.c:293: P1_6 = 0;
      000590 C2 96            [12] 1423 	clr	_P1_6
                                   1424 ;	assignment3.c:294: P1_5 = 0;
      000592 C2 95            [12] 1425 	clr	_P1_5
                                   1426 ;	assignment3.c:295: P1_4 = 1;
      000594 D2 94            [12] 1427 	setb	_P1_4
                                   1428 ;	assignment3.c:296: P1_3 = sc;
      000596 A2 03            [12] 1429 	mov	c,_cursorOrDisplayShift_PARM_1
      000598 92 93            [24] 1430 	mov	_P1_3,c
                                   1431 ;	assignment3.c:297: P1_2 = rl;
      00059A A2 04            [12] 1432 	mov	c,_cursorOrDisplayShift_PARM_2
      00059C 92 92            [24] 1433 	mov	_P1_2,c
                                   1434 ;	assignment3.c:298: P1_1 = 0;
      00059E C2 91            [12] 1435 	clr	_P1_1
                                   1436 ;	assignment3.c:299: P1_0 = 0;
      0005A0 C2 90            [12] 1437 	clr	_P1_0
                                   1438 ;	assignment3.c:300: E = 1;
      0005A2 D2 B2            [12] 1439 	setb	_P3_2
                                   1440 ;	assignment3.c:301: E = 0;
      0005A4 C2 B2            [12] 1441 	clr	_P3_2
                                   1442 ;	assignment3.c:302: delay();
      0005A6 02 06 0B         [24] 1443 	ljmp	_delay
                                   1444 ;------------------------------------------------------------
                                   1445 ;Allocation info for local variables in function 'functionSet'
                                   1446 ;------------------------------------------------------------
                                   1447 ;	assignment3.c:305: void functionSet(void) {
                                   1448 ;	-----------------------------------------
                                   1449 ;	 function functionSet
                                   1450 ;	-----------------------------------------
      0005A9                       1451 _functionSet:
                                   1452 ;	assignment3.c:306: RS = 0;
      0005A9 C2 B3            [12] 1453 	clr	_P3_3
                                   1454 ;	assignment3.c:307: P1 = 0x38; // 8-bit mode, 2 lines LCD
      0005AB 75 90 38         [24] 1455 	mov	_P1,#0x38
                                   1456 ;	assignment3.c:308: E = 1;
      0005AE D2 B2            [12] 1457 	setb	_P3_2
                                   1458 ;	assignment3.c:309: E = 0;
      0005B0 C2 B2            [12] 1459 	clr	_P3_2
                                   1460 ;	assignment3.c:310: delay();
      0005B2 02 06 0B         [24] 1461 	ljmp	_delay
                                   1462 ;------------------------------------------------------------
                                   1463 ;Allocation info for local variables in function 'clearDisplay'
                                   1464 ;------------------------------------------------------------
                                   1465 ;	assignment3.c:313: void clearDisplay(void) {
                                   1466 ;	-----------------------------------------
                                   1467 ;	 function clearDisplay
                                   1468 ;	-----------------------------------------
      0005B5                       1469 _clearDisplay:
                                   1470 ;	assignment3.c:314: RS = 0;
      0005B5 C2 B3            [12] 1471 	clr	_P3_3
                                   1472 ;	assignment3.c:315: P1 = 0x01; // command to clear LCD and return the cursor to the home position
      0005B7 75 90 01         [24] 1473 	mov	_P1,#0x01
                                   1474 ;	assignment3.c:316: E = 1;
      0005BA D2 B2            [12] 1475 	setb	_P3_2
                                   1476 ;	assignment3.c:317: E = 0;
      0005BC C2 B2            [12] 1477 	clr	_P3_2
                                   1478 ;	assignment3.c:318: big_delay(); // This operation needs a bigger delay
      0005BE 02 06 14         [24] 1479 	ljmp	_big_delay
                                   1480 ;------------------------------------------------------------
                                   1481 ;Allocation info for local variables in function 'setDdRamAddress'
                                   1482 ;------------------------------------------------------------
                                   1483 ;address                   Allocated to registers r7 
                                   1484 ;------------------------------------------------------------
                                   1485 ;	assignment3.c:321: void setDdRamAddress(char address) {  // Determine the place to place the next character - First LCD location address in 00h for line 1 and 40h for line 2
                                   1486 ;	-----------------------------------------
                                   1487 ;	 function setDdRamAddress
                                   1488 ;	-----------------------------------------
      0005C1                       1489 _setDdRamAddress:
      0005C1 AF 82            [24] 1490 	mov	r7,dpl
                                   1491 ;	assignment3.c:322: RS = 0;
      0005C3 C2 B3            [12] 1492 	clr	_P3_3
                                   1493 ;	assignment3.c:323: P1 = address | 0x80;  // set the MSB to detect that this is an address
      0005C5 74 80            [12] 1494 	mov	a,#0x80
      0005C7 4F               [12] 1495 	orl	a,r7
      0005C8 F5 90            [12] 1496 	mov	_P1,a
                                   1497 ;	assignment3.c:324: E = 1;
      0005CA D2 B2            [12] 1498 	setb	_P3_2
                                   1499 ;	assignment3.c:325: E = 0;
      0005CC C2 B2            [12] 1500 	clr	_P3_2
                                   1501 ;	assignment3.c:326: delay();
      0005CE 02 06 0B         [24] 1502 	ljmp	_delay
                                   1503 ;------------------------------------------------------------
                                   1504 ;Allocation info for local variables in function 'sendChar'
                                   1505 ;------------------------------------------------------------
                                   1506 ;c                         Allocated to registers r7 
                                   1507 ;------------------------------------------------------------
                                   1508 ;	assignment3.c:331: void sendChar(char c) {  // Function to send one character to be displayed on the LCD
                                   1509 ;	-----------------------------------------
                                   1510 ;	 function sendChar
                                   1511 ;	-----------------------------------------
      0005D1                       1512 _sendChar:
      0005D1 AF 82            [24] 1513 	mov	r7,dpl
                                   1514 ;	assignment3.c:332: RS = 1;
      0005D3 D2 B3            [12] 1515 	setb	_P3_3
                                   1516 ;	assignment3.c:333: P1 = c;
      0005D5 8F 90            [24] 1517 	mov	_P1,r7
                                   1518 ;	assignment3.c:334: E = 1;
      0005D7 D2 B2            [12] 1519 	setb	_P3_2
                                   1520 ;	assignment3.c:335: E = 0;
      0005D9 C2 B2            [12] 1521 	clr	_P3_2
                                   1522 ;	assignment3.c:336: delay();
      0005DB 02 06 0B         [24] 1523 	ljmp	_delay
                                   1524 ;------------------------------------------------------------
                                   1525 ;Allocation info for local variables in function 'sendString'
                                   1526 ;------------------------------------------------------------
                                   1527 ;str                       Allocated to registers 
                                   1528 ;c                         Allocated to registers r3 
                                   1529 ;------------------------------------------------------------
                                   1530 ;	assignment3.c:339: void sendString(char* str) {  // Function to send a string of characters to be displayed on the lCD
                                   1531 ;	-----------------------------------------
                                   1532 ;	 function sendString
                                   1533 ;	-----------------------------------------
      0005DE                       1534 _sendString:
      0005DE AD 82            [24] 1535 	mov	r5,dpl
      0005E0 AE 83            [24] 1536 	mov	r6,dph
      0005E2 AF F0            [24] 1537 	mov	r7,b
                                   1538 ;	assignment3.c:341: while (c = *str++) {
      0005E4                       1539 00101$:
      0005E4 8D 82            [24] 1540 	mov	dpl,r5
      0005E6 8E 83            [24] 1541 	mov	dph,r6
      0005E8 8F F0            [24] 1542 	mov	b,r7
      0005EA 12 07 1B         [24] 1543 	lcall	__gptrget
      0005ED FC               [12] 1544 	mov	r4,a
      0005EE A3               [24] 1545 	inc	dptr
      0005EF AD 82            [24] 1546 	mov	r5,dpl
      0005F1 AE 83            [24] 1547 	mov	r6,dph
      0005F3 EC               [12] 1548 	mov	a,r4
      0005F4 FB               [12] 1549 	mov	r3,a
      0005F5 60 13            [24] 1550 	jz	00104$
                                   1551 ;	assignment3.c:342: sendChar(c);
      0005F7 8B 82            [24] 1552 	mov	dpl,r3
      0005F9 C0 07            [24] 1553 	push	ar7
      0005FB C0 06            [24] 1554 	push	ar6
      0005FD C0 05            [24] 1555 	push	ar5
      0005FF 12 05 D1         [24] 1556 	lcall	_sendChar
      000602 D0 05            [24] 1557 	pop	ar5
      000604 D0 06            [24] 1558 	pop	ar6
      000606 D0 07            [24] 1559 	pop	ar7
      000608 80 DA            [24] 1560 	sjmp	00101$
      00060A                       1561 00104$:
      00060A 22               [24] 1562 	ret
                                   1563 ;------------------------------------------------------------
                                   1564 ;Allocation info for local variables in function 'delay'
                                   1565 ;------------------------------------------------------------
                                   1566 ;c                         Allocated to registers r7 
                                   1567 ;------------------------------------------------------------
                                   1568 ;	assignment3.c:346: void delay(void) {
                                   1569 ;	-----------------------------------------
                                   1570 ;	 function delay
                                   1571 ;	-----------------------------------------
      00060B                       1572 _delay:
                                   1573 ;	assignment3.c:348: for (c = 0; c < 50; c++);
      00060B 7F 32            [12] 1574 	mov	r7,#0x32
      00060D                       1575 00104$:
      00060D EF               [12] 1576 	mov	a,r7
      00060E 14               [12] 1577 	dec	a
      00060F FE               [12] 1578 	mov	r6,a
      000610 FF               [12] 1579 	mov	r7,a
      000611 70 FA            [24] 1580 	jnz	00104$
      000613 22               [24] 1581 	ret
                                   1582 ;------------------------------------------------------------
                                   1583 ;Allocation info for local variables in function 'big_delay'
                                   1584 ;------------------------------------------------------------
                                   1585 ;c                         Allocated to registers r7 
                                   1586 ;------------------------------------------------------------
                                   1587 ;	assignment3.c:351: void big_delay(void) {
                                   1588 ;	-----------------------------------------
                                   1589 ;	 function big_delay
                                   1590 ;	-----------------------------------------
      000614                       1591 _big_delay:
                                   1592 ;	assignment3.c:353: for (c = 0; c < 255; c++);
      000614 7F FF            [12] 1593 	mov	r7,#0xFF
      000616                       1594 00104$:
      000616 8F 06            [24] 1595 	mov	ar6,r7
      000618 1E               [12] 1596 	dec	r6
      000619 EE               [12] 1597 	mov	a,r6
      00061A FF               [12] 1598 	mov	r7,a
      00061B 70 F9            [24] 1599 	jnz	00104$
      00061D 22               [24] 1600 	ret
                                   1601 ;------------------------------------------------------------
                                   1602 ;Allocation info for local variables in function 'keypad'
                                   1603 ;------------------------------------------------------------
                                   1604 ;row                       Allocated to registers r6 
                                   1605 ;col                       Allocated to registers r3 
                                   1606 ;keypad                    Allocated with name '_keypad_keypad_1_53'
                                   1607 ;i                         Allocated to registers r5 
                                   1608 ;gotkey                    Allocated to registers r7 
                                   1609 ;------------------------------------------------------------
                                   1610 ;	assignment3.c:357: void keypad(void) {
                                   1611 ;	-----------------------------------------
                                   1612 ;	 function keypad
                                   1613 ;	-----------------------------------------
      00061E                       1614 _keypad:
                                   1615 ;	assignment3.c:360: unsigned char keypad[4][3] = {   // This array contains the ASCII of the keypad keys
      00061E 75 54 33         [24] 1616 	mov	_keypad_keypad_1_53,#0x33
      000621 75 55 32         [24] 1617 	mov	(_keypad_keypad_1_53 + 0x0001),#0x32
      000624 75 56 31         [24] 1618 	mov	(_keypad_keypad_1_53 + 0x0002),#0x31
      000627 75 57 36         [24] 1619 	mov	(_keypad_keypad_1_53 + 0x0003),#0x36
      00062A 75 58 35         [24] 1620 	mov	(_keypad_keypad_1_53 + 0x0004),#0x35
      00062D 75 59 34         [24] 1621 	mov	(_keypad_keypad_1_53 + 0x0005),#0x34
      000630 75 5A 39         [24] 1622 	mov	(_keypad_keypad_1_53 + 0x0006),#0x39
      000633 75 5B 38         [24] 1623 	mov	(_keypad_keypad_1_53 + 0x0007),#0x38
      000636 75 5C 37         [24] 1624 	mov	(_keypad_keypad_1_53 + 0x0008),#0x37
      000639 75 5D 3D         [24] 1625 	mov	(_keypad_keypad_1_53 + 0x0009),#0x3D
      00063C 75 5E 30         [24] 1626 	mov	(_keypad_keypad_1_53 + 0x000a),#0x30
      00063F 75 5F 2B         [24] 1627 	mov	(_keypad_keypad_1_53 + 0x000b),#0x2B
                                   1628 ;	assignment3.c:367: unsigned char gotkey = 0;
      000642 7F 00            [12] 1629 	mov	r7,#0x00
                                   1630 ;	assignment3.c:368: while(1){
      000644                       1631 00107$:
                                   1632 ;	assignment3.c:369: row = 0xf7;  // The first row (connected to P0.3) will be zero
      000644 7E F7            [12] 1633 	mov	r6,#0xF7
                                   1634 ;	assignment3.c:371: for (i=0;i<4;++i){ // loop over the 4 rows
      000646 7D 00            [12] 1635 	mov	r5,#0x00
      000648 7C 00            [12] 1636 	mov	r4,#0x00
      00064A                       1637 00109$:
                                   1638 ;	assignment3.c:373: P0 = 0xff;     // Initialize the 4 rows to '1' and set the column ports to inputs
      00064A 75 80 FF         [24] 1639 	mov	_P0,#0xFF
                                   1640 ;	assignment3.c:374: P0 = P0 & row; // clear one row at a time
      00064D EE               [12] 1641 	mov	a,r6
      00064E 52 80            [12] 1642 	anl	_P0,a
                                   1643 ;	assignment3.c:375: col = P0 & 0x70;  // Read the 3 columns
      000650 74 70            [12] 1644 	mov	a,#0x70
      000652 55 80            [12] 1645 	anl	a,_P0
      000654 FB               [12] 1646 	mov	r3,a
                                   1647 ;	assignment3.c:376: if (col != 0x70){ // If any column is zero i.e. a key is pressed
      000655 BB 70 02         [24] 1648 	cjne	r3,#0x70,00125$
      000658 80 19            [24] 1649 	sjmp	00102$
      00065A                       1650 00125$:
                                   1651 ;	assignment3.c:377: col = (~col) & 0x70;  // because the selected column returns zero
      00065A EB               [12] 1652 	mov	a,r3
      00065B F4               [12] 1653 	cpl	a
      00065C FA               [12] 1654 	mov	r2,a
      00065D 74 70            [12] 1655 	mov	a,#0x70
      00065F 5A               [12] 1656 	anl	a,r2
                                   1657 ;	assignment3.c:378: col = col >> 5;       // The column variable now contain the number of the selected column
      000660 C4               [12] 1658 	swap	a
      000661 03               [12] 1659 	rr	a
      000662 54 07            [12] 1660 	anl	a,#0x07
      000664 FB               [12] 1661 	mov	r3,a
                                   1662 ;	assignment3.c:379: gotkey = keypad[i][col]; // Get the ASCII of the corresponding pressed key
      000665 ED               [12] 1663 	mov	a,r5
      000666 75 F0 03         [24] 1664 	mov	b,#0x03
      000669 A4               [48] 1665 	mul	ab
      00066A 24 54            [12] 1666 	add	a,#_keypad_keypad_1_53
      00066C FA               [12] 1667 	mov	r2,a
      00066D 2B               [12] 1668 	add	a,r3
      00066E F9               [12] 1669 	mov	r1,a
      00066F 87 07            [24] 1670 	mov	ar7,@r1
                                   1671 ;	assignment3.c:380: break;  // Since a key was detected -> Exit the for loop
      000671 80 0F            [24] 1672 	sjmp	00103$
      000673                       1673 00102$:
                                   1674 ;	assignment3.c:382: row = row >> 1;   // No key is detected yet, try the next row
      000673 EE               [12] 1675 	mov	a,r6
      000674 C3               [12] 1676 	clr	c
      000675 13               [12] 1677 	rrc	a
      000676 FE               [12] 1678 	mov	r6,a
                                   1679 ;	assignment3.c:383: row = row | 0xf0; // Only one of the least 4 significant bits is '0' at a time 
      000677 43 06 F0         [24] 1680 	orl	ar6,#0xF0
                                   1681 ;	assignment3.c:371: for (i=0;i<4;++i){ // loop over the 4 rows
      00067A 0C               [12] 1682 	inc	r4
      00067B 8C 05            [24] 1683 	mov	ar5,r4
      00067D BC 04 00         [24] 1684 	cjne	r4,#0x04,00126$
      000680                       1685 00126$:
      000680 40 C8            [24] 1686 	jc	00109$
      000682                       1687 00103$:
                                   1688 ;	assignment3.c:387: if (gotkey != 0){break;}  // Since a key was detected -> exit the while loop
      000682 EF               [12] 1689 	mov	a,r7
      000683 60 BF            [24] 1690 	jz	00107$
                                   1691 ;	assignment3.c:391: P1 = gotkey;  // Send the detected key to the output
      000685 8F 90            [24] 1692 	mov	_P1,r7
      000687 22               [24] 1693 	ret
                                   1694 	.area CSEG    (CODE)
                                   1695 	.area CONST   (CODE)
                                   1696 	.area XINIT   (CODE)
                                   1697 	.area CABS    (ABS,CODE)
