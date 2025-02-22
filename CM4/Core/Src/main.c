/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "cmsis_os.h"
#include "crc.h"
#include "dma.h"
#include "dma2d.h"
#include "dsihost.h"
#include "ltdc.h"
#include "quadspi.h"
#include "rng.h"
#include "gpio.h"
#include "fmc.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */
int32_t synth_GetImageData(uint32_t index);
int32_t synth_SetImageData(uint32_t index, int32_t value);
void SystemClock_Config(void);
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

/* USER CODE BEGIN Boot_Mode_Sequence_1 */
	/*HW semaphore Clock enable*/
	__HAL_RCC_HSEM_CLK_ENABLE();
	/* Activate HSEM notification for Cortex-M4*/
	HAL_HSEM_ActivateNotification(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_0));
	/*
  Domain D2 goes to STOP mode (Cortex-M4 in deep-sleep) waiting for Cortex-M7 to
  perform system initialization (system clock config, external memory configuration.. )
	 */
	HAL_PWREx_ClearPendingEvent();
	HAL_PWREx_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFE, PWR_D2_DOMAIN);
	/* Clear HSEM flag */
	__HAL_HSEM_CLEAR_FLAG(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_0));
/* USER CODE END Boot_Mode_Sequence_1 */
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
//	SystemClock_Config();
  /* USER CODE END Init */

  /* USER CODE BEGIN SysInit */

  /* CM4 takes HW sempahore 0 to inform CM7 that he finished his job */
  HAL_HSEM_FastTake(HSEM_ID_0);

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DSIHOST_DSI_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_DMA2D_Init();
  MX_RNG_Init();
  MX_QUADSPI_Init();
  MX_CRC_Init();
  MX_DMA_Init();
  MX_TouchGFX_Init();
  /* Call PreOsInit function */
  MX_TouchGFX_PreOSInit();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	/* Initialize the LCD */
	//	BSP_LCD_Init(0, LCD_ORIENTATION_LANDSCAPE);
	//	UTIL_LCD_SetFuncDriver(&LCD_Driver);
	//	UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
	//	UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
	//	UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLACK);
	//	UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
	//
	//	UTIL_LCD_DrawBitmapBW(sss_Img, (LCD_DEFAULT_WIDTH - 151) / 2, (LCD_DEFAULT_HEIGHT - 64) / 2, 151, 64, UTIL_LCD_COLOR_WHITE);
	//	HAL_Delay(500);
	//
	//	UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

	//		QSPI_Demo();
	//	QSPI_Init();
	//	QSPI_ResetData();

	//	uint8_t FreqStr[256] = {0};
	//	static uint32_t start_tick;
	//	uint32_t latency;
	//	uint32_t i = 0;


	while (1)
	{
		//		start_tick = HAL_GetTick();

		//		while ((params.synth_process_cnt) < (SAMPLING_FREQUENCY / DISPLAY_REFRESH_FPS));

		//		shared_var.synth_process_cnt = 0;
		//		HAL_Delay(1000 / DISPLAY_REFRESH_FPS);

		//		latency = HAL_GetTick() - start_tick;
		//		sprintf((char *)FreqStr, "  %dHz", (int)((shared_var.synth_process_cnt * 1000) / (1000 / DISPLAY_REFRESH_FPS)));

		//		UTIL_LCD_FillRect(0, DISPLAY_AERA1_Y1POS, DISPLAY_MAX_X_LENGTH, DISPLAY_AERAS1_HEIGHT, UTIL_LCD_COLOR_ST_GRAY_DARK);

		//		static uint32_t note = 10;
		//		if (note > NUMBER_OF_NOTES)
		//		{
		//			note = 10;
		//			synth_SetImageData(note - 10, 0);
		//		}
		//
		//		synth_SetImageData(note++, 10500); //for testing
		//		synth_SetImageData(note - 1, 0);
		//
		//		synth_SetImageData(note - 9, 26500); //for testing
		//		synth_SetImageData(note - 10, 0);

		//				for (i = 0; i < ((DISPLAY_MAX_X_LENGTH) - 1); i++)
		//				{
		//					UTIL_LCD_SetPixel(i, DISPLAY_AERA1_Y1POS + (DISPLAY_AERAS1_HEIGHT / 2) - (pcm5102_GetAudioData(i / 4) / 256), UTIL_LCD_COLOR_LIGHTYELLOW);
		//				}

		//		for (i = 0; i < ((DISPLAY_MAX_X_LENGTH) - 1); i++)
		//		{
		//			uint32_t height_bar = (synth_GetImageData(i * NUMBER_OF_NOTES / DISPLAY_MAX_X_LENGTH) * (DISPLAY_AERAS1_HEIGHT - 2) / 32768);
		//			UTIL_LCD_DrawVLine(i, (DISPLAY_AERA1_Y1POS + DISPLAY_AERAS1_HEIGHT - 2) - height_bar, height_bar, UTIL_LCD_COLOR_WHITE);
		//		}
		//
		//		UTIL_LCD_FillRect(0, DISPLAY_AERA2_Y1POS, DISPLAY_MAX_X_LENGTH, DISPLAY_AERAS2_HEIGHT, UTIL_LCD_COLOR_ST_GRAY_DARK);
		//
		//		for (i = 0; i < ((DISPLAY_MAX_X_LENGTH) - 1); i++)
		//		{
		//			UTIL_LCD_SetPixel(i, DISPLAY_AERA2_Y2POS - ((cvData[((NUMBER_OF_NOTES / IMAGE_WEIGHT) * i) / DISPLAY_MAX_X_LENGTH] / 31) - 2), UTIL_LCD_COLOR_YELLOW);
		//		}
		//
		//		UTIL_LCD_DisplayStringAt(0, 1, (uint8_t*)FreqStr, RIGHT_MODE);

		//		HAL_Delay(10);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

/**
 * @brief  Get Image buffer data
 * @param  Index
 * @retval Value
 */
int32_t synth_GetImageData(uint32_t index)
{
	//	if (index >= RFFT_BUFFER_SIZE)
	//		Error_Handler();
	return imageData[index];
}

/**
 * @brief  Set Image buffer data
 * @param  Index
 * @retval Value
 */
int32_t synth_SetImageData(uint32_t index, int32_t value)
{
	//	if (index >= RFFT_BUFFER_SIZE)
	//		Error_Handler();
	imageData[index] = value;
	return 0;
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Supply configuration update enable
	 */
	HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);
	/** Configure the main internal regulator output voltage
	 */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

	while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
	/** Macro to configure the PLL clock source
	 */
	__HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSE);
	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSI
			|RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 5;
	RCC_OscInitStruct.PLL.PLLN = 192;
	RCC_OscInitStruct.PLL.PLLP = 2;
	RCC_OscInitStruct.PLL.PLLQ = 5;
	RCC_OscInitStruct.PLL.PLLR = 2;
	RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
	RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
	RCC_OscInitStruct.PLL.PLLFRACN = 0;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
			|RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
	RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
	{
		Error_Handler();
	}
	HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSI, RCC_MCODIV_1);
	/** Enables the Clock Security System
	 */
	HAL_RCC_EnableCSS();
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM3 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM3) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
