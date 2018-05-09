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
static const char *ng0 = "C:/Users/Jack/Desktop/EECS 112L/Assignment Repository/Lab4/pc.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0345691092_3212880686_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(66, ng0);
    t1 = (t0 + 2328U);
    t3 = *((char **)t1);
    t1 = (t0 + 5908U);
    t4 = (t0 + 6035);
    t8 = (t0 + 5860U);
    t2 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t1, t4, t8);
    if (t2 != 0)
        goto LAB10;

LAB12:
LAB11:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 2328U);
    t3 = *((char **)t1);
    t1 = (t0 + 3712);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 32U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3632);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(58, ng0);
    t3 = (t0 + 1352U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 1192U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(59, ng0);
    t3 = xsi_get_transient_memory(32U);
    memset(t3, 0, 32U);
    t7 = t3;
    memset(t7, (unsigned char)2, 32U);
    t8 = (t0 + 2328U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    memcpy(t8, t3, 32U);
    goto LAB6;

LAB8:    xsi_set_current_line(62, ng0);
    t1 = (t0 + 1512U);
    t4 = *((char **)t1);
    t1 = (t0 + 2328U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    memcpy(t1, t4, 32U);
    goto LAB6;

LAB10:    xsi_set_current_line(67, ng0);
    t9 = xsi_get_transient_memory(32U);
    memset(t9, 0, 32U);
    t10 = t9;
    memset(t10, (unsigned char)2, 32U);
    t11 = (t0 + 2328U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    memcpy(t11, t9, 32U);
    goto LAB11;

}


extern void work_a_0345691092_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0345691092_3212880686_p_0};
	xsi_register_didat("work_a_0345691092_3212880686", "isim/processor_isim_beh.exe.sim/work/a_0345691092_3212880686.didat");
	xsi_register_executes(pe);
}
