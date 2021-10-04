/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "rtc.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../WS_2812B_TIMER/ws2812b_tim.h"
#include "../MENU/menu.h"
#include "../BITMAPS/bitmaps.h"
#include "keyb.h"
#include "../EE_lib/ee.h"


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

/* USER CODE BEGIN PV */
RTC_TimeTypeDef RtcTime;
RTC_DateTypeDef RtcDate;
uint8_t KEY_STATE;
uint32_t test_val;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void HAL_SYSTICK_Callback(void)
{
	//HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	//WS2812BFX_SysTickCallback();	// FX effects software timers
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	//wywo³ywanie funkcji sprawdzaj¹cej klawisze co 10ms
	if (htim->Instance == TIM3) KeybProc();
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//				43210
// KEY_STATE=xxxODRUL

	if (HAL_GPIO_ReadPin(KEY_LEFT_GPIO_Port, GPIO_Pin) == GPIO_PIN_RESET) {
		switch (GPIO_Pin) {

		case KEY_LEFT_Pin:
			KEY_STATE |= KEY_LEFT;
			//WS2812BFX_PrevMode(0);
			break;
		case KEY_UP_Pin:
			KEY_STATE |= KEY_UP;
			break;
		case KEY_RIGHT_Pin:
			KEY_STATE |= KEY_RIGHT;
			//WS2812BFX_NextMode(0);
			break;
		case KEY_DOWN_Pin:
			KEY_STATE |= KEY_DOWN;
			break;
		case KEY_OK_Pin:
			KEY_STATE |= KEY_OK;
			//HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
			break;
		}
	} else {
		switch (GPIO_Pin) {

		case KEY_LEFT_Pin:
			KEY_STATE &= ~KEY_LEFT;
			break;
		case KEY_UP_Pin:
			KEY_STATE &= ~KEY_UP;
			break;
		case KEY_RIGHT_Pin:
			KEY_STATE &= ~KEY_RIGHT;
			break;
		case KEY_DOWN_Pin:
			KEY_STATE &= ~KEY_DOWN;
			break;
		case KEY_OK_Pin:
			KEY_STATE &= ~KEY_OK;
			//HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
			break;
		}
	}

}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_RTC_Init();
  MX_TIM2_Init();
  MX_SPI1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
//  ee_init();
//  //menu_variables_save_eeprom();
//
//  uint8_t data[32];
//  //ee_read(4, 32, data);
//	for(int i=0;i<8;i++){
//		ee_read(i*4, 4, &data[i*4]);
//	}



  menu_init(&hi2c1);

  ws2812b_init(&htim2, TIM_CHANNEL_1);

  HAL_TIM_Base_Start_IT(&htim3);

  HAL_RTC_GetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN);

  menu_refresh();

  test_val=sizeof(float);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  allColor_t *temp_color=kolorDzien_var.color;
	switch(temp_color->type){
	case _ColorRGB:
		for(uint8_t i=0;i<NUMBER_OF_LEDS;i++)
		ws2812b_setRgb(i, temp_color->rgb.r, temp_color->rgb.g, temp_color->rgb.b, GammaCorrectionRGB_var.byte);
		break;
	case _ColorHSV:
		for(uint8_t i=0;i<NUMBER_OF_LEDS;i++)
		ws2812b_setHSV(i, temp_color->hsv.h, temp_color->hsv.s, temp_color->hsv.v, GammaCorrectionHSV_var.byte);
		break;
	case _ColorTemp:
		for(uint8_t i=0;i<NUMBER_OF_LEDS;i++)
		ws2812b_setKelvin(i, temp_color->temp, GammaCorrectionTEMPERATURE_var.byte);
		break;
	}

	ws2812b_refresh();


	if(IsKey(ANYKEY)&&buzzer_state.byte){
	  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
	  HAL_Delay(1);
	  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
	}
	uint8_t key=GetKeys();
	key_press(key);


	HAL_RTC_GetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN);

	refresh_func();
	if (hi2c1.hdmatx->State == HAL_DMA_STATE_READY) SSD1306_Display(); //odświerzenie DMA(tym samym wyświetlacza)

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 12;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
