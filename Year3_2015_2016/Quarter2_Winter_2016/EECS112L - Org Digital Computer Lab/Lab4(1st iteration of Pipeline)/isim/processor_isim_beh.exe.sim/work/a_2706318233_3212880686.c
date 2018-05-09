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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab4/PipelineReg3_EX_MEM.vhd";



static void work_a_2706318233_3212880686_p_0(char *t0)
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

LAB0:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 4848U);
    t4 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 6712);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 4968U);
    t4 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 6776);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 5088U);
    t4 = *((char **)t2);
    t2 = (t0 + 6840);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t14 = *((char **)t9);
    memcpy(t14, t4, 5U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 4968U);
    t4 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 6904);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 5208U);
    t4 = *((char **)t2);
    t2 = (t0 + 6968);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t14 = *((char **)t9);
    memcpy(t14, t4, 3U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 4968U);
    t4 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 7032);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 4968U);
    t4 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 7096);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 4848U);
    t4 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 7160);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 4848U);
    t4 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 7224);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 4848U);
    t4 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 7288);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 5328U);
    t4 = *((char **)t2);
    t2 = (t0 + 7352);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t14 = *((char **)t9);
    memcpy(t14, t4, 2U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 6632);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(83, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t4 = (t0 + 4848U);
    t9 = *((char **)t4);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t4 = (t9 + t13);
    memcpy(t4, t8, 32U);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 4968U);
    t5 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t2 = (t0 + 5088U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    memcpy(t2, t4, 5U);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 1672U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 4968U);
    t5 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1832U);
    t4 = *((char **)t2);
    t2 = (t0 + 5208U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    memcpy(t2, t4, 3U);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 1992U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 4968U);
    t5 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2152U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 4968U);
    t5 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 2312U);
    t4 = *((char **)t2);
    t2 = (t0 + 4848U);
    t5 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t2 = (t0 + 4848U);
    t5 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t2 = (t0 + 4848U);
    t5 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 2792U);
    t4 = *((char **)t2);
    t2 = (t0 + 5328U);
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


extern void work_a_2706318233_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2706318233_3212880686_p_0};
	xsi_register_didat("work_a_2706318233_3212880686", "isim/processor_isim_beh.exe.sim/work/a_2706318233_3212880686.didat");
	xsi_register_executes(pe);
}
