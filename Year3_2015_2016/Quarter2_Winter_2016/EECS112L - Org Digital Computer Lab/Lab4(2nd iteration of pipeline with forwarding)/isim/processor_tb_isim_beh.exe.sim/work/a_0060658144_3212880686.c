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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Lab4(2nd iteration of pipeline with forwarding)/regfile.vhd";
extern char *IEEE_P_3620187407;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
unsigned char ieee_p_3620187407_sub_3890342512_3965413181(char *, char *, char *, int );


static void work_a_0060658144_3212880686_p_0(char *t0)
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
    int t11;
    int t12;
    char *t13;
    int t14;
    int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned char t26;

LAB0:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 2968U);
    t4 = *((char **)t2);
    t2 = (t0 + 1512U);
    t5 = *((char **)t2);
    t2 = (t0 + 8136U);
    t11 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t5, t2);
    t12 = (t11 - 0);
    t22 = (t12 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, t11);
    t23 = (32U * t22);
    t24 = (0 + t23);
    t8 = (t4 + t24);
    t13 = (t0 + 3088U);
    t16 = *((char **)t13);
    t13 = (t16 + 0);
    memcpy(t13, t8, 32U);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2968U);
    t4 = *((char **)t2);
    t2 = (t0 + 1672U);
    t5 = *((char **)t2);
    t2 = (t0 + 8152U);
    t11 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t5, t2);
    t12 = (t11 - 0);
    t22 = (t12 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, t11);
    t23 = (32U * t22);
    t24 = (0 + t23);
    t8 = (t4 + t24);
    t13 = (t0 + 3208U);
    t16 = *((char **)t13);
    t13 = (t16 + 0);
    memcpy(t13, t8, 32U);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3088U);
    t4 = *((char **)t2);
    t2 = (t0 + 4592);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t13 = (t8 + 56U);
    t16 = *((char **)t13);
    memcpy(t16, t4, 32U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3208U);
    t4 = *((char **)t2);
    t2 = (t0 + 4656);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t13 = (t8 + 56U);
    t16 = *((char **)t13);
    memcpy(t16, t4, 32U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 4512);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(66, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t6 = *((unsigned char *)t4);
    t7 = (t6 == (unsigned char)3);
    if (t7 == 1)
        goto LAB21;

LAB22:    t3 = (unsigned char)0;

LAB23:    if (t3 == 1)
        goto LAB18;

LAB19:    t1 = (unsigned char)0;

LAB20:    if (t1 != 0)
        goto LAB16;

LAB17:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)2);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(67, ng0);
    t11 = xsi_vhdl_pow(2, 5);
    t12 = (t11 - 1);
    t4 = (t0 + 9438);
    *((int *)t4) = 0;
    t13 = (t0 + 9442);
    *((int *)t13) = t12;
    t14 = 0;
    t15 = t12;

LAB11:    if (t14 <= t15)
        goto LAB12;

LAB14:    goto LAB9;

LAB12:    xsi_set_current_line(68, ng0);
    t16 = xsi_get_transient_memory(32U);
    memset(t16, 0, 32U);
    t17 = t16;
    memset(t17, (unsigned char)2, 32U);
    t18 = (t0 + 2968U);
    t19 = *((char **)t18);
    t18 = (t0 + 9438);
    t20 = *((int *)t18);
    t21 = (t20 - 0);
    t22 = (t21 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, *((int *)t18));
    t23 = (32U * t22);
    t24 = (0 + t23);
    t25 = (t19 + t24);
    memcpy(t25, t16, 32U);

LAB13:    t2 = (t0 + 9438);
    t14 = *((int *)t2);
    t4 = (t0 + 9442);
    t15 = *((int *)t4);
    if (t14 == t15)
        goto LAB14;

LAB15:    t11 = (t14 + 1);
    t14 = t11;
    t5 = (t0 + 9438);
    *((int *)t5) = t14;
    goto LAB11;

LAB16:    xsi_set_current_line(72, ng0);
    t13 = (t0 + 2312U);
    t16 = *((char **)t13);
    t13 = (t0 + 2968U);
    t17 = *((char **)t13);
    t13 = (t0 + 1832U);
    t18 = *((char **)t13);
    t13 = (t0 + 8168U);
    t11 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t18, t13);
    t12 = (t11 - 0);
    t22 = (t12 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, t11);
    t23 = (32U * t22);
    t24 = (0 + t23);
    t19 = (t17 + t24);
    memcpy(t19, t16, 32U);
    goto LAB9;

LAB18:    t2 = (t0 + 1832U);
    t8 = *((char **)t2);
    t2 = (t0 + 8168U);
    t26 = ieee_p_3620187407_sub_3890342512_3965413181(IEEE_P_3620187407, t8, t2, 0);
    t1 = t26;
    goto LAB20;

LAB21:    t2 = (t0 + 1192U);
    t5 = *((char **)t2);
    t9 = *((unsigned char *)t5);
    t10 = (t9 == (unsigned char)2);
    t3 = t10;
    goto LAB23;

}


extern void work_a_0060658144_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0060658144_3212880686_p_0};
	xsi_register_didat("work_a_0060658144_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_0060658144_3212880686.didat");
	xsi_register_executes(pe);
}
