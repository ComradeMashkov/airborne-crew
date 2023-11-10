#include "domain_functions.h"

int main() {
    sf::RenderWindow window{ {800, 600}, "Main window" };
    tgui::Gui gui{ window };

    std::optional<sf::CircleShape> circle;

    auto canvas = tgui::CanvasSFML::create({ 400, 300 });
    canvas->setHeight("&.height - 22");
    canvas->setWidth("&.width");
    canvas->setAutoLayout(tgui::AutoLayout::Bottom);
    canvas->onMousePress(&moveCircle, std::ref(circle));

    auto menu = tgui::MenuBar::create();
    menu->setHeight(22.f);
    menu->addMenu("Program");
    menu->addMenuItem("Start");
    menu->onMenuItemClick(&startProgram, std::ref(circle));
    menu->addMenuItem("Finish");
    menu->onMenuItemClick(&finishProgram, std::ref(circle));

    menu->addMenu("File");
    menu->addMenuItem("Save");
    menu->onMenuItemClick(&saveFile, "test.txt");
    menu->addMenuItem("Clear");

    menu->addMenu("Info");
    menu->addMenuItem("About");
    menu->onMenuItemClick(&showInfo, std::ref(gui));

    auto label = tgui::Label::create();
    label->setPosition({ "&.left + 7", "&.bottom - 15" });

    gui.add(menu);
    gui.add(canvas);
    gui.add(label);

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
                    label->setText(text);
                    break;
            }
        }
        
        canvas->clear(sf::Color{ 211, 211, 211 });
        if (circle.has_value()) {
            canvas->draw(circle.value());
        }
        canvas->display();

        window.clear(sf::Color{ 211, 211, 211 });
        gui.draw();
        window.display();
    }
}