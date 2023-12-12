#pragma once

#include <cstddef>
#include <cstdint>

namespace global_parameters {

// Window
constexpr size_t WIDTH = 800;
constexpr size_t HEIGHT = 600;

// Menu
constexpr size_t MENU_WIDTH = WIDTH;
constexpr size_t MENU_HEIGHT = HEIGHT * 0.035;
constexpr size_t MENU_FONTSIZE = HEIGHT * 0.02;

// Canvas
constexpr size_t CANVAS_WIDTH = WIDTH * 0.6;
constexpr size_t CANVAS_HEIGHT = HEIGHT * 0.6;

// Separator lines
constexpr size_t TW_HLINE_Y = 100;
constexpr size_t LINE_WIDTH = 2;

// Labels
constexpr size_t TT_LABEL_X = WIDTH - 190;
constexpr size_t TT_LABEL_Y = 25;

constexpr size_t TW_LABEL_X = WIDTH - 190;
constexpr size_t TW_LABEL_Y = 120;

constexpr size_t TEXT_LABELS_FONTSIZE = 18;

constexpr size_t COORDS_LABEL_X = 7;
constexpr size_t COORDS_LABEL_Y = HEIGHT - 15;

constexpr size_t FPS_LABEL_X = WIDTH - 75;
constexpr size_t FPS_LABEL_Y = 20;

constexpr size_t DATESTAMP_LABEL_X = WIDTH - 200;
constexpr size_t DATESTAMP_LABEL_Y = 75;
constexpr size_t DATESTAMP_LABEL_FONTSIZE = 14;

constexpr size_t TIMESTAMP_LABEL_X = WIDTH - 210;
constexpr size_t TIMESTAMP_LABEL_Y = 45;
constexpr size_t TIMESTAMP_LABEL_FONTSIZE = 24;

// Colors
struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

constexpr RGB CANVAS_DEFAULT_COLOR = { 211, 211, 211 };
constexpr RGB BACKGROUND_DEFAULT_COLOR = { 255, 255, 255 };

} // namespace global_parameters