# Utilities

### About
В этой директории будут храниться всопомгательные утилиты, необходимые для реализации основной логики проекта.

## aviation_handler
Класс обработки данных 
### Поля класса:

### Методы класса:

## log_handler
Класс для логированиия данных
### Поля класса:

### Методы класса:

## weather_handler
Класс обработки данных погоды с сайта http://api.weatherapi.com в Москве.
### Поля класса:
*Приватные*  
*is_day* — время дня: вечер/день\
*wind_angle* — направление ветра\
*std::string settings_path* — путь до файла weather_settings.txt (файл с настройками API-запроса)\
*std::string api_key* — апи запроса\
*std::string region* — регион запроса\
*std::string outfile_path* — местоположение файла с выходными данными\
*std::string buffer* — промежуточный буффер
 
*Публичные*  
*std::string temperature* — температура\
*std::string pressure* — давление\
*std::string humidity* — влажность  
*std::string wind_speed* — скорость ветра\
*std::string wind_dir* — направление ветра
*std::string times_of_day* — время
### Методы класса:
*ParseSettingsFile()* — считывает настройки запроса из файла weather_settings.txt\
*SendRequest()* — отправляет API запрос\
*ProcessWeatherValues()* — обрабытвает json файл, получая данные о погоде

