#pragma once

#include "gui/canvas.h"
#include "gui/coords.h"
#include "gui/fps.h"
#include "gui/menu.h"
#include "gui/separator.h"
#include "gui/slider.h"
#include "gui/stamp.h"
#include "gui/text_label.h"

#include "../utils/aviation_handler.h"
#include "../utils/weather_handler.h"

namespace gui_wrapper {

class InterfaceBuilder {
public:
    InterfaceBuilder(sf::RenderWindow* window, 
                    tgui::Gui* gui, objects::Plane* plane, 
                    utils::weather_handler::WeatherHandler* weather_handler, 
                    utils::aviation_handler::AviationHandler* aviation_handler);

    void CreateAsyncComponents();
    void CreateAwaitComponents();

    void UpdateFrameRateLabel();
    void UpdateCoordsLabel(const tgui::String& text);
    void UpdateStampLabels();
    void UpdatePlaneCoordsLabel();
    void UpdateCanvas();

private:
    sf::RenderWindow* window_;
    tgui::Gui* gui_;
    objects::Plane* plane_;
    utils::weather_handler::WeatherHandler* weather_handler_;
    utils::aviation_handler::AviationHandler* aviation_handler_;

    gui_wrapper::Canvas canvas_;
    sf::Texture map_texture_;
    sf::Sprite map_sprite_;
    gui_wrapper::FrameRateLabel frame_rate_label_;
    gui_wrapper::CoordsLabel coords_label_;;
    gui_wrapper::TimeStamp time_label_;
    gui_wrapper::DateStamp date_label_;
    gui_wrapper::TextLabel longtitude_label_;
    gui_wrapper::TextLabel latitude_label_;
    gui_wrapper::ValueSlider linear_speed_slider_;
    gui_wrapper::ValueSlider angle_speed_slider_;
    gui_wrapper::TextLabel linear_speed_slider_value_label_;
    gui_wrapper::TextLabel angle_speed_slider_value_label_;

private:
    void CreateMainLines();
    void CreateTimeWeatherHline();
    void CreateFlightsTableLines();
    void CreateCanvas();
    void CreateMapSprite();
    void CreateFrameRateLabel();
    void CreateCoordinateLabel();
    void CreateUpperMenu();
    void CreateStampLabels();
    void CreateTextLabels();
    void CreateWeatherLabels();
    void CreatePlaneCoordsLabel();
    void CreateFlightsTableLabels();
    void CreateSlider();
    void CreateSliderValueLabel();
};

} // namespace gui_wrapper