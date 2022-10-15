/**
	******************************************************************************
	* @file       bluetooth.c/h
	* @brief      HC05蓝牙DMA通信
	* @note 			能触发空闲中断，但寄存器读不到值和长度，
								可读取huart2.Instance->DR 获得ASCII码 只读得到第一位
	* @history
	*  Version    Date            Author          Modification
	*  V1.0.0     2022-7-14     	钟泽鹏          1. done
	*
	******************************************************************************
	*/

#include "bluetooth.h"
#include "main.h"
#include "usart.h"
#include "dma.h"
#include "User_Debug.h"


uint8_t RxBuffer;
uint16_t RXBUFFER_LEN;
uint16_t Rx_len;
uint8_t RX_flag;

uint16_t ch[100];
uint8_t buffercnt = 0;
void BT_init()
{
	__HAL_UART_ENABLE_IT(&huart2,UART_IT_IDLE);  
	HAL_UART_Receive_DMA(&huart2,&RxBuffer,RXBUFFER_LEN); 
//	usart_printf("bt init\r\n");
}

/*重写串口接收中断 在stm32f4xx_it.c里屏蔽掉该函数*/
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
	//DMA处理
	uint32_t temp_flag = 0;
	uint32_t temp;
	temp_flag = __HAL_UART_GET_FLAG(&huart2,UART_FLAG_IDLE);
	if((temp_flag!=RESET))
	{
			__HAL_UART_CLEAR_IDLEFLAG(&huart2);
			temp = huart2.Instance->SR;   //通过读取清除标志位
			temp = huart2.Instance->DR;   //读取数据寄存器中的数据
			HAL_UART_DMAStop(&huart2);    //防止中途冲突
			temp = hdma_usart2_rx.Instance->NDTR;  //获取未读取的数据个数
			//F1的板子使用temp = hdma_usart2_rx.Instance->CNDTR;  //获取未读取的数据个数
			Rx_len = RXBUFFER_LEN-temp;  //总共读取了多少个数 需要读的数目-未读的=读取到的数目
			RX_flag = 1;   //完成标志
//		buffercnt++;
//		  usart_printf("temp %d\r\n ",huart2.Instance->DR);
	}
//	ch[buffercnt++] = huart2.Instance->DR;
	HAL_UART_Receive_DMA(&huart2,&RxBuffer,RXBUFFER_LEN);//重新开启DMA接收
  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//  /* Prevent unused argument(s) compilation warning */
//	int i ;
//  UNUSED(huart);
//	for(i=0;i<buffercnt;i++)usart_printf("ch %c",ch[i]);
//	
//	usart_printf("ok\r\n");
//  /* NOTE: This function should not be modified, when the callback is needed,
//           the HAL_UART_RxCpltCallback could be implemented in the user file
//   */
//}

void Check_Rx()
{
//	int i ;
		if(RX_flag == 1)   //如果完全接收了
		{
//			usart_printf("cnt%d\r\n",buffercnt);
//			for(i=1;i<=buffercnt;i++)usart_printf("ch %c i=%d",ch[i],i);
//			usart_printf("\r\n ok\r\n");
//			
//			for(i=1;i<=buffercnt;i++)ch[i]=0;
//			buffercnt = 0;
//				usart_printf("temp %c\r\n ",huart2.Instance->DR
//				usart_printf("I got the message %s\r\n",RxBuffer);//huart2.pRxBuffPtr););
//				usart_printf("Rx_len = %d\r\n",Rx_len);
				
//				for(uint8_t i=0;i<Rx_len;i++)  //清空buffer
//				{
//						RxBuffer[i] = 0;
//				}
				Rx_len=0;
				RX_flag = 0;
		}
//		usart_printf("TT %c\r\n",huart2.Instance->DR);
}


//uint8_t BT_flag=0;//标志位
//void BT_test()
//{
//	 while(BT_flag==0)
//	  {
//	        HAL_UART_Receive(&huart2, (uint8_t*)&BT_flag, sizeof(BT_flag), HAL_MAX_DELAY);
//	  }//让蓝牙模块一直处于接收状态
//}
