#include "canvas.h"

namespace gui_wrapper {

void Canvas::InitializeCanvas(std::optional<sf::CircleShape>& circle) {
    canvas_->setHeight("&.height - 22");
    canvas_->setWidth("&.width");
    canvas_->setAutoLayout(tgui::AutoLayout::Bottom);
    canvas_->onMousePress(&moveCircle, std::ref(circle));
}

tgui::CanvasSFML::Ptr Canvas::GetCanvas() const {
    return canvas_;
}

} // namespace gui_wrapper