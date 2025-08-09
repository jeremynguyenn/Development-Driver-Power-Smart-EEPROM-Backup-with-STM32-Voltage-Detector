#ifndef SYS_BACKUP_H_
#define SYS_BACKUP_H_

typedef struct{
	uint32_t loggingInterval;
	uint32_t temperatureCalibOffset;
	uint32_t humidityCalibOffset;

}SystemSettings;

typedef struct{
	uint32_t timestamp;
	uint32_t temperature;
	uint32_t humidity;

}SensorReading;


#define SYS_SETTINGS_PAGE_NUM		4
#define SYS_SETTINGS_PAGE_OFFSET	0

#define SENSOR_DATA_PAGE_NUM		5
#define SENSOR_DATA_PAGE_OFFSET		0
void backup_settings(const SystemSettings* settings);
void restore_settings(const SystemSettings* settings);
void backup_last_reading(const SensorReading* reading);
void restore_last_reading(const SensorReading* reading);

#endif
