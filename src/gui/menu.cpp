#include "menu.h"

using namespace event_handler;

namespace gui_wrapper {

void UpperMenu::InitializeMenu(tgui::Gui& gui, objects::Plane& plane, FrameRateLabel& fps) {
    upper_menu_->setWidth(global_parameters::MENU_WIDTH);
    upper_menu_->setHeight(global_parameters::MENU_HEIGHT);
    upper_menu_->setAutoLayout(tgui::AutoLayout::Manual);
    upper_menu_->setTextSize(global_parameters::MENU_FONTSIZE);

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

} // namespace gui_wrapper