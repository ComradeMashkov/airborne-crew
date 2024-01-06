#pragma once

#include "../global_parameters.h"
#include "label_base.h"

namespace gui_wrapper {

class CoordsLabel final : public LabelBase {
public:
    CoordsLabel() = default;

    void InitializeLabel() override;

    tgui::Label::Ptr GetLabel() const override;

    void SetLabelText(const tgui::String& text) override;

    void ShowLabel();

private:
    tgui::Label::Ptr label_ = tgui::Label::create();
};

} // namespace gui_wrapper