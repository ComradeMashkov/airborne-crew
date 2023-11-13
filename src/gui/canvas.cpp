#include "canvas.h"

using namespace event_handler;

namespace gui_wrapper {

void Canvas::InitializeCanvas(objects::Plane& plane) {
    canvas_->setHeight("&.height - 22");
    canvas_->setWidth("&.width");
    canvas_->setAutoLayout(tgui::AutoLayout::Bottom);
    canvas_->onMousePress(&EventHandler::moveCircle, std::ref(plane));
}

tgui::CanvasSFML::Ptr Canvas::GetCanvas() const {
    return canvas_;
}

} // namespace gui_wrapper