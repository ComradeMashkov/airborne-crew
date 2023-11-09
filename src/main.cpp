#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <fstream>
#include "../lib/dialogs/tinyfiledialogs.h"

void showInfo (tgui::Gui& gui, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "Info" && menuItem[1] == "About") {
        auto messageBox = tgui::MessageBox::create();
        messageBox->setPosition("(&.size - size) / 2");
        messageBox->setText("This program was developed by comrademashkov");
        messageBox->addButton("OK");
        messageBox->setButtonAlignment(tgui::MessageBox::Alignment::Center);
        messageBox->onButtonPress([msgBox = messageBox.get()] (const tgui::String& button) {
            msgBox->getParent()->remove(msgBox->shared_from_this());
        });
        gui.add(messageBox);
    }
}

void startProgram(std::optional<sf::CircleShape>& circle, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "Program" && menuItem[1] == "Start") {
        sf::CircleShape c(50.f);
        c.setPosition({ 50, 50 });
        c.setFillColor(sf::Color::Red);
        circle.emplace(c);
    }
}

void finishProgram(std::optional<sf::CircleShape>& circle, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "Program" && menuItem[1] == "Finish") {
        circle.reset();
    }
}

void moveCircle(std::optional<sf::CircleShape>& circle, const sf::Vector2f& posMouse) {
    if (circle.has_value()) {
        sf::Vector2f posCircle{ circle.value().getRadius(), circle.value().getRadius() };
        circle.value().setPosition(posMouse - posCircle);
    }
}

void saveFile(const std::string& filename, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "File" && menuItem[1] == "Save") {
        const char *file_path = tinyfd_saveFileDialog(
            "Сохранить файл",
            filename.c_str(),
            0,
            nullptr,
            "Текстовые файлы (*.txt), *.txt"
        );
        std::ofstream ofs(file_path);
        ofs << "TEST\n";
        ofs.close();
    }
}

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