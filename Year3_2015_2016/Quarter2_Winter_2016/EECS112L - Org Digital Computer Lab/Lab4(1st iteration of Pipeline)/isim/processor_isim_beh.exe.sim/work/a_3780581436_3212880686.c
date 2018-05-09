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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab4/ram.vhd";
extern char *IEEE_P_1242562249;
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_2547962040_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3780581436_3212880686_p_0(char *t0)
{
    char t1[16];
    char t33[16];
    char t34[16];
    char t45[16];
    char t46[16];
    char t57[16];
    char t59[16];
    char *t2;
    char *t3;
    char *t4;
    int t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned char t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    int t23;
    int t24;
    int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    int t39;
    int t40;
    int t41;
    int t42;
    int t43;
    int t44;
    char *t47;
    int t48;
    unsigned int t49;
    char *t50;
    char *t51;
    int t52;
    int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t58;
    char *t60;
    char *t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;

LAB0:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t2 = (t0 + 7184U);
    t4 = ieee_p_1242562249_sub_2547962040_1035706684(IEEE_P_1242562249, t1, t3, t2, 2);
    t5 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t4, t1);
    t6 = (t0 + 2608U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    *((int *)t6) = t5;
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 992U);
    t9 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t2, 0U, 0U);
    if (t9 == 1)
        goto LAB5;

LAB6:    t8 = (unsigned char)0;

