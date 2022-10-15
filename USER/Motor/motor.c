/**
	******************************************************************************
	* @file       motor.c/h
	* @brief      a4950���� 
	* @note 			��·pwm�źţ��ɵ�ѹ������ٶȺͷ���
								����� ---->  OUT1
								����� ---->  out2
								
								IN1   ---->   CH1/CH3
								IN2   ---->   CH2/CH4
	* @history
	*  Version    Date            Author          Modification
	*  V1.0.0     2022-7-15     	������          1. done
	*
	******************************************************************************
	*/

#include "motor.h"
#include "tim.h"
#include "bluetooth.h"
#include "usart.h"
#include "User_Debug.h"
#include "gpio.h"


void motor_init()
{
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
	
	HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_2);
	
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,50);//
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,50);//
	
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,50);//
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,50);//
	
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,50);//
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,50);//
	
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,50);//
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,50);//
}

void forward()//ǰ�� 1  0011
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,20);//��һ
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,80);//
	
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,20);//��һ
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,80);//
//	
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,80);//���
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,20);//
	
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,80);//�Ҷ�
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,20);//
	
	usart_printf("ǰ��\r\n");
	HAL_UART_Transmit(&huart2,"forward\r\n",9,HAL_MAX_DELAY);
}

void recede()//���� 2   1100
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,80);//��һ
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,20);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,80);//��һ
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,20);// 
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,20);//���
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,80);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,20);//�Ҷ�
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,80);//
	usart_printf("����\r\n");
	HAL_UART_Transmit(&huart2,"recede\r\n",8,HAL_MAX_DELAY);
}

void CW()//˳ʱ�� �� 4   0110
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,20);//��һ
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,80);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,80);//��һ
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,20);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,80);//���
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,20);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,20);//�Ҷ�
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,80);//
	usart_printf("��ƫ\r\n");
	HAL_UART_Transmit(&huart2,"CW\r\n",4,HAL_MAX_DELAY);
}

void CCW()//��ʱ�� �� 3    1001
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,80);//��һ
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,20);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,20);//��һ
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,80);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,20);//���
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,80);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,80);//�Ҷ�
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,20);//
	usart_printf("��ƫ\r\n");
	HAL_UART_Transmit(&huart2,"CCW\r\n",5,HAL_MAX_DELAY);
}

void left()//����  0011  1010
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,80);//��һ
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,20);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,20);//��һ
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,80);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,80);//���
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,20);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,20);//�Ҷ�
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,80);//
}

void right()//���� 0101
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,20);//��һ
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,80);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,80);//��һ
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,20);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,20);//���
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,80);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,80);//�Ҷ�
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,20);//
}

uint8_t motor_flag = 0;
void stop()// 0
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,50);//��һ
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,50);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,50);//��һ
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,50);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,50);//���
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,50);//
	                                                 
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,50);//�Ҷ�
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,50);//
	
}

void Tracing()
{
	if(hw1 == 0 && hw2 == 0 && hw3 == 0 && hw4 == 0)//ֱ��        0000
	{
//		forward();
		HAL_UART_Transmit(&huart2,"XUNJI\r\n",7,HAL_MAX_DELAY);
	}
	else if(hw1 == 0 && hw2 == 1 && hw3 == 0 && hw4 == 0)//С��   0100
	{
//		CCW();
		HAL_UART_Transmit(&huart2,"CCW1\r\n",6,HAL_MAX_DELAY);
	}
	else if(hw1 == 0 && hw2 == 0 && hw3 == 1 && hw4 == 0)//       0010
	{
//		CW();
		HAL_UART_Transmit(&huart2,"CW1\r\n",5,HAL_MAX_DELAY);
	}
	else if(hw1 == 1 && hw2 == 0 && hw3 == 0 && hw4 == 0)//����   1000
	{
//		CCW();
		HAL_UART_Transmit(&huart2,"CCW2\r\n",6,HAL_MAX_DELAY);
	}
	else if(hw1 == 0 && hw2 == 0 && hw3 == 0 && hw4 == 1)//       0001
	{
//		CW();
		HAL_UART_Transmit(&huart2,"CW2\r\n",5,HAL_MAX_DELAY);
	}
}
void motor_delay()//�� �ߵ�ƽ
{
	if(motor_flag == 0)
	{
	forward();
	HAL_Delay(500);
	CCW();
	HAL_Delay(500);
		stop();
		motor_flag = 1;
	}
}

void motor()
{
	uint8_t MO = 0;
		MO = huart2.Instance->DR;
		switch(MO){
			case '0': stop();motor_flag = 0;break;
			case '1': forward();break;
			case '2': recede();break;
			case '3': CCW();break;
			case '4': CW();break;
			case '5': left();break;
			case '6': right();break;
			case '9': Tracing();break;
			default:stop();break;
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12) == 0)
	{
		usart_printf("xunji\r\n");
//		HAL_UART_Transmit(&huart2,"ok\r\n",4,HAL_MAX_DELAY);
//		stop();
	}
}

//git test1
