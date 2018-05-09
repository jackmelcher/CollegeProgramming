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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Lab4/output_mux.vhd";
extern char *IEEE_P_2592010699;



static void work_a_3486750924_3212880686_p_0(char *t0)
{
    char t42[16];
    char t44[16];
    char t49[16];
    char *t1;
    char *t2;
    unsigned char t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned char t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned char t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;
    char *t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t43;
    char *t45;
    char *t46;
    int t47;
    unsigned int t48;
    char *t50;
    int t51;
    unsigned char t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;

LAB0:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 5126);
    t4 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    if (t4 != 0)
        goto LAB3;

LAB4:    t14 = (t0 + 1512U);
    t15 = *((char **)t14);
    t14 = (t0 + 5128);
    t17 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t17 = 0;

LAB15:    if (t17 != 0)
        goto LAB11;

LAB12:    t27 = (t0 + 1512U);
    t28 = *((char **)t27);
    t27 = (t0 + 5130);
    t30 = 1;
    if (2U == 2U)
        goto LAB21;

LAB22:    t30 = 0;

LAB23:    if (t30 != 0)
        goto LAB19;

LAB20:
LAB29:    t57 = xsi_get_transient_memory(32U);
    memset(t57, 0, 32U);
    t58 = t57;
    memset(t58, (unsigned char)4, 32U);
    t59 = (t0 + 3232);
    t60 = (t59 + 56U);
    t61 = *((char **)t60);
    t62 = (t61 + 56U);
    t63 = *((char **)t62);
    memcpy(t63, t57, 32U);
    xsi_driver_first_trans_fast_port(t59);

LAB2:    t64 = (t0 + 3152);
    *((int *)t64) = 1;

LAB1:    return;
LAB3:    t8 = (t0 + 1032U);
    t9 = *((char **)t8);
    t8 = (t0 + 3232);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t9, 32U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB2;

LAB5:    t5 = 0;

LAB8:    if (t5 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t5 = (t5 + 1);
    goto LAB8;

LAB11:    t21 = (t0 + 1192U);
    t22 = *((char **)t21);
    t21 = (t0 + 3232);
    t23 = (t21 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t22, 32U);
    xsi_driver_first_trans_fast_port(t21);
    goto LAB2;

LAB13:    t18 = 0;

LAB16:    if (t18 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t19 = (t15 + t18);
    t20 = (t14 + t18);
    if (*((unsigned char *)t19) != *((unsigned char *)t20))
        goto LAB14;

LAB18:    t18 = (t18 + 1);
    goto LAB16;

LAB19:    t34 = (t0 + 5132);
    t36 = (t0 + 1352U);
    t37 = *((char **)t36);
    t38 = (31 - 31);
    t39 = (t38 * 1U);
    t40 = (0 + t39);
    t36 = (t37 + t40);
    t43 = ((IEEE_P_2592010699) + 4024);
    t45 = (t44 + 0U);
    t46 = (t45 + 0U);
    *((int *)t46) = 0;
    t46 = (t45 + 4U);
    *((int *)t46) = 1;
    t46 = (t45 + 8U);
    *((int *)t46) = 1;
    t47 = (1 - 0);
    t48 = (t47 * 1);
    t48 = (t48 + 1);
    t46 = (t45 + 12U);
    *((unsigned int *)t46) = t48;
    t46 = (t49 + 0U);
    t50 = (t46 + 0U);
    *((int *)t50) = 31;
    t50 = (t46 + 4U);
    *((int *)t50) = 2;
    t50 = (t46 + 8U);
    *((int *)t50) = -1;
    t51 = (2 - 31);
    t48 = (t51 * -1);
    t48 = (t48 + 1);
    t50 = (t46 + 12U);
    *((unsigned int *)t50) = t48;
    t41 = xsi_base_array_concat(t41, t42, t43, (char)97, t34, t44, (char)97, t36, t49, (char)101);
    t48 = (2U + 30U);
    t52 = (32U != t48);
    if (t52 == 1)
        goto LAB27;

LAB28:    t50 = (t0 + 3232);
    t53 = (t50 + 56U);
    t54 = *((char **)t53);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    memcpy(t56, t41, 32U);
    xsi_driver_first_trans_fast_port(t50);
    goto LAB2;

LAB21:    t31 = 0;

LAB24:    if (t31 < 2U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t32 = (t28 + t31);
    t33 = (t27 + t31);
    if (*((unsigned char *)t32) != *((unsigned char *)t33))
        goto LAB22;

LAB26:    t31 = (t31 + 1);
    goto LAB24;

LAB27:    xsi_size_not_matching(32U, t48, 0);
    goto LAB28;

LAB30:    goto LAB2;

}


extern void work_a_3486750924_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3486750924_3212880686_p_0};
	xsi_register_didat("work_a_3486750924_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_3486750924_3212880686.didat");
	xsi_register_executes(pe);
}
