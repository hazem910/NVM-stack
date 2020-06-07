#include "softwareDelay.h"
#define CLEAR 0


void softwareDelayMs(uint32_t u32_delay_in_ms)
{
	uint32_t i;
	uint32_t j;
    for(i=CLEAR;i<u32_delay_in_ms;i++)
    {
    	for(j=CLEAR;j<NUMBER_OF_ITERATIONS;j++)
    	{

    	}
    }
}



void softwareDelayUS(uint32_t u32_delay_in_US)
{
	for (uint16_t counter=0;counter<u32_delay_in_US;counter++)
	{
		for(uint16_t internalcounter=0;internalcounter<40;internalcounter++)
		{

		}
	}
}
