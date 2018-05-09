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
static const char *ng0 = "C:/Users/Jack/Desktop/reg_file.vhd";
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);


static void work_a_0590584482_0318166943_p_0(char *t0)
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
    int t12;
    int t13;
    char *t14;
    int t15;
    int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    int t21;
    int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    xsi_set_current_line(34, ng0);
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

LAB4:    t3 = (t0 + 992U);
    t2 = xsi_signal_has_event(t3);
    if (t2 == 1)
        goto LAB18;

LAB19:    t1 = (unsigned char)0;

LAB20:    if (t1 != 0)
        goto LAB16;

LAB17:
LAB3:    xsi_set_current_line(47, ng0);
    t3 = (t0 + 2968U);
    t5 = *((char **)t3);
    t3 = (t0 + 4472);
    t6 = (t3 + 56U);
    t9 = *((char **)t6);
    t14 = (t9 + 56U);
    t17 = *((char **)t14);
    memcpy(t17, t5, 32U);
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(48, ng0);
    t3 = (t0 + 3088U);
    t5 = *((char **)t3);
    t3 = (t0 + 4536);
    t6 = (t3 + 56U);
    t9 = *((char **)t6);
    t14 = (t9 + 56U);
    t17 = *((char **)t14);
    memcpy(t17, t5, 32U);
    xsi_driver_first_trans_fast_port(t3);
    t3 = (t0 + 4392);
    *((int *)t3) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(35, ng0);
    t12 = xsi_vhdl_pow(2, 3);
    t13 = (t12 - 1);
    t5 = (t0 + 7440);
    *((int *)t5) = 0;
    t14 = (t0 + 7444);
    *((int *)t14) = t13;
    t15 = 0;
    t16 = t13;

LAB11:    if (t15 <= t16)
        goto LAB12;

LAB14:    xsi_set_current_line(38, ng0);
    t3 = xsi_get_transient_memory(32U);
    memset(t3, 0, 32U);
    t5 = t3;
    memset(t5, (unsigned char)2, 32U);
    t6 = (t0 + 2968U);
    t9 = *((char **)t6);
    t6 = (t9 + 0);
    memcpy(t6, t3, 32U);
    xsi_set_current_line(39, ng0);
    t3 = xsi_get_transient_memory(32U);
    memset(t3, 0, 32U);
    t5 = t3;
    memset(t5, (unsigned char)2, 32U);
    t6 = (t0 + 3088U);
    t9 = *((char **)t6);
    t6 = (t9 + 0);
    memcpy(t6, t3, 32U);
    goto LAB3;

LAB5:    t5 = (t0 + 1192U);
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

LAB12:    xsi_set_current_line(36, ng0);
    t17 = xsi_get_transient_memory(32U);
    memset(t17, 0, 32U);
    t18 = t17;
    memset(t18, (unsigned char)2, 32U);
    t19 = (t0 + 2848U);
    t20 = *((char **)t19);
    t19 = (t0 + 7440);
    t21 = *((int *)t19);
    t22 = (t21 - 0);
    t23 = (t22 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, *((int *)t19));
    t24 = (32U * t23);
    t25 = (0 + t24);
    t26 = (t20 + t25);
    memcpy(t26, t17, 32U);

LAB13:    t3 = (t0 + 7440);
    t15 = *((int *)t3);
    t5 = (t0 + 7444);
    t16 = *((int *)t5);
    if (t15 == t16)
        goto LAB14;

LAB15:    t12 = (t15 + 1);
    t15 = t12;
    t6 = (t0 + 7440);
    *((int *)t6) = t15;
    goto LAB11;

LAB16:    xsi_set_current_line(41, ng0);
    t5 = (t0 + 2848U);
    t9 = *((char **)t5);
    t5 = (t0 + 1512U);
    t14 = *((char **)t5);
    t5 = (t0 + 6916U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t14, t5);
    t13 = (t12 - 0);
    t23 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t12);
    t24 = (32U * t23);
    t25 = (0 + t24);
    t17 = (t9 + t25);
    t18 = (t0 + 2968U);
    t19 = *((char **)t18);
    t18 = (t19 + 0);
    memcpy(t18, t17, 32U);
    xsi_set_current_line(42, ng0);
    t3 = (t0 + 2848U);
    t5 = *((char **)t3);
    t3 = (t0 + 1672U);
    t6 = *((char **)t3);
    t3 = (t0 + 6932U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t6, t3);
    t13 = (t12 - 0);
    t23 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t12);
    t24 = (32U * t23);
    t25 = (0 + t24);
    t9 = (t5 + t25);
    t14 = (t0 + 3088U);
    t17 = *((char **)t14);
    t14 = (t17 + 0);
    memcpy(t14, t9, 32U);
    xsi_set_current_line(43, ng0);
    t3 = (t0 + 1352U);
    t5 = *((char **)t3);
    t1 = *((unsigned char *)t5);
    t2 = (t1 == (unsigned char)3);
    if (t2 != 0)
        goto LAB21;

LAB23:
LAB22:    goto LAB3;

LAB18:    t5 = (t0 + 1032U);
    t6 = *((char **)t5);
    t4 = *((unsigned char *)t6);
    t7 = (t4 == (unsigned char)3);
    t1 = t7;
    goto LAB20;

LAB21:    xsi_set_current_line(44, ng0);
    t3 = (t0 + 2312U);
    t6 = *((char **)t3);
    t3 = (t0 + 2848U);
    t9 = *((char **)t3);
    t3 = (t0 + 1832U);
    t14 = *((char **)t3);
    t3 = (t0 + 6948U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t14, t3);
    t13 = (t12 - 0);
    t23 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t12);
    t24 = (32U * t23);
    t25 = (0 + t24);
    t17 = (t9 + t25);
    memcpy(t17, t6, 32U);
    goto LAB22;

}


void ieee_p_2592010699_sub_3130575329_503743352();

extern void work_a_0590584482_0318166943_init()
{
	static char *pe[] = {(void *)work_a_0590584482_0318166943_p_0};
	xsi_register_didat("work_a_0590584482_0318166943", "isim/REGFILE_TB_isim_beh.exe.sim/work/a_0590584482_0318166943.didat");
	xsi_register_executes(pe);
	xsi_register_resolution_function(1, 2, (void *)ieee_p_2592010699_sub_3130575329_503743352, 5);
}
