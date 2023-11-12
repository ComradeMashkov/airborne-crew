#include "coords.h"

namespace gui_wrapper {

void CoordsLabel::InitializeCoordsLabel() {
    label_->setPosition({ "&.left + 7", "&.bottom - 15" });
}

void CoordsLabel::SetLabelText(const tgui::String& text) {
    label_->setText(text);
}

tgui::Label::Ptr CoordsLabel::GetLabel() const {
    return label_;
}

} // namespace gui_wrapper