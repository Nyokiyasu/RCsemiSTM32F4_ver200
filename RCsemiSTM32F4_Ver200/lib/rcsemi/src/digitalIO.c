/***************************************************************************
 *	@ファイル名		:	digitalIO.c
 *	@概要		:	DIGITAL-IOxポートを用いて，デジタル的な入出力を行います．
 *					以下にマザーボード上に設けられているDIGITAL-IOxのピン配置を示しておきます．
 *
 *					[DIO0]	PB7 , PB8 , PB11, PB12, PB13, PB14, PB15, PC6
 *					[DIO1]	PC8 , PC9 , PC11, PD0 , PD1 , PD2 , PD3 , PD7
 *					[DIO2]	PD10, PD11, PD14, PD15, PE2 , PE4 , PE7 , PE8
 *
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "stm32f4xx_gpio.h"
#include "digitalIO.h"

/* TODO: 2次元配列へのアクセスが遅いという意見もあります */
/* bit banding */
/* bit_word_addr = bit_band_base + (byte_offset * 32) + (bit_number * 4) */
// GPIOB : 0x40020400 GPIOC : 0x40020800 GPIOD : 0x40020C00 GPIOE : 0x40021000
// GPIOx_ODR : 0x14
const u32 DIO_ODR_ADDR_BB[3][8] =
{
		{	0x4240829C, 0x424082A0, 0x424082AC, 0x424082B0, 0x424082B4, 0x424082B8, 0x424082BC, 0x42410298	},
		{	0x424102A0, 0x424102A4, 0x424102AC, 0x42418280, 0x42418284, 0x42418288, 0x4241828C, 0x4241829C	},
		{	0x424182A8, 0x424182AC, 0x424182B8, 0x424182BC, 0x42420288, 0x42420290, 0x4242029C, 0x424202A0	}
};
// GPIOx_IDR : 0x10
const u32 DIO_IDR_ADDR_BB[3][8] =
{
		{	0x4240821C, 0x42408220, 0x4240822C, 0x42408230, 0x42408234, 0x42408238, 0x4240823C, 0x42410218	},
		{	0x42410220, 0x42410224, 0x4241022C, 0x42418200, 0x42418204, 0x42418208, 0x4241820C, 0x4241821C	},
		{	0x42418228, 0x4241822C, 0x42418238, 0x4241823C, 0x42420208, 0x42420210, 0x4242021C, 0x42420220	}
};

/* ------------------------------------------------------------
 * @関数名		:	DIO0_Init
 * @概要			:	Digital-IO0の初期化をします．
 * @引数-pin	:	設定するピンを8bit(1:対象/0:対象外)で表す．
 * 			-mode	:	DIO_MODE_INを設定すると入力として初期化
 * 	   					DIO_MODE_OUTを設定すると出力として初期化
 * @使用例		: 上位4bitを入力，下位4bitを出力で初期化するとき．
 *							DIO0_Init(0xF0, DIO_MODE_IN);
 *							DIO0_Init(0x0F, DIO_MODE_OUT);
   --------------------------------------------------------- */
void DIO0_Init(u8 pin, GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = mode;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/* PORTB */
	if(pin & 0x7F)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x01)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_7;	// PB7
		if(pin & 0x02)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_8;	// PB8
		if(pin & 0x04)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_11;	// PB11
		if(pin & 0x08)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_12;	// PB12
		if(pin & 0x10)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_13;	// PB13
		if(pin & 0x20)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_14;	// PB14
		if(pin & 0x40)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_15;	// PB15
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	/* PORTC */
	if(pin & 0x80)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	// PC6
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	}
}

/* ------------------------------------------------------------
 * @関数名		:	DIO1_Init
 * @概要			:	Digital-IO1の初期化をします．
 * @引数-pin	:	設定するピンを8bit(1:対象/0:対象外)で表す．
 * 			-mode	:	DIO_MODE_INを設定すると入力として初期化
 * 	   					DIO_MODE_OUTを設定すると出力として初期化
 * @使用例		: 上位4bitを入力，下位4bitを出力で初期化するとき．
 *							DIO1_Init(0xF0, DIO_MODE_IN);
 *							DIO1_Init(0x0F, DIO_MODE_OUT);
   --------------------------------------------------------- */
void DIO1_Init(u8 pin, GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = mode;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/* PORTC */
	if(pin & 0x07)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x01)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_8;	// PC8
		if(pin & 0x02)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_9;	// PC9
		if(pin & 0x04)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_11;	// PC11
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	}
	/* PORTD */
	if(pin & 0xF8)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		if(pin & 0x08)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_0;	// PD0
		if(pin & 0x10)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_1;	// PD1
		if(pin & 0x20)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_2;	// PD2
		if(pin & 0x40)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_3;	// PD3
		if(pin & 0x80)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_7;	// PD7
		GPIO_Init(GPIOD, &GPIO_InitStructure);
	}
}

/* ------------------------------------------------------------
 * @関数名		:	DIO2_Init
 * @概要			:	Digital-IO2の初期化をします．
 * @引数-pin	:	設定するピンを8bit(1:対象/0:対象外)で表す．
 * 			-mode	:	DIO_MODE_INを設定すると入力として初期化
 * 	   					DIO_MODE_OUTを設定すると出力として初期化
 * @使用例		: 上位4bitを入力，下位4bitを出力で初期化するとき．
 *							DIO2_Init(0xF0, DIO_MODE_IN);
 *							DIO2_Init(0x0F, DIO_MODE_OUT);
   --------------------------------------------------------- */
void DIO2_Init(u8 pin, GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = mode;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/* PORTD */
	if(pin & 0x1F)
	{
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
		if(pin & 0x01)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_10;	// PD10
		if(pin & 0x02)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_11;	// PD11
		if(pin & 0x04)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_14;	// PD14
		if(pin & 0x08)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_15;	// PD15
		GPIO_Init(GPIOD, &GPIO_InitStructure);
	}
	/* PORTE */
	if(pin & 0xE0)
	{
		GPIO_InitStructure.GPIO_Pin = 0x0000;
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
		if(pin & 0x10)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_2;	// PE2
		if(pin & 0x20)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_4;	// PE4
		if(pin & 0x40)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_7;	// PE7
		if(pin & 0x80)	GPIO_InitStructure.GPIO_Pin |= GPIO_Pin_8;	// PE8
		GPIO_Init(GPIOE, &GPIO_InitStructure);
	}
}
