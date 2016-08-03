/***************************************************************************
 *	@ファイル名		:	terunet_common.h
 *	@概要		:	Terunet通信で共通部分となる機能のコマンドと関数を提供する．
 *	@バージョン		:	1.0.0
 *	@開発者		:	佐藤輝一
 *				:	キネクト
 *				:	太田那菜
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver2, Coocox CoIDE
 **************************************************************************/

#ifndef __TERUNET_COMMON_H__
#define __TERUNET_COMMON_H__

#include <stm32f4xx.h>

typedef enum
{
	TerunetCmd_ReadSlaveAddr = 0x01,
	TerunetCmd_ReadSystemVersion,
	TerunetCmd_Head
} eTerunetCmdList_common_t;

extern int Terunet_ReadSlaveAddr(u8 addr, u8* buff);
extern int Terunet_ReadSystemVersion(u8 addr, u8* buff);

#endif /* __TERUNET_COMMON_H__ */
