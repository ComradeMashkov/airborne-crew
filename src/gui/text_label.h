#pragma once

#include "label_base.h"

namespace gui_wrapper {

class TextLabel final : public LabelBase {
public:
    TextLabel() = default;

    void InitializeLabel() override {}

    void InitializeLabel(const tgui::Layout2d &position, int text_size);

    tgui::Label::Ptr GetLabel() const override;

    void SetLabelText(const tgui::String& text) override;

private:
    tgui::Label::Ptr label_ = tgui::Label::create();
};

} // namespace gui_wrapper