#include "separator.h"

namespace gui_wrapper {

void VerticalLine::InitializeLine(const sf::RenderWindow& window) {
    line_->setSize(2, window.getSize().y);
    line_->setPosition(window.getSize().x * 0.6 - line_->getSize().x / 2, 0);
    line_->getRenderer()->setBackgroundColor(sf::Color::Black);
}

tgui::Panel::Ptr VerticalLine::GetLine() const {
    return line_;
}

tgui::Panel::Ptr HorizontalLine::GetLine() const {
    return line_;
}

void HorizontalLine::InitializeLine(const sf::RenderWindow& window) {
    line_->setSize(window.getSize().x, 2);
    line_->setPosition(0, window.getSize().y * 0.6 - line_->getSize().y / 2);
    line_->getRenderer()->setBackgroundColor(sf::Color::Black); // Цвет разделителя
}

} // namespace gui_wrapper