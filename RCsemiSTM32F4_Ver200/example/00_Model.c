/***************************************************************************
 *	@�t�@�C����		:	00_Model.c
 *	@�T�v		:	�{�T���v���͂��ׂẴv���O�����̂ЂȌ`�ƂȂ�܂��D
 *					���̃\�[�X�����{�Ƃ��āC�v���O���������Ƃ����ł��傤�D
 *
 *					�K�v�ȏ����̓R�����g�̐擪��**�����Ă��܂��̂ŁC
 *					�K���L������悤�ɂ��Ă��������D
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#include "example.h"

#ifdef __00_MODEL__

/******************************/
/* �����@�ȉ����T���v���@���� */
/******************************/
#include <stm32f4xx.h>	// **�ŏ��ɃC���N���[�h����

int main(void)
{
	/* -----------------	������	----------------- */
	SystemCoreClockUpdate();	// **�ŏ��ɌĂяo��

	/*
		�l�X�ȏ������������L�q����
	*/
	/* ---------------------------------------------- */

	/* -------------	���C�����[�v	------------- */
	while(1)
	{
		/*
			�l�X�ȃ��C���������L�q����
		*/
	}
	/* ---------------------------------------------- */

	return 0;
}
/******************************/
/* �����@�ȏオ�T���v���@���� */
/******************************/

#endif /* __00_MODEL__ */