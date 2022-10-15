/**
	******************************************************************************
	* @file       version.c/h
	* @brief      USART3与K210通信，控制舵机转动
	* @note 			1.直角三角形计算角度，直接转换对应的PWM
								2.根据坐标差确定转动方向，逐步靠近目标
								坐标差 目标-准星
	* @history
	*  Version    Date            Author          Modification
	*  V1.0.0     2022-7-24     	钟泽鹏          1. 采用第二种方法，未实验
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

		target_x = (target>>2);//8位 x,y 左移两位取x
		target_y = (target&0x0011);//高位置0
	
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

