#include "canvas.h"

using namespace event_handler;

namespace gui_wrapper {

void Canvas::InitializeCanvas(objects::Plane& plane) {
    canvas_->setWidth("&.width * 0.6");
    canvas_->setHeight("&.height * 0.6");
    canvas_->setAutoLayout(tgui::AutoLayout::Manual);
    canvas_->onMousePress(&EventHandler::moveCircle, std::ref(plane));
}

tgui::CanvasSFML::Ptr Canvas::GetCanvas() const {
    return canvas_;
}

void Canvas::SetSize(tgui::Layout width, tgui::Layout height) {
    canvas_->setSize(width, height);
}

void Canvas::SetPosition(tgui::Layout x, tgui::Layout y) {
    canvas_->setPosition(x, y);
}

tgui::Vector2f Canvas::GetSize() const {
    return canvas_->getSize();
}

} // namespace gui_wrapper