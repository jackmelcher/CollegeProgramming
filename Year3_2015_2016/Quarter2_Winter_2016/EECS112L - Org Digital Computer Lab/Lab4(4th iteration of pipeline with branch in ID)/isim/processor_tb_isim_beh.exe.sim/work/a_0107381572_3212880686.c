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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab4/HazardDetectionUnit.vhd";



static void work_a_0107381572_3212880686_p_0(char *t0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    unsigned char t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned char t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned char t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned char t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned char t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;

LAB0:    xsi_set_current_line(52, ng0);
    t5 = (t0 + 1512U);
    t6 = *((char **)t5);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB14;

LAB15:    t4 = (unsigned char)0;

LAB16:    if (t4 == 1)
        goto LAB11;

LAB12:    t3 = (unsigned char)0;

LAB13:    if (t3 == 1)
        goto LAB8;

LAB9:    t2 = (unsigned char)0;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB50:    t47 = (t0 + 4080);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    *((unsigned char *)t51) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t47);

LAB2:    t52 = (t0 + 3968);
    *((int *)t52) = 1;

LAB1:    return;
LAB3:    t42 = (t0 + 4080);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    t45 = (t44 + 56U);
    t46 = *((char **)t45);
    *((unsigned char *)t46) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t42);
    goto LAB2;

LAB5:    t35 = (t0 + 1352U);
    t36 = *((char **)t35);
    t35 = (t0 + 6634);
    t38 = 1;
    if (5U == 5U)
        goto LAB44;

LAB45:    t38 = 0;

LAB46:    t1 = (!(t38));
    goto LAB7;

LAB8:    t28 = (t0 + 1192U);
    t29 = *((char **)t28);
    t28 = (t0 + 6629);
    t31 = 1;
    if (5U == 5U)
        goto LAB38;

LAB39:    t31 = 0;

LAB40:    t2 = (!(t31));
    goto LAB10;

LAB11:    t21 = (t0 + 1032U);
    t22 = *((char **)t21);
    t21 = (t0 + 6624);
    t24 = 1;
    if (5U == 5U)
        goto LAB32;

LAB33:    t24 = 0;

LAB34:    t3 = (!(t24));
    goto LAB13;

LAB14:    t5 = (t0 + 1352U);
    t10 = *((char **)t5);
    t5 = (t0 + 1032U);
    t11 = *((char **)t5);
    t12 = 1;
    if (5U == 5U)
        goto LAB20;

LAB21:    t12 = 0;

LAB22:    if (t12 == 1)
        goto LAB17;

LAB18:    t15 = (t0 + 1352U);
    t16 = *((char **)t15);
    t15 = (t0 + 1192U);
    t17 = *((char **)t15);
    t18 = 1;
    if (5U == 5U)
        goto LAB26;

LAB27:    t18 = 0;

LAB28:    t9 = t18;

LAB19:    t4 = t9;
    goto LAB16;

LAB17:    t9 = (unsigned char)1;
    goto LAB19;

LAB20:    t13 = 0;

LAB23:    if (t13 < 5U)
        goto LAB24;
    else
        goto LAB22;

LAB24:    t5 = (t10 + t13);
    t14 = (t11 + t13);
    if (*((unsigned char *)t5) != *((unsigned char *)t14))
        goto LAB21;

LAB25:    t13 = (t13 + 1);
    goto LAB23;

LAB26:    t19 = 0;

LAB29:    if (t19 < 5U)
        goto LAB30;
    else
        goto LAB28;

LAB30:    t15 = (t16 + t19);
    t20 = (t17 + t19);
    if (*((unsigned char *)t15) != *((unsigned char *)t20))
        goto LAB27;

LAB31:    t19 = (t19 + 1);
    goto LAB29;

LAB32:    t25 = 0;

LAB35:    if (t25 < 5U)
        goto LAB36;
    else
        goto LAB34;

LAB36:    t26 = (t22 + t25);
    t27 = (t21 + t25);
    if (*((unsigned char *)t26) != *((unsigned char *)t27))
        goto LAB33;

LAB37:    t25 = (t25 + 1);
    goto LAB35;

LAB38:    t32 = 0;

LAB41:    if (t32 < 5U)
        goto LAB42;
    else
        goto LAB40;

LAB42:    t33 = (t29 + t32);
    t34 = (t28 + t32);
    if (*((unsigned char *)t33) != *((unsigned char *)t34))
        goto LAB39;

LAB43:    t32 = (t32 + 1);
    goto LAB41;

LAB44:    t39 = 0;

LAB47:    if (t39 < 5U)
        goto LAB48;
    else
        goto LAB46;

LAB48:    t40 = (t36 + t39);
    t41 = (t35 + t39);
    if (*((unsigned char *)t40) != *((unsigned char *)t41))
        goto LAB45;

