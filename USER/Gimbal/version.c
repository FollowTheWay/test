/**
	******************************************************************************
	* @file       version.c/h
	* @brief      USART3��K210ͨ�ţ����ƶ��ת��
	* @note 			1.ֱ�������μ���Ƕȣ�ֱ��ת����Ӧ��PWM
								2.���������ȷ��ת�������𲽿���Ŀ��
								����� Ŀ��-׼��
	* @history
	*  Version    Date            Author          Modification
	*  V1.0.0     2022-7-24     	������          1. ���õڶ��ַ�����δʵ��
	*
	******************************************************************************
	*/
	
#include "version.h"
#include "tim.h"
#include "usart.h"

#define Collimation_x 950
#define Collimation_y 450

uint8_t target;
uint8_t target_x;
uint8_t target_y;
uint8_t coordinate_x;
uint8_t coordinate_y;
void gimbal_motor()
{
	HAL_UART_Receive(&huart3,&target,8,HAL_MAX_DELAY);

		target_x = (target>>2);//8λ x,y ������λȡx
		target_y = (target&0x0011);//��λ��0
	
		coordinate_x = Collimation_x - target_x;
	  coordinate_y = Collimation_y - target_y;
		if(coordinate_x>0)
		{
			//
		}
		else if(coordinate_x<0)
		{
			
		}
		
		if(coordinate_y>0)
		{
			//
		}
		else if(coordinate_y<0)
		{
			
		}

}

