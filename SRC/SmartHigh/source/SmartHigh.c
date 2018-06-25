/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_ftm.h"
#include "fsl_uart.h"
#include "fsl_gpio.h"

#define MAXWHITELEVEL 550

#define BASEADDRESS 2
#define BAUDRATE 38400

#define BOARD_INITPINS_CH1A_DIM_PERIPHERAL FTM0                    /*!<@brief Device name: FTM0 */
#define BOARD_INITPINS_CH1A_DIM_CHANNEL 3                          /*!<@brief FTM0 channel: 3 */
#define BOARD_INITPINS_CH1B_DIM_PERIPHERAL FTM0                    /*!<@brief Device name: FTM0 */
#define BOARD_INITPINS_CH1B_DIM_CHANNEL 0                          /*!<@brief FTM0 channel: 0 */
#define BOARD_INITPINS_CH2A_DIM_PERIPHERAL FTM0                    /*!<@brief Device name: FTM0 */
#define BOARD_INITPINS_CH2A_DIM_CHANNEL 1                          /*!<@brief FTM0 channel: 1 */
#define BOARD_INITPINS_CH2B_DIM_PERIPHERAL FTM2                    /*!<@brief Device name: FTM2 */
#define BOARD_INITPINS_CH2B_DIM_CHANNEL 0                          /*!<@brief FTM2 channel: 0 */
#define BOARD_INITPINS_CH3A_DIM_PERIPHERAL FTM2                    /*!<@brief Device name: FTM2 */
#define BOARD_INITPINS_CH3A_DIM_CHANNEL 1                          /*!<@brief FTM2 channel: 1 */
#define BOARD_INITPINS_CH3B_DIM_PERIPHERAL FTM1                    /*!<@brief Device name: FTM1 */
#define BOARD_INITPINS_CH3B_DIM_CHANNEL 0                          /*!<@brief FTM1 channel: 0 */
#define BOARD_INITPINS_CH4A_DIM_PERIPHERAL FTM1                    /*!<@brief Device name: FTM1 */
#define BOARD_INITPINS_CH4A_DIM_CHANNEL 1                          /*!<@brief FTM1 channel: 1 */
#define BOARD_INITPINS_CH4B_DIM_PERIPHERAL FTM0                    /*!<@brief Device name: FTM0 */
#define BOARD_INITPINS_CH4B_DIM_CHANNEL 2                          /*!<@brief FTM0 channel: 2 */
#define BOARD_INITPINS_CH5A_DIM_PERIPHERAL FTM0                    /*!<@brief Device name: FTM0 */
#define BOARD_INITPINS_CH5A_DIM_CHANNEL 4                          /*!<@brief FTM0 channel: 4 */
#define BOARD_INITPINS_CH5B_DIM_PERIPHERAL FTM0                    /*!<@brief Device name: FTM0 */
#define BOARD_INITPINS_CH5B_DIM_CHANNEL 5                          /*!<@brief FTM0 channel: 5 */
#define BOARD_INITPINS_CH6A_DIM_PERIPHERAL FTM4                    /*!<@brief Device name: FTM4 */
#define BOARD_INITPINS_CH6A_DIM_CHANNEL 0                          /*!<@brief FTM4 channel: 0 */
#define BOARD_INITPINS_CH6B_DIM_PERIPHERAL FTM4                    /*!<@brief Device name: FTM4 */
#define BOARD_INITPINS_CH6B_DIM_CHANNEL 1                          /*!<@brief FTM4 channel: 1 */

FTM_Type * dimFtms[12] = { BOARD_INITPINS_CH1A_DIM_PERIPHERAL,
		BOARD_INITPINS_CH1B_DIM_PERIPHERAL, BOARD_INITPINS_CH2A_DIM_PERIPHERAL,
		BOARD_INITPINS_CH2B_DIM_PERIPHERAL, BOARD_INITPINS_CH3A_DIM_PERIPHERAL,
		BOARD_INITPINS_CH3B_DIM_PERIPHERAL, BOARD_INITPINS_CH4A_DIM_PERIPHERAL,
		BOARD_INITPINS_CH4B_DIM_PERIPHERAL, BOARD_INITPINS_CH5A_DIM_PERIPHERAL,
		BOARD_INITPINS_CH5B_DIM_PERIPHERAL, BOARD_INITPINS_CH6A_DIM_PERIPHERAL,
		BOARD_INITPINS_CH6B_DIM_PERIPHERAL };

