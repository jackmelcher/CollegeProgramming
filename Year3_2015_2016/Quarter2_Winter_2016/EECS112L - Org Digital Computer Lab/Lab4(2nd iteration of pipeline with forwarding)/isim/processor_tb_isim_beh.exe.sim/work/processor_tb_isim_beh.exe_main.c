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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *WORK_P_1408714369;
char *IEEE_P_1242562249;
char *STD_TEXTIO;
char *IEEE_P_3620187407;
char *IEEE_P_3499444699;
char *IEEE_P_0774719531;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002089673073_1600815965_init();
    work_m_00000000004134447467_2073120511_init();
    ieee_p_2592010699_init();
    work_p_1408714369_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    ieee_p_1242562249_init();
    std_textio_init();
    ieee_p_0774719531_init();
    work_a_0345691092_3212880686_init();
    work_a_2717587577_3212880686_init();
    work_a_4204489651_3212880686_init();
    work_a_1607257461_3212880686_init();
    work_a_1208337864_3212880686_init();
    work_a_0060658144_3212880686_init();
    work_a_3905514557_3212880686_init();
    work_a_1426260211_3212880686_init();
    work_a_4064438392_3212880686_init();
    work_a_2832637653_3212880686_init();
    work_a_2438701584_3212880686_init();
    work_a_0832606739_3212880686_init();
    work_a_3040279891_3212880686_init();
    work_a_1631857915_3212880686_init();
    work_a_1791977183_3212880686_init();
    work_a_2706318233_3212880686_init();
    work_a_3780581436_3212880686_init();
    work_a_1955958757_3212880686_init();
    work_a_3895641916_3212880686_init();
    work_a_3486750924_3212880686_init();
    work_a_1640669797_3212880686_init();


    xsi_register_tops("work_m_00000000002089673073_1600815965");
    xsi_register_tops("work_m_00000000004134447467_2073120511");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    WORK_P_1408714369 = xsi_get_engine_memory("work_p_1408714369");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_0774719531 = xsi_get_engine_memory("ieee_p_0774719531");

    return xsi_run_simulation(argc, argv);

}
