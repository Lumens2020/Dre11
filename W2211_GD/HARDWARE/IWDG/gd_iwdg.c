#include "gd_iwdg.h"


//独立看门狗初始化
void fwdgt_init(void)
{

	  fwdgt_config(50, FWDGT_PSC_DIV64);		//  40k/64 = 625hz		1/625825 = 40MS 
    fwdgt_enable();
		fwdgt_counter_reload();
}

void fwdgt_reload(void)
{
   fwdgt_counter_reload();
}


void irc40k_config(void)
{
    /* enable IRC40K */
    rcu_osci_on(RCU_IRC40K);
    /* wait till IRC40K is ready */
    while(ERROR == rcu_osci_stab_wait(RCU_IRC40K));
}












