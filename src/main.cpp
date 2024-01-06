#include "gui_builder.h"

using namespace global_parameters;
using namespace gui_wrapper;
using namespace objects;
using namespace utils;

int main(int argc, char* argv[]) {
    // Создаем и инициализируем окно размером 800х600 и заголовком
    sf::RenderWindow window{ { WIDTH, HEIGHT }, "Dispatch window", sf::Style::Titlebar | sf::Style::Close };
    tgui::Gui gui{ window };
    window.setFramerateLimit(MAX_FPS); // ограничитель кадров

    // Погода
    weather_handler::WeatherHandler weather_handler;
    sf::Thread weather_thread(&weather_handler::WeatherHandler::Initialize, &weather_handler);
    weather_thread.launch();

    // Авиация
    aviation_handler::AviationHandler aviation_handler;
    sf::Thread aviation_thread(&aviation_handler::AviationHandler::Initialize, &aviation_handler);
    aviation_thread.launch(); 

    // Объект самолета
    Plane plane;

    InterfaceBuilder builder(&window, &gui, &plane, &weather_handler, &aviation_handler);
    builder.CreateAsyncComponents();

    weather_thread.wait();
    aviation_thread.wait();

    builder.CreateAwaitComponents();

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
                    builder.UpdateCoordsLabel(text);
                    break;
            }
        }
        
        builder.UpdateStampLabels();

        builder.UpdateFrameRateLabel();

        plane.Control();
        builder.UpdatePlaneCoordsLabel();
        
        builder.UpdateCanvas();

        window.clear(sf::Color{ BACKGROUND_DEFAULT_COLOR.r, BACKGROUND_DEFAULT_COLOR.g, BACKGROUND_DEFAULT_COLOR.b });
        gui.draw();
        window.display();
    }

    return 0;
}