LAB49:    t39 = (t39 + 1);
    goto LAB47;

LAB51:    goto LAB2;

}

static void work_a_0107381572_3212880686_p_1(char *t0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    unsigned char t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned char t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned char t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned char t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned char t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;

LAB0:    xsi_set_current_line(56, ng0);
    t5 = (t0 + 1512U);
    t6 = *((char **)t5);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB14;

LAB15:    t4 = (unsigned char)0;

LAB16:    if (t4 == 1)
        goto LAB11;

LAB12:    t3 = (unsigned char)0;

LAB13:    if (t3 == 1)
        goto LAB8;

LAB9:    t2 = (unsigned char)0;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB50:    t47 = (t0 + 4144);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    *((unsigned char *)t51) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t47);

LAB2:    t52 = (t0 + 3984);
    *((int *)t52) = 1;

LAB1:    return;
LAB3:    t42 = (t0 + 4144);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    t45 = (t44 + 56U);
    t46 = *((char **)t45);
    *((unsigned char *)t46) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t42);
    goto LAB2;

LAB5:    t35 = (t0 + 1352U);
    t36 = *((char **)t35);
    t35 = (t0 + 6649);
    t38 = 1;
    if (5U == 5U)
        goto LAB44;

LAB45:    t38 = 0;

LAB46:    t1 = (!(t38));
    goto LAB7;

LAB8:    t28 = (t0 + 1192U);
    t29 = *((char **)t28);
    t28 = (t0 + 6644);
    t31 = 1;
    if (5U == 5U)
        goto LAB38;

LAB39:    t31 = 0;

LAB40:    t2 = (!(t31));
    goto LAB10;

LAB11:    t21 = (t0 + 1032U);
    t22 = *((char **)t21);
    t21 = (t0 + 6639);
    t24 = 1;
    if (5U == 5U)
        goto LAB32;

LAB33:    t24 = 0;

LAB34:    t3 = (!(t24));
    goto LAB13;

LAB14:    t5 = (t0 + 1352U);
    t10 = *((char **)t5);
    t5 = (t0 + 1032U);
    t11 = *((char **)t5);
    t12 = 1;
    if (5U == 5U)
        goto LAB20;

LAB21:    t12 = 0;

LAB22:    if (t12 == 1)
        goto LAB17;

LAB18:    t15 = (t0 + 1352U);
    t16 = *((char **)t15);
    t15 = (t0 + 1192U);
    t17 = *((char **)t15);
    t18 = 1;
    if (5U == 5U)
        goto LAB26;

LAB27:    t18 = 0;

LAB28:    t9 = t18;

LAB19:    t4 = t9;
    goto LAB16;

LAB17:    t9 = (unsigned char)1;
    goto LAB19;

LAB20:    t13 = 0;

LAB23:    if (t13 < 5U)
        goto LAB24;
    else
        goto LAB22;

LAB24:    t5 = (t10 + t13);
    t14 = (t11 + t13);
    if (*((unsigned char *)t5) != *((unsigned char *)t14))
        goto LAB21;

LAB25:    t13 = (t13 + 1);
    goto LAB23;

LAB26:    t19 = 0;

LAB29:    if (t19 < 5U)
        goto LAB30;
    else
        goto LAB28;

LAB30:    t15 = (t16 + t19);
    t20 = (t17 + t19);
    if (*((unsigned char *)t15) != *((unsigned char *)t20))
        goto LAB27;

LAB31:    t19 = (t19 + 1);
    goto LAB29;

LAB32:    t25 = 0;

LAB35:    if (t25 < 5U)
        goto LAB36;
    else
        goto LAB34;

LAB36:    t26 = (t22 + t25);
    t27 = (t21 + t25);
    if (*((unsigned char *)t26) != *((unsigned char *)t27))
        goto LAB33;

LAB37:    t25 = (t25 + 1);
    goto LAB35;

LAB38:    t32 = 0;

LAB41:    if (t32 < 5U)
        goto LAB42;
    else
        goto LAB40;

LAB42:    t33 = (t29 + t32);
    t34 = (t28 + t32);
    if (*((unsigned char *)t33) != *((unsigned char *)t34))
        goto LAB39;

LAB43:    t32 = (t32 + 1);
    goto LAB41;

LAB44:    t39 = 0;

LAB47:    if (t39 < 5U)
        goto LAB48;
    else
        goto LAB46;

LAB48:    t40 = (t36 + t39);
    t41 = (t35 + t39);
    if (*((unsigned char *)t40) != *((unsigned char *)t41))
        goto LAB45;

LAB49:    t39 = (t39 + 1);
    goto LAB47;

LAB51:    goto LAB2;

}

static void work_a_0107381572_3212880686_p_2(char *t0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    unsigned char t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned char t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned char t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned char t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned char t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;

LAB0:    xsi_set_current_line(61, ng0);
    t5 = (t0 + 1512U);
    t6 = *((char **)t5);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)3);
    if (t8 == 1)
        goto LAB14;

