/*
 * NVM_Cfg.h
 *
 * Created: 29/04/2020 20:02:00
 *  Author: sony
 */ 


#ifndef NVM_CFG_H_
#define NVM_CFG_H_
#include "NVM.h"
#define NVM_NUM_OF_BLOCKS 2u
extern  NVM_ConfigType NVM_BlocConfig[NVM_NUM_OF_BLOCKS];
extern  NVM_GlobalCallbacksType NVM_GlobalCallbacks;


#endif /* NVM_CFG_H_ */