#pragma once

#include "../global_parameters.h"
#include "label_base.h"

#include <ctime>

namespace gui_wrapper {

class DateStamp : public LabelBase {
public:
    DateStamp() = default;

    void SetTimezone(const std::string& timezone);

    void InitializeLabel() override;

    tgui::Label::Ptr GetLabel() const override;

    void SetLabelText(const tgui::String& text) override;

    void Update();

private:
    std::string timezone_;

    tgui::Label::Ptr label_ = tgui::Label::create();
    time_t now = time(0);
    tm* ltm = localtime(&now);

    tgui::String year = std::move(std::to_string(1900 + ltm->tm_year));
    tgui::String month = std::move(std::to_string(1 + ltm->tm_mon));
    tgui::String day = std::move(std::to_string(ltm->tm_mday));
};

class TimeStamp : public LabelBase {
public:
    TimeStamp() = default;

    void SetTimezone(const std::string& timezone);

    void InitializeLabel() override;

    tgui::Label::Ptr GetLabel() const override;

    void SetLabelText(const tgui::String& text) override;

    void Update();

private:
    std::string timezone_;

    tgui::Label::Ptr label_ = tgui::Label::create();
    time_t now = time(0);
    tm* ltm = localtime(&now);

    tgui::String hour = std::move(std::to_string(ltm->tm_hour));
    tgui::String minute = std::move(std::to_string(ltm->tm_min));
    tgui::String second = std::move(std::to_string(ltm->tm_sec));
};

} // namespace gui_wrapper