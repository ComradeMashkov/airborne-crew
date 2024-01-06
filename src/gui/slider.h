#pragma once

#include "text_label.h"
#include "../event_handler.h"
#include "../objects/plane.h"

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace gui_wrapper {

class ValueSlider {
public:
    ValueSlider() = default;

    void InitializeSlider(const tgui::Layout2d& position, float minimum, float maximum, float step, TextLabel& slider_label, objects::Plane& plane, bool change_linear);

    tgui::Slider::Ptr GetSlider() const;

private:
    tgui::Slider::Ptr slider_ = tgui::Slider::create();
    const tgui::Layout2d SLIDER_DEFAULT_SIZE = { 100.f, 12.f };
};

} // namespace gui_wrapper