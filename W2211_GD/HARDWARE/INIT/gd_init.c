#include "gd_init.h"
#include "key.h"

#include "brush.h"
#include "bldc.h"
#include "sewage.h"
#include "control.h"
#include "waterpump.h"
#include "waterelec.h"
#include "cleanwater.h"
#include "commbms.h"
#include "commdry.h"
#include "commbldc.h"
#include "commscreen.h"
#include "separate.h"

extern MCUtoDRYData MtoDRYData;
extern MCUtoBMSData  MtoBMSData;
extern MCUtoBLDCData  MtoBLDCData;
extern MCUtoLCDData   MtoLCDData;
extern TimePara      TimeVar;
extern BMStoMCUData  BMStoMData;
extern ADCPara       ADCVar; 
extern KeyPara       KeyVar;

extern SewagePara     SewageVar;

extern Eeprom_TypeDef E2prom;
extern WaterBoxStatus WaterBSta;

extern BrushPara      BrushVar;
extern BLDCCtl        BLDCVar;
extern DryPara        DryVar;
extern WaterElecPara  WaterElecVar;
extern PumpPara       PumpVar;
extern WorkPara       WorkVar;
extern VoicePara      Voice;
extern MCUtoVoiceData McuToVoice;
extern SEPARATE SEPAR;


void gd_system_init(void)
{
	irc40k_config();
	gd_gpio_init();
	gd_adc_gpio_init();
	gd_exit_init();
	gd_tim0_init();
	gd_tim1_init();
	gd_tim14_init();
	gd_tim2_init();
//	gd_tim13_init();
	systick_config();
	dma_adc_config();
	gd_adc_init();
	KEY_Init();
	voice_uart_cmd_init();
	dma_ch1_usart0_dry_config();
	gd_uart0_init(9600);	
	dma_ch3_usart1_bms_config();	
	gd_uart1_init(9600);
	Init_Pamameter();
	gd_read_eeprom();
#if IWDGOnOffENABLE==1		
 fwdgt_init();
#endif

}


void Init_Pamameter(void)
{
    ADCVar.V_adc_trans_count=0x83;

	TimeVar.bTmr200usFlag=0;
	TimeVar.bTmr01msFlag=0;
	TimeVar.bTmr02msFlag=0;
	TimeVar.bTmr10msFlag=0;
	TimeVar.bPowerOnmsFlag=0;
	TimeVar.bTmr01msCount=0;
	TimeVar.bTmr02msCount=0;
	TimeVar.bTmr10msCount=0;
	TimeVar.bTmrRun02msCount=0;
	TimeVar.bTmrRun10msCount=0;
	TimeVar.bPowerOn1sCount=0;	

	BMStoMData.xpWorkStatus=0;
	BMStoMData.xpWarnStatus=0;
	BMStoMData.xpKeyOnOffStatus=0;
	BMStoMData.xpErrorStatus=0;
	BMStoMData.xpBatVolL=0;
	BMStoMData.xpBatVolH=0;
	BMStoMData.xpBatTempVal=0;
	BMStoMData.xpBatSocVal=0;
	BMStoMData.u8ChargeFullSleepFlag=0;
	BMStoMData.reserve1=0;
	MtoLCDData.xpBrushStatus=BRUSH_YES_STA;//20210909

	KeyVar.bCleanKeyPressFlag = 0;
	KeyVar.bGearKeyPressFlag = 0;
	ADCVar.uiKeyAdcValue=4095;
	
	SewageVar.xpSewageLVcnt0=0;
	SewageVar.xpSewageLVcnt1=0;
	SewageVar.xpSewageChangeFlag=0;//20211012
	SewageVar.xpSewageChangecnt=0;

	WaterBSta.ucQBucketStatus = QBULET_FULL_STA;
	E2prom.uiWriteDataFlash[EE_HEADER]=EEPROM_HEADADD;
	WorkVar.ucFirstONFlag=0;// 20211108

	Voice.off_op_cnt=0;// 2021115
	Voice.on_op_cnt=0;// 2021115
	
	SEPAR_PWM = 0;
	SEPAR.SeparDuty	= 0;		


	SewageVar.xpSewageStateCount=SEWAGE_STAGE_COUNT;

	Set_Bldc_OFF(&BLDCVar);
	Set_Brush_OFF(&BrushVar);
	Set_WaterPump_OFF(&PumpVar);
	Set_Dry_OFF(&DryVar);
	Set_WaterElec_OFF(&WaterElecVar);
	
	
//	voice_uart_cmd_init();
}
