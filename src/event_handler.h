#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <fstream>
#include <tinyfiledialogs.h>

#include "gui/fps.h"
#include "objects/plane.h"

namespace event_handler {

class EventHandler {
public:
    // Debug

    static void showFPS(gui_wrapper::FrameRateLabel& fps, const std::vector<tgui::String>& menuItem);

    // Info

    static void showInfo (tgui::Gui& gui, const std::vector<tgui::String>& menuItem);

    // Program

    static void startProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem);

    static void finishProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem);

    // File

    static void saveFile(const std::string& filename, const std::vector<tgui::String>& menuItem);

    // Graphics

    static void moveCircle(objects::Plane& plane, const sf::Vector2f& mousePosition);
};

} // namespace event_handler