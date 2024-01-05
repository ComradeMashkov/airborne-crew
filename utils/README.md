# Utilities

### About
В этой директории хранятся всопомгательные утилиты, необходимые для реализации основной логики проекта: обработка полетов, погоды и логгирование.

## aviation_handler
Класс обработки данных о полетах. Сейчас класс генерирует данные из-за сложностей с сайтом
### Поля класса:
*Приватные*\
*std::string settings_path* — путь к файлу aviation_settings.txt, содержащему настройки API-запроса\
*std::string outfile_path* — путь файла с выходными данными

*Публичные*\
*size_t fcount* — число выводимых полетов\
*std::vector<std::string> flight_numbers* — номер рейса\
*std::vector<std::string> departure_times* — время вылета\
*std::vector<std::string> arrival_times* — время прилета\
*std::vector<std::string> flight_statuses* — статус рейса
    
### Методы класса:
*AviationHandler()* — конструктор\
*Initialize()* — запуск обработки: генерация JSON файла и обработка данных\
*ProcessAviationValues()* — обработка данных из JSON файла\
*GenerateJSON()* — генерация JSON файла с номером рейсов, временем вылета/прилета и статусом рейсов\
*ParseSettingsFile()* — считывает настройки запроса из файла aviation_settings.txt\
*GenerateRandomString(size_t length)* — генерация буквенной части номера рейса длиной length\
*GenerateRandomFlightNumber()* — генерация цифровой части рейса\
*GenerateRandomTime()* — генерация времени\
*GenerateRandomFlightStatus()* — генерация статуса полета

## log_handler
Класс отвечает за логированиия данных. Определение и реализация.
### Поля класса:
*Приватные*\
*logging::sources::severity_logger<logging::trivial::severity_level> logger_* — уровни логгирования

### Методы класса:
*LogHandler()* — дефолтный конструктор\
*LogHandler(const std::string& filename)* — параметризированный конструктор
*~LogHandler()* — декструктор, очищает поток вывода логгера\
*LogTrivial(logging::trivial::severity_level level, const std::string& message)* — выводит сообщение через макрос из Boost.Log
*InitConsoleLogging()*— метод вывода в консоль\
*InitFileLogging(const std::string& filename)* —  метод вывода в консоль\

## weather_handler
Класс обработки данных погоды с сайта http://api.weatherapi.com в Москве. Определение и реализация.
### Поля класса:
*Приватные*  
*is_day* — время дня: вечер/день\
*wind_angle* — направление ветра\
*std::string settings_path* — путь до файла weather_settings.txt (файл с настройками API-запроса)\
*std::string api_key* — апи запроса\
*std::string region* — регион запроса\
*std::string outfile_path* — местоположение JSON файла с выходными данными\
*std::string buffer* — промежуточный буффер
 
*Публичные*  
*std::string temperature* — температура\
*std::string pressure* — давление\
*std::string humidity* — влажность  
*std::string wind_speed* — скорость ветра\
*std::string wind_dir* — направление ветра
*std::string times_of_day* — время
### Методы класса:
*WeatherHandler()* — конструктор\
*Initialize()* — запуск обработки: отправление запроса и обработка полученных данных\
*ParseSettingsFile()* — считывает настройки запроса из файла weather_settings.txt\
*SendRequest()* — отправляет API запрос\
*ProcessWeatherValues()* — обрабытвает JSON файл, получая данные о погоде

