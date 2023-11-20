#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace gui_wrapper {

class Line {
public:
    virtual void InitializeLine(const sf::RenderWindow& window) = 0;

    virtual tgui::Panel::Ptr GetLine() const = 0;

    virtual ~Line() {}
};

class VerticalLine final : public Line {
public:
    VerticalLine() = default;

    void InitializeLine(const sf::RenderWindow& window) override;

    tgui::Panel::Ptr GetLine() const override;

private:
    tgui::Panel::Ptr line_ = tgui::Panel::create();
};

class HorizontalLine final : public Line {
public:
    HorizontalLine() = default;

    void InitializeLine(const sf::RenderWindow& window) override;

    tgui::Panel::Ptr GetLine() const override;

private:
    tgui::Panel::Ptr line_ = tgui::Panel::create();
};

} // namespace gui_wrapper