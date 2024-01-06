# SRC 
## event_handler
Класс для хранения определения функций, отвечающих за события, которые происходят во время определенного действия.\
### Поле класса:
*Публичное*\
*utils::log_handler::LogHandler* logger_* - указатель на логгер, который вызывается при совершении действия\

### Методы класса:
*showFPS* - отвечает за кнопку Debug -> Show FPS\
*showCoordinates* - отвечает за кнопку Debug -> Show coordinates\
*showInfo* - отвечает за кнопку Info -> About\
*startProgram* -отвечает за кнопку Program -> Start\
*finishProgram* - отвечает за кнопку Program -> Finish\
*movePlane* - отвечает за передвижение самолета\
*changeSliderValue* - отвечает за передвижение ползунка\
*SetLogger* - передача логгера в EventHandler\

## global_parameters
Класс для задания глобальных переменных\

## gui_builder
Класс для создания графической оболочки\
### Поля класса:
*Приватные*\
*sf::RenderWindow* window_* - окно\
*objects::Plane* plane_* - самолет\
*utils::weather_handler::WeatherHandler* weather_handler_* - погодный диспетчер\
*utils::aviation_handler::AviationHandler* aviation_handler_* - афиационный диспетчер\
*gui_wrapper::Canvas canvas_* - холст\
*sf::Texture map_texture_* - текстура карты\
*sf::Sprite map_sprite_* - спрайт карты\
*gui_wrapper::FrameRateLabel frame_rate_label_* - метка частоты кадров\
*gui_wrapper::CoordsLabel coords_label_* - метка координат\
*gui_wrapper::TimeStamp time_label_* - метка времени\
*gui_wrapper::DateStamp date_label_* - метка даты\
*gui_wrapper::TextLabel longtitude_label_* - метка долготы\
*gui_wrapper::TextLabel latitude_label_* - метка широты\
*gui_wrapper::ValueSlider linear_speed_slider_* - линейная скорость ползунка\
*gui_wrapper::ValueSlider angle_speed_slider_* - смещение угла корости\
*gui_wrapper::TextLabel linear_speed_slider_value_label_* - линейная скорость значения метки ползунка\
*gui_wrapper::TextLabel angle_speed_slider_value_label_* - угол скорости значения метки ползунка\

### Методы класса:
*Публичные*\
*InterfaceBuilder* - конструктор интерфейса\
*CreateAsyncComponents* - создание асинхронных компонентов\
*CreateAwaitComponents* - создание ожидающих компонентов\
*UpdateFrameRateLabel* - обновление метки частоты кадров\
*UpdateCoordsLabel* - обновление метки координат\
*UpdateStampLabels* - обновление метки штампа\
*UpdatePlaneCoordsLabel* - обновление метки координат плоскости\
*UpdateCanvas* - обновление холста\

*Приватные*\
*CreateMainLines* - создание основных линий\
*CreateTimeWeatherHline* - создание временной линии погоды\
*CreateFlightsTableLines* - создание строк таблицы рейсов\
*CreateCanvas* - создание холста\
*CreateMapSprite* - создание спрайта карты\
*CreateFrameRateLabel* - создание метки частоты кадров\
*CreateCoordinateLabel* - создание координатной метки\
*CreateUpperMenu* - создание верхнего меню\
*CreateStampLabels* - создание метки штампа\
*CreateTextLabels* - создание текстовых меток\
*CreateWeatherLabels* - создание погодных меток\
*CreatePlaneCoordsLabel* - создание меток координат самолета\
*CreateFlightsTableLabels* - создание меток таблиц рейсов\
*CreateSlider* - создание ползунка\
*CreateSliderValueLabel* - создание метки значения ползунка\
