#include "gui_builder.h"

using namespace global_parameters;

namespace gui_wrapper {

InterfaceBuilder::InterfaceBuilder(sf::RenderWindow* window, 
                                   tgui::Gui* gui, objects::Plane* plane, 
                                   utils::weather_handler::WeatherHandler* weather_handler,
                                   utils::aviation_handler::AviationHandler* aviation_handler) 
    : window_(window)
    , gui_(gui)
    , plane_(plane)
    , weather_handler_(weather_handler)
    , aviation_handler_(aviation_handler) {
}

void InterfaceBuilder::CreateAsyncComponents() {
    CreateMainLines();
    CreateTimeWeatherHline();
    CreateFlightsTableLines();
    CreateCanvas();
    CreateMapSprite();
    CreateFrameRateLabel();
    CreateCoordinateLabel();
    CreateUpperMenu();
    CreateStampLabels();
    CreateTextLabels();
    CreatePlaneCoordsLabel();
    CreateSliderValueLabel();
    CreateSlider();
}

void InterfaceBuilder::CreateAwaitComponents() {
    CreateWeatherLabels();
    CreateFlightsTableLabels();
}

void InterfaceBuilder::CreateMainLines() {
    HorizontalLine main_hline;
    main_hline.InitializeLine(0, MAIN_HLINE_Y, MAIN_HLINE_LENGTH, LINE_WIDTH);
    gui_->add(main_hline.GetLine());

    VerticalLine main_vline;
    main_vline.InitializeLine(MAIN_VLINE_X, 0, MAIN_VLINE_LENGTH, LINE_WIDTH);
    gui_->add(main_vline.GetLine());
}

void InterfaceBuilder::CreateTimeWeatherHline() {
    HorizontalLine time_weather_hline;
    time_weather_hline.InitializeLine(0, TW_HLINE_Y, window_->getSize().x, LINE_WIDTH);
    gui_->add(time_weather_hline.GetLine());
}

void InterfaceBuilder::CreateFlightsTableLines() {
    // Horizontal lines
    std::array<HorizontalLine, 4> aviation_table_hlines;
    for (int i = 0; i < 4; ++i) {
        aviation_table_hlines[i].InitializeLine(AT_HLINE_X, AT_HLINE_Y - i * AT_HLINE_OFFSET, AT_HLINE_LENGTH, LINE_WIDTH);
        gui_->add(aviation_table_hlines[i].GetLine());
    }

    // Vertical lines
    std::array<VerticalLine, 4> aviation_table_vlines;
    for (int i = 0; i < 4; ++i) {
        aviation_table_vlines[i].InitializeLine(AT_VLINE_X - AT_VLINE_OFFSET * i, AT_VLINE_Y, AT_VLINE_LENGTH, LINE_WIDTH);
        gui_->add(aviation_table_vlines[i].GetLine());
    }
}

void InterfaceBuilder::CreateCanvas() {
    canvas_.InitializeCanvas(*plane_);
    gui_->add(canvas_.GetCanvas());
}

void InterfaceBuilder::CreateMapSprite() {
    map_texture_.loadFromFile("../meta/map.png");
    map_sprite_.setTexture(map_texture_);
}

void InterfaceBuilder::CreateFrameRateLabel() {
    frame_rate_label_.InitializeLabel();
    gui_->add(frame_rate_label_.GetLabel());
}

void InterfaceBuilder::CreateCoordinateLabel() {
    coords_label_.InitializeLabel();
    gui_->add(coords_label_.GetLabel());
}

void InterfaceBuilder::CreateUpperMenu() {
    UpperMenu menu;
    menu.InitializeMenu(*gui_, *plane_, frame_rate_label_, coords_label_);
    gui_->add(menu.GetMenu());
}

void InterfaceBuilder::CreateStampLabels() {
    time_label_.InitializeLabel();
    gui_->add(time_label_.GetLabel());

    date_label_.InitializeLabel();
    gui_->add(date_label_.GetLabel());
}

void InterfaceBuilder::CreateTextLabels() {
    TextLabel time_text_label;
    time_text_label.SetLabelText("Время");
    time_text_label.InitializeLabel({ TT_LABEL_X, TT_LABEL_Y }, TEXT_LABELS_FONTSIZE);
    gui_->add(time_text_label.GetLabel());

    TextLabel weather_text_label;
    weather_text_label.SetLabelText("Погода");
    weather_text_label.InitializeLabel({ TW_LABEL_X, TW_LABEL_Y }, TEXT_LABELS_FONTSIZE);
    gui_->add(weather_text_label.GetLabel());

    TextLabel temperature_text_label;
    temperature_text_label.SetLabelText("Температура");
    temperature_text_label.InitializeLabel({ TEMP_TEXT_LABEL_X, TEMP_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(temperature_text_label.GetLabel());

    TextLabel pressure_text_label;
    pressure_text_label.SetLabelText("Давление");
    pressure_text_label.InitializeLabel({ PRESSURE_TEXT_LABEL_X, PRESSURE_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(pressure_text_label.GetLabel());

    TextLabel humidity_text_label;
    humidity_text_label.SetLabelText("Влажность");
    humidity_text_label.InitializeLabel({ HUMIDITY_TEXT_LABEL_X, HUMIDITY_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(humidity_text_label.GetLabel());

    TextLabel wind_speed_text_label;
    wind_speed_text_label.SetLabelText("Скорость ветра");
    wind_speed_text_label.InitializeLabel({ WIND_SPEED_TEXT_LABEL_X, WIND_SPEED_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(wind_speed_text_label.GetLabel());

    TextLabel times_of_day_text_label;
    times_of_day_text_label.SetLabelText("Время суток");
    times_of_day_text_label.InitializeLabel({ TIMES_OF_DAY_TEXT_LABEL_X, TIMES_OF_DAY_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(times_of_day_text_label.GetLabel());

    TextLabel flight_number_text_label;
    flight_number_text_label.SetLabelText("Номер рейса");
    flight_number_text_label.InitializeLabel({ FLIGHT_NUMBER_TEXT_LABEL_X, FLIGHT_NUMBER_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(flight_number_text_label.GetLabel());

    TextLabel departure_time_text_label;
    departure_time_text_label.SetLabelText("Время вылета");
    departure_time_text_label.InitializeLabel({ DEPARTURE_TIME_TEXT_LABEL_X, DEPARTURE_TIME_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(departure_time_text_label.GetLabel());

    TextLabel arrival_time_text_label;
    arrival_time_text_label.SetLabelText("Время прилета");
    arrival_time_text_label.InitializeLabel({ ARRIVAL_TIME_TEXT_LABEL_X, ARRIVAL_TIME_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(arrival_time_text_label.GetLabel());

    TextLabel flight_status_text_label;
    flight_status_text_label.SetLabelText("Статус рейса");
    flight_status_text_label.InitializeLabel({ FLIGHT_STATUS_TEXT_LABEL_X, FLIGHT_STATUS_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(flight_status_text_label.GetLabel());

    TextLabel plane_info_text_label;
    plane_info_text_label.SetLabelText("Информация о самолете");
    plane_info_text_label.InitializeLabel({ PLANE_INFO_TEXT_LABEL_X, PLANE_INFO_TEXT_LABEL_Y }, TEXT_LABELS_FONTSIZE);
    gui_->add(plane_info_text_label.GetLabel());

    TextLabel longtitude_text_label;
    longtitude_text_label.SetLabelText("Долгота");
    longtitude_text_label.InitializeLabel({ LONGTITUDE_TEXT_LABEL_X, LONGTITUDE_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(longtitude_text_label.GetLabel());

    TextLabel latitude_text_label;
    latitude_text_label.SetLabelText("Широта");
    latitude_text_label.InitializeLabel({ LATITUDE_TEXT_LABEL_X, LATITUDE_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(latitude_text_label.GetLabel());

    TextLabel linear_speed_text_label;
    linear_speed_text_label.SetLabelText("Линейная скорость");
    linear_speed_text_label.InitializeLabel({ LINEAR_SPEED_TEXT_LABEL_X, LINEAR_SPEED_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(linear_speed_text_label.GetLabel());

    TextLabel angle_speed_text_label;
    angle_speed_text_label.SetLabelText("Угловая скорость");
    angle_speed_text_label.InitializeLabel({ ANGLE_SPEED_TEXT_LABEL_X, ANGLE_SPEED_TEXT_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(angle_speed_text_label.GetLabel());
}

void InterfaceBuilder::CreateWeatherLabels() {
    TextLabel temperature_label;
    temperature_label.SetLabelText(weather_handler_->temperature + " °C");
    temperature_label.InitializeLabel({ TEMP_LABEL_X, TEMP_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(temperature_label.GetLabel());

    TextLabel pressure_label;
    pressure_label.SetLabelText(weather_handler_->pressure + "  мбар");
    pressure_label.InitializeLabel({ PRESSURE_LABEL_X, PRESSURE_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(pressure_label.GetLabel());

    TextLabel humidity_label;
    humidity_label.SetLabelText(weather_handler_->humidity + " %");
    humidity_label.InitializeLabel({ HUMIDITY_LABEL_X, HUMIDITY_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(humidity_label.GetLabel());

    TextLabel wind_speed_label;
    wind_speed_label.SetLabelText(weather_handler_->wind_speed + " км/ч");
    wind_speed_label.InitializeLabel({ WIND_SPEED_LABEL_X, WIND_SPEED_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(wind_speed_label.GetLabel());

    TextLabel wind_dir_label;
    wind_dir_label.SetLabelText(weather_handler_->wind_dir);
    wind_dir_label.InitializeLabel({ WIND_DIR_LABEL_X, WIND_DIR_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(wind_dir_label.GetLabel());

    TextLabel times_of_day_label;
    times_of_day_label.SetLabelText(weather_handler_->times_of_day);
    times_of_day_label.InitializeLabel({ TIMES_OF_DAY_LABEL_X, TIMES_OF_DAY_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(times_of_day_label.GetLabel());
}

void InterfaceBuilder::CreatePlaneCoordsLabel() {
    longtitude_label_.SetLabelText(plane_->longtitude);
    longtitude_label_.InitializeLabel({ LONGTITUDE_LABEL_X, LONGTITUDE_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(longtitude_label_.GetLabel());

    latitude_label_.SetLabelText(plane_->latitude);
    latitude_label_.InitializeLabel({ LATITUDE_LABEL_X, LATITUDE_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(latitude_label_.GetLabel());
}

void InterfaceBuilder::CreateFlightsTableLabels() {
    for (int i = 0; i < aviation_handler_->fcount; ++i) {
        TextLabel flight_number_label;
        flight_number_label.SetLabelText(aviation_handler_->flight_numbers[i]);
        flight_number_label.InitializeLabel({ FLIGHT_NUMBER_LABEL_X, AVIATION_PARAMETERS_START_Y + AVIATION_PARAMETERS_OFFSET * i }, SUBTEXT_LABELS_FONTSIZE);
        gui_->add(flight_number_label.GetLabel());

        TextLabel departure_time_label;
        departure_time_label.SetLabelText(aviation_handler_->departure_times[i]);
        departure_time_label.InitializeLabel({ DEPARTURE_TIME_LABEL_X, AVIATION_PARAMETERS_START_Y + AVIATION_PARAMETERS_OFFSET * i }, SUBTEXT_LABELS_FONTSIZE);
        gui_->add(departure_time_label.GetLabel());

        TextLabel arrival_time_label;
        arrival_time_label.SetLabelText(aviation_handler_->arrival_times[i]);
        arrival_time_label.InitializeLabel({ ARRIVAL_TIME_LABEL_X, AVIATION_PARAMETERS_START_Y + AVIATION_PARAMETERS_OFFSET * i }, SUBTEXT_LABELS_FONTSIZE);
        gui_->add(arrival_time_label.GetLabel());

        TextLabel flight_status_label;
        flight_status_label.SetLabelText(aviation_handler_->flight_statuses[i]);
        flight_status_label.InitializeLabel({ FLIGHT_STATUS_LABEL_X, AVIATION_PARAMETERS_START_Y + AVIATION_PARAMETERS_OFFSET * i }, SUBTEXT_LABELS_FONTSIZE);
        gui_->add(flight_status_label.GetLabel());
    }
}

void InterfaceBuilder::CreateSlider() {
    linear_speed_slider_.InitializeSlider({ LINEAR_SPEED_SLIDER_X, LINEAR_SPEED_SLIDER_Y }, LINEAR_SPEED_SLIDER_MINIMUM, LINEAR_SPEED_SLIDER_MAXIMUM, LINEAR_SPEED_SLIDER_STEP, linear_speed_slider_value_label_, *plane_, true);
    gui_->add(linear_speed_slider_.GetSlider());

    angle_speed_slider_.InitializeSlider({ ANGLE_SPEED_SLIDER_X, ANGLE_SPEED_SLIDER_Y }, ANGLE_SPEED_SLIDER_MINIMUM, ANGLE_SPEED_SLIDER_MAXIMUM, ANGLE_SPEED_SLIDER_STEP, angle_speed_slider_value_label_, *plane_, false);
    gui_->add(angle_speed_slider_.GetSlider());
}

void InterfaceBuilder::CreateSliderValueLabel() {
    linear_speed_slider_value_label_.SetLabelText(objects::Plane::FloatToStringWithPrecision(LINEAR_SPEED_SLIDER_MINIMUM));
    linear_speed_slider_value_label_.InitializeLabel({ LINEAR_SPEED_SLIDER_VALUE_LABEL_X, LINEAR_SPEED_SLIDER_VALUE_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(linear_speed_slider_value_label_.GetLabel());

    angle_speed_slider_value_label_.SetLabelText(objects::Plane::FloatToStringWithPrecision(ANGLE_SPEED_SLIDER_MINIMUM));
    angle_speed_slider_value_label_.InitializeLabel({ ANGLE_SPEED_SLIDER_VALUE_LABEL_X, ANGLE_SPEED_SLIDER_VALUE_LABEL_Y }, SUBTEXT_LABELS_FONTSIZE);
    gui_->add(angle_speed_slider_value_label_.GetLabel());
}

void InterfaceBuilder::UpdateFrameRateLabel() {
    frame_rate_label_.CalculateFrameRate();
}

void InterfaceBuilder::UpdateCoordsLabel(const tgui::String& text) {
    coords_label_.SetLabelText(text);
}

void InterfaceBuilder::UpdateStampLabels() {
    time_label_.Update();
    date_label_.Update();
}

void InterfaceBuilder::UpdatePlaneCoordsLabel() {
    longtitude_label_.SetLabelText(plane_->longtitude);
    latitude_label_.SetLabelText(plane_->latitude);
}

void InterfaceBuilder::UpdateCanvas() {
    canvas_.GetCanvas()->clear(sf::Color{ CANVAS_DEFAULT_COLOR.r, CANVAS_DEFAULT_COLOR.g, CANVAS_DEFAULT_COLOR.b });
    canvas_.GetCanvas()->draw(map_sprite_);
    if (plane_->GetToDraw()) {
        canvas_.GetCanvas()->draw(plane_->GetPrimitive()); 
    }
    canvas_.GetCanvas()->display();
}

} // namespace gui_wrapper