#include "pvd.h"
#include "at24cxx_eeprom.h"
#include <stdio.h>

void backup_settings(const SystemSettings* settings)
{
	eeprom_write(SYS_SETTINGS_PAGE_NUM,SYS_SETTINGS_PAGE_OFFSET,
			     (uint8_t *)settings,sizeof(SystemSettings));

}

void restore_settings(const SystemSettings* settings)
{
	eeprom_read(SYS_SETTINGS_PAGE_NUM,SYS_SETTINGS_PAGE_OFFSET,
			     (uint8_t *)settings,sizeof(SystemSettings));

}


void backup_last_reading(const SensorReading* reading)
{
	eeprom_write(SENSOR_DATA_PAGE_NUM,SENSOR_DATA_PAGE_OFFSET,
			     (uint8_t *)reading,sizeof(SensorReading));

}

void restore_last_reading(const SensorReading* reading)
{
	eeprom_read(SENSOR_DATA_PAGE_NUM,SENSOR_DATA_PAGE_OFFSET,
			     (uint8_t *)reading,sizeof(SensorReading));

}
