#include "fps.h"

namespace gui_wrapper {

void FrameRateLabel::InitializeFrameRateLabel() {
    label_->setPosition({ "&.right - 75", "&.top + 25" });
}

tgui::Label::Ptr FrameRateLabel::GetLabel() const {
    return label_;
}

float FrameRateLabel::GetFrameRate() const {
    return frame_rate_;
}

void FrameRateLabel::CalculateFrameRate() {
    if (frame_clock_.getElapsedTime().asSeconds() >= 1.0f) {
        frame_rate_ = static_cast<float>(frame_count_) / frame_clock_.restart().asSeconds();
        frame_count_ = 0;
        label_->setText("FPS " + std::to_string(static_cast<int>(frame_rate_)));
    }
    ++frame_count_;
}

void FrameRateLabel::ShowLabel() {
    label_->setVisible(!label_->isVisible());
}

} // namespace gui_wrapper