#include "Btn.h"
#include "Dio.h"
#include "std_types.h"
#include "avr/io.h"
#include "BTN_Cfg.h"
static BtnStateType Array_state[BTN_NUM_OF_BUTTONS];
void BTN_Init(void)
{
	/***Initializing first state for all buttons****/
	unsigned char i=0;
	for(i=0;i<BTN_NUM_OF_BUTTONS ;i++)
	{
		Array_state[i] = BUT_OFF;
		
	}
}
void BTN_GetState(BtnStateType *BtnStatePtr, unsigned char BtnId)
{
	*BtnStatePtr = Array_state[BtnId];
    
}
void BTN_Manager(void)
{

	static uint8_t au8_btn1state=0;
	static uint8_t au8_btn2state=0;
	static uint8_t au8_btn3state=0;
	if((PINB&0x01)==0)
	{
		au8_btn1state++;
		if(au8_btn1state==3)
		{
			au8_btn1state=0;
			Array_state[0]=1;
		}
	}
	else	
	{
		au8_btn1state=0;
		Array_state[0]=0;
	}
	if((PINB&0x02)==0)
	{
		au8_btn2state++;
		if(au8_btn2state==3)
		{
			au8_btn2state=0;
			Array_state[1]=1;
		}
	}
	else
	{
		au8_btn2state=0;
		Array_state[1]=0;
	}
	if((PINB&0x04)==0)
	{
		au8_btn3state++;
		if(au8_btn3state==3)
		{
			au8_btn3state=0;
			Array_state[2]=1;
		}
	}
	else
	{
		au8_btn3state=0;
		Array_state[2]=0;
	}
	/*
	
	for(i=0;i<BTN_NUM_OF_BUTTONS;i++) 					//for all buttons
	{
		state = Array_state[i]; 						//put previous state in state
		DIO_Read(BUT_ConfigParam[i].DioGroupId , &Data);
		switch(BUT_ConfigParam[i].BtnActiveState)		//switching on Btn active state is it active low or active high
		{
			case ActiveLow:
			{
				switch(state)
				{
					case BUT_OFF:
					{
						if(Data == 0)
						{
							state = BUT_PRSSED;
						}
						else
						{
							state = BUT_OFF;
						}
					}
					break;
					case BUT_PRSSED:
					{
						if(Data == 0)
						{
							state = BUT_ON;
						}
						else
						{
							state = BUT_OFF;
						}
					}

					break;
					case BUT_ON:
					{
						if(Data == 0)
						{
							state = BUT_ON;
						}
						else
						{
							state = BUT_RELEASED;
						}
					}

					break;
					case BUT_RELEASED:
					{
						if(Data == 0)
						{
							state = BUT_ON;
						}
						else
						{
							state = BUT_OFF;
						}
					}
					break;
				}

				break;
			}
			case ActiveHigh:
			{
				switch(state)
				{
					case BUT_OFF:
					{
						if(Data != 0)
						{
							state = BUT_PRSSED;
						}
						else
						{
							state = BUT_OFF;
						}
					}
					break;
					case BUT_PRSSED:
					{
						if(Data != 0)
						{
							state = BUT_ON;
						}
						else
						{
							state = BUT_OFF;
						}
					}

					break;
					case BUT_ON:
					{
						if(Data != 0)
						{
							state = BUT_ON;
						}
						else
						{
							state = BUT_RELEASED;
						}
					}

					break;
					case BUT_RELEASED:
					{
						if(Data != 0)
						{
							state = BUT_ON;
						}
						else
						{
							state = BUT_OFF;
						}
					}
					break;
				}

				break;
			}
			
			break;
		}
		Array_state[i] = state;
	}*/
}
