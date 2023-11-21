#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/fps.h"
#include "gui/menu.h"
#include "gui/separator.h"
#include "objects/plane.h"

using namespace gui_wrapper;
using namespace objects;

int main(int argc, char* argv[]) {
    // Создаем и инициализируем окно размером 800х600 и заголовком
    sf::RenderWindow window{ {800, 600}, "Dispatch window" };
    tgui::Gui gui{ window };
    // window.setFramerateLimit(60); - ограничитель кадров

    // Создаем спрайт карты
    sf::Texture map_texture;
    map_texture.loadFromFile("../meta/map.png");
    sf::Sprite map_sprite(map_texture);

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

    VerticalLine vline;
    vline.InitializeLine(window);

    HorizontalLine hline;
    hline.InitializeLine(window);

    // Добавляем все объекты в наш интерфейс
    gui.add(canvas.GetCanvas());
    gui.add(vline.GetLine());
    gui.add(hline.GetLine());
    gui.add(menu.GetMenu());
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
                case sf::Event::Resized:
                    canvas.SetSize(event.size.width * 0.6, event.size.height * 0.6);
                    menu.SetTextSize(event.size.height * 0.025);
                    break;
                case sf::Event::MouseMoved:
                    tgui::String text{ std::to_string(event.mouseMove.x) + " " + std::to_string(event.mouseMove.y) };
                    coords_label.SetLabelText(text);
                    break;
            }
        }

        frame_rate_label.CalculateFrameRate();

        plane.Control();
        
        canvas.GetCanvas()->clear(sf::Color{ 211, 211, 211 });
        canvas.GetCanvas()->draw(map_sprite);
        if (plane.GetToDraw()) {
            canvas.GetCanvas()->draw(plane.GetPrimitive()); 
        }
        canvas.GetCanvas()->display();

        window.clear(sf::Color{ 255, 255, 255 });
        gui.draw();
        window.display();
    }

    return 0;
}