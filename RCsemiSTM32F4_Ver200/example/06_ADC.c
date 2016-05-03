/***************************************************************************
 *	@ファイル名		:	06_ADC.c
 *	@概要		:	AnalogINに入力された電圧をADCを用いて観測する．
 *					出力はsemihostingを用いる
 *
 *					必要な処理はコメントの先頭に**がついていますので，
 *					必ず記入するようにしてください．
 *	@バージョン		:	2.0.0
 *	@開発者		:	キネクト
 *	@使用環境		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __06_ADC__

/******************************/
/* ↓↓　以下がサンプル　↓↓ */
/******************************/
#include <stm32f4xx.h>	// **最初にインクルードする
#include "adc.h"	// **インクルードする

#include <stdio.h>

int main(void)
{
	/* -------------	変数宣言	----------------- */

	/* ---------------------------------------------- */

	/* -----------------	初期化	----------------- */
	SystemCoreClockUpdate();	// **最初に呼び出す
	ADC_Single_Init();

	/* ---------------------------------------------- */

	/* -------------	メインループ	------------- */
	while(1)
	{
		printf("%3d %3d %3d %3d %3d %3d %3d %3d\n",
				ADC_Single_Read(0),
				ADC_Single_Read(1),
				ADC_Single_Read(2),
				ADC_Single_Read(3),
				ADC_Single_Read(4),
				ADC_Single_Read(5),
				ADC_Single_Read(6),
				ADC_Single_Read(7));
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* ↑↑　以上がサンプル　↑↑ */
/******************************/

#endif /* __06_ADC__ */
