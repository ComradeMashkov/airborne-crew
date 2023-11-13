#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace gui_wrapper {

class FrameRateLabel {
public:
    FrameRateLabel() = default;

    void InitializeFrameRateLabel();

    tgui::Label::Ptr GetLabel() const;

    float GetFrameRate() const;

    void CalculateFrameRate();

    void ShowLabel();

private:
    tgui::Label::Ptr label_ = tgui::Label::create();
    sf::Clock frame_clock_;
    int frame_count_ = 0;
    float frame_rate_ = 0.f;
};

} // namespace gui_wrapper