LAB7:    if (t8 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 2368U);
    t3 = *((char **)t2);
    t2 = (t0 + 2608U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t23 = (t5 + 3);
    t24 = (t23 - 0);
    t15 = (t24 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t23);
    t18 = (8U * t15);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t6 = (t0 + 2368U);
    t7 = *((char **)t6);
    t6 = (t0 + 2608U);
    t12 = *((char **)t6);
    t25 = *((int *)t12);
    t29 = (t25 + 2);
    t39 = (t29 - 0);
    t26 = (t39 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t29);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t6 = (t7 + t28);
    t14 = ((IEEE_P_2592010699) + 4024);
    t17 = (t33 + 0U);
    t20 = (t17 + 0U);
    *((int *)t20) = 7;
    t20 = (t17 + 4U);
    *((int *)t20) = 0;
    t20 = (t17 + 8U);
    *((int *)t20) = -1;
    t40 = (0 - 7);
    t30 = (t40 * -1);
    t30 = (t30 + 1);
    t20 = (t17 + 12U);
    *((unsigned int *)t20) = t30;
    t20 = (t34 + 0U);
    t21 = (t20 + 0U);
    *((int *)t21) = 7;
    t21 = (t20 + 4U);
    *((int *)t21) = 0;
    t21 = (t20 + 8U);
    *((int *)t21) = -1;
    t41 = (0 - 7);
    t30 = (t41 * -1);
    t30 = (t30 + 1);
    t21 = (t20 + 12U);
    *((unsigned int *)t21) = t30;
    t13 = xsi_base_array_concat(t13, t1, t14, (char)97, t2, t33, (char)97, t6, t34, (char)101);
    t21 = (t0 + 2368U);
    t22 = *((char **)t21);
    t21 = (t0 + 2608U);
    t35 = *((char **)t21);
    t42 = *((int *)t35);
    t43 = (t42 + 1);
    t44 = (t43 - 0);
    t30 = (t44 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t43);
    t31 = (8U * t30);
    t32 = (0 + t31);
    t21 = (t22 + t32);
    t37 = ((IEEE_P_2592010699) + 4024);
    t38 = (t46 + 0U);
    t47 = (t38 + 0U);
    *((int *)t47) = 7;
    t47 = (t38 + 4U);
    *((int *)t47) = 0;
    t47 = (t38 + 8U);
    *((int *)t47) = -1;
    t48 = (0 - 7);
    t49 = (t48 * -1);
    t49 = (t49 + 1);
    t47 = (t38 + 12U);
    *((unsigned int *)t47) = t49;
    t36 = xsi_base_array_concat(t36, t45, t37, (char)97, t13, t1, (char)97, t21, t46, (char)101);
    t47 = (t0 + 2368U);
    t50 = *((char **)t47);
    t47 = (t0 + 2608U);
    t51 = *((char **)t47);
    t52 = *((int *)t51);
    t53 = (t52 - 0);
    t49 = (t53 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t52);
    t54 = (8U * t49);
    t55 = (0 + t54);
    t47 = (t50 + t55);
    t58 = ((IEEE_P_2592010699) + 4024);
    t60 = (t59 + 0U);
    t61 = (t60 + 0U);
    *((int *)t61) = 7;
    t61 = (t60 + 4U);
    *((int *)t61) = 0;
    t61 = (t60 + 8U);
    *((int *)t61) = -1;
    t62 = (0 - 7);
    t63 = (t62 * -1);
    t63 = (t63 + 1);
    t61 = (t60 + 12U);
    *((unsigned int *)t61) = t63;
    t56 = xsi_base_array_concat(t56, t57, t58, (char)97, t36, t45, (char)97, t47, t59, (char)101);
    t63 = (8U + 8U);
    t64 = (t63 + 8U);
    t65 = (t64 + 8U);
    t8 = (32U != t65);
    if (t8 == 1)
        goto LAB25;

LAB26:    t61 = (t0 + 4232);
    t66 = (t61 + 56U);
    t67 = *((char **)t66);
    t68 = (t67 + 56U);
    t69 = *((char **)t68);
    memcpy(t69, t56, 32U);
    xsi_driver_first_trans_fast_port(t61);
    t2 = (t0 + 4152);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(75, ng0);
    t3 = (t0 + 1352U);
    t6 = *((char **)t3);
    t3 = (t0 + 7168U);
    t7 = (t0 + 11484);
    t13 = (t1 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 0;
    t14 = (t13 + 4U);
    *((int *)t14) = 2;
    t14 = (t13 + 8U);
    *((int *)t14) = 1;
    t5 = (2 - 0);
    t15 = (t5 * 1);
    t15 = (t15 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t15;
    t16 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t6, t3, t7, t1);
    if (t16 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t2 = (t0 + 7168U);
    t4 = (t0 + 11487);
    t7 = (t1 + 0U);
    t12 = (t7 + 0U);
    *((int *)t12) = 0;
    t12 = (t7 + 4U);
    *((int *)t12) = 2;
    t12 = (t7 + 8U);
    *((int *)t12) = 1;
    t5 = (2 - 0);
    t15 = (t5 * 1);
    t15 = (t15 + 1);
    t12 = (t7 + 12U);
    *((unsigned int *)t12) = t15;
    t8 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t2, t4, t1);
    if (t8 != 0)
        goto LAB11;

LAB12:    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t2 = (t0 + 7168U);
    t4 = (t0 + 11490);
    t7 = (t1 + 0U);
    t12 = (t7 + 0U);
    *((int *)t12) = 0;
    t12 = (t7 + 4U);
    *((int *)t12) = 2;
    t12 = (t7 + 8U);
    *((int *)t12) = 1;
    t5 = (2 - 0);
    t15 = (t5 * 1);
    t15 = (t15 + 1);
    t12 = (t7 + 12U);
    *((unsigned int *)t12) = t15;
    t8 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t2, t4, t1);
    if (t8 != 0)
        goto LAB16;

LAB17:
LAB9:    goto LAB3;

LAB5:    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t10 = *((unsigned char *)t4);
    t11 = (t10 == (unsigned char)3);
    t8 = t11;
    goto LAB7;

LAB8:    xsi_set_current_line(76, ng0);
    t14 = (t0 + 1672U);
    t17 = *((char **)t14);
    t15 = (31 - 31);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t14 = (t17 + t19);
    t20 = (t0 + 2368U);
    t21 = *((char **)t20);
    t20 = (t0 + 2608U);
    t22 = *((char **)t20);
    t23 = *((int *)t22);
    t24 = (t23 + 3);
    t25 = (t24 - 0);
    t26 = (t25 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t24);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t20 = (t21 + t28);
    memcpy(t20, t14, 8U);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t15 = (31 - 23);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t0 + 2368U);
    t6 = *((char **)t4);
    t4 = (t0 + 2608U);
    t7 = *((char **)t4);
    t5 = *((int *)t7);
    t23 = (t5 + 2);
    t24 = (t23 - 0);
    t26 = (t24 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t23);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t4 = (t6 + t28);
    memcpy(t4, t2, 8U);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t15 = (31 - 15);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t0 + 2368U);
    t6 = *((char **)t4);
    t4 = (t0 + 2608U);
    t7 = *((char **)t4);
    t5 = *((int *)t7);
    t23 = (t5 + 1);
    t24 = (t23 - 0);
    t26 = (t24 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t23);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t4 = (t6 + t28);
    memcpy(t4, t2, 8U);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t15 = (31 - 7);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t0 + 2368U);
    t6 = *((char **)t4);
    t4 = (t0 + 2608U);
    t7 = *((char **)t4);
    t5 = *((int *)t7);
    t23 = (t5 - 0);
    t26 = (t23 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t5);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t4 = (t6 + t28);
    memcpy(t4, t2, 8U);
    goto LAB9;

