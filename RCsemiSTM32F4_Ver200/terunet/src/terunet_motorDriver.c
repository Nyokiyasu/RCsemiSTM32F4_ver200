/***************************************************************************
 *	@ファイル名		:	terunet_motorDriver.c
 *	@概要		:	Terunet通信にてモータドライバを制御する．
 *	@バージョン		:	1.0.0
 *	@開発者		:	佐藤輝一
 *				:	キネクト
 *				:	太田那菜
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver2, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "terunet.h"
#include "terunet_common.h"
#include "terunet_motorDriver.h"
#include "terunet_slaveAddress.h"

/* -------------------------------------------------
 * @関数名		:	Terunet_MD_Drive
 * @概要			:	TerunetにてPWMの情報を1つずつ送信する
 * @引数-addr	:	送信先のアドレス
 *　          -ch		:	モータ番号
 *　          -duty	:	PWMのデューティ比(%)
 * @戻り値		:	RS485で受信したデータ
 * ---------------------------------------------- */
int Terunet_MD_Drive(u8 addr, u8 ch, int duty, u8 recvData[])
{
	u8 sendVal;
	u8 data[2];

	if(duty == TERUNET_MD_BRAKEVALUE)	sendVal = 127;
	else								sendVal = (u8)(duty&0xff);

	data[0] = ch;
	data[1] = sendVal;

	Terunet_SendFrame((TERUNET_BASEADDR_MD|(addr&0x0F)), TerunetCmd_MD_ReqSingleDrive, 2, data);
	return Terunet_ReceiveFrame(recvData, TerunetCmd_MD_ReqSingleDrive);
}
