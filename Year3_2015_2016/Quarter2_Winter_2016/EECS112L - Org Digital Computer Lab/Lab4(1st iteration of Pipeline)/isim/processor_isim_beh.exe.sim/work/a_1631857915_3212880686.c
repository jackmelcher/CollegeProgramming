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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab4/BranchAdder.vhd";
extern char *IEEE_P_3620187407;
extern char *IEEE_P_2592010699;

char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );
char *ieee_p_3620187407_sub_767668596_3965413181(char *, char *, char *, char *, char *, char *);


static void work_a_1631857915_3212880686_p_0(char *t0)
{
    char t5[16];
    char t6[16];
    char t17[16];
    char t19[16];
    char t24[16];
    char t46[16];
    char t48[16];
    char t53[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t16;
    char *t18;
    char *t20;
    char *t21;
    int t22;
    unsigned int t23;
    char *t25;
    int t26;
    char *t27;
    unsigned int t28;
    unsigned char t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned char t37;
    unsigned char t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t45;
    char *t47;
    char *t49;
    char *t50;
    int t51;
    unsigned int t52;
    char *t54;
    int t55;
    unsigned char t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;

LAB0:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB3;

LAB4:    t35 = (t0 + 1672U);
    t36 = *((char **)t35);
    t37 = *((unsigned char *)t36);
    t38 = (t37 == (unsigned char)3);
    if (t38 != 0)
        goto LAB7;

LAB8:
LAB11:    t61 = xsi_get_transient_memory(32U);
    memset(t61, 0, 32U);
    t62 = t61;
    memset(t62, (unsigned char)2, 32U);
    t63 = (t0 + 3816);
    t64 = (t63 + 56U);
    t65 = *((char **)t64);
    t66 = (t65 + 56U);
    t67 = *((char **)t66);
    memcpy(t67, t61, 32U);
    xsi_driver_first_trans_fast_port(t63);

LAB2:    t68 = (t0 + 3720);
    *((int *)t68) = 1;

LAB1:    return;
LAB3:    t1 = (t0 + 1032U);
    t7 = *((char **)t1);
    t1 = (t0 + 6092U);
    t8 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t6, t7, t1, 4);
    t9 = (t0 + 1192U);
    t10 = *((char **)t9);
    t11 = (31 - 29);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t9 = (t10 + t13);
    t14 = (t0 + 6278);
    t18 = ((IEEE_P_2592010699) + 4024);
    t20 = (t19 + 0U);
    t21 = (t20 + 0U);
    *((int *)t21) = 29;
    t21 = (t20 + 4U);
    *((int *)t21) = 0;
    t21 = (t20 + 8U);
    *((int *)t21) = -1;
    t22 = (0 - 29);
    t23 = (t22 * -1);
    t23 = (t23 + 1);
    t21 = (t20 + 12U);
    *((unsigned int *)t21) = t23;
    t21 = (t24 + 0U);
    t25 = (t21 + 0U);
    *((int *)t25) = 0;
    t25 = (t21 + 4U);
    *((int *)t25) = 1;
    t25 = (t21 + 8U);
    *((int *)t25) = 1;
    t26 = (1 - 0);
    t23 = (t26 * 1);
    t23 = (t23 + 1);
    t25 = (t21 + 12U);
    *((unsigned int *)t25) = t23;
    t16 = xsi_base_array_concat(t16, t17, t18, (char)97, t9, t19, (char)97, t14, t24, (char)101);
    t25 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t5, t8, t6, t16, t17);
    t27 = (t5 + 12U);
    t23 = *((unsigned int *)t27);
    t28 = (1U * t23);
    t29 = (32U != t28);
    if (t29 == 1)
        goto LAB5;

LAB6:    t30 = (t0 + 3816);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    memcpy(t34, t25, 32U);
    xsi_driver_first_trans_fast_port(t30);
    goto LAB2;

LAB5:    xsi_size_not_matching(32U, t28, 0);
    goto LAB6;

LAB7:    t35 = (t0 + 1352U);
    t39 = *((char **)t35);
    t40 = (31 - 29);
    t41 = (t40 * 1U);
    t42 = (0 + t41);
    t35 = (t39 + t42);
    t43 = (t0 + 6280);
    t47 = ((IEEE_P_2592010699) + 4024);
    t49 = (t48 + 0U);
    t50 = (t49 + 0U);
    *((int *)t50) = 29;
    t50 = (t49 + 4U);
    *((int *)t50) = 0;
    t50 = (t49 + 8U);
    *((int *)t50) = -1;
    t51 = (0 - 29);
    t52 = (t51 * -1);
    t52 = (t52 + 1);
    t50 = (t49 + 12U);
    *((unsigned int *)t50) = t52;
    t50 = (t53 + 0U);
    t54 = (t50 + 0U);
    *((int *)t54) = 0;
    t54 = (t50 + 4U);
    *((int *)t54) = 1;
    t54 = (t50 + 8U);
    *((int *)t54) = 1;
    t55 = (1 - 0);
    t52 = (t55 * 1);
    t52 = (t52 + 1);
    t54 = (t50 + 12U);
    *((unsigned int *)t54) = t52;
    t45 = xsi_base_array_concat(t45, t46, t47, (char)97, t35, t48, (char)97, t43, t53, (char)101);
    t52 = (30U + 2U);
    t56 = (32U != t52);
    if (t56 == 1)
        goto LAB9;

LAB10:    t54 = (t0 + 3816);
    t57 = (t54 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memcpy(t60, t45, 32U);
    xsi_driver_first_trans_fast_port(t54);
    goto LAB2;

LAB9:    xsi_size_not_matching(32U, t52, 0);
    goto LAB10;

LAB12:    goto LAB2;

}

static void work_a_1631857915_3212880686_p_1(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(51, ng0);

LAB3:    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t2 = (t0 + 6092U);
    t4 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t1, t3, t2, 4);
    t5 = (t1 + 12U);
    t6 = *((unsigned int *)t5);
    t7 = (1U * t6);
    t8 = (32U != t7);
    if (t8 == 1)
        goto LAB5;

LAB6:    t9 = (t0 + 3880);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t4, 32U);
    xsi_driver_first_trans_fast_port(t9);

LAB2:    t14 = (t0 + 3736);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(32U, t7, 0);
    goto LAB6;

}


extern void work_a_1631857915_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1631857915_3212880686_p_0,(void *)work_a_1631857915_3212880686_p_1};
	xsi_register_didat("work_a_1631857915_3212880686", "isim/processor_isim_beh.exe.sim/work/a_1631857915_3212880686.didat");
	xsi_register_executes(pe);
}
