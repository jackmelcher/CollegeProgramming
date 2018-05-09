/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 31L/hw4/assignment4_67574625/assignment4_67574625_counter.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );
char *ieee_p_3620187407_sub_436351764_3965413181(char *, char *, char *, char *, int );


static void work_a_0565269370_3212880686_p_0(char *t0)
{
    char t14[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    int t18;
    int t19;
    unsigned int t20;
    int t21;
    int t22;
    unsigned int t23;
    unsigned int t24;

LAB0:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 2368U);
    t4 = *((char **)t2);
    t2 = (t0 + 3752);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 32U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 3672);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB11;

LAB12:    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)2);
    if (t6 == 1)
        goto LAB15;

LAB16:    t1 = (unsigned char)0;

LAB17:    if (t1 != 0)
        goto LAB13;

LAB14:    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)2);
    if (t6 == 1)
        goto LAB23;

LAB24:    t1 = (unsigned char)0;

LAB25:    if (t1 != 0)
        goto LAB21;

LAB22:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(49, ng0);
    t4 = xsi_get_transient_memory(32U);
    memset(t4, 0, 32U);
    t11 = t4;
    memset(t11, (unsigned char)2, 32U);
    t12 = (t0 + 2368U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    memcpy(t12, t4, 32U);
    goto LAB9;

LAB11:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 1672U);
    t5 = *((char **)t2);
    t2 = (t0 + 2368U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    memcpy(t2, t5, 32U);
    goto LAB9;

LAB13:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2368U);
    t8 = *((char **)t2);
    t2 = (t0 + 6268U);
    t11 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t14, t8, t2, 1);
    t12 = (t0 + 2368U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    t15 = (t14 + 12U);
    t16 = *((unsigned int *)t15);
    t17 = (1U * t16);
    memcpy(t12, t11, t17);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2368U);
    t4 = *((char **)t2);
    t18 = (32 - 1);
    t19 = (t18 - 31);
    t16 = (t19 * -1);
    t17 = (1U * t16);
    t20 = (0 + t17);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB18;

LAB20:
LAB19:    goto LAB9;

LAB15:    t2 = (t0 + 1352U);
    t5 = *((char **)t2);
    t7 = *((unsigned char *)t5);
    t9 = (t7 == (unsigned char)3);
    t1 = t9;
    goto LAB17;

LAB18:    xsi_set_current_line(58, ng0);
    t5 = xsi_get_transient_memory(32U);
    memset(t5, 0, 32U);
    t8 = t5;
    memset(t8, (unsigned char)2, 32U);
    t11 = (t0 + 2368U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    memcpy(t11, t5, 32U);
    goto LAB19;

LAB21:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2368U);
    t8 = *((char **)t2);
    t2 = (t0 + 6268U);
    t11 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t14, t8, t2, 1);
    t12 = (t0 + 2368U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    t15 = (t14 + 12U);
    t16 = *((unsigned int *)t15);
    t17 = (1U * t16);
    memcpy(t12, t11, t17);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 2368U);
    t4 = *((char **)t2);
    t18 = (32 - 1);
    t19 = (t18 - 31);
    t16 = (t19 * -1);
    t17 = (1U * t16);
    t20 = (0 + t17);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB26;

LAB28:
LAB27:    goto LAB9;

LAB23:    t2 = (t0 + 1352U);
    t5 = *((char **)t2);
    t7 = *((unsigned char *)t5);
    t9 = (t7 == (unsigned char)2);
    t1 = t9;
    goto LAB25;

LAB26:    xsi_set_current_line(65, ng0);
    t5 = xsi_get_transient_memory(32U);
    memset(t5, 0, 32U);
    t8 = t5;
    memset(t8, (unsigned char)3, 32U);
    t21 = (32 - 1);
    t22 = (t21 - 31);
    t23 = (t22 * -1);
    t24 = (1U * t23);
    t11 = (t8 + t24);
    *((unsigned char *)t11) = (unsigned char)2;
    t12 = (t0 + 2368U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    memcpy(t12, t5, 32U);
    goto LAB27;

}


extern void work_a_0565269370_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0565269370_3212880686_p_0};
	xsi_register_didat("work_a_0565269370_3212880686", "isim/testbench_counter_isim_beh.exe.sim/work/a_0565269370_3212880686.didat");
	xsi_register_executes(pe);
}
