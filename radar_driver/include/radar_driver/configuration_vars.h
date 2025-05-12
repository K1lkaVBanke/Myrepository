#ifndef RADAR_DRIVER_CONFIGURATION_VARS_H_
#define RADAR_DRIVER_CONFIGURATION_VARS_H_

namespace radar_driver {

// Radar Configuration 0x200

const int RADARCFG_MAXDISTANCE_VALID = 1; // Allow change of maximum distance 0-1
const int RADARCFG_SENSORID_VALID = 1; // Allow change of sensor Id 0-1
const int RADARCFG_RADARPOWER_VALID = 1; // Allow change in radar output power
const int RADARCFG_OUTPUTTYPE_VALID = 1; // Allow change of output type
const int RADARCFG_SENDQUALITY_VALID = 1; // Allow change of quality option
const int RADARCFG_SENDEXTINFO_VALID = 1; // Allow change of extended information
const int RADARCFG_SORTINDEX_VALID = 1; // Allow change of sorting index
const int RADARCFG_STOREINNVM_VALID = 1; // Allow storing to non-volatile memory

const int RADARCFG_MAXDISTANCE = 250; // Максимальное расстояние дальнего сканирования. Стандартный диапазон: 96-260
const int RADARCFG_SENSORID = 0; // Sensor Id 0-7
const int RADARCFG_OUTPUTTYPE = 1; // Output type 0 none - 1 objects - 2 clusters

const int RADARCFG_RADARPOWER = 3; // Transmitted radar power 0 Standard - 3 -9dB Tx gain



const int RADARCFG_CTRLRELAY_VALID = 0; // Разрешить изменение управляющего выхода реле
const int RADARCFG_CTRLRELAY = 0; // Если это так, отправляется управляющее сообщение, и активируется обнаружение столкновений
const int RADARCFG_SENDQUALITY = 1; // Отправка информации о качестве
const int RADARCFG_SENDEXTINFO = 1; // Отправка расширенной информации
const int RADARCFG_SORTINDEX = 1; // Индекс сортировки 0 нет сортировки - 1 сортировка по диапазону - 2 сортировка по RCS
const int RADARCFG_STOREINNVM = 1; // Сохранение текущей конфигурации в энергонезависимой памяти

const int RADARCFG_RCS_THRESHOLD_VALID = 1; // Разрешить изменение пороговой опции RCS
const int RADARCFG_RCS_THRESHOLD = 1; // Установка чувствительности обнаружения кластеров 0 стандартная - 1 высокая чувствительность

// Конфигурация кластера и фильтра объектов 0x202

const int FILTERCFG_VALID = 1; // Разрешить изменение конфигурации фильтра
const int FILTERCFG_ACTIVE = 1; // Активация конфигурации фильтра
const int FILTERCFG_INDEX = 8; //Мультиплексор для указания критерия фильтрации
const int FILTERCFG_TYPE = 1; // выбор между объектами и кластерами 0 кластер - 1 объект
// Index 0. Clusters and objects
const double FILTERCFG_MIN_NOFOBJ = 0; // Количество кластеров или объектов 0 - 4095
const double FILTERCFG_MAX_NOFOBJ = 50;
const double FILTERCFG_RES_NOFOBJ = 1;
// Index 1. Clusters and objects
const double FILTERCFG_MIN_DISTANCE = 0; // Радиальное расстояние 0 - 409,5 м 
const double FILTERCFG_MAX_DISTANCE = 60;
const double FILTERCFG_RES_DISTANCE = 0.1;
// Index 2. Clusters and objects
const double FILTERCFG_MIN_AZIMUTH = -50; // Азимутальный угол -50 - 52,375 град
const double FILTERCFG_MAX_AZIMUTH = 52.375;
const double FILTERCFG_MINIMUM_AZIMUTH = -50;
const double FILTERCFG_RES_AZIMUTH = 0.025;
// Index 3. Clusters and objects
const double FILTERCFG_MIN_VRELONCOME = 0; // Радиальная скорость в зоне видимости датчика встречного объекта/clus 
const double FILTERCFG_MAX_VRELONCOME = 128.993; // 0 - 128.993 m/s
const double FILTERCFG_RES_VRELONCOME = 0;//0.0315;
// Index 4. Clusters and objects
const double FILTERCFG_MIN_VRELDEPART = 0; // Радиальная скорость в зоне прямой видимости датчика отлетающего объекта/ключа
const double FILTERCFG_MAX_VRELDEPART = 128.993; // 0 - 128.993 m/s
const double FILTERCFG_RES_VRELDEPART= 0;//0.0315;
// Index 5. Clusters and objects
const double FILTERCFG_MIN_RCS = -20; // сечение радара -50 - 52.375 dBm2
const double FILTERCFG_MAX_RCS = 52.375;
const double FILTERCFG_MINIMUM_RCS = -50;
const double FILTERCFG_RES_RCS = 0.025;
// Index 6. Objects
const double FILTERCFG_MIN_LIFETIME = 0; // Время жизни с момента первого обнаружения 0 - 409,5 с
const double FILTERCFG_MAX_LIFETIME = 409.5;
const double FILTERCFG_RES_LIFETIME = 0.2;
// Index 7. Objects
const double FILTERCFG_MIN_SIZE = 0; // Площадь объекта 0 - 102,375 м2
const double FILTERCFG_MAX_SIZE = 102.375;
const double FILTERCFG_RES_SIZE = 0.025;
// Index 8. Objects
const double FILTERCFG_MIN_PROBEXISTS = 2; // Вероятность существования
const double FILTERCFG_MAX_PROBEXISTS = 7; //  0 0% - 1 25 % - 2 50 % - 3 75 % - 4 90 % - 5 99 % - 6 99.9 % - 7 100 %
const double FILTERCFG_RES_PROBEXISTS = 1;
// Index 9. Objects
const double FILTERCFG_MIN_Y = -409.5; // Боковое расстояние -409,5 - 409,5 м
const double FILTERCFG_MAX_Y = 409.5;
const double FILTERCFG_MINIMUM_Y = -409.5;
const double FILTERCFG_RES_Y = 0.2;
// Index 10. Objects
const double FILTERCFG_MIN_X = -10; // Продольное расстояние -500 - 1138,2 м
const double FILTERCFG_MAX_X = 260;
const double FILTERCFG_MINIMUM_X = -500;
const double FILTERCFG_RES_X = 0.2;
// Index 11. Objects
const double FILTERCFG_MIN_VYRIGHTLEFT = 0; // Боковая составляющая скорости для движущегося справа налево объекта
const double FILTERCFG_MAX_VYRIGHTLEFT = 128.993; // 0 - 128.993 m/s
const double FILTERCFG_RES_VYRIGHTLEFT = 0.0315;
// Index 12. Objects
const double FILTERCFG_MIN_VXONCOME = 0; // Продольная составляющая скорости для встречного движущегося объекта
const double FILTERCFG_MAX_VXONCOME = 128.993; // 0 - 128.993 m/s
const double FILTERCFG_RES_VXONCOME = 0.0315;
// Index 13. Objects
const double FILTERCFG_MIN_VYLEFTRIGHT = 0; // Боковая составляющая скорости для движущегося слева направо объекта
const double FILTERCFG_MAX_VYLEFTRIGHT = 128.993; // 0 - 128.993 m/s
const double FILTERCFG_RES_VYLEFTRIGHT = 0.0315;
// Index 14. Objects
const double FILTERCFG_MIN_VXDEPART = 0; // Продольная составляющая скорости при вылете из движущегося объекта
const double FILTERCFG_MAX_VXDEPART = 128.993; // 0 - 128.993 m/s
const double FILTERCFG_RES_VXDEPART = 0.0315;

// Конфигурация обнаружения столкновений 0x400

const int COLLDETCFG_WARNINGRESET = 0; // Сброс текущих активных предупреждений для всех регионов
const int COLLDETCFG_ACTIVATION = 0; // Активация функции обнаружения столкновений
const int COLLDETCFG_MINTIME_VALID = 0; //Разрешить изменение временного параметра
const int COLLDETCFG_CLEARREGIONS = 0; // Очистить все конфигурации региона
const double COLLDETCFG_MINTIME = 0; // Минимальное время обнаружения объекта внутри области 0 - 25,5 с
const double COLLDETCFG_RESTIME = 0.1;

//  Конфигурация региона обнаружения столкновений 0x401

const int COLLDETREGCFG_ACTIVATION = 1; // Активировать текущий регион
const int COLLDETREGCFG_COORDINATES_VALID = 1; //  Разрешить изменение координат текущего региона
const int COLLDETREGCFG_REGIONID = 0; // Id текущего региона для конфигурирования
const double COLLDETREGCFG_POINT1X = 0; // Продольное положение первой точки -500 - 1138,2 м
const double COLLDETREGCFG_POINT1Y = -1; // Боковое положение первой точки -204,6 - 204,8 м
const double COLLDETREGCFG_POINT2X = 1; // Продольное положение второй точки -500 - 1138,2 м
const double COLLDETREGCFG_POINT2Y = 1; // Боковое положение второй точки -204,6 - 204,8 м
const double COLLDETREGCFG_POINTRES = 0.2;

}  // namespace radar_driver

#endif
