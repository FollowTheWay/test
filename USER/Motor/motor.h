#ifndef __MOTOR_H
#define __MOTOR_H

//#include "gpio.h"

#define hw1 HAL_GPIO_ReadPin(GPIOC,HW1_Pin)
#define hw2 HAL_GPIO_ReadPin(GPIOC,HW2_Pin)
#define hw3 HAL_GPIO_ReadPin(GPIOC,HW3_Pin)
#define hw4 HAL_GPIO_ReadPin(GPIOC,HW4_Pin)

void motor_init(void);
void forward(void);//前进
void recede(void);//后退
void CW(void);//顺时针 右
void CCW(void);//逆时针 左
void left(void);//左移
void right(void);//右移
void stop(void);

void motor(void);

#endif