uint8_t dimChs[12] = { BOARD_INITPINS_CH1A_DIM_CHANNEL,
		BOARD_INITPINS_CH1B_DIM_CHANNEL, BOARD_INITPINS_CH2A_DIM_CHANNEL,
		BOARD_INITPINS_CH2B_DIM_CHANNEL, BOARD_INITPINS_CH3A_DIM_CHANNEL,
		BOARD_INITPINS_CH3B_DIM_CHANNEL, BOARD_INITPINS_CH4A_DIM_CHANNEL,
		BOARD_INITPINS_CH4B_DIM_CHANNEL, BOARD_INITPINS_CH5A_DIM_CHANNEL,
		BOARD_INITPINS_CH5B_DIM_CHANNEL, BOARD_INITPINS_CH6A_DIM_CHANNEL,
		BOARD_INITPINS_CH6B_DIM_CHANNEL };

/* Get source clock for FTM driver */
#define FTM_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_CoreSysClk)

void setPwm(uint8_t channel, uint16_t level) {
	FTM_Type *ftmA = dimFtms[(channel*2)];
	FTM_Type *ftmB = dimFtms[(channel*2)+1];
	uint32_t modulusA = ftmA->MOD;
	uint32_t modulusB = ftmB->MOD;
    if (level>300) //more than 30%
    {
    	uint32_t val = (level * modulusA) / 1000;
    	ftmA->CONTROLS[dimChs[(channel*2)]].CnV = val;
    	ftmB->CONTROLS[dimChs[(channel*2)+1]].CnV = 0;
    }
    else
    {
    	uint32_t val = ((300-level) * modulusB) / 300;
    	ftmA->CONTROLS[dimChs[(channel*2)]].CnV = .3*modulusA;
    	ftmB->CONTROLS[dimChs[(channel*2)+1]].CnV = val;
    }
	FTM_SetSoftwareTrigger(ftmA, true);
	FTM_SetSoftwareTrigger(ftmB, true);
}

void delay(uint32_t dt) {
	uint32_t i = dt;
	while (i > 0) {
		__asm("NOP");
		i--;
	}
}

