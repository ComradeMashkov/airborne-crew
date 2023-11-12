#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <fstream>
#include <tinyfiledialogs.h>

#include "objects/plane.h"

// Info

void showInfo (tgui::Gui& gui, const std::vector<tgui::String>& menuItem);

// Program

void startProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem);

void finishProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem);

// File

void saveFile(const std::string& filename, const std::vector<tgui::String>& menuItem);

// Graphics

void moveCircle(objects::Plane& plane, const sf::Vector2f& mousePosition);