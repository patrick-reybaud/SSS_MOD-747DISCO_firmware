/**
 ******************************************************************************
 * @file           : audio.c
 * @brief          : Audio Stereo DAC with 32-bit, 384kHz PCM Interface
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"

#include "main.h"
#include "config.h"
#include "shared.h"

/* Private includes ----------------------------------------------------------*/
#include "audio.h"

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
BSP_AUDIO_Init_t AudioPlayInit;
static BUFFER_AUDIO_StateTypeDef bufferAudioState;

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/;
uint32_t bytesread;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
 * @brief  Initialise audio peripheral
 * @param  void
 * @retval void
 */
void audio_Init(void)
{
//	printf("----------- DAC INIT ----------\n");
//	printf("-------------------------------\n");

	AudioPlayInit.Device = AUDIO_OUT_DEVICE_HEADPHONE;
	AudioPlayInit.ChannelsNbr = 2;
	AudioPlayInit.SampleRate = SAMPLING_FREQUENCY ;
	AudioPlayInit.BitsPerSample = AUDIO_RESOLUTION_32B;
	AudioPlayInit.Volume = VOLUME;
	if(BSP_AUDIO_OUT_Init(0, &AudioPlayInit) != HAL_OK)
	{
		Error_Handler();
	}

	bufferAudioState = AUDIO_BUFFER_OFFSET_NONE;
	HAL_SAI_Transmit_DMA(&haudio_out_sai,(uint8_t *)audioBuff, AUDIO_BUFFER_SIZE * 4);
}

/**
 * @brief  Mute
 * @param  void
 * @retval void
 */
void audio_Mute(void)
{
	BSP_AUDIO_OUT_Mute(0);
}

/**
 * @brief  Unmute
 * @param  void
 * @retval void
 */
void audio_UnMute(void)
{

	BSP_AUDIO_OUT_UnMute(0);
}

/**
 * @brief  Get audio buffer data
 * @param  Index
 * @retval Value
 */
int32_t audio_GetAudioData(uint32_t index)
{
	//	if (index >= RFFT_BUFFER_SIZE)
	//		Error_Handler();
	return audioBuff[index];
}

/**
 * @brief  Get audio buffer index pointer
 * @param  index
 * @retval index address
 */
volatile int32_t * audio_GetDataPtr(uint32_t index)
{
	return &audioBuff[index];
}

/**
 * @brief  Get state of audio process
 * @param  void
 * @retval state
 */
__inline BUFFER_AUDIO_StateTypeDef * audio_GetBufferState(void)
{
	return &bufferAudioState;
}

/**
 * @brief  Reset state of audio process
 * @param  void
 * @retval void
 */
__inline void audio_ResetBufferState(void)
{
	bufferAudioState = AUDIO_BUFFER_OFFSET_NONE;
}

/*------------------------------------------------------------------------------
       Callbacks implementation:
           the callbacks API are defined __weak in the stm32769i_discovery_audio.c file
           and their implementation should be done the user code if they are needed.
           Below some examples of callback implementations.
  ----------------------------------------------------------------------------*/
/**
 * @brief  Manages the full Transfer complete event.
 * @param  None
 * @retval None
 */
void BSP_AUDIO_OUT_TransferComplete_CallBack(uint32_t Interface)
{
	/* allows AUDIO_Process() to refill 2nd part of the buffer  */
	bufferAudioState = AUDIO_BUFFER_OFFSET_FULL;
}

/**
 * @brief  Manages the DMA Half Transfer complete event.
 * @param  None
 * @retval None
 */
void BSP_AUDIO_OUT_HalfTransfer_CallBack(uint32_t Interface)
{
	//	buffer_ctl.state = AUDIO_BUFFER_OFFSET_HALF;
	bufferAudioState = AUDIO_BUFFER_OFFSET_HALF;
}

/**
 * @brief  Manages the DMA FIFO error event.
 * @param  None
 * @retval None
 */
void BSP_AUDIO_OUT_Error_CallBack(uint32_t Interface)
{
	Error_Handler();
}
