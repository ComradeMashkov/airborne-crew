#include "global_parameters.h"

#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/fps.h"
#include "gui/menu.h"
#include "gui/separator.h"
#include "gui/text_label.h"
#include "gui/stamp.h"

#include "objects/plane.h"

#include "../utils/weather_handler.h"

using namespace global_parameters;
using namespace gui_wrapper;
using namespace objects;
using namespace utils;

int main(int argc, char* argv[]) {
    // Создаем и инициализируем окно размером 800х600 и заголовком
    sf::RenderWindow window{ { WIDTH, HEIGHT }, "Dispatch window", sf::Style::Titlebar | sf::Style::Close };
    tgui::Gui gui{ window };
    window.setFramerateLimit(60); // ограничитель кадров

    // Вертикальная линия, отделяющая блок времени от блока погоды
    HorizontalLine time_weather_hline;
    time_weather_hline.InitializeLine(0, TW_HLINE_Y, window.getSize().x, LINE_WIDTH);
    gui.add(time_weather_hline.GetLine());

    // Объект самолета
    Plane plane;

    // Полотно
    Canvas canvas;
    canvas.InitializeCanvas(plane);
    gui.add(canvas.GetCanvas());

    // Спрайт карты
    sf::Texture map_texture;
    map_texture.loadFromFile("../meta/tst2.png"); //map.png
    sf::Sprite map_sprite(map_texture);

    // Главные горизонтальная и вертикальная линии
    VerticalLine vline;
    vline.InitializeLine();
    HorizontalLine hline_main;
    hline_main.InitializeLine();
    gui.add(vline.GetLine());
    gui.add(hline_main.GetLine());

    // Метка кадров в секунду
    FrameRateLabel frame_rate_label;
    frame_rate_label.InitializeLabel();
    gui.add(frame_rate_label.GetLabel());

    // Координатная метка
    CoordsLabel coords_label;
    coords_label.InitializeLabel();
    gui.add(coords_label.GetLabel());

    // Верхнее меню
    UpperMenu menu;
    menu.InitializeMenu(gui, plane, frame_rate_label);
    gui.add(menu.GetMenu());

    // Метка с текущим временем и датой
    TimeStamp time_label;
    time_label.InitializeLabel();
    DateStamp date_label;
    date_label.InitializeLabel();
    gui.add(time_label.GetLabel());
    gui.add(date_label.GetLabel());

    // Надписи
    TextLabel time_text_label;
    time_text_label.SetLabelText("Время");
    time_text_label.InitializeLabel({ TT_LABEL_X, TT_LABEL_Y }, TEXT_LABELS_FONTSIZE);
    gui.add(time_text_label.GetLabel());

    TextLabel weather_text_label;
    weather_text_label.SetLabelText("Погода");
    weather_text_label.InitializeLabel({ TW_LABEL_X, TW_LABEL_Y }, TEXT_LABELS_FONTSIZE);
    gui.add(weather_text_label.GetLabel());

    TextLabel temperature_text_label;
    temperature_text_label.SetLabelText("Температура");
    temperature_text_label.InitializeLabel({ TEMP_TEXT_LABEL_X, TEMP_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(temperature_text_label.GetLabel());

    TextLabel pressure_text_label;
    pressure_text_label.SetLabelText("Давление");
    pressure_text_label.InitializeLabel({ PRESSURE_TEXT_LABEL_X, PRESSURE_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(pressure_text_label.GetLabel());

    TextLabel humidity_text_label;
    humidity_text_label.SetLabelText("Влажность");
    humidity_text_label.InitializeLabel({ HUMIDITY_TEXT_LABEL_X, HUMIDITY_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(humidity_text_label.GetLabel());

    TextLabel wind_speed_text_label;
    wind_speed_text_label.SetLabelText("Скорость ветра");
    wind_speed_text_label.InitializeLabel({ WIND_SPEED_TEXT_LABEL_X, WIND_SPEED_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(wind_speed_text_label.GetLabel());

    TextLabel times_of_day_text_label;
    times_of_day_text_label.SetLabelText("Время суток");
    times_of_day_text_label.InitializeLabel({ TIMES_OF_DAY_TEXT_LABEL_X, TIMES_OF_DAY_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(times_of_day_text_label.GetLabel());

    // Погода
    weather_handler::WeatherHandler weather;
    weather.Initialize();

    TextLabel temperature_label;
    temperature_label.SetLabelText(weather.temperature + " °C");
    temperature_label.InitializeLabel({ TEMP_LABEL_X, TEMP_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(temperature_label.GetLabel());

    TextLabel pressure_label;
    pressure_label.SetLabelText(weather.pressure + "  мбар");
    pressure_label.InitializeLabel({ PRESSURE_LABEL_X, PRESSURE_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(pressure_label.GetLabel());

    TextLabel humidity_label;
    humidity_label.SetLabelText(weather.humidity + " %");
    humidity_label.InitializeLabel({ HUMIDITY_LABEL_X, HUMIDITY_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(humidity_label.GetLabel());

    TextLabel wind_speed_label;
    wind_speed_label.SetLabelText(weather.wind_speed + " км/ч");
    wind_speed_label.InitializeLabel({ WIND_SPEED_LABEL_X, WIND_SPEED_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(wind_speed_label.GetLabel());

    TextLabel wind_dir_label;
    wind_dir_label.SetLabelText(weather.wind_dir);
    wind_dir_label.InitializeLabel({ WIND_DIR_LABEL_X, WIND_DIR_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(wind_dir_label.GetLabel());

    TextLabel times_of_day_label;
    times_of_day_label.SetLabelText(weather.times_of_day);
    times_of_day_label.InitializeLabel({ TIMES_OF_DAY_LABEL_X, TIMES_OF_DAY_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(times_of_day_label.GetLabel());

    //Координаты самолета
    TextLabel plane_coordinates_label;
    plane_coordinates_label.SetLabelText(plane.coordinates);
    plane_coordinates_label.InitializeLabel({ PLANE_COORDINATES_LABEL_X, PLANE_COORDINATES_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui.add(plane_coordinates_label.GetLabel());

    // Создаем логгер, выводящий все в файл (папка logs)
    log_handler::LogHandler logger("../logs/sample.log");
    logger.LogTrivial(boost::log::trivial::severity_level::info, "-------------------- LOGGER HAS BEEN INITIALIZED --------------------");
    event_handler::EventHandler::SetLogger(&logger);

    // ОСНОВНОЙ ПРОГРАММНЫЙ ЦИКЛ
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            gui.handleEvent(event);

            // Обработчик событий
            switch (event.type) {
                case sf::Event::Closed:
                    logger.LogTrivial(boost::log::trivial::severity_level::info, "Program has been closed");
                    window.close();
                    break;
                case sf::Event::MouseMoved:
                    tgui::String text{ std::to_string(event.mouseMove.x) + " " + std::to_string(event.mouseMove.y) };
                    coords_label.SetLabelText(text);
                    break;
            }
        }
        
        time_label.Update();
        date_label.Update();

        frame_rate_label.CalculateFrameRate();

        plane.Control();
        plane_coordinates_label.SetLabelText(plane.coordinates);
        
        canvas.GetCanvas()->clear(sf::Color{ CANVAS_DEFAULT_COLOR.r, CANVAS_DEFAULT_COLOR.g, CANVAS_DEFAULT_COLOR.b });
        canvas.GetCanvas()->draw(map_sprite);
        if (plane.GetToDraw()) {
            canvas.GetCanvas()->draw(plane.GetPrimitive()); 
        }
        canvas.GetCanvas()->display();

        window.clear(sf::Color{ BACKGROUND_DEFAULT_COLOR.r, BACKGROUND_DEFAULT_COLOR.g, BACKGROUND_DEFAULT_COLOR.b });
        gui.draw();
        window.display();
    }

    return 0;
}