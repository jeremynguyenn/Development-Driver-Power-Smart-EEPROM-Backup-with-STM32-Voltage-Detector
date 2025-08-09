#include <stdio.h>
#include "stm32f4xx.h"
#include "fpu.h"
#include "uart.h"
#include "timebase.h"
#include "at24cxx_eeprom.h"
#include "i2c.h"
#include "pvd.h"
#include <string.h>

SystemSettings settings;
SensorReading  reading;

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

	settings.loggingInterval =10;
	settings.temperatureCalibOffset = 2;
	settings.humidityCalibOffset = 3;

	restore_settings(&settings);
	restore_last_reading(&reading);


	while(1)
	{
        counter++;

        reading.timestamp  += counter +  settings.loggingInterval;
        reading.temperature += (counter/2) + settings.temperatureCalibOffset;
        reading.humidity    += (counter/3) + settings.humidityCalibOffset;


       printf("Timestamp: %d\n\r",(int)reading.timestamp);
       printf("Temperature: %d\n\r",(int)reading.temperature);
       printf("Humidity: %d\n\r",(int)reading.humidity);

		delay(1000);
	}
}

