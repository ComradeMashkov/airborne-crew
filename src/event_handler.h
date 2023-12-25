#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <fstream>

#include "gui/fps.h"
#include "objects/plane.h"
#include "../utils/log_handler.h"

/* 
   Здесь хранятся определения функций, отвечающие за события,
   происходящие во время того или иного действия. За все эти
   события отвечает класс EventHandler и его статические 
   методы. Методы статические, потому что для их вызова
   экземпляр класса не нужен. По сути, класс нам нужен
   лишь как полочка для хранения методов в одном месте.
   В классе присутствует единственное поле - указатель на
   логгер, который вызывается при совершении какого-либо 
   действия (события).
   
   Реализацию смотрите в .cpp файле.
*/

namespace event_handler {

class EventHandler {
public:
    static void showFPS(gui_wrapper::FrameRateLabel& fps, const std::vector<tgui::String>& menuItem);

    static void showInfo (tgui::Gui& gui, const std::vector<tgui::String>& menuItem);

    static void startProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem);

    static void finishProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem);

    static void moveCircle(objects::Plane& plane, const sf::Vector2f& mousePosition);

    static void SetLogger(utils::log_handler::LogHandler* logger);

public:
    static utils::log_handler::LogHandler* logger_;
    static sf::Texture* plane_texture_;
};

} // namespace event_handler