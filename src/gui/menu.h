#pragma once

#include "../domain_functions.h"

namespace gui_wrapper {

class UpperMenu {
public:
    UpperMenu() = default;

    void InitializeMenu(tgui::Gui& gui, std::optional<sf::CircleShape>& circle);

    tgui::MenuBar::Ptr GetMenu() const;

private:
    tgui::MenuBar::Ptr upper_menu_ = tgui::MenuBar::create();
};

} // namespace gui_wrapper