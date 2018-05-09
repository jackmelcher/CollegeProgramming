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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab4/PipelineReg4_MEM_WB.vhd";



static void work_a_3895641916_3212880686_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3608U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 4992);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t10 = (t8 + 56U);
    t15 = *((char **)t10);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3368U);
    t4 = *((char **)t2);
    t2 = (t0 + 5056);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t10 = (t8 + 56U);
    t15 = *((char **)t10);
    memcpy(t15, t4, 5U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 3248U);
    t4 = *((char **)t2);
    t11 = (0 - 0);
    t12 = (t11 * 1);
    t13 = (32U * t12);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t5 = (t0 + 5120);
    t8 = (t5 + 56U);
    t10 = *((char **)t8);
    t15 = (t10 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 3248U);
    t4 = *((char **)t2);
    t11 = (1 - 0);
    t12 = (t11 * 1);
    t13 = (32U * t12);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t5 = (t0 + 5184);
    t8 = (t5 + 56U);
    t10 = *((char **)t8);
    t15 = (t10 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3248U);
    t4 = *((char **)t2);
    t11 = (2 - 0);
    t12 = (t11 * 1);
    t13 = (32U * t12);
    t14 = (0 + t13);
    t2 = (t4 + t14);
    t5 = (t0 + 5248);
    t8 = (t5 + 56U);
    t10 = *((char **)t8);
    t15 = (t10 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 3488U);
    t4 = *((char **)t2);
    t2 = (t0 + 5312);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t10 = (t8 + 56U);
    t15 = *((char **)t10);
    memcpy(t15, t4, 2U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 4912);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(71, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t4 = (t0 + 3608U);
    t10 = *((char **)t4);
    t4 = (t10 + 0);
    *((unsigned char *)t4) = t9;
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t2 = (t0 + 3368U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    memcpy(t2, t4, 5U);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t2 = (t0 + 3248U);
    t5 = *((char **)t2);
    t11 = (0 - 0);
    t12 = (t11 * 1);
    t13 = (32U * t12);
    t14 = (0 + t13);
    t2 = (t5 + t14);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t2 = (t0 + 3248U);
    t5 = *((char **)t2);
    t11 = (1 - 0);
    t12 = (t11 * 1);
    t13 = (32U * t12);
    t14 = (0 + t13);
    t2 = (t5 + t14);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 1832U);
    t4 = *((char **)t2);
    t2 = (t0 + 3248U);
    t5 = *((char **)t2);
    t11 = (2 - 0);
    t12 = (t11 * 1);
    t13 = (32U * t12);
    t14 = (0 + t13);
    t2 = (t5 + t14);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 1992U);
    t4 = *((char **)t2);
    t2 = (t0 + 3488U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    memcpy(t2, t4, 2U);
    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

}


extern void work_a_3895641916_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3895641916_3212880686_p_0};
	xsi_register_didat("work_a_3895641916_3212880686", "isim/processor_isim_beh.exe.sim/work/a_3895641916_3212880686.didat");
	xsi_register_executes(pe);
}
