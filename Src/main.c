
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "../externallibs/ECUAL/LM35/LM35.h"
#include "../externallibs/ECUAL/SEVEN_SEGMENTS/SEVEN_SEGMENTS.h"
#include "stm32f1xx_hal.h"
#include "../externallibs/ECUAL/JOYSTICK/JOYSTICK.h"

#define JoyStick1    0



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
uint8_t SysTicks = 0;

void SysTick_CallBack(void);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE END Includes */



/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);


/* USER CODE BEGIN PFP */
uint8_t Counter = 0;
TIM_HandleTypeDef htim2;
   HAL_Init();
   SystemClock_Config();
   MX_GPIO_Init();
   SEVEN_SEG_Init(0);
   SEVEN_SEG_Enable(0);
   SEVEN_SEG_Write(0, 0);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint32_t VR[3];
/* USER CODE END 0 */


int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();



  /* Configure the system clock */
  SystemClock_Config();



  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_TIM16_Init();
  /* USER CODE BEGIN 2 */
  HAL_ADC_Start_DMA(&hadc1,VR,3); //START ADC IN DMA MODE FOR MULTICHANNEL
  /* USER CODE END 2 */
  // Start timer
   HAL_TIM_Base_Start(&htim16);
  /* Infinite loop */																		//TASK TO CHECK JOYSTICK

	   uint16_t JoyStick1_XY[2] = {0};

		    HAL_Init();
		    SystemClock_Config();
		    MX_GPIO_Init();
		    MX_TIM2_Init();
		    JoyStick_Init(JoyStick1);
		    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

  /* USER CODE BEGIN WHILE */						//TASK TO DISPLAY TO THE RGB LED graph
   void disgraph(){
	   //writing to the ports. The statement 6 PCA9532 LEDS
	  	  			GPIOA->ODR = 0x0001;
	  	  					HAL_Delay(250);     //Quater second delay
	  	  					GPIOA->ODR = 0x0003;
	  	  					HAL_Delay(250);     //Quater second delay
	  	  					GPIOA->ODR = 0x0007;
	  	  					HAL_Delay(250);     //Quater second delay
	  	  					GPIOA->ODR = 0x000F;
	  	  					HAL_Delay(250);     //Quater second delay
	  	  					GPIOA->ODR = 0x001F;
	  	  					HAL_Delay(250);     //Quater second delay
	  	  					GPIOA->ODR = 0x003F;



	  	  					HAL_Delay(1000);     //1 second delay
	  	  					GPIOA->ODR = 0x0000; //Reset all Leds
	  	  					//One second delay after each successive loop execution of led array is to give controller some rest.

   }
   void checkjoystick(){

	   //TASK TO CHECK JOYSTICK
	        JoyStick_Read(JoyStick1, JoyStick1_XY);
	        TIM2->CCR1 = JoyStick1_XY[0];
	        HAL_Delay(10);
   }

   // Each 100mSec/0.1sec
   				        // & Write It To The 7-Segments Display					//TASK TO DISPLAY ON THE SEVEN SEGMENT DISPLAY
   void channel1(){
	   SEVEN_SEG_Write(1);
	   HAL_Delay(100);
   }
   void channel2(){
 	   SEVEN_SEG_Write(2);
 	   HAL_Delay(100);
    }
   void channel3(){
 	   SEVEN_SEG_Write(3);
 	   HAL_Delay(100);
    }

void xpindisplaytorgb(){													//A task to display on the RGB LED.
	 // Get current time (microseconds)
			 	    timer_val = __HAL_TIM_GET_COUNTER(&htim16);

    // Wait for 100 ms/0.1s then read the input from pin
	 	   HAL_GPIO_WritePin(xmin_GPIO_Port, xmin_Pin, GPIO_PIN_RESET);//TURN OFF XMIN LED
	 	   	HAL_GPIO_WritePin(xplus_GPIO_Port, xplus_Pin, GPIO_PIN_RESET);//TURN OFF XPLUS LED
}

  while (1)
  {


  checkjoystick();
	  //data acquisation and control
    /* USER CODE END WHILE */
	  if((VR[0] >= 1000) && (VR[0] <= 3000)){ //if the value is between 2000 and 3000 light green


		 	   xpindisplaytorgb();


	  }

	  if(VR[0] > 3000){//if above 3000  towards xplus configured in stmcube									A task to display on the RGB LED.
		  xpindisplaytorgb();
	  			channel1();
	  			disgraph();
	  			   }
	  if(VR[0] < 1000){//if below 1000  towards xmin configured in stmcube									A task to display on the RGB LED.
		  xpindisplaytorgb();

				  channel1();
				  disgraph();
			  }

	  if(VR[1] > 3000){//if above 3000  towards yplus configured in stmcube									A task to display on the RGB LED.
		  xpindisplaytorgb();
		  			channel2();
		  			disgraph();
		  		  }
		  if(VR[1] < 1000){//if below 1000  towards ymin configured in stmcube								A task to display on the RGB LED.
			  xpindisplaytorgb();
					  channel2();
					  disgraph();
				  }
		  if(VR[2] > 3000){//if above 3000  towards zplus configured in stmcube									A task to display on the RGB LED.
			  xpindisplaytorgb();
				  			channel3();
				  			disgraph();
				  		  }
				  if(VR[2] < 1000){//if below 1000  towards zmin configured in stmcube								A task to display on the RGB LED.
					  xpindisplaytorgb();
							  channel3();
							  disgraph();
				  }
    /* USER CODE BEGIN 3 */






  }
  /* USER CODE END 3 */

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}


static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};


  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 3;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }


}

/**
  * Enable DMA controller clock
  */
void SysTick_CallBack(void)
{
    SysTicks++;
    if(SysTicks == 5) // Each 5msec
    {
    SEVEN_SEG_Main();
    SysTicks = 0;
    }
}
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}


static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */


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

void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif /* USE_FULL_ASSERT */

