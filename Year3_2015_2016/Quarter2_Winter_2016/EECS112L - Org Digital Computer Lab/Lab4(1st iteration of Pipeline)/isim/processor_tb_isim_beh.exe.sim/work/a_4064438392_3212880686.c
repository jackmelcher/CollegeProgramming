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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Lab4/PipelineReg2_ID_EX.vhd";



static void work_a_4064438392_3212880686_p_0(char *t0)
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

LAB0:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 6448U);
    t4 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 8432);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 6448U);
    t4 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 8496);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 6688U);
    t4 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 8560);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 6808U);
    t4 = *((char **)t2);
    t2 = (t0 + 8624);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t14 = *((char **)t9);
    memcpy(t14, t4, 5U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 6688U);
    t4 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 8688);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 6928U);
    t4 = *((char **)t2);
    t2 = (t0 + 8752);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t14 = *((char **)t9);
    memcpy(t14, t4, 3U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 6568U);
    t4 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (6U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 8816);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(122, ng0);
    t2 = (t0 + 6568U);
    t4 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (6U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 8880);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 6688U);
    t4 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 8944);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 6688U);
    t4 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 9008);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 6448U);
    t4 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 9072);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(126, ng0);
    t2 = (t0 + 6448U);
    t4 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 9136);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 6448U);
    t4 = *((char **)t2);
    t10 = (4 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 9200);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 6448U);
    t4 = *((char **)t2);
    t10 = (5 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 9264);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(129, ng0);
    t2 = (t0 + 7048U);
    t4 = *((char **)t2);
    t2 = (t0 + 9328);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t14 = *((char **)t9);
    memcpy(t14, t4, 2U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 6448U);
    t4 = *((char **)t2);
    t10 = (6 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t4 + t13);
    t5 = (t0 + 9392);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t14 = (t9 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);
    t2 = (t0 + 8352);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(95, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t4 = (t0 + 6448U);
    t9 = *((char **)t4);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t4 = (t9 + t13);
    memcpy(t4, t8, 32U);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t2 = (t0 + 6448U);
    t5 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 1512U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 6688U);
    t5 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 1672U);
    t4 = *((char **)t2);
    t2 = (t0 + 6808U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    memcpy(t2, t4, 5U);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 1832U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 6688U);
    t5 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 1992U);
    t4 = *((char **)t2);
    t2 = (t0 + 6928U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    memcpy(t2, t4, 3U);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 2152U);
    t4 = *((char **)t2);
    t2 = (t0 + 6568U);
    t5 = *((char **)t2);
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t12 = (6U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 6U);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 2312U);
    t4 = *((char **)t2);
    t2 = (t0 + 6568U);
    t5 = *((char **)t2);
    t10 = (1 - 0);
    t11 = (t10 * 1);
    t12 = (6U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 6U);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 6688U);
    t5 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t2 = (t0 + 6688U);
    t5 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    *((unsigned char *)t2) = t1;
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 2792U);
    t4 = *((char **)t2);
    t2 = (t0 + 6448U);
    t5 = *((char **)t2);
    t10 = (2 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 2952U);
    t4 = *((char **)t2);
    t2 = (t0 + 6448U);
    t5 = *((char **)t2);
    t10 = (3 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 3112U);
    t4 = *((char **)t2);
    t2 = (t0 + 6448U);
    t5 = *((char **)t2);
    t10 = (4 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 3272U);
    t4 = *((char **)t2);
    t2 = (t0 + 6448U);
    t5 = *((char **)t2);
    t10 = (5 - 0);
    t11 = (t10 * 1);
    t12 = (32U * t11);
    t13 = (0 + t12);
    t2 = (t5 + t13);
    memcpy(t2, t4, 32U);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 3432U);
    t4 = *((char **)t2);
    t2 = (t0 + 7048U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    memcpy(t2, t4, 2U);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3592U);
    t4 = *((char **)t2);
    t2 = (t0 + 6448U);
    t5 = *((char **)t2);
    t10 = (6 - 0);
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


extern void work_a_4064438392_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4064438392_3212880686_p_0};
	xsi_register_didat("work_a_4064438392_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_4064438392_3212880686.didat");
	xsi_register_executes(pe);
}
