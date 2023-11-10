#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <fstream>
#include <tinyfiledialogs.h>

// Info

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

// Program

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

// File

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

// Graphics

void moveCircle(std::optional<sf::CircleShape>& circle, const sf::Vector2f& posMouse) {
    if (circle.has_value()) {
        sf::Vector2f posCircle{ circle.value().getRadius(), circle.value().getRadius() };
        circle.value().setPosition(posMouse - posCircle);
    }
}