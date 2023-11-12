#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/menu.h"
#include "objects/plane.h"

using namespace gui_wrapper;
using namespace objects;

int main() {
    sf::RenderWindow window{ {800, 600}, "Main window" };
    tgui::Gui gui{ window };

    Plane plane;

    Canvas canvas;
    canvas.InitializeCanvas(plane);

    UpperMenu menu;
    menu.InitializeMenu(gui, plane);

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

        plane.Control();
        
        canvas.GetCanvas()->clear(sf::Color{ 211, 211, 211 });
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