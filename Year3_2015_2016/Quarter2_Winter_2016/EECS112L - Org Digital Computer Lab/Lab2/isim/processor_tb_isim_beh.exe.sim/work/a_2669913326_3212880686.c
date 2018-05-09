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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab2/ram.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3620187407;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
unsigned char ieee_p_3620187407_sub_3905759485_3965413181(char *, char *, char *, int );


static void work_a_2669913326_3212880686_p_0(char *t0)
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
    char *t12;
    char *t13;
    int t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    int t20;
    int t21;

LAB0:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1352U);
    t4 = *((char **)t2);
    t2 = (t0 + 6464U);
    t14 = xsi_vhdl_pow(2, 9);
    t15 = (t14 - 1);
    t1 = ieee_p_3620187407_sub_3905759485_3965413181(IEEE_P_3620187407, t4, t2, t15);
    if (t1 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(66, ng0);
    t2 = xsi_get_transient_memory(32U);
    memset(t2, 0, 32U);
    t4 = t2;
    memset(t4, (unsigned char)2, 32U);
    t5 = (t0 + 2448U);
    t8 = *((char **)t5);
    t5 = (t8 + 0);
    memcpy(t5, t2, 32U);

LAB12:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 2448U);
    t4 = *((char **)t2);
    t2 = (t0 + 3832);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 32U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 3752);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(57, ng0);
    t4 = (t0 + 1192U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(58, ng0);
    t4 = (t0 + 1512U);
    t11 = *((char **)t4);
    t4 = (t0 + 2328U);
    t12 = *((char **)t4);
    t4 = (t0 + 1352U);
    t13 = *((char **)t4);
    t4 = (t0 + 6464U);
    t14 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t13, t4);
    t15 = (t14 - 0);
    t16 = (t15 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t14);
    t17 = (32U * t16);
    t18 = (0 + t17);
    t19 = (t12 + t18);
    memcpy(t19, t11, 32U);
    goto LAB9;

LAB11:    xsi_set_current_line(64, ng0);
    t5 = (t0 + 2328U);
    t8 = *((char **)t5);
    t5 = (t0 + 1352U);
    t11 = *((char **)t5);
    t5 = (t0 + 6464U);
    t20 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t11, t5);
    t21 = (t20 - 0);
    t16 = (t21 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t20);
    t17 = (32U * t16);
    t18 = (0 + t17);
    t12 = (t8 + t18);
    t13 = (t0 + 2448U);
    t19 = *((char **)t13);
    t13 = (t19 + 0);
    memcpy(t13, t12, 32U);
    goto LAB12;

}


extern void work_a_2669913326_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2669913326_3212880686_p_0};
	xsi_register_didat("work_a_2669913326_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_2669913326_3212880686.didat");
	xsi_register_executes(pe);
}
