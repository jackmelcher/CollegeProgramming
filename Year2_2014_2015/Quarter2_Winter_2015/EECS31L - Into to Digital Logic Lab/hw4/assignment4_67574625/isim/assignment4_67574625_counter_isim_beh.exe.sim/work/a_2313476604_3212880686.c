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


static void work_a_2313476604_3212880686_p_0(char *t0)
{
    char t13[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    unsigned char t11;
    char *t12;
    char *t14;
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

LAB0:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 2368U);
    t2 = *((char **)t1);
    t1 = (t0 + 3752);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t12 = *((char **)t7);
    memcpy(t12, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3672);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(48, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t5 = t1;
    memset(t5, (unsigned char)2, 32U);
    t6 = (t0 + 2368U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    memcpy(t6, t1, 32U);
    goto LAB3;

LAB5:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 1512U);
    t6 = *((char **)t2);
    t10 = *((unsigned char *)t6);
    t11 = (t10 == (unsigned char)3);
    if (t11 != 0)
        goto LAB10;

LAB12:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t8 = (t4 == (unsigned char)2);
    if (t8 == 1)
        goto LAB15;

LAB16:    t3 = (unsigned char)0;

LAB17:    if (t3 != 0)
        goto LAB13;

LAB14:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t8 = (t4 == (unsigned char)2);
    if (t8 == 1)
        goto LAB23;

LAB24:    t3 = (unsigned char)0;

LAB25:    if (t3 != 0)
        goto LAB21;

LAB22:
LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    t3 = t9;
    goto LAB9;

LAB10:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1672U);
    t7 = *((char **)t2);
    t2 = (t0 + 2368U);
    t12 = *((char **)t2);
    t2 = (t12 + 0);
    memcpy(t2, t7, 32U);
    goto LAB11;

LAB13:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 2368U);
    t6 = *((char **)t1);
    t1 = (t0 + 6268U);
    t7 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t13, t6, t1, 1);
    t12 = (t0 + 2368U);
    t14 = *((char **)t12);
    t12 = (t14 + 0);
    t15 = (t13 + 12U);
    t16 = *((unsigned int *)t15);
    t17 = (1U * t16);
    memcpy(t12, t7, t17);
    xsi_set_current_line(58, ng0);
    t1 = (t0 + 2368U);
    t2 = *((char **)t1);
    t18 = (32 - 1);
    t19 = (t18 - 31);
    t16 = (t19 * -1);
    t17 = (1U * t16);
    t20 = (0 + t17);
    t1 = (t2 + t20);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB18;

LAB20:
LAB19:    goto LAB11;

LAB15:    t1 = (t0 + 1352U);
    t5 = *((char **)t1);
    t9 = *((unsigned char *)t5);
    t10 = (t9 == (unsigned char)3);
    t3 = t10;
    goto LAB17;

LAB18:    xsi_set_current_line(59, ng0);
    t5 = xsi_get_transient_memory(32U);
    memset(t5, 0, 32U);
    t6 = t5;
    memset(t6, (unsigned char)2, 32U);
    t7 = (t0 + 2368U);
    t12 = *((char **)t7);
    t7 = (t12 + 0);
    memcpy(t7, t5, 32U);
    goto LAB19;

LAB21:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 2368U);
    t6 = *((char **)t1);
    t1 = (t0 + 6268U);
    t7 = ieee_p_3620187407_sub_436351764_3965413181(IEEE_P_3620187407, t13, t6, t1, 1);
    t12 = (t0 + 2368U);
    t14 = *((char **)t12);
    t12 = (t14 + 0);
    t15 = (t13 + 12U);
    t16 = *((unsigned int *)t15);
    t17 = (1U * t16);
    memcpy(t12, t7, t17);
    xsi_set_current_line(65, ng0);
    t1 = (t0 + 2368U);
    t2 = *((char **)t1);
    t18 = (32 - 1);
    t19 = (t18 - 31);
    t16 = (t19 * -1);
    t17 = (1U * t16);
    t20 = (0 + t17);
    t1 = (t2 + t20);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB26;

LAB28:
LAB27:    goto LAB11;

LAB23:    t1 = (t0 + 1352U);
    t5 = *((char **)t1);
    t9 = *((unsigned char *)t5);
    t10 = (t9 == (unsigned char)2);
    t3 = t10;
    goto LAB25;

LAB26:    xsi_set_current_line(66, ng0);
    t5 = xsi_get_transient_memory(32U);
    memset(t5, 0, 32U);
    t6 = t5;
    memset(t6, (unsigned char)3, 32U);
    t21 = (32 - 1);
    t22 = (t21 - 31);
    t23 = (t22 * -1);
    t24 = (1U * t23);
    t7 = (t6 + t24);
    *((unsigned char *)t7) = (unsigned char)2;
    t12 = (t0 + 2368U);
    t14 = *((char **)t12);
    t12 = (t14 + 0);
    memcpy(t12, t5, 32U);
    goto LAB27;

}


extern void work_a_2313476604_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2313476604_3212880686_p_0};
	xsi_register_didat("work_a_2313476604_3212880686", "isim/assignment4_67574625_counter_isim_beh.exe.sim/work/a_2313476604_3212880686.didat");
	xsi_register_executes(pe);
}
