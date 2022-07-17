#ifndef __MAIN_H__
#define	__MAIN_H__

#include "gd32f3x0.h"
#include <stdio.h>
#include "systick.h"

#include "config.h"

#include "gd_adc.h"
#include "gd_exit.h"
#include "gd_gpio.h"
#include "gd_init.h"
#include "gd_iwdg.h"
#include "gd_tim.h"
#include "gd_uart.h"
#include "gd_dma.h"
#include "gd_eeprom.h"

#include "commbldc.h"
#include "commbms.h"
#include "commdry.h"
#include "commfct.h"
#include "commscreen.h"
#include "commtest.h"
#include "uartconfig.h"



#include "adcconfig.h"
#include "autoclean.h"
#include "bldc.h"
#include "brush.h"
#include "charge.h"
#include "cleanwater.h"
#include "control.h"
#include "drycontrol.h"
#include "error.h"
#include "key.h"
#include "keyad.h"
#include "keyio.h"
#include "modedeal.h"
#include "waterpump.h"
#include "separate.h"
#include "sewage.h"
#include "tilt.h"
#include "voice.h"
#include "voicelist.h"
#include "waterelec.h"
//#include "pumpvolt.h"
#include "improve.h"
#include "commvoice.h"

void Main_Running(void);
#endif

