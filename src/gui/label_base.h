#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace gui_wrapper {

class LabelBase {
public:
    virtual void InitializeLabel() = 0;
    virtual tgui::Label::Ptr GetLabel() const = 0;
    virtual void SetLabelText(const tgui::String& text) = 0;
};

} // namespace gui_wrapper