LAB11:    xsi_set_current_line(82, ng0);
    t12 = (t0 + 1512U);
    t13 = *((char **)t12);
    t23 = (1 - 8);
    t15 = (t23 * -1);
    t18 = (1U * t15);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t9 = *((unsigned char *)t12);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t15 = (31 - 15);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t0 + 2368U);
    t6 = *((char **)t4);
    t4 = (t0 + 2608U);
    t7 = *((char **)t4);
    t5 = *((int *)t7);
    t23 = (t5 + 1);
    t24 = (t23 - 0);
    t26 = (t24 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t23);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t4 = (t6 + t28);
    memcpy(t4, t2, 8U);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t15 = (31 - 7);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t0 + 2368U);
    t6 = *((char **)t4);
    t4 = (t0 + 2608U);
    t7 = *((char **)t4);
    t5 = *((int *)t7);
    t23 = (t5 - 0);
    t26 = (t23 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t5);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t4 = (t6 + t28);
    memcpy(t4, t2, 8U);

LAB14:    goto LAB9;

LAB13:    xsi_set_current_line(83, ng0);
    t14 = (t0 + 1672U);
    t17 = *((char **)t14);
    t26 = (31 - 15);
    t27 = (t26 * 1U);
    t28 = (0 + t27);
    t14 = (t17 + t28);
    t20 = (t0 + 2368U);
    t21 = *((char **)t20);
    t20 = (t0 + 2608U);
    t22 = *((char **)t20);
    t24 = *((int *)t22);
    t25 = (t24 + 3);
    t29 = (t25 - 0);
    t30 = (t29 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t25);
    t31 = (8U * t30);
    t32 = (0 + t31);
    t20 = (t21 + t32);
    memcpy(t20, t14, 8U);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t15 = (31 - 7);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t0 + 2368U);
    t6 = *((char **)t4);
    t4 = (t0 + 2608U);
    t7 = *((char **)t4);
    t5 = *((int *)t7);
    t23 = (t5 + 2);
    t24 = (t23 - 0);
    t26 = (t24 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t23);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t4 = (t6 + t28);
    memcpy(t4, t2, 8U);
    goto LAB14;

LAB16:    xsi_set_current_line(90, ng0);
    t12 = (t0 + 1512U);
    t13 = *((char **)t12);
    t15 = (8 - 1);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t14 = (t33 + 0U);
    t17 = (t14 + 0U);
    *((int *)t17) = 1;
    t17 = (t14 + 4U);
    *((int *)t17) = 0;
    t17 = (t14 + 8U);
    *((int *)t17) = -1;
    t23 = (0 - 1);
    t26 = (t23 * -1);
    t26 = (t26 + 1);
    t17 = (t14 + 12U);
    *((unsigned int *)t17) = t26;
    t17 = (t0 + 11493);
    t21 = (t34 + 0U);
    t22 = (t21 + 0U);
    *((int *)t22) = 0;
    t22 = (t21 + 4U);
    *((int *)t22) = 1;
    t22 = (t21 + 8U);
    *((int *)t22) = 1;
    t24 = (1 - 0);
    t26 = (t24 * 1);
    t26 = (t26 + 1);
    t22 = (t21 + 12U);
    *((unsigned int *)t22) = t26;
    t9 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t12, t33, t17, t34);
    if (t9 != 0)
        goto LAB18;

