#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/menu.h"

using namespace gui_wrapper;

int main() {
    sf::RenderWindow window{ {800, 600}, "Main window" };
    tgui::Gui gui{ window };

    std::optional<sf::CircleShape> circle;

    Canvas canvas;
    canvas.InitializeCanvas(circle);

    UpperMenu menu;
    menu.InitializeMenu(gui, circle);

    CoordsLabel label;
    label.InitializeCoordsLabel();

    gui.add(menu.GetMenu());
    gui.add(canvas.GetCanvas());
    gui.add(label.GetLabel());

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
                    label.SetLabelText(text);
                    break;
            }
        }
        
        canvas.GetCanvas()->clear(sf::Color{ 211, 211, 211 });
        if (circle.has_value()) {
            canvas.GetCanvas()->draw(circle.value());
        }
        canvas.GetCanvas()->display();

        window.clear(sf::Color{ 211, 211, 211 });
        gui.draw();
        window.display();
    }
}