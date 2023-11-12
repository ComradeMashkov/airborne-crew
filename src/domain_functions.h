#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <fstream>
#include <tinyfiledialogs.h>

// Info

void showInfo (tgui::Gui& gui, const std::vector<tgui::String>& menuItem);

// Program

void startProgram(std::optional<sf::CircleShape>& circle, const std::vector<tgui::String>& menuItem);

void finishProgram(std::optional<sf::CircleShape>& circle, const std::vector<tgui::String>& menuItem);

// File

void saveFile(const std::string& filename, const std::vector<tgui::String>& menuItem);

// Graphics

void moveCircle(std::optional<sf::CircleShape>& circle, const sf::Vector2f& posMouse);