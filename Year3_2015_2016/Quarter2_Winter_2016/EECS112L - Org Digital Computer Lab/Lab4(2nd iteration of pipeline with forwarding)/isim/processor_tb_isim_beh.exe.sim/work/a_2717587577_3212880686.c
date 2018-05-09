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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Lab4(2nd iteration of pipeline with forwarding)/PCadder.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_2717587577_3212880686_p_0(char *t0)
{
    char t14[16];
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;

LAB0:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t2 = (t0 + 1512U);
    t6 = *((char **)t2);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)3);
    t1 = t8;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB8:    t15 = (t0 + 1032U);
    t16 = *((char **)t15);
    t15 = (t0 + 5332U);
    t17 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t14, t16, t15, 4);
    t18 = (t14 + 12U);
    t19 = *((unsigned int *)t18);
    t20 = (1U * t19);
    t21 = (32U != t20);
    if (t21 == 1)
        goto LAB10;

LAB11:    t22 = (t0 + 3232);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t17, 32U);
    xsi_driver_first_trans_fast_port(t22);

LAB2:    t27 = (t0 + 3152);
    *((int *)t27) = 1;

LAB1:    return;
LAB3:    t2 = (t0 + 1192U);
    t9 = *((char **)t2);
    t2 = (t0 + 3232);
    t10 = (t2 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t9, 32U);
    xsi_driver_first_trans_fast_port(t2);
    goto LAB2;

LAB5:    t1 = (unsigned char)1;
    goto LAB7;

LAB9:    goto LAB2;

LAB10:    xsi_size_not_matching(32U, t20, 0);
    goto LAB11;

}


extern void work_a_2717587577_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2717587577_3212880686_p_0};
	xsi_register_didat("work_a_2717587577_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_2717587577_3212880686.didat");
	xsi_register_executes(pe);
}
