#pragma once

#include <cstddef>
#include <cstdint>

namespace global_parameters {

// Window
constexpr size_t WIDTH = 800;
constexpr size_t HEIGHT = 600;

constexpr unsigned int MAX_FPS = 60;

// Menu
constexpr size_t MENU_WIDTH = WIDTH;
constexpr size_t MENU_HEIGHT = HEIGHT * 0.035;
constexpr size_t MENU_FONTSIZE = HEIGHT * 0.02;

// Canvas
constexpr size_t CANVAS_WIDTH = WIDTH * 0.6;
constexpr size_t CANVAS_HEIGHT = HEIGHT * 0.6;

// Separator lines
constexpr size_t LINE_WIDTH = 2;

constexpr size_t TW_HLINE_Y = 100;

constexpr size_t AT_HLINE_X = 320;
constexpr size_t AT_HLINE_Y = 540;
constexpr size_t AT_HLINE_LENGTH = WIDTH - AT_HLINE_X;
constexpr size_t AT_HLINE_OFFSET = 60;

constexpr size_t AT_VLINE_X = 680;
constexpr size_t AT_VLINE_Y = 360;
constexpr size_t AT_VLINE_LENGTH = 240;
constexpr size_t AT_VLINE_OFFSET = 120;

constexpr size_t MAIN_HLINE_Y = CANVAS_HEIGHT;
constexpr size_t MAIN_HLINE_LENGTH = WIDTH - AT_HLINE_LENGTH;

constexpr size_t MAIN_VLINE_X = CANVAS_WIDTH;
constexpr size_t MAIN_VLINE_LENGTH = CANVAS_HEIGHT;

// Plane
constexpr float PLANE_INITIAL_POS_X = 100.f;
constexpr float PLANE_INITIAL_POS_Y = 100.f;

constexpr int PLANE_ANGLE_ROTATION_X = 480;
constexpr int PLANE_ANGLE_ROTATION_Y = 360;

constexpr float PLANE_ROTATION_COEFFICIENT_X = 0.61268f;
constexpr float PLANE_ROTATION_COEFFICIENT_Y = -0.36113f;

constexpr float PLANE_INITIAL_ANGLE_POS_X = -77.347776f;
constexpr float PLANE_INITIAL_ANGLE_POS_Y = 39.089530f;

constexpr float PLANE_CRITICAL_ANGLE = 0.02f;

// Labels
constexpr size_t TT_LABEL_X = WIDTH - 190;
constexpr size_t TT_LABEL_Y = 25;

constexpr size_t TW_LABEL_X = WIDTH - 190;
constexpr size_t TW_LABEL_Y = 120;

constexpr size_t TEMP_TEXT_LABEL_X = WIDTH - 300;
constexpr size_t TEMP_TEXT_LABEL_Y = 160;

constexpr size_t TEMP_LABEL_X = TEMP_TEXT_LABEL_X + 20;
constexpr size_t TEMP_LABEL_Y = TEMP_TEXT_LABEL_Y + 20;

constexpr size_t PRESSURE_TEXT_LABEL_X = WIDTH - 190;
constexpr size_t PRESSURE_TEXT_LABEL_Y = 160;

constexpr size_t PRESSURE_LABEL_X = PRESSURE_TEXT_LABEL_X;
constexpr size_t PRESSURE_LABEL_Y = PRESSURE_TEXT_LABEL_Y + 20;

constexpr size_t HUMIDITY_TEXT_LABEL_X = WIDTH - 100;
constexpr size_t HUMIDITY_TEXT_LABEL_Y = 160;

constexpr size_t HUMIDITY_LABEL_X = HUMIDITY_TEXT_LABEL_X + 15;
constexpr size_t HUMIDITY_LABEL_Y = HUMIDITY_TEXT_LABEL_Y + 20;

constexpr size_t WIND_SPEED_TEXT_LABEL_X = WIDTH - 300;
constexpr size_t WIND_SPEED_TEXT_LABEL_Y = 220;

constexpr size_t WIND_SPEED_LABEL_X = WIND_SPEED_TEXT_LABEL_X + 120;
constexpr size_t WIND_SPEED_LABEL_Y = WIND_SPEED_TEXT_LABEL_Y;

constexpr size_t WIND_DIR_LABEL_X = WIND_SPEED_LABEL_X + 100;
constexpr size_t WIND_DIR_LABEL_Y = WIND_SPEED_LABEL_Y;

constexpr size_t TIMES_OF_DAY_TEXT_LABEL_X = WIDTH - 200;
constexpr size_t TIMES_OF_DAY_TEXT_LABEL_Y = 280;

constexpr float MAP_TOP_COORDINATES = 39.089530f;
constexpr float MAP_LEFT_COORDINATES = -77.347776f;
constexpr float MAP_WIDTH = 0.61268f;
constexpr float MAP_HEIGHT = -0.36113f;

constexpr size_t TIMES_OF_DAY_LABEL_X = TIMES_OF_DAY_TEXT_LABEL_X + 20;
constexpr size_t TIMES_OF_DAY_LABEL_Y = TIMES_OF_DAY_TEXT_LABEL_Y + 20;

constexpr size_t TEXT_LABELS_FONTSIZE = 18;
constexpr size_t SUBTEXT_LABELS_FONTSIZE = 12;

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

constexpr size_t FLIGHT_NUMBER_TEXT_LABEL_X = 340;
constexpr size_t FLIGHT_NUMBER_TEXT_LABEL_Y = 385;

constexpr size_t FLIGHT_NUMBER_LABEL_X = 355;

constexpr size_t DEPARTURE_TIME_TEXT_LABEL_X = 455;
constexpr size_t DEPARTURE_TIME_TEXT_LABEL_Y = FLIGHT_NUMBER_TEXT_LABEL_Y;

constexpr size_t DEPARTURE_TIME_LABEL_X = 475;

constexpr size_t ARRIVAL_TIME_TEXT_LABEL_X = 570;
constexpr size_t ARRIVAL_TIME_TEXT_LABEL_Y = FLIGHT_NUMBER_TEXT_LABEL_Y;

constexpr size_t ARRIVAL_TIME_LABEL_X = 595;

constexpr size_t FLIGHT_STATUS_TEXT_LABEL_X = 700;
constexpr size_t FLIGHT_STATUS_TEXT_LABEL_Y = FLIGHT_NUMBER_TEXT_LABEL_Y;

constexpr size_t FLIGHT_STATUS_LABEL_X = 710;

constexpr size_t AVIATION_PARAMETERS_START_Y = 445;
constexpr size_t AVIATION_PARAMETERS_OFFSET = 60;

constexpr size_t PLANE_INFO_TEXT_LABEL_X = 40;
constexpr size_t PLANE_INFO_TEXT_LABEL_Y = 390;

constexpr size_t LONGTITUDE_TEXT_LABEL_X = 15;
constexpr size_t LONGTITUDE_TEXT_LABEL_Y = 435;

constexpr size_t LONGTITUDE_LABEL_X = LONGTITUDE_TEXT_LABEL_X + 70;
constexpr size_t LONGTITUDE_LABEL_Y = LONGTITUDE_TEXT_LABEL_Y;

constexpr size_t LATITUDE_TEXT_LABEL_X = LONGTITUDE_TEXT_LABEL_X;
constexpr size_t LATITUDE_TEXT_LABEL_Y = LONGTITUDE_TEXT_LABEL_Y + 30;

constexpr size_t LATITUDE_LABEL_X = LONGTITUDE_LABEL_X;
constexpr size_t LATITUDE_LABEL_Y = LATITUDE_TEXT_LABEL_Y;

constexpr size_t LINEAR_SPEED_TEXT_LABEL_X = LONGTITUDE_TEXT_LABEL_X;
constexpr size_t LINEAR_SPEED_TEXT_LABEL_Y = LATITUDE_TEXT_LABEL_Y + 50;

constexpr size_t ANGLE_SPEED_TEXT_LABEL_X = LONGTITUDE_TEXT_LABEL_X;
constexpr size_t ANGLE_SPEED_TEXT_LABEL_Y = LINEAR_SPEED_TEXT_LABEL_Y + 30;

// Sliders
constexpr size_t LINEAR_SPEED_SLIDER_X = LINEAR_SPEED_TEXT_LABEL_X + 150;
constexpr size_t LINEAR_SPEED_SLIDER_Y = LINEAR_SPEED_TEXT_LABEL_Y;

constexpr float LINEAR_SPEED_SLIDER_MINIMUM = 0.f;
constexpr float LINEAR_SPEED_SLIDER_MAXIMUM = 5.f;
constexpr float LINEAR_SPEED_SLIDER_STEP = 0.05f;

constexpr size_t ANGLE_SPEED_SLIDER_X = LINEAR_SPEED_SLIDER_X;
constexpr size_t ANGLE_SPEED_SLIDER_Y = ANGLE_SPEED_TEXT_LABEL_Y;

constexpr float ANGLE_SPEED_SLIDER_MINIMUM = 0.f;
constexpr float ANGLE_SPEED_SLIDER_MAXIMUM = 0.2f;
constexpr float ANGLE_SPEED_SLIDER_STEP = 0.005f;

constexpr size_t LINEAR_SPEED_SLIDER_VALUE_LABEL_X = LINEAR_SPEED_SLIDER_X + 110;
constexpr size_t LINEAR_SPEED_SLIDER_VALUE_LABEL_Y = LINEAR_SPEED_SLIDER_Y;

constexpr size_t ANGLE_SPEED_SLIDER_VALUE_LABEL_X = LINEAR_SPEED_SLIDER_VALUE_LABEL_X;
constexpr size_t ANGLE_SPEED_SLIDER_VALUE_LABEL_Y = ANGLE_SPEED_SLIDER_Y;

// Colors
struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

constexpr RGB CANVAS_DEFAULT_COLOR = { 211, 211, 211 };
constexpr RGB BACKGROUND_DEFAULT_COLOR = { 255, 255, 255 };

} // namespace global_parameters