#ifndef __MOTOR_H
#define __MOTOR_H

//#include "gpio.h"

#define hw1 HAL_GPIO_ReadPin(GPIOC,HW1_Pin)
#define hw2 HAL_GPIO_ReadPin(GPIOC,HW2_Pin)
#define hw3 HAL_GPIO_ReadPin(GPIOC,HW3_Pin)
#define hw4 HAL_GPIO_ReadPin(GPIOC,HW4_Pin)

void motor_init(void);
void forward(void);//ǰ��
void recede(void);//����
void CW(void);//˳ʱ�� ��
void CCW(void);//��ʱ�� ��
void left(void);//����
void right(void);//����
void stop(void);

void motor(void);

#endif



