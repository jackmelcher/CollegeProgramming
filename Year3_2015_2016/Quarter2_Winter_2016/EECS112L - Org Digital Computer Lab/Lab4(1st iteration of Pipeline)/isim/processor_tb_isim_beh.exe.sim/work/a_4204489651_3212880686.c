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
extern char *STD_TEXTIO;
static const char *ng1 = "mem_file";
extern char *STD_STANDARD;
extern char *IEEE_P_1242562249;
static const char *ng4 = "C:/Users/Jack/Desktop/EECS 112L/Lab4/rom.vhd";

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );


char *work_a_4204489651_3212880686_sub_149539859_3057020925(char *t1, char *t2, char *t3)
{
    char t4[688];
    char t5[24];
    char t20[8];
    char t26[8];
    char t32[8];
    char t38[8];
    char t41[32];
    char t50[4096];
    char t73[16];
    char t74[16];
    char t75[16];
    char *t0;
    char *t6;
    char *t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    char *t42;
    char *t43;
    int t44;
    unsigned int t45;
    char *t46;
    int t47;
    char *t48;
    char *t49;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    unsigned char t57;
    char *t58;
    int t59;
    int t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned char t68;
    unsigned char t69;
    unsigned char t70;
    unsigned char t71;
    unsigned char t72;
    int t76;
    int t77;
    int t78;
    int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;

LAB0:    t6 = ((STD_TEXTIO) + 3440);
    t7 = (t3 + 12U);
    t8 = *((unsigned int *)t7);
    t8 = (t8 * 1U);
    t9 = (t4 + 4U);
    t10 = xsi_create_file_variable_in_buffer(0, ng1, t6, t2, t8, 1);
    *((char **)t9) = t10;
    t11 = (t4 + 12U);
    t12 = ((STD_TEXTIO) + 3280);
    t13 = (t11 + 56U);
    *((char **)t13) = t12;
    t14 = (t11 + 40U);
    *((char **)t14) = 0;
    t15 = (t11 + 64U);
    *((int *)t15) = 1;
    t16 = (t11 + 48U);
    *((char **)t16) = 0;
    t17 = (t4 + 84U);
    t18 = ((STD_STANDARD) + 192);
    t19 = (t17 + 88U);
    *((char **)t19) = t18;
    t21 = (t17 + 56U);
    *((char **)t21) = t20;
    xsi_type_set_default_value(t18, t20, 0);
    t22 = (t17 + 80U);
    *((unsigned int *)t22) = 1U;
    t23 = (t4 + 204U);
    t24 = ((STD_STANDARD) + 384);
    t25 = (t23 + 88U);
    *((char **)t25) = t24;
    t27 = (t23 + 56U);
    *((char **)t27) = t26;
    xsi_type_set_default_value(t24, t26, 0);
    t28 = (t23 + 80U);
    *((unsigned int *)t28) = 4U;
    t29 = (t4 + 324U);
    t30 = ((STD_STANDARD) + 384);
    t31 = (t29 + 88U);
    *((char **)t31) = t30;
    t33 = (t29 + 56U);
    *((char **)t33) = t32;
    xsi_type_set_default_value(t30, t32, 0);
    t34 = (t29 + 80U);
    *((unsigned int *)t34) = 4U;
    t35 = (t4 + 444U);
    t36 = ((STD_STANDARD) + 384);
    t37 = (t35 + 88U);
    *((char **)t37) = t36;
    t39 = (t35 + 56U);
    *((char **)t39) = t38;
    xsi_type_set_default_value(t36, t38, 0);
    t40 = (t35 + 80U);
    *((unsigned int *)t40) = 4U;
    t42 = (t41 + 0U);
    t43 = (t42 + 0U);
    *((int *)t43) = 0;
    t43 = (t42 + 4U);
    *((int *)t43) = 127;
    t43 = (t42 + 8U);
    *((int *)t43) = 1;
    t44 = (127 - 0);
    t45 = (t44 * 1);
    t45 = (t45 + 1);
    t43 = (t42 + 12U);
    *((unsigned int *)t43) = t45;
    t43 = (t41 + 16U);
    t46 = (t43 + 0U);
    *((int *)t46) = 31;
    t46 = (t43 + 4U);
    *((int *)t46) = 0;
    t46 = (t43 + 8U);
    *((int *)t46) = -1;
    t47 = (0 - 31);
    t45 = (t47 * -1);
    t45 = (t45 + 1);
    t46 = (t43 + 12U);
    *((unsigned int *)t46) = t45;
    t46 = (t4 + 564U);
    t48 = (t1 + 3408);
    t49 = (t46 + 88U);
    *((char **)t49) = t48;
    t51 = (t46 + 56U);
    *((char **)t51) = t50;
    xsi_type_set_default_value(t48, t50, 0);
    t52 = (t46 + 64U);
    t53 = (t48 + 80U);
    t54 = *((char **)t53);
    *((char **)t52) = t54;
    t55 = (t46 + 80U);
    *((unsigned int *)t55) = 4096U;
    t56 = (t5 + 4U);
    t57 = (t2 != 0);
    if (t57 == 1)
        goto LAB3;

LAB2:    t58 = (t5 + 12U);
    *((char **)t58) = t3;
    t59 = 0;
    t60 = 63;

LAB4:    if (t59 <= t60)
        goto LAB5;

LAB7:    t6 = (t29 + 56U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    *((int *)t6) = 0;

LAB9:    t6 = (t4 + 4U);
    t7 = *((char **)t6);
    t57 = std_textio_endfile(t7);
    t68 = (!(t57));
    if (t68 != 0)
        goto LAB10;

LAB12:    t6 = (t46 + 56U);
    t7 = *((char **)t6);
    t57 = (4096U != 4096U);
    if (t57 == 1)
        goto LAB29;

LAB30:    t0 = xsi_get_transient_memory(4096U);
    memcpy(t0, t7, 4096U);

LAB1:    xsi_access_variable_delete(t11);
    t6 = (t4 + 4U);
    t7 = *((char **)t6);
    xsi_delete_file_variable(t7);
    return t0;
LAB3:    *((char **)t56) = t2;
    goto LAB2;

LAB5:    t61 = xsi_get_transient_memory(32U);
    memset(t61, 0, 32U);
    t62 = t61;
    memset(t62, (unsigned char)2, 32U);
    t63 = (t46 + 56U);
    t64 = *((char **)t63);
    t65 = (t59 - 0);
    t45 = (t65 * 1);
    xsi_vhdl_check_range_of_index(0, 127, 1, t59);
    t66 = (32U * t45);
    t67 = (0 + t66);
    t63 = (t64 + t67);
    memcpy(t63, t61, 32U);

LAB6:    if (t59 == t60)
        goto LAB7;

LAB8:    t44 = (t59 + 1);
    t59 = t44;
    goto LAB4;

LAB10:    t9 = (t4 + 4U);
    t10 = *((char **)t9);
    std_textio_readline(STD_TEXTIO, (char *)0, t10, t11);
    t6 = (t35 + 56U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    *((int *)t6) = 0;
    t44 = 1;
    t47 = 8;

LAB13:    if (t44 <= t47)
        goto LAB14;

LAB16:    t6 = (t29 + 56U);
    t7 = *((char **)t6);
    t44 = *((int *)t7);
    t47 = (t44 + 4);
    t6 = (t29 + 56U);
    t9 = *((char **)t6);
    t6 = (t9 + 0);
    *((int *)t6) = t47;
    goto LAB9;

LAB11:;
LAB14:    t6 = (t17 + 56U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    std_textio_read8(STD_TEXTIO, (char *)0, t11, t6);
    t6 = (t17 + 56U);
    t7 = *((char **)t6);
    t68 = *((unsigned char *)t7);
    t69 = ((unsigned char)48 <= t68);
    if (t69 == 1)
        goto LAB20;

LAB21:    t57 = (unsigned char)0;

LAB22:    if (t57 != 0)
        goto LAB17;

LAB19:    t6 = (t17 + 56U);
    t7 = *((char **)t6);
    t68 = *((unsigned char *)t7);
    t69 = ((unsigned char)97 <= t68);
    if (t69 == 1)
        goto LAB25;

LAB26:    t57 = (unsigned char)0;

LAB27:    if (t57 != 0)
        goto LAB23;

LAB24:    t6 = (t1 + 9044);
    t9 = ((STD_STANDARD) + 384);
    t10 = (t29 + 56U);
    t12 = *((char **)t10);
    t59 = *((int *)t12);
    t10 = xsi_int_to_mem(t59);
    t13 = xsi_string_variable_get_image(t73, t9, t10);
    t15 = ((STD_STANDARD) + 1008);
    t16 = (t75 + 0U);
    t18 = (t16 + 0U);
    *((int *)t18) = 1;
    t18 = (t16 + 4U);
    *((int *)t18) = 20;
    t18 = (t16 + 8U);
    *((int *)t18) = 1;
    t60 = (20 - 1);
    t8 = (t60 * 1);
    t8 = (t8 + 1);
    t18 = (t16 + 12U);
    *((unsigned int *)t18) = t8;
    t14 = xsi_base_array_concat(t14, t74, t15, (char)97, t6, t75, (char)97, t13, t73, (char)101);
    t18 = (t73 + 12U);
    t8 = *((unsigned int *)t18);
    t45 = (20U + t8);
    xsi_report(t14, t45, (unsigned char)2);

LAB18:    t6 = (t35 + 56U);
    t7 = *((char **)t6);
    t59 = *((int *)t7);
    t6 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t73, t59, 4);
    t9 = (t46 + 56U);
    t10 = *((char **)t9);
    t60 = (t44 * 4);
    t65 = (35 - t60);
    t8 = (31 - t65);
    t76 = (t44 * 4);
    t77 = (32 - t76);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t65, t77, -1);
    t45 = (t8 * 1U);
    t9 = (t29 + 56U);
    t12 = *((char **)t9);
    t78 = *((int *)t12);
    t79 = (t78 - 0);
    t66 = (t79 * 1);
    xsi_vhdl_check_range_of_index(0, 127, 1, t78);
    t67 = (32U * t66);
    t80 = (0 + t67);
    t81 = (t80 + t45);
    t9 = (t10 + t81);
    t13 = (t73 + 12U);
    t82 = *((unsigned int *)t13);
    t82 = (t82 * 1U);
    memcpy(t9, t6, t82);

LAB15:    if (t44 == t47)
        goto LAB16;

LAB28:    t59 = (t44 + 1);
    t44 = t59;
    goto LAB13;

LAB17:    t6 = (t17 + 56U);
    t10 = *((char **)t6);
    t72 = *((unsigned char *)t10);
    t59 = ((((int)(t72))) - (((int)((unsigned char)48))));
    t6 = (t35 + 56U);
    t12 = *((char **)t6);
    t6 = (t12 + 0);
    *((int *)t6) = t59;
    goto LAB18;

LAB20:    t6 = (t17 + 56U);
    t9 = *((char **)t6);
    t70 = *((unsigned char *)t9);
    t71 = (t70 <= (unsigned char)57);
    t57 = t71;
    goto LAB22;

LAB23:    t6 = (t17 + 56U);
    t10 = *((char **)t6);
    t72 = *((unsigned char *)t10);
    t59 = ((((int)(t72))) - (((int)((unsigned char)97))));
    t60 = (t59 + 10);
    t6 = (t35 + 56U);
    t12 = *((char **)t6);
    t6 = (t12 + 0);
    *((int *)t6) = t60;
    goto LAB18;

LAB25:    t6 = (t17 + 56U);
    t9 = *((char **)t6);
    t70 = *((unsigned char *)t9);
    t71 = (t70 <= (unsigned char)102);
    t57 = t71;
    goto LAB27;

LAB29:    xsi_size_not_matching(4096U, 4096U, 0);
    goto LAB30;

LAB31:;
}

static void work_a_4204489651_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(73, ng4);

LAB3:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 1032U);
    t3 = *((char **)t1);
    t1 = (t0 + 4844U);
    t4 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t3, t1);
    t5 = (t4 - 0);
    t6 = (t5 * 1);
    xsi_vhdl_check_range_of_index(0, 127, 1, t4);
    t7 = (32U * t6);
    t8 = (0 + t7);
    t9 = (t2 + t8);
    t10 = (t0 + 2912);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t9, 32U);
    xsi_driver_first_trans_fast_port(t10);

LAB2:    t15 = (t0 + 2832);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_4204489651_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4204489651_3212880686_p_0};
	static char *se[] = {(void *)work_a_4204489651_3212880686_sub_149539859_3057020925};
	xsi_register_didat("work_a_4204489651_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_4204489651_3212880686.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
