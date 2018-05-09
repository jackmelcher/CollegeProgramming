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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab2/pc.vhd";
extern char *IEEE_P_3620187407;

unsigned char ieee_p_3620187407_sub_2546418145_3965413181(char *, char *, char *, int );
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_1004167507_3212880686_p_0(char *t0)
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
    unsigned int t15;
    unsigned int t16;

LAB0:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2168U);
    t4 = *((char **)t2);
    t2 = (t0 + 5644U);
    t1 = ieee_p_3620187407_sub_2546418145_3965413181(IEEE_P_3620187407, t4, t2, 14);
    if (t1 != 0)
        goto LAB13;

LAB15:
LAB14:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2168U);
    t4 = *((char **)t2);
    t2 = (t0 + 3552);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 32U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 3472);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(54, ng0);
    t4 = (t0 + 1352U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1192U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB11;

LAB12:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(55, ng0);
    t4 = xsi_get_transient_memory(32U);
    memset(t4, 0, 32U);
    t11 = t4;
    memset(t11, (unsigned char)2, 32U);
    t12 = (t0 + 2168U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    memcpy(t12, t4, 32U);
    goto LAB9;

LAB11:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2168U);
    t5 = *((char **)t2);
    t2 = (t0 + 5644U);
    t8 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t14, t5, t2, 1);
    t11 = (t0 + 2168U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    t13 = (t14 + 12U);
    t15 = *((unsigned int *)t13);
    t16 = (1U * t15);
    memcpy(t11, t8, t16);
    goto LAB9;

LAB13:    xsi_set_current_line(63, ng0);
    t5 = xsi_get_transient_memory(32U);
    memset(t5, 0, 32U);
    t8 = t5;
    memset(t8, (unsigned char)2, 32U);
    t11 = (t0 + 2168U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    memcpy(t11, t5, 32U);
    goto LAB14;

}


extern void work_a_1004167507_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1004167507_3212880686_p_0};
	xsi_register_didat("work_a_1004167507_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_1004167507_3212880686.didat");
	xsi_register_executes(pe);
}
