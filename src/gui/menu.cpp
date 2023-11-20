#include "menu.h"

using namespace event_handler;

namespace gui_wrapper {

void UpperMenu::InitializeMenu(tgui::Gui& gui, objects::Plane& plane, FrameRateLabel& fps) {
    upper_menu_->setWidth("&.width");
    upper_menu_->setHeight("&.height * 0.035");
    upper_menu_->setAutoLayout(tgui::AutoLayout::Manual);
    upper_menu_->setTextSize(gui.getWindow()->getSize().y * 0.025);

    upper_menu_->addMenu("Program");
    upper_menu_->addMenuItem("Start");
    upper_menu_->onMenuItemClick(&EventHandler::startProgram, std::ref(plane));
    upper_menu_->addMenuItem("Finish");
    upper_menu_->onMenuItemClick(&EventHandler::finishProgram, std::ref(plane));

    upper_menu_->addMenu("Debug");
    upper_menu_->addMenuItem("Show FPS");
    upper_menu_->onMenuItemClick(&EventHandler::showFPS, std::ref(fps));

    upper_menu_->addMenu("Info");
    upper_menu_->addMenuItem("About");
    upper_menu_->onMenuItemClick(&EventHandler::showInfo, std::ref(gui));
}

tgui::MenuBar::Ptr UpperMenu::GetMenu() const {
    return upper_menu_;
}

void UpperMenu::SetSize(tgui::Layout width, tgui::Layout height) {
    upper_menu_->setSize(width, height);
}

void UpperMenu::SetTextSize(unsigned int size) {
    upper_menu_->setTextSize(size);
}

} // namespace gui_wrapper