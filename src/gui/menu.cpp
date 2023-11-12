#include "menu.h"

namespace gui_wrapper {

void UpperMenu::InitializeMenu(tgui::Gui& gui, std::optional<sf::CircleShape>& circle) {
    upper_menu_->setHeight(22.f);
    upper_menu_->addMenu("Program");
    upper_menu_->addMenuItem("Start");
    upper_menu_->onMenuItemClick(&startProgram, std::ref(circle));
    upper_menu_->addMenuItem("Finish");
    upper_menu_->onMenuItemClick(&finishProgram, std::ref(circle));

    upper_menu_->addMenu("File");
    upper_menu_->addMenuItem("Save");
    upper_menu_->onMenuItemClick(&saveFile, "test.txt");
    upper_menu_->addMenuItem("Clear");

    upper_menu_->addMenu("Info");
    upper_menu_->addMenuItem("About");
    upper_menu_->onMenuItemClick(&showInfo, std::ref(gui));
}

tgui::MenuBar::Ptr UpperMenu::GetMenu() const {
    return upper_menu_;
}

} // namespace gui_wrapper