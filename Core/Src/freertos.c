/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "User_Debug.h"
#include "bluetooth.h"
#include "usart.h"
#include "motor.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId Debug_TaskHandle;
osThreadId BT_TaskHandle;
osThreadId Motor_TaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void Start_Debug_Task(void const * argument);
void BT_Task_Task(void const * argument);
void Start_Motor_Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of Debug_Task */
  osThreadDef(Debug_Task, Start_Debug_Task, osPriorityIdle, 0, 128);
  Debug_TaskHandle = osThreadCreate(osThread(Debug_Task), NULL);

  /* definition and creation of BT_Task */
  osThreadDef(BT_Task, BT_Task_Task, osPriorityIdle, 0, 128);
  BT_TaskHandle = osThreadCreate(osThread(BT_Task), NULL);

  /* definition and creation of Motor_Task */
  osThreadDef(Motor_Task, Start_Motor_Task, osPriorityIdle, 0, 128);
  Motor_TaskHandle = osThreadCreate(osThread(Motor_Task), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {

		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
//		usart_printf("helloworld\r\n");
    osDelay(500);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Start_Debug_Task */
/**
* @brief Function implementing the Debug_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_Debug_Task */
void Start_Debug_Task(void const * argument)
{
  /* USER CODE BEGIN Start_Debug_Task */
  /* Infinite loop */
  for(;;)
  {
		Debug_Usart();
    osDelay(1);
  }
  /* USER CODE END Start_Debug_Task */
}

/* USER CODE BEGIN Header_BT_Task_Task */
/**
* @brief Function implementing the BT_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BT_Task_Task */
void BT_Task_Task(void const * argument)
{
  /* USER CODE BEGIN BT_Task_Task */
	BT_init();
//		uint8_t rx = 0;
  /* Infinite loop */
  for(;;)
  {
//		HAL_UART_Receive(&huart2,&rx,1,HAL_MAX_DELAY);
//		usart_printf("%c\r\n",rx);
		Check_Rx();
    osDelay(10);
  }
  /* USER CODE END BT_Task_Task */
}

/* USER CODE BEGIN Header_Start_Motor_Task */
/**
* @brief Function implementing the Motor_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_Motor_Task */
void Start_Motor_Task(void const * argument)
{
  /* USER CODE BEGIN Start_Motor_Task */
		motor_init();
  /* Infinite loop */
  for(;;)
  {
		motor();
    osDelay(1);
  }
  /* USER CODE END Start_Motor_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
