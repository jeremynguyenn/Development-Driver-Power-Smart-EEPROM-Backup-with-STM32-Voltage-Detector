#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "at24cxx_eeprom.h"
#include "i2c.h"
#include "pvd.h"
#include <string.h>


uint32_t last_val_from_eeprom;
uint32_t counter;

int main()
{
	/*Enable FPU*/
	fpu_enable();

	/*Initialize debug UART*/
	debug_uart_init();

	/*Initialize timebase*/
	timebase_init();

	/*Initialize i2c*/
	i2c1_init();

   /*Initialize PVD*/
	pvd_init();


	last_val_from_eeprom = eeprom_read_number(VAL_PAGE_NUM,VAL_PAGE_OFFSET);

	counter = last_val_from_eeprom;


	while(1)
	{
        counter++;
        printf("Count Value: %d \n\r",(int)counter);
        printf("Last EEPROM Value: %d \n\r",(int)last_val_from_eeprom);

		delay(100);
	}
}