LAB15:    t4 = (unsigned char)0;

LAB16:    if (t4 == 1)
        goto LAB11;

LAB12:    t3 = (unsigned char)0;

LAB13:    if (t3 == 1)
        goto LAB8;

LAB9:    t2 = (unsigned char)0;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB50:    t47 = (t0 + 4208);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    *((unsigned char *)t51) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t47);

LAB2:    t52 = (t0 + 4000);
    *((int *)t52) = 1;

LAB1:    return;
LAB3:    t42 = (t0 + 4208);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    t45 = (t44 + 56U);
    t46 = *((char **)t45);
    *((unsigned char *)t46) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t42);
    goto LAB2;

LAB5:    t35 = (t0 + 1352U);
    t36 = *((char **)t35);
    t35 = (t0 + 6664);
    t38 = 1;
    if (5U == 5U)
        goto LAB44;

LAB45:    t38 = 0;

LAB46:    t1 = (!(t38));
    goto LAB7;

LAB8:    t28 = (t0 + 1192U);
    t29 = *((char **)t28);
    t28 = (t0 + 6659);
    t31 = 1;
    if (5U == 5U)
        goto LAB38;

LAB39:    t31 = 0;

LAB40:    t2 = (!(t31));
    goto LAB10;

LAB11:    t21 = (t0 + 1032U);
    t22 = *((char **)t21);
    t21 = (t0 + 6654);
    t24 = 1;
    if (5U == 5U)
        goto LAB32;

LAB33:    t24 = 0;

LAB34:    t3 = (!(t24));
    goto LAB13;

LAB14:    t5 = (t0 + 1352U);
    t10 = *((char **)t5);
    t5 = (t0 + 1032U);
    t11 = *((char **)t5);
    t12 = 1;
    if (5U == 5U)
        goto LAB20;

LAB21:    t12 = 0;

LAB22:    if (t12 == 1)
        goto LAB17;

LAB18:    t15 = (t0 + 1352U);
    t16 = *((char **)t15);
    t15 = (t0 + 1192U);
    t17 = *((char **)t15);
    t18 = 1;
    if (5U == 5U)
        goto LAB26;

LAB27:    t18 = 0;

LAB28:    t9 = t18;

LAB19:    t4 = t9;
    goto LAB16;

LAB17:    t9 = (unsigned char)1;
    goto LAB19;

LAB20:    t13 = 0;

LAB23:    if (t13 < 5U)
        goto LAB24;
    else
        goto LAB22;

LAB24:    t5 = (t10 + t13);
    t14 = (t11 + t13);
    if (*((unsigned char *)t5) != *((unsigned char *)t14))
        goto LAB21;

LAB25:    t13 = (t13 + 1);
    goto LAB23;

LAB26:    t19 = 0;

LAB29:    if (t19 < 5U)
        goto LAB30;
    else
        goto LAB28;

LAB30:    t15 = (t16 + t19);
    t20 = (t17 + t19);
    if (*((unsigned char *)t15) != *((unsigned char *)t20))
        goto LAB27;

LAB31:    t19 = (t19 + 1);
    goto LAB29;

LAB32:    t25 = 0;

LAB35:    if (t25 < 5U)
        goto LAB36;
    else
        goto LAB34;

LAB36:    t26 = (t22 + t25);
    t27 = (t21 + t25);
    if (*((unsigned char *)t26) != *((unsigned char *)t27))
        goto LAB33;

LAB37:    t25 = (t25 + 1);
    goto LAB35;

LAB38:    t32 = 0;

LAB41:    if (t32 < 5U)
        goto LAB42;
    else
        goto LAB40;

LAB42:    t33 = (t29 + t32);
    t34 = (t28 + t32);
    if (*((unsigned char *)t33) != *((unsigned char *)t34))
        goto LAB39;

LAB43:    t32 = (t32 + 1);
    goto LAB41;

LAB44:    t39 = 0;

LAB47:    if (t39 < 5U)
        goto LAB48;
    else
        goto LAB46;

LAB48:    t40 = (t36 + t39);
    t41 = (t35 + t39);
    if (*((unsigned char *)t40) != *((unsigned char *)t41))
        goto LAB45;

LAB49:    t39 = (t39 + 1);
    goto LAB47;

LAB51:    goto LAB2;

}


extern void work_a_0107381572_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0107381572_3212880686_p_0,(void *)work_a_0107381572_3212880686_p_1,(void *)work_a_0107381572_3212880686_p_2};
	xsi_register_didat("work_a_0107381572_3212880686", "isim/processor_tb_isim_beh.exe.sim/work/a_0107381572_3212880686.didat");
	xsi_register_executes(pe);
}
