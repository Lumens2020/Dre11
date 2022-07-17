#ifndef __GD_EXIT_H__
#define __GD_EXIT_H__

#include "gd_config.h"

#define PORT_RGM_EXIT				GPIOA
#define	PIN_RGM_EXIT				GPIO_PIN_3

//#define PORT_SM_EXIT				GPIOF
//#define	PIN_SM_EXIT					GPIO_PIN_5


#define	PORT_FGM_EXIT				GPIOC
#define	PIN_FGM_EXIT				GPIO_PIN_9

#define	PORT_PM_EXIT				GPIOB
#define	PIN_PM_EXIT					GPIO_PIN_2

//#define 


void gd_exit_init(void);

void Brush_First_Project(void);
void Brush_First_Recover(void);


void Pump_Project(void);
void Pump_Recover(void);
void Brush_Second_Recover(void);
void Brush_Second_Project(void);
void Separate_Project(void);
void Separate_Recover(void);
#endif


