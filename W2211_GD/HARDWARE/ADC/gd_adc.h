#ifndef __GD_ADC_H__
#define __GD_ADC_H__

#include "gd_config.h"


#define ADC_RDATA1                        REG32(ADC + 0x50U)               /*!< ADC regular data register */



typedef enum{
	WaterPumpCHN=0,
	BrushR_CHN,
	BrushF_CHN,
	Key_CHN,
	SewageLV_CHN,// A_DHL_CHN
	SewageStage_CHN,// SIGL_CHN
	CHGVol_CHN,
	WaterLV_CHN
}ADC_CHN;

#define ADC_CHANNAL_NUM 		9

typedef struct{
	uint16_t uiADC_ResultBuff[ADC_CHANNAL_NUM];
	uint16_t uiWaterPumpAdcValue;// ˮ�õ���AD
	uint16_t uiBrushRAdcValue;// ��ˢ1����AD
	uint16_t uiBrushFAdcValue;// ��ˢ2����AD
	uint16_t uiKeyAdcValue;// ����AD
	uint16_t uiSewageStageAdcValue;// ��ˮˮλAD
	uint16_t uiSewageLVAdcValue;// ��ˮ����AD
	uint16_t uiCHGAdcValue;// ����AD
	uint16_t uiCleanWaterAdcValue;// ��ˮ����AD
	uint16_t uiNOBrushAdcValue;
	uint16_t uiStallBrushAdcValue;
	uint16_t uiOC1BrushAdcValue;
	uint16_t uiOC2BrushAdcValue;
	uint16_t uiLimitBrushAdcValue;
	uint16_t uiWaterPumpAdcValue_sum;
	uint16_t uiWaterPumpAdcValue_max;
	uint16_t uiWaterPumpAdcValue_min;
	uint16_t uiBrushRAdcValue_sum;
	uint16_t uiBrushRAdcValue_max;
	uint16_t uiBrushRAdcValue_min;
	uint16_t uiBrushFAdcValue_sum;
	uint16_t uiBrushFAdcValue_max;
	uint16_t uiBrushFAdcValue_min;
	uint16_t uiKeyAdcValue_sum;
	uint16_t uiKeyAdcValue_max;
	uint16_t uiKeyAdcValue_min;
	uint16_t uiSewageLVAdcValue_sum;
	uint16_t uiSewageLVAdcValue_max;
	uint16_t uiSewageLVAdcValue_min;
	uint16_t uiSewageStageAdcValue_sum;
	uint16_t uiSewageStageAdcValue_max;
	uint16_t uiSewageStageAdcValue_min;
	uint8_t  V_adc_trans_count;	
	uint8_t  uiBrushRAdcValue_cnt;	
	uint8_t  uiBrushFAdcValue_cnt;	
	
	uint16_t uiBrushRAdcValueH;// ��ˢ����AD
	uint16_t uiBrushRAdcValueL;// ��ˢ����AD
	uint16_t uiBrushFAdcValueH;// ��ˢ����AD
	uint16_t uiBrushFAdcValueL;// ��ˢ����AD
	uint16_t uiSewageAdc;
}ADCPara;



void gd_adc_gpio_init(void);
void gd_adc_init(void);


#endif

