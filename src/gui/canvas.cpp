#include "canvas.h"

using namespace event_handler;

namespace gui_wrapper {

void Canvas::InitializeCanvas(objects::Plane& plane) {
    canvas_->setWidth(global_parameters::CANVAS_WIDTH);
    canvas_->setHeight(global_parameters::CANVAS_HEIGHT);
    canvas_->setAutoLayout(tgui::AutoLayout::Manual);
    canvas_->onMousePress(&EventHandler::movePlane, std::ref(plane));
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