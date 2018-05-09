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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 31L/Final Project/FinalProject_67574625_cpu/register_bank_67574625.vhd";
extern char *WORK_P_3220498246;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);


static void work_a_3220818382_3212880686_p_0(char *t0)
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
    unsigned char t10;
    char *t11;
    int t12;
    int t13;
    int t14;
    char *t15;
    int t16;
    int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    int t22;
    int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2608U);
    t4 = *((char **)t2);
    t2 = (t0 + 1512U);
    t5 = *((char **)t2);
    t2 = (t0 + 7592U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t5, t2);
    t13 = (t12 - 0);
    t24 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 63, 1, t12);
    t25 = (32U * t24);
    t26 = (0 + t25);
    t8 = (t4 + t26);
    t11 = (t0 + 2728U);
    t15 = *((char **)t11);
    t11 = (t15 + 0);
    memcpy(t11, t8, 32U);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2608U);
    t4 = *((char **)t2);
    t2 = (t0 + 1672U);
    t5 = *((char **)t2);
    t2 = (t0 + 7608U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t5, t2);
    t13 = (t12 - 0);
    t24 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 63, 1, t12);
    t25 = (32U * t24);
    t26 = (0 + t25);
    t8 = (t4 + t26);
    t11 = (t0 + 2848U);
    t15 = *((char **)t11);
    t11 = (t15 + 0);
    memcpy(t11, t8, 32U);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2728U);
    t4 = *((char **)t2);
    t2 = (t0 + 4232);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t15 = *((char **)t11);
    memcpy(t15, t4, 32U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2848U);
    t4 = *((char **)t2);
    t2 = (t0 + 4296);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t15 = *((char **)t11);
    memcpy(t15, t4, 32U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 4152);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(55, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)3);
    if (t6 == 1)
        goto LAB18;

LAB19:    t1 = (unsigned char)0;

LAB20:    if (t1 != 0)
        goto LAB16;

LAB17:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(56, ng0);
    t4 = ((WORK_P_3220498246) + 1888U);
    t11 = *((char **)t4);
    t12 = *((int *)t11);
    t13 = xsi_vhdl_pow(2, t12);
    t14 = (t13 - 1);
    t4 = (t0 + 9909);
    *((int *)t4) = 0;
    t15 = (t0 + 9913);
    *((int *)t15) = t14;
    t16 = 0;
    t17 = t14;

LAB11:    if (t16 <= t17)
        goto LAB12;

LAB14:    goto LAB9;

LAB12:    xsi_set_current_line(57, ng0);
    t18 = xsi_get_transient_memory(32U);
    memset(t18, 0, 32U);
    t19 = t18;
    memset(t19, (unsigned char)2, 32U);
    t20 = (t0 + 2608U);
    t21 = *((char **)t20);
    t20 = (t0 + 9909);
    t22 = *((int *)t20);
    t23 = (t22 - 0);
    t24 = (t23 * 1);
    xsi_vhdl_check_range_of_index(0, 63, 1, *((int *)t20));
    t25 = (32U * t24);
    t26 = (0 + t25);
    t27 = (t21 + t26);
    memcpy(t27, t18, 32U);

LAB13:    t2 = (t0 + 9909);
    t16 = *((int *)t2);
    t4 = (t0 + 9913);
    t17 = *((int *)t4);
    if (t16 == t17)
        goto LAB14;

LAB15:    t12 = (t16 + 1);
    t16 = t12;
    t5 = (t0 + 9909);
    *((int *)t5) = t16;
    goto LAB11;

LAB16:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2312U);
    t8 = *((char **)t2);
    t2 = (t0 + 2608U);
    t11 = *((char **)t2);
    t2 = (t0 + 1832U);
    t15 = *((char **)t2);
    t2 = (t0 + 7624U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t15, t2);
    t13 = (t12 - 0);
    t24 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 63, 1, t12);
    t25 = (32U * t24);
    t26 = (0 + t25);
    t18 = (t11 + t26);
    memcpy(t18, t8, 32U);
    goto LAB9;

LAB18:    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    t7 = *((unsigned char *)t5);
    t9 = (t7 == (unsigned char)2);
    t1 = t9;
    goto LAB20;

}


extern void work_a_3220818382_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3220818382_3212880686_p_0};
	xsi_register_didat("work_a_3220818382_3212880686", "isim/testbench_processor_isim_beh.exe.sim/work/a_3220818382_3212880686.didat");
	xsi_register_executes(pe);
}
