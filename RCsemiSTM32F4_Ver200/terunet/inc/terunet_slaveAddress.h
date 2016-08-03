/***************************************************************************
 *	@ファイル名		:	terunet_slaveAddress.h
 *	@概要		:	Terunet通信においてのコマンド値や，スレーブのアドレス分類などを定義する．
 *					スレーブ側の機器においてもマスターと同じものをインクルードすること．
 *	@バージョン		:	1.0.0
 *	@開発者		:	佐藤輝一
 *				:	キネクト
 *				:	太田那菜
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver2, Coocox CoIDE
 **************************************************************************/

#ifndef __TERUNET_SLAVEADDRESS_H__
#define __TERUNET_SLAVEADDRESS_H__

#define TERUNET_BASEADDR_OTHER0	0x10
#define TERUNET_BASEADDR_OTHER1	0x20
#define TERUNET_BASEADDR_OTHER2 0x30
#define TERUNET_BASEADDR_MD		0xD0
#define TERUNET_BASEADDR_DIO	0xE0
#define TERUNET_BASEADDR_ADC	0xF0

#endif /* __TERUNET_SLAVEADDRESS_H__ */
