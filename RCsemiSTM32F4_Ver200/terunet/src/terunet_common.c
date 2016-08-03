/***************************************************************************
 *	@ファイル名		:	terunet_common.c
 *	@概要		:	Terunet通信で共通部分となる機能のコマンドと関数を提供する．
 *	@バージョン		:	1.0.0
 *	@開発者		:	佐藤輝一
 *				:	キネクト
 *				:	太田那菜
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver2, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "terunet.h"
#include "terunet_common.h"

int Terunet_ReadSlaveAddr(u8 addr, u8* buff)
{
	Terunet_SendFrame(addr, TerunetCmd_ReadSlaveAddr, 0, 0);
	return Terunet_ReceiveFrame(buff, TerunetCmd_ReadSlaveAddr);
}

int Terunet_ReadSystemVersion(u8 addr, u8* buff)
{
	Terunet_SendFrame(addr, TerunetCmd_ReadSystemVersion, 0, 0);
	return Terunet_ReceiveFrame(buff, TerunetCmd_ReadSystemVersion);
}
