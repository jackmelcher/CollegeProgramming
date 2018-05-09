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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab4/PipelineReg1_IF_ID.vhd";



static void work_a_1607257461_3212880686_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1968U);
    t4 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 3352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 1968U);
    t4 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 3416);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    t2 = (t0 + 3272);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(56, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t4 = (t0 + 1968U);
    t9 = *((char **)t4);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t4 = (t9 + t13);
    memcpy(t4, t8, 32U);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t2 = (t0 + 1968U);
    t5 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

}


extern void work_a_1607257461_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1607257461_3212880686_p_0};
	xsi_register_didat("work_a_1607257461_3212880686", "isim/processor_isim_beh.exe.sim/work/a_1607257461_3212880686.didat");
	xsi_register_executes(pe);
}
