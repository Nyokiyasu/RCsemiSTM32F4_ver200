/***************************************************************************
 *	@�t�@�C����		:	rotary_encoder.c
 *	@�T�v		:	���[�^���[�G���R�[�_�|�[�g�̏������ƁC�ǂݎ���񋟂���D
 *					�|�[�g��ENC0-2������C�g�p����^�C�}�CGPIO�͈ȉ��̂Ƃ���C
 *					ENC0	:TIM3	A:PB4  / B:PB5
 *					ENC1	:TIM4	A:PD12 / B:PD13
 *					ENC2	:TIM1	A:PE9  / B:PE11
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#include <stm32f4xx.h>
#include "rotary_encoder.h"

/* -------------------------------------------------
 * @�֐���	:	ENCn_Init
 * @�T�v		:	���[�^���[�G���R�[�_�̏�����������
 * @����		:	�Ȃ�
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void ENC0_Init(void)
{
	/* �N���b�N������ */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	/* GPIO�̏����� */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;	// �v���A�b�v��R�͊O���Őڑ��ς�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* GPIO�s�����^�C�}�Ƃ��ė��p����ݒ� */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_TIM3);

	/* �^�C�}�̐ݒ� */
	TIM_DeInit(TIM3);	// �K�v�Ȃ���������Ȃ�
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period 		= 0xffff;	// �ő�l
	TIM_TimeBaseStructure.TIM_Prescaler 	= 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode 	= TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* ���[�^���[�G���R�[�_�ݒ� */
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12,
							   TIM_ICPolarity_Rising,
							   TIM_ICPolarity_Rising);
	// �^�C�}��L����
	TIM_Cmd(TIM3, ENABLE);
}

void ENC1_Init(void)
{
	/* �N���b�N������ */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	/* GPIO�̏����� */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;	// �v���A�b�v��R�͊O���Őڑ��ς�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* GPIO�s�����^�C�}�Ƃ��ė��p����ݒ� */
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);

	/* �^�C�}�̐ݒ� */
	TIM_DeInit(TIM4);	// �K�v�Ȃ���������Ȃ�
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period 		= 0xffff;	// �ő�l
	TIM_TimeBaseStructure.TIM_Prescaler 	= 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode 	= TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	/* ���[�^���[�G���R�[�_�ݒ� */
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12,
							   TIM_ICPolarity_Rising,
							   TIM_ICPolarity_Rising);
	// �^�C�}��L����
	TIM_Cmd(TIM4, ENABLE);
}

void ENC2_Init(void)
{
	/* �N���b�N������ */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	/* GPIO�̏����� */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;	// �v���A�b�v��R�͊O���Őڑ��ς�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* GPIO�s�����^�C�}�Ƃ��ė��p����ݒ� */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_TIM1);

	/* �^�C�}�̐ݒ� */
	TIM_DeInit(TIM1);	// �K�v�Ȃ���������Ȃ�
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period 		= 0xffff;	// �ő�l
	TIM_TimeBaseStructure.TIM_Prescaler 	= 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode 	= TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	/* ���[�^���[�G���R�[�_�ݒ� */
	TIM_EncoderInterfaceConfig(TIM1, TIM_EncoderMode_TI12,
							   TIM_ICPolarity_Rising,
							   TIM_ICPolarity_Rising);
	// �^�C�}��L����
	TIM_Cmd(TIM1, ENABLE);
}
