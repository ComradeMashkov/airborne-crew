#pragma once

#include "../event_handler.h"

namespace gui_wrapper {

class Canvas {
public:
    Canvas() = default;

    void InitializeCanvas(objects::Plane& plane);

    tgui::CanvasSFML::Ptr GetCanvas() const;

    void SetSize(tgui::Layout width, tgui::Layout height);

    void SetPosition(tgui::Layout x, tgui::Layout y);

    tgui::Vector2f GetSize() const;

private:
    tgui::CanvasSFML::Ptr canvas_ = tgui::CanvasSFML::create({ 400, 300 });
};

} // namespace gui_wrapper