int main(void) {
	/* Board pin, clock, debug console init */
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	/* Add your code here */
	ftm_config_t ftmInfo;
	ftm_chnl_pwm_signal_param_t ftmParam[6];

	ftmParam[0].chnlNumber = 0;
	ftmParam[0].level = kFTM_HighTrue;
	ftmParam[0].dutyCyclePercent = 0U;
	ftmParam[0].firstEdgeDelayPercent = 0U;

	ftmParam[1].chnlNumber = 1;
	ftmParam[1].level = kFTM_HighTrue;
	ftmParam[1].dutyCyclePercent = 0U;
	ftmParam[1].firstEdgeDelayPercent = 0U;

	ftmParam[2].chnlNumber = 2;
	ftmParam[2].level = kFTM_HighTrue;
	ftmParam[2].dutyCyclePercent = 0U;
	ftmParam[2].firstEdgeDelayPercent = 0U;

	ftmParam[3].chnlNumber = 3;
	ftmParam[3].level = kFTM_HighTrue;
	ftmParam[3].dutyCyclePercent = 0U;
	ftmParam[3].firstEdgeDelayPercent = 0U;

	ftmParam[4].chnlNumber = 4;
	ftmParam[4].level = kFTM_HighTrue;
	ftmParam[4].dutyCyclePercent = 0U;
	ftmParam[4].firstEdgeDelayPercent = 0U;

	ftmParam[5].chnlNumber = 5;
	ftmParam[5].level = kFTM_HighTrue;
	ftmParam[5].dutyCyclePercent = 0U;
	ftmParam[5].firstEdgeDelayPercent = 0U;

	FTM_GetDefaultConfig(&ftmInfo);
	FTM_Init(FTM0, &ftmInfo);
	FTM_Init(FTM1, &ftmInfo);
	FTM_Init(FTM2, &ftmInfo);
	FTM_Init(FTM4, &ftmInfo);

	FTM_SetupPwm(FTM0, ftmParam, 6U, kFTM_EdgeAlignedPwm, 10000U, FTM_SOURCE_CLOCK);
	FTM_SetupPwm(FTM1, ftmParam, 2U, kFTM_EdgeAlignedPwm, 10000U, FTM_SOURCE_CLOCK);
	FTM_SetupPwm(FTM2, ftmParam, 2U, kFTM_EdgeAlignedPwm, 10000U, FTM_SOURCE_CLOCK);
	FTM_SetupPwm(FTM4, ftmParam, 2U, kFTM_EdgeAlignedPwm, 10000U, FTM_SOURCE_CLOCK);

	FTM_SetWriteProtection(FTM0,false);
	FTM_SetWriteProtection(FTM1,false);
	FTM_SetWriteProtection(FTM2,false);
	FTM_SetWriteProtection(FTM4,false);

	FTM_StartTimer(FTM0, kFTM_SystemClock);
	FTM_StartTimer(FTM1, kFTM_SystemClock);
	FTM_StartTimer(FTM2, kFTM_SystemClock);
	FTM_StartTimer(FTM4, kFTM_SystemClock);

	int i;
	for (i = 0; i < 6; i++) {
		FTM_UpdateChnlEdgeLevelSelect(FTM0, i, kFTM_HighTrue); //Should be able to do this during FTM initialization
	}
	for (i = 0; i < 2; i++) {
		FTM_UpdateChnlEdgeLevelSelect(FTM1, i, kFTM_HighTrue); //Should be able to do this during FTM initialization
		FTM_UpdateChnlEdgeLevelSelect(FTM2, i, kFTM_HighTrue); //Should be able to do this during FTM initialization
		FTM_UpdateChnlEdgeLevelSelect(FTM4, i, kFTM_HighTrue); //Should be able to do this during FTM initialization
	}

	FTM_SetSoftwareTrigger(FTM0, true);
	FTM_SetSoftwareTrigger(FTM1, true);
	FTM_SetSoftwareTrigger(FTM2, true);
	FTM_SetSoftwareTrigger(FTM4, true);

	uint8_t ch;
	uart_config_t user_config;
	UART_GetDefaultConfig(&user_config);
	user_config.baudRate_Bps = BAUDRATE;
	user_config.enableTx = true;
	user_config.enableRx = true;
	UART_Init(UART0, &user_config, CLOCK_GetCoreSysClkFreq());

	if (GPIO_ReadPinInput(GPIOC, 6) == 0) //Shit, we're inverted!!
			{
		UART0->S2 |= UART_S2_RXINV_MASK; //Set the receiver to invert
	}

	uint8_t index = 0;


	int warmWhiteLevel=0,coolWhiteLevel=0;
	while (1)
	{
		UART_ReadBlocking(UART0, &ch, 1);
	    if(ch==BASEADDRESS)
	    {
	    	index=0;
	    }
	    else if (ch>=5)
	    {
	    	if (index<4)
	    	{
	    		setPwm(index,(ch-5)*4);
	    	}
	    	else if (index==4)
	    	{
	    		warmWhiteLevel=ch-5;
	    	}
	    	else if (index==5)
	    	{
	    		coolWhiteLevel=ch-5;
	    		int totalWhiteLevel=warmWhiteLevel+coolWhiteLevel;
	    		if (totalWhiteLevel>250)
	    		{
	    			coolWhiteLevel=(int)(coolWhiteLevel*((float)250/totalWhiteLevel));
	    			warmWhiteLevel=(int)(warmWhiteLevel*((float)250/totalWhiteLevel));
	    		}
	    		warmWhiteLevel=(int)(warmWhiteLevel*4*((float)MAXWHITELEVEL/1000));
	    		coolWhiteLevel=(int)(coolWhiteLevel*4*((float)MAXWHITELEVEL/1000));
	    		setPwm(4,warmWhiteLevel);
	    		setPwm(5,coolWhiteLevel);
	    	}
	    	if (index<6)
	    	{
	    		index++;
	    	}
	    }
	}



/*
  //Super spicy demo mode!!
	while (1)
	{
		__asm("NOP");
		for (i=0;i<6;i++)
		{
			if (i<4)
			{
				setPwm(i,100);
			}
			else
			{
				setPwm(i,10);
			}
			if(i>0)
			{
				setPwm(i-1,0);
			}
			delay(5000000);
		}
		for (i=0;i<6;i++)
		{
			if (i<4)
			{
				setPwm(i,100);
			}
			else
			{
				setPwm(i,10);
			}
		}
		delay(10000000);
		for (i=0;i<6;i++)
		{
			setPwm(i,0);
		}
	}

*/

/*
	setPwm(3,100);
	while (1)
	{
		__asm("NOP");
	}
*/
}
