/***************************************************************************
 *	@ファイル名		:	motherboard.c
 *	@概要		:	MB上のLED，プッシュスイッチ，ロータリースイッチの機能を提供します．
 *					以下に，各要素のピン配置を示します．
 *					LED			0:PA8, 1:PA15
 *					PushSW		0:PE5, 1:PE6
 *					RotarySW	0:PE12, 1:PE13, 2:PE14, 3:PE15
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "motherboard.h"

/* -------------------------------------------------
 * @関数名	:	MB_LED_Init
 * @概要		:	MB上LEDに接続されているGPIO(PA8, PA15)を
 * 				初期化します．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_Init(void)
{
	/* クロック供給 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	/* GPIO設定 */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @関数名	:	MB_LED_TurnOff
 * @概要		:	指定のLEDを消灯します．
 * @引数-num	:	LEDの番号、0, 1
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_TurnOff(int num)
{
	if     (num == 0) GPIOA->BSRRH = GPIO_Pin_8;
	else if(num == 1) GPIOA->BSRRH = GPIO_Pin_15;
}

/* -------------------------------------------------
 * @関数名	:	MB_LED_TurnOn
 * @概要		:	指定のLEDを点灯します．
 * @引数-num	:	LEDの番号、0, 1
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_TurnOn(int num)
{
	if     (num == 0) GPIOA->BSRRL = GPIO_Pin_8;
	else if(num == 1) GPIOA->BSRRL = GPIO_Pin_15;
}

/* -------------------------------------------------
 * @関数名	:	MB_LED_Toggle
 * @概要		:	指定のLEDを前回と違う状態にします．
 * @引数-num	:	LEDの番号、0, 1
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_LED_Toggle(int num)
{
	if     (num == 0) GPIOA->ODR ^= GPIO_Pin_8;
	else if(num == 1) GPIOA->ODR ^= GPIO_Pin_15;
}

/* -------------------------------------------------
 * @関数名	:	MB_PushSW_Init
 * @概要		:	プッシュスイッチに接続されているGPIO(PE5, PE6)の
 * 				初期化をします．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_PushSW_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @関数名	:	MB_PushSW_IsPushed
 * @概要		:	プッシュスイッチが押されたかどうか判定します．
 * @引数		:	プッシュスイッチの番号
 * @戻り値	:	押されたら1, そうでなければ0
 * ---------------------------------------------- */
int MB_PushSW_IsPushed(int num)
{
	if     (num == 0)	return !(GPIOE->IDR & GPIO_Pin_5);
	else if(num == 1)	return !(GPIOE->IDR & GPIO_Pin_6);
	return -1;
}

/* -------------------------------------------------
 * @関数名	:	MB_RotarySW_Init
 * @概要		:	ロータリースイッチに接続されている
 * 				GPIO(PE12, PE13, PE14, PE15)の初期化をします．
 * @引数		:	なし
 * @戻り値	:	なし
 * ---------------------------------------------- */
void MB_RotarySW_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/* -------------------------------------------------
 * @関数名	:	MB_RotarySW_Check
 * @概要		:	ロータリースイッチが示す値(0-15)を判別します．
 * @引数		:	なし
 * @戻り値	:	ロータリースイッチの値(0-15)
 * ---------------------------------------------- */
u8 MB_RotarySW_Check(void)
{
	return (!(GPIOE->IDR & GPIO_Pin_12)     ) | (!(GPIOE->IDR & GPIO_Pin_13) << 1) |
		   (!(GPIOE->IDR & GPIO_Pin_14) << 2) | (!(GPIOE->IDR & GPIO_Pin_15) << 3);

}
