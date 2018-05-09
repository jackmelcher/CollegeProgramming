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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Lab4(2nd iteration of pipeline with forwarding)/fwd_a.vhd";



static void work_a_2832637653_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned char t12;
    unsigned char t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB3;

LAB4:    t10 = (t0 + 1672U);
    t11 = *((char **)t10);
    t12 = *((unsigned char *)t11);
    t13 = (t12 == (unsigned char)3);
    if (t13 != 0)
        goto LAB5;

LAB6:
LAB7:    t19 = (t0 + 1032U);
    t20 = *((char **)t19);
    t19 = (t0 + 3392);
    t21 = (t19 + 56U);
    t22 = *((char **)t21);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t20, 32U);
    xsi_driver_first_trans_fast_port(t19);

LAB2:    t25 = (t0 + 3312);
    *((int *)t25) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 1192U);
    t5 = *((char **)t1);
    t1 = (t0 + 3392);
    t6 = (t1 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 32U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB2;

LAB5:    t10 = (t0 + 1352U);
    t14 = *((char **)t10);
    t10 = (t0 + 3392);
    t15 = (t10 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t14, 32U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB2;

LAB8:    goto LAB2;

}


extern void work_a_2832637653_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2832637653_3212880686_p_0};
	xsi_register_didat("work_a_2832637653_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_2832637653_3212880686.didat");
	xsi_register_executes(pe);
}
