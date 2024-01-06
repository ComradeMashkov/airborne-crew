#include "slider.h"

namespace gui_wrapper {

void ValueSlider::InitializeSlider(const tgui::Layout2d& position, float minimum, float maximum, float step, TextLabel& slider_label, objects::Plane& plane, bool change_linear) {
    slider_->setPosition(position);
    slider_->setMinimum(minimum);
    slider_->setMaximum(maximum);
    slider_->setSize(SLIDER_DEFAULT_SIZE);
    slider_->setStep(step);

    slider_->onValueChange.connect(&event_handler::EventHandler::changeSliderValue, std::ref(slider_label), std::ref(plane), change_linear);
}

tgui::Slider::Ptr ValueSlider::GetSlider() const {
    return slider_;
}

} // namespace gui_wrapper