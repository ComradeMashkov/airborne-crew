#include "global_parameters.h"

#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/fps.h"
#include "gui/menu.h"
#include "gui/separator.h"
#include "gui/text_label.h"
#include "gui/stamp.h"

#include "objects/plane.h"

using namespace global_parameters;
using namespace gui_wrapper;
using namespace objects;

int main(int argc, char* argv[]) {
    // Создаем и инициализируем окно размером 800х600 и заголовком
    sf::RenderWindow window{ { WIDTH, HEIGHT }, "Dispatch window", sf::Style::Titlebar | sf::Style::Close };
    tgui::Gui gui{ window };
    // window.setFramerateLimit(60); // ограничитель кадров

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
    map_texture.loadFromFile("../meta/map.png");
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

    TextLabel weather_text_label;
    weather_text_label.SetLabelText("Погода");
    weather_text_label.InitializeLabel({ TW_LABEL_X, TW_LABEL_Y }, TEXT_LABELS_FONTSIZE);
    
    gui.add(time_text_label.GetLabel());
    gui.add(weather_text_label.GetLabel());

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