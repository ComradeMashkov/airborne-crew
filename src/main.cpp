#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/fps.h"
#include "gui/menu.h"
#include "objects/plane.h"

using namespace gui_wrapper;
using namespace objects;

int main(int argc, char* argv[]) {
    // Создаем и инициализируем окно размером 800х600 и заголовком
    sf::RenderWindow window{ {800, 600}, "Dispatch window" };
    tgui::Gui gui{ window };
    // window.setFramerateLimit(60); - ограничитель кадров

    // Создаем логгер, выводящий все в файл (папка logs)
    log_handler::LogHandler logger("../logs/sample.log");
    event_handler::EventHandler::SetLogger(&logger);

    // Создаем объект самолета
    Plane plane;

    // Создаем координатную метку
    CoordsLabel coords_label;
    coords_label.InitializeCoordsLabel();

    // Создаем метку кадров в секунду
    FrameRateLabel frame_rate_label;
    frame_rate_label.InitializeFrameRateLabel();

    // Создаем полотно
    Canvas canvas;
    canvas.InitializeCanvas(plane);

    // Создаем верхнее меню
    UpperMenu menu;
    menu.InitializeMenu(gui, plane, frame_rate_label);

    // Добавляем все объекты в наш интерфейс
    gui.add(menu.GetMenu());
    gui.add(canvas.GetCanvas());
    gui.add(coords_label.GetLabel());
    gui.add(frame_rate_label.GetLabel());

    // ОСНОВНОЙ ПРОГРАММНЫЙ ЦИКЛ
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            gui.handleEvent(event);

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseMoved:
                    tgui::String text{ std::to_string(event.mouseMove.x) + " " + std::to_string(event.mouseMove.y) };
                    coords_label.SetLabelText(text);
                    break;
            }
        }

        frame_rate_label.CalculateFrameRate();

        plane.Control();
        
        canvas.GetCanvas()->clear(sf::Color{ 28, 170, 214 });
        if (plane.GetToDraw()) {
            canvas.GetCanvas()->draw(plane.GetPrimitive()); 
        }
        canvas.GetCanvas()->display();

        window.clear(sf::Color{ 211, 211, 211 });
        gui.draw();
        window.display();
    }

    return 0;
}