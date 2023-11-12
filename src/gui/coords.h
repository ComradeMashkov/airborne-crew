#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace gui_wrapper {

class CoordsLabel {
public:
    CoordsLabel() = default;

    void InitializeCoordsLabel();

    void SetLabelText(const tgui::String& text);

    tgui::Label::Ptr GetLabel() const;

private:
    tgui::Label::Ptr label_ = tgui::Label::create();
};

} // namespace gui_wrapper