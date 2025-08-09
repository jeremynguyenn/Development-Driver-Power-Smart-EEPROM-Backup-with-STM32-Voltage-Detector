#include "pvd.h"
#include "at24cxx_eeprom.h"

#define PWR_EN		(1U<<28)


extern	SystemSettings settings;
extern SensorReading  reading;

void pvd_init(void)
{
	/*Enable clock access to PWR module*/
	RCC->APB1ENR |=PWR_EN;

	/*Set PVD threshold value*/
	PWR->CR &=~PWR_CR_PLS;
	PWR->CR  |=PWR_CR_PLS_LEV7;

	/*Enable PWR PVD EXTI */
	EXTI->IMR |=(EXTI_IMR_MR16);

	/*Enable Rising edge detection*/
	EXTI->RTSR |=EXTI_IMR_MR16;

	/*Enable PVD*/
	PWR->CR |=(1U<<4);

	/*Enable PVD Interrupt in NVIC*/
	NVIC_EnableIRQ(PVD_IRQn);
}

void pwr_pvd_callback(void)
{

	static uint8_t backup_completed = 0;

	SystemSettings last_setting;
	SensorReading	last_reading;

	/*Check if backup operation has already been performed*/
	if(!backup_completed)
	{
		last_reading  = reading;
		last_setting =  settings;

		backup_last_reading(&last_reading);
		backup_settings(&last_setting);

		/*Set flag indicating that the backup operation is complete*/
		backup_completed = 1;

	}

}

void PVD_IRQHandler(void)
{
	/*Check PWR EXTI flag*/
	if((EXTI->PR & EXTI_IMR_MR16 )!= 0)
	{
		pwr_pvd_callback();

		/*Clear PVD EXT flag*/
		EXTI->PR |=EXTI_IMR_MR16;

	}
}
