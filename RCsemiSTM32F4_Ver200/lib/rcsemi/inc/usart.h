/***************************************************************************
 *	@�t�@�C����		:	usart.h
 *	@�T�v		:	USART2, USART3�������⑗��M��񋟂���D
 *					USART2(Bluetooth)	TX:PD5 / RX:PD6
 *					USART3(�d�b��)		TX:PD8 / RX:PD9
 *	@�o�[�W����		:	2.0.0
 *	@�J����		:	�L�l�N�g
 *	@�g�p��		:	STM32F4DISCOVERY, MB_Ver3, Coocox CoIDE
 **************************************************************************/

#ifndef __USART_H__
#define __USART_H__

/* �C���N���[�h	============================================================= */
#include <stm32f4xx.h>

/* �萔��`	============================================================= */
#define BLUETOOTH_RECV_TIMEOUT_MS	200	// S��y�̊�
#define MODULAR_RECV_TIMEOUT_MS	200	// S��y�̊�

#define BT_BAUDRATE	9600

/* �֐��v���g�^�C�v�錾	===================================================== */
/* -------------------------------------------------
 * @�֐���			:	Bluetooth_USART_Init, Modular_USART_Init
 * @�T�v				:	Bluetooth, Modular-Jack��USART������������
 * @����-baud		:	�{�[���[�g��ݒ肷��
 * @�߂�l			:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_USART_Init(int baud);
void Modular_USART_Init(int baud);

/* -------------------------------------------------
 * @�֐���	:	Bluetooth_RecvByte, Modular_RecvByte
 * @�T�v		:	Bluetooth, Modular-Jack����1[Byte]�̏����󂯎��
 * @����		:	�Ȃ�
 * @�߂�l	:	��M�����f�[�^
 * ---------------------------------------------- */
int Bluetooth_RecvByte(void);
int	Modular_RecvByte(void);

/* -------------------------------------------------
 * @�֐���	:	Bluetooth_RecvString, Modular_RecvString
 * @�T�v		:	Bluetooth, Modular-Jack����max[Byte]�󂯎��A
 * 				������Ƃ��ĉ��߂���
 * @����-buf	:	�󂯎����������̊i�[��
 *�@          -max	:	������̒���[Byte]
 * @�߂�l	:	�G���[
 * ---------------------------------------------- */
int	Bluetooth_RecvString(char *buf, int max);
int	Modular_RecvString(char *buf, int max);

/* -------------------------------------------------
 * @�֐���		:	Bluetooth_SendByte, Modular_SendByte
 * @�T�v			:	Bluetooth, Modular-Jack����1[Byte]���M����
 * @����-byte	:	���M����1[Byte]����
 * @�߂�l		:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_SendByte(u8 byte);
void Modular_SendByte(u8 byte);

/* -------------------------------------------------
 * @�֐���	:	Bluetooth_SendString, Modular_SendString
 * @�T�v		:	Bluetooth, Modular-Jack���當����𑗐M����
 * @����-buf	:	���M���镶����
 * @�߂�l	:	�Ȃ�
 * ---------------------------------------------- */
void Bluetooth_SendString(char *str);
void Modular_SendString(char *str);

#endif /* __USART_H__ */