LAB20:    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t15 = (8 - 1);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t1 + 0U);
    t6 = (t4 + 0U);
    *((int *)t6) = 1;
    t6 = (t4 + 4U);
    *((int *)t6) = 0;
    t6 = (t4 + 8U);
    *((int *)t6) = -1;
    t5 = (0 - 1);
    t26 = (t5 * -1);
    t26 = (t26 + 1);
    t6 = (t4 + 12U);
    *((unsigned int *)t6) = t26;
    t6 = (t0 + 11495);
    t12 = (t33 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 0;
    t13 = (t12 + 4U);
    *((int *)t13) = 1;
    t13 = (t12 + 8U);
    *((int *)t13) = 1;
    t23 = (1 - 0);
    t26 = (t23 * 1);
    t26 = (t26 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t26;
    t8 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t6, t33);
    if (t8 != 0)
        goto LAB21;

LAB22:    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t15 = (8 - 1);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t1 + 0U);
    t6 = (t4 + 0U);
    *((int *)t6) = 1;
    t6 = (t4 + 4U);
    *((int *)t6) = 0;
    t6 = (t4 + 8U);
    *((int *)t6) = -1;
    t5 = (0 - 1);
    t26 = (t5 * -1);
    t26 = (t26 + 1);
    t6 = (t4 + 12U);
    *((unsigned int *)t6) = t26;
    t6 = (t0 + 11497);
    t12 = (t33 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 0;
    t13 = (t12 + 4U);
    *((int *)t13) = 1;
    t13 = (t12 + 8U);
    *((int *)t13) = 1;
    t23 = (1 - 0);
    t26 = (t23 * 1);
    t26 = (t26 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t26;
    t8 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t6, t33);
    if (t8 != 0)
        goto LAB23;

LAB24:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t15 = (31 - 7);
    t18 = (t15 * 1U);
    t19 = (0 + t18);
    t2 = (t3 + t19);
    t4 = (t0 + 2368U);
    t6 = *((char **)t4);
    t4 = (t0 + 2608U);
    t7 = *((char **)t4);
    t5 = *((int *)t7);
    t23 = (t5 - 0);
    t26 = (t23 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t5);
    t27 = (8U * t26);
    t28 = (0 + t27);
    t4 = (t6 + t28);
    memcpy(t4, t2, 8U);

LAB19:    goto LAB9;

LAB18:    xsi_set_current_line(91, ng0);
    t22 = (t0 + 1672U);
    t35 = *((char **)t22);
    t26 = (31 - 7);
    t27 = (t26 * 1U);
    t28 = (0 + t27);
    t22 = (t35 + t28);
    t36 = (t0 + 2368U);
    t37 = *((char **)t36);
    t36 = (t0 + 2608U);
    t38 = *((char **)t36);
    t25 = *((int *)t38);
    t29 = (t25 + 3);
    t39 = (t29 - 0);
    t30 = (t39 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t29);
    t31 = (8U * t30);
    t32 = (0 + t31);
    t36 = (t37 + t32);
    memcpy(t36, t22, 8U);
    goto LAB19;

LAB21:    xsi_set_current_line(93, ng0);
    t13 = (t0 + 1672U);
    t14 = *((char **)t13);
    t26 = (31 - 7);
    t27 = (t26 * 1U);
    t28 = (0 + t27);
    t13 = (t14 + t28);
    t17 = (t0 + 2368U);
    t20 = *((char **)t17);
    t17 = (t0 + 2608U);
    t21 = *((char **)t17);
    t24 = *((int *)t21);
    t25 = (t24 + 2);
    t29 = (t25 - 0);
    t30 = (t29 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t25);
    t31 = (8U * t30);
    t32 = (0 + t31);
    t17 = (t20 + t32);
    memcpy(t17, t13, 8U);
    goto LAB19;

LAB23:    xsi_set_current_line(95, ng0);
    t13 = (t0 + 1672U);
    t14 = *((char **)t13);
    t26 = (31 - 7);
    t27 = (t26 * 1U);
    t28 = (0 + t27);
    t13 = (t14 + t28);
    t17 = (t0 + 2368U);
    t20 = *((char **)t17);
    t17 = (t0 + 2608U);
    t21 = *((char **)t17);
    t24 = *((int *)t21);
    t25 = (t24 + 1);
    t29 = (t25 - 0);
    t30 = (t29 * 1);
    xsi_vhdl_check_range_of_index(0, 511, 1, t25);
    t31 = (8U * t30);
    t32 = (0 + t31);
    t17 = (t20 + t32);
    memcpy(t17, t13, 8U);
    goto LAB19;

LAB25:    xsi_size_not_matching(32U, t65, 0);
    goto LAB26;

}


extern void work_a_3780581436_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3780581436_3212880686_p_0};
	xsi_register_didat("work_a_3780581436_3212880686", "isim/processor_isim_beh.exe.sim/work/a_3780581436_3212880686.didat");
	xsi_register_executes(pe);
}
