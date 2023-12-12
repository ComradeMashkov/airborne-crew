#pragma once

#include "../global_parameters.h"
#include "label_base.h"

namespace gui_wrapper {

class FrameRateLabel final : public LabelBase {
public:
    FrameRateLabel() = default;

    void InitializeLabel() override;

    tgui::Label::Ptr GetLabel() const override;

    void SetLabelText(const tgui::String& text) override;

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