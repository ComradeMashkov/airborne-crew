#pragma once

#include "../domain_functions.h"

namespace gui_wrapper {

class Canvas {
public:
    Canvas() = default;

    void InitializeCanvas(std::optional<sf::CircleShape>& circle);

    tgui::CanvasSFML::Ptr GetCanvas() const;

private:
    tgui::CanvasSFML::Ptr canvas_ = tgui::CanvasSFML::create({ 400, 300 });
};

} // namespace gui_wrapper