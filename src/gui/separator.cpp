#include "separator.h"

namespace gui_wrapper {

void VerticalLine::InitializeLine() {
    line_->setSize(global_parameters::LINE_WIDTH, global_parameters::WIDTH);
    line_->setPosition(global_parameters::CANVAS_WIDTH - line_->getSize().x / 2, 0);
    line_->getRenderer()->setBackgroundColor(sf::Color::Black);
}

void VerticalLine::InitializeLine(tgui::Layout x, tgui::Layout y, tgui::Layout width, tgui::Layout height) {
    line_->setSize(height, width);
    line_->setPosition(x, y);
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

void HorizontalLine::InitializeLine() {
    line_->setSize(global_parameters::WIDTH, global_parameters::LINE_WIDTH);
    line_->setPosition(0, global_parameters::CANVAS_HEIGHT - line_->getSize().y / 2);
    line_->getRenderer()->setBackgroundColor(sf::Color::Black); 
}

void HorizontalLine::InitializeLine(tgui::Layout x, tgui::Layout y, tgui::Layout width, tgui::Layout height) {
    line_->setSize(width, height);
    line_->setPosition(x, y);
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