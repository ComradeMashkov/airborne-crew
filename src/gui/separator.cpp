#include "separator.h"

namespace gui_wrapper {

void VerticalLine::InitializeLine(const sf::RenderWindow& window) {
    line_->setSize(2, window.getSize().y);
    line_->setPosition(window.getSize().x * 0.6 - line_->getSize().x / 2, 0);
    line_->getRenderer()->setBackgroundColor(sf::Color::Black);
}

void VerticalLine::SetPosition(tgui::Layout x, tgui::Layout y) {
    line_->setPosition(x, y);
}

void VerticalLine::SetSize(tgui::Layout width, tgui::Layout height) {
    line_->setSize(width, height);
}

tgui::Panel::Ptr VerticalLine::GetLine() const {
    return line_;
}

sf::Vector2f VerticalLine::GetSize() const {
    return line_->getSize();
}

void HorizontalLine::InitializeLine(const sf::RenderWindow& window) {
    line_->setSize(window.getSize().x, 2);
    line_->setPosition(0, window.getSize().y * 0.6 - line_->getSize().y / 2);
    line_->getRenderer()->setBackgroundColor(sf::Color::Black); 
}

void HorizontalLine::SetPosition(tgui::Layout x, tgui::Layout y) {
    line_->setPosition(x, y);
}

void HorizontalLine::SetSize(tgui::Layout width, tgui::Layout height) {
    line_->setSize(width, height);
}

tgui::Panel::Ptr HorizontalLine::GetLine() const {
    return line_;
}

sf::Vector2f HorizontalLine::GetSize() const {
    return line_->getSize();
}

} // namespace gui_wrapper