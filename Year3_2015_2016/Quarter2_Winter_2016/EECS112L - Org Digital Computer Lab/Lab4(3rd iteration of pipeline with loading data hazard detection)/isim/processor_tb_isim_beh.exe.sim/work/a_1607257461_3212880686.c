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
    unsigned char t2;
    char *t3;
    unsigned char t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    unsigned char t10;
    unsigned char t11;
    char *t12;
    char *t13;
    int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    xsi_set_current_line(56, ng0);
    t3 = (t0 + 992U);
    t4 = xsi_signal_has_event(t3);
    if (t4 == 1)
        goto LAB8;

LAB9:    t2 = (unsigned char)0;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(62, ng0);
    t3 = (t0 + 2128U);
    t5 = *((char **)t3);
    t14 = (0 - 0);
    t15 = (t14 * 1);
    t16 = (32U * t15);
    t17 = (0 + t16);
    t3 = (t5 + t17);
    t6 = (t0 + 3512);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    t13 = (t12 + 56U);
    t18 = *((char **)t13);
    memcpy(t18, t3, 32U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(63, ng0);
    t3 = (t0 + 2128U);
    t5 = *((char **)t3);
    t14 = (1 - 0);
    t15 = (t14 * 1);
    t16 = (32U * t15);
    t17 = (0 + t16);
    t3 = (t5 + t17);
    t6 = (t0 + 3576);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    t13 = (t12 + 56U);
    t18 = *((char **)t13);
    memcpy(t18, t3, 32U);
    xsi_driver_first_trans_fast_port(t6);
    t3 = (t0 + 3432);
    *((int *)t3) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(57, ng0);
    t5 = (t0 + 1192U);
    t12 = *((char **)t5);
    t5 = (t0 + 2128U);
    t13 = *((char **)t5);
    t14 = (0 - 0);
    t15 = (t14 * 1);
    t16 = (32U * t15);
    t17 = (0 + t16);
    t5 = (t13 + t17);
    memcpy(t5, t12, 32U);
    xsi_set_current_line(58, ng0);
    t3 = (t0 + 1352U);
    t5 = *((char **)t3);
    t3 = (t0 + 2128U);
    t6 = *((char **)t3);
    t14 = (1 - 0);
    t15 = (t14 * 1);
    t16 = (32U * t15);
    t17 = (0 + t16);
    t3 = (t6 + t17);
    memcpy(t3, t5, 32U);
    goto LAB3;

LAB5:    t5 = (t0 + 1512U);
    t9 = *((char **)t5);
    t10 = *((unsigned char *)t9);
    t11 = (t10 == (unsigned char)3);
    t1 = t11;
    goto LAB7;

LAB8:    t5 = (t0 + 1032U);
    t6 = *((char **)t5);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)3);
    t2 = t8;
    goto LAB10;

}


extern void work_a_1607257461_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1607257461_3212880686_p_0};
	xsi_register_didat("work_a_1607257461_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_1607257461_3212880686.didat");
	xsi_register_executes(pe);
}
