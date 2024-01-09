#include "stamp.h"

namespace gui_wrapper {

void DateStamp::SetTimezone(const std::string& timezone) {
    timezone_ = timezone;
}

void DateStamp::InitializeLabel() {
    label_->setPosition({ global_parameters::DATESTAMP_LABEL_X, global_parameters::DATESTAMP_LABEL_Y });
    label_->setTextSize(global_parameters::DATESTAMP_LABEL_FONTSIZE);

    year = std::move(std::to_string(1900 + ltm->tm_year));
    month = std::move(std::to_string(ltm->tm_mon));
    day = std::move(std::to_string(ltm->tm_mday));
}

tgui::Label::Ptr DateStamp::GetLabel() const {
    return label_;
}

void DateStamp::SetLabelText(const tgui::String& text) {
    label_->setText(text);
}

void DateStamp::Update() {
    now = time(0);
    ltm = localtime(&now);

    year = std::move(std::to_string(1900 + ltm->tm_year));
    month = (1 + ltm->tm_mon < 10) ? month = std::move("0" + std::to_string(1 + ltm->tm_mon)) : std::move(std::to_string(1 + ltm->tm_mon));
    day = (ltm->tm_mday < 10) ? std::move("0" + std::to_string(ltm->tm_mday)) : std::move(std::to_string(ltm->tm_mday));

    SetLabelText(day + "." + month + "." + year);
}

void TimeStamp::SetTimezone(const std::string& timezone) {
    timezone_ = timezone;
}

void TimeStamp::InitializeLabel() {
    setenv("TZ", timezone_.c_str(), 1);

    label_->setPosition({ global_parameters::TIMESTAMP_LABEL_X, global_parameters::TIMESTAMP_LABEL_Y });
    label_->setTextSize(global_parameters::TIMESTAMP_LABEL_FONTSIZE);

    hour = std::move(std::to_string(ltm->tm_hour));
    minute = std::move(std::to_string(ltm->tm_min));
    second = std::move(std::to_string(ltm->tm_sec));
}

tgui::Label::Ptr TimeStamp::GetLabel() const {
    return label_;
}

void TimeStamp::SetLabelText(const tgui::String& text) {
    label_->setText(text);
}

void TimeStamp::Update() {
    now = time(0);
    ltm = localtime(&now);

    hour = (ltm->tm_hour < 10) ? std::move("0" + std::to_string(ltm->tm_hour)) : std::move(std::to_string(ltm->tm_hour));
    minute = (ltm->tm_min < 10) ? std::move("0" + std::to_string(ltm->tm_min)) : std::move(std::to_string(ltm->tm_min));
    second = (ltm->tm_sec < 10) ? std::move("0" + std::to_string(ltm->tm_sec)) : std::move(std::to_string(ltm->tm_sec));

    SetLabelText(hour + ":" + minute + ":" + second);
}

} // namespace gui_wrapper