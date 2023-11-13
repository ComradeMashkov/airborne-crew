#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/fps.h"
#include "gui/menu.h"
#include "objects/plane.h"

using namespace gui_wrapper;
using namespace objects;

int main() {
    sf::RenderWindow window{ {800, 600}, "Dispatch window" };
    tgui::Gui gui{ window };
    // window.setFramerateLimit(60);

    Plane plane;

    CoordsLabel coords_label;
    coords_label.InitializeCoordsLabel();

    FrameRateLabel frame_rate_label;
    frame_rate_label.InitializeFrameRateLabel();

    Canvas canvas;
    canvas.InitializeCanvas(plane);

    UpperMenu menu;
    menu.InitializeMenu(gui, plane, frame_rate_label);

    gui.add(menu.GetMenu());
    gui.add(canvas.GetCanvas());
    gui.add(coords_label.GetLabel());
    gui.add(frame_rate_label.GetLabel());

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