#include "coords.h"

namespace gui_wrapper {

void CoordsLabel::InitializeLabel() {
    label_->setVisible(false);
    label_->setPosition({ global_parameters::COORDS_LABEL_X, global_parameters::COORDS_LABEL_Y });
}

tgui::Label::Ptr CoordsLabel::GetLabel() const {
    return label_;
}

void CoordsLabel::SetLabelText(const tgui::String& text) {
    label_->setText(text);
}

void CoordsLabel::ShowLabel() {
    label_->setVisible(!label_->isVisible());
}

} // namespace gui_wrapper