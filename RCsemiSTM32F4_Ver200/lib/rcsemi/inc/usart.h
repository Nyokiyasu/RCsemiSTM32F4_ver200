/***************************************************************************
 *	@ファイル名		:	usart.h
 *	@概要		:	USART2, USART3初期化や送受信を提供する．
 *					USART2(Bluetooth)	TX:PD5 / RX:PD6
 *					USART3(電話線)		TX:PD8 / RX:PD9
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#ifndef __USART_H__
#define __USART_H__

/* インクルード	============================================================= */
#include <stm32f4xx.h>

/* 定数定義	============================================================= */
#define BLUETOOTH_RECV_TIMEOUT_MS	200	// S先輩の勘
#define MODULAR_RECV_TIMEOUT_MS	200	// S先輩の勘

#define BT_BAUDRATE	9600

/* 関数プロトタイプ宣言	===================================================== */
/* -------------------------------------------------
 * @関数名			:	Bluetooth_USART_Init, Modular_USART_Init
 * @概要				:	Bluetooth, Modular-JackのUSARTを初期化する
 * @引数-baud		:	ボーレートを設定する
 * @戻り値			:	なし
 * ---------------------------------------------- */
void Bluetooth_USART_Init(int baud);
void Modular_USART_Init(int baud);

/* -------------------------------------------------
 * @関数名	:	Bluetooth_RecvByte, Modular_RecvByte
 * @概要		:	Bluetooth, Modular-Jackから1[Byte]の情報を受け取る
 * @引数		:	なし
 * @戻り値	:	受信したデータ
 * ---------------------------------------------- */
int Bluetooth_RecvByte(void);
int	Modular_RecvByte(void);

/* -------------------------------------------------
 * @関数名	:	Bluetooth_RecvString, Modular_RecvString
 * @概要		:	Bluetooth, Modular-Jackからmax[Byte]受け取り、
 * 				文字列として解釈する
 * @引数-buf	:	受け取った文字列の格納先
 *　          -max	:	文字列の長さ[Byte]
 * @戻り値	:	エラー
 * ---------------------------------------------- */
int	Bluetooth_RecvString(char *buf, int max);
int	Modular_RecvString(char *buf, int max);

/* -------------------------------------------------
 * @関数名		:	Bluetooth_SendByte, Modular_SendByte
 * @概要			:	Bluetooth, Modular-Jackから1[Byte]送信する
 * @引数-byte	:	送信する1[Byte]文字
 * @戻り値		:	なし
 * ---------------------------------------------- */
void Bluetooth_SendByte(u8 byte);
void Modular_SendByte(u8 byte);

/* -------------------------------------------------
 * @関数名	:	Bluetooth_SendString, Modular_SendString
 * @概要		:	Bluetooth, Modular-Jackから文字列を送信する
 * @引数-buf	:	送信する文字列
 * @戻り値	:	なし
 * ---------------------------------------------- */
void Bluetooth_SendString(char *str);
void Modular_SendString(char *str);

#endif /* __USART_H__ */
