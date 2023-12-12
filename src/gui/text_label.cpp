#include "text_label.h"

namespace gui_wrapper {

void TextLabel::InitializeLabel(const tgui::Layout2d &position, int text_size) {
    label_->setPosition(position);
    label_->setTextSize(text_size);
}

tgui::Label::Ptr TextLabel::GetLabel() const {
    return label_;
}

void TextLabel::SetLabelText(const tgui::String& text) {
    label_->setText(text);
}

} // namespace gui_wrapper