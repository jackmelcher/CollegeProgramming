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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 31L/Final Project/FinalProject_67574625_cpu/assignment3_67574625_arithmetic_unit.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );


static void work_a_2857801645_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned char t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned char t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned char t33;
    unsigned int t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned char t45;
    unsigned int t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    unsigned char t57;
    unsigned int t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    unsigned char t69;
    unsigned int t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    unsigned char t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;

LAB0:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 4908);
    t4 = 1;
    if (3U == 3U)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    if (t4 != 0)
        goto LAB3;

LAB4:    t15 = (t0 + 1192U);
    t16 = *((char **)t15);
    t15 = (t0 + 4911);
    t18 = 1;
    if (3U == 3U)
        goto LAB13;

LAB14:    t18 = 0;

LAB15:    if (t18 != 0)
        goto LAB11;

LAB12:    t30 = (t0 + 1192U);
    t31 = *((char **)t30);
    t30 = (t0 + 4914);
    t33 = 1;
    if (3U == 3U)
        goto LAB21;

LAB22:    t33 = 0;

LAB23:    if (t33 != 0)
        goto LAB19;

LAB20:    t42 = (t0 + 1192U);
    t43 = *((char **)t42);
    t42 = (t0 + 4917);
    t45 = 1;
    if (3U == 3U)
        goto LAB29;

LAB30:    t45 = 0;

LAB31:    if (t45 != 0)
        goto LAB27;

LAB28:    t54 = (t0 + 1192U);
    t55 = *((char **)t54);
    t54 = (t0 + 4920);
    t57 = 1;
    if (3U == 3U)
        goto LAB37;

LAB38:    t57 = 0;

LAB39:    if (t57 != 0)
        goto LAB35;

LAB36:    t66 = (t0 + 1192U);
    t67 = *((char **)t66);
    t66 = (t0 + 4923);
    t69 = 1;
    if (3U == 3U)
        goto LAB45;

LAB46:    t69 = 0;

LAB47:    if (t69 != 0)
        goto LAB43;

LAB44:
LAB51:    t80 = (t0 + 2912);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    t83 = (t82 + 56U);
    t84 = *((char **)t83);
    *((unsigned char *)t84) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t80);

LAB2:    t85 = (t0 + 2832);
    *((int *)t85) = 1;

LAB1:    return;
LAB3:    t8 = (t0 + 1032U);
    t9 = *((char **)t8);
    t10 = *((unsigned char *)t9);
    t8 = (t0 + 2912);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t10;
    xsi_driver_first_trans_fast_port(t8);
    goto LAB2;

LAB5:    t5 = 0;

LAB8:    if (t5 < 3U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t5 = (t5 + 1);
    goto LAB8;

LAB11:    t22 = (t0 + 1032U);
    t23 = *((char **)t22);
    t24 = *((unsigned char *)t23);
    t25 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t24);
    t22 = (t0 + 2912);
    t26 = (t22 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    *((unsigned char *)t29) = t25;
    xsi_driver_first_trans_fast_port(t22);
    goto LAB2;

LAB13:    t19 = 0;

LAB16:    if (t19 < 3U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t20 = (t16 + t19);
    t21 = (t15 + t19);
    if (*((unsigned char *)t20) != *((unsigned char *)t21))
        goto LAB14;

LAB18:    t19 = (t19 + 1);
    goto LAB16;

LAB19:    t37 = (t0 + 2912);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    *((unsigned char *)t41) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t37);
    goto LAB2;

LAB21:    t34 = 0;

LAB24:    if (t34 < 3U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t35 = (t31 + t34);
    t36 = (t30 + t34);
    if (*((unsigned char *)t35) != *((unsigned char *)t36))
        goto LAB22;

LAB26:    t34 = (t34 + 1);
    goto LAB24;

LAB27:    t49 = (t0 + 2912);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    t52 = (t51 + 56U);
    t53 = *((char **)t52);
    *((unsigned char *)t53) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t49);
    goto LAB2;

LAB29:    t46 = 0;

LAB32:    if (t46 < 3U)
        goto LAB33;
    else
        goto LAB31;

LAB33:    t47 = (t43 + t46);
    t48 = (t42 + t46);
    if (*((unsigned char *)t47) != *((unsigned char *)t48))
        goto LAB30;

LAB34:    t46 = (t46 + 1);
    goto LAB32;

LAB35:    t61 = (t0 + 2912);
    t62 = (t61 + 56U);
    t63 = *((char **)t62);
    t64 = (t63 + 56U);
    t65 = *((char **)t64);
    *((unsigned char *)t65) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t61);
    goto LAB2;

LAB37:    t58 = 0;

LAB40:    if (t58 < 3U)
        goto LAB41;
    else
        goto LAB39;

LAB41:    t59 = (t55 + t58);
    t60 = (t54 + t58);
    if (*((unsigned char *)t59) != *((unsigned char *)t60))
        goto LAB38;

LAB42:    t58 = (t58 + 1);
    goto LAB40;

LAB43:    t73 = (t0 + 1032U);
    t74 = *((char **)t73);
    t75 = *((unsigned char *)t74);
    t73 = (t0 + 2912);
    t76 = (t73 + 56U);
    t77 = *((char **)t76);
    t78 = (t77 + 56U);
    t79 = *((char **)t78);
    *((unsigned char *)t79) = t75;
    xsi_driver_first_trans_fast_port(t73);
    goto LAB2;

LAB45:    t70 = 0;

LAB48:    if (t70 < 3U)
        goto LAB49;
    else
        goto LAB47;

LAB49:    t71 = (t67 + t70);
    t72 = (t66 + t70);
    if (*((unsigned char *)t71) != *((unsigned char *)t72))
        goto LAB46;

LAB50:    t70 = (t70 + 1);
    goto LAB48;

LAB52:    goto LAB2;

}


extern void work_a_2857801645_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2857801645_3212880686_p_0};
	xsi_register_didat("work_a_2857801645_3212880686", "isim/testbench_processor_isim_beh.exe.sim/work/a_2857801645_3212880686.didat");
	xsi_register_executes(pe);
}
