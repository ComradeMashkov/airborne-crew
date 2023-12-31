#pragma once

#include "fps.h"
#include "../event_handler.h"
#include "../global_parameters.h"
#include "../objects/plane.h"

namespace gui_wrapper {

class UpperMenu {
public:
    UpperMenu() = default;

    void InitializeMenu(tgui::Gui& gui, objects::Plane& plane, FrameRateLabel& fps, CoordsLabel& coords_label);

    tgui::MenuBar::Ptr GetMenu() const;

private:
    tgui::MenuBar::Ptr upper_menu_ = tgui::MenuBar::create();
};

} // namespace gui_wrapper