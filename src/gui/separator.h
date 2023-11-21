#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

namespace gui_wrapper {

class Line {
public:
    virtual void InitializeLine(const sf::RenderWindow& window) = 0;

    virtual void SetPosition(tgui::Layout x, tgui::Layout y) = 0;

    virtual void SetSize(tgui::Layout width, tgui::Layout height) = 0;

    virtual tgui::Panel::Ptr GetLine() const = 0;

    virtual sf::Vector2f GetSize() const = 0;

    virtual ~Line() {}
};

class VerticalLine final : public Line {
public:
    VerticalLine() = default;

    void InitializeLine(const sf::RenderWindow& window) override;

    void SetPosition(tgui::Layout x, tgui::Layout y) override;

    void SetSize(tgui::Layout width, tgui::Layout height) override;

    tgui::Panel::Ptr GetLine() const override;

    sf::Vector2f GetSize() const override;

private:
    tgui::Panel::Ptr line_ = tgui::Panel::create();
};

class HorizontalLine final : public Line {
public:
    HorizontalLine() = default;

    void InitializeLine(const sf::RenderWindow& window) override;

    void SetPosition(tgui::Layout x, tgui::Layout y) override;

    void SetSize(tgui::Layout width, tgui::Layout height) override;

    tgui::Panel::Ptr GetLine() const override;

    sf::Vector2f GetSize() const override;

private:
    tgui::Panel::Ptr line_ = tgui::Panel::create();
};

} // namespace gui_wrapper