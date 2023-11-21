#include "event_handler.h"

namespace event_handler {

// Для статического поля обязательна предварительная инициализация
log_handler::LogHandler* EventHandler::logger_ = nullptr;
sf::Texture* EventHandler::plane_texture_ = nullptr;

// Метод, отвечающий за кнопку Debug -> Show FPS
void EventHandler::showFPS(gui_wrapper::FrameRateLabel& fps, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "Debug" && menuItem[1] == "Show FPS") {
        fps.ShowLabel();

        // Пример логгирования
        // Слэши перед кавычками (\") нужны для правильного экранирования кавычек, т.к. это служебный символ
        logger_->LogTrivial(boost::log::trivial::severity_level::info, "\"Show FPS\" button pressed");
    }
}

// Метод, отвечающий за кнопку Info -> About
void EventHandler::showInfo(tgui::Gui& gui, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "Info" && menuItem[1] == "About") {
        auto messageBox = tgui::MessageBox::create();
        messageBox->setPosition("(&.size - size) / 2");
        messageBox->setText("This program was developed by comrademashkov");
        messageBox->addButton("OK");
        messageBox->setButtonAlignment(tgui::MessageBox::Alignment::Center);
        messageBox->onButtonPress([msgBox = messageBox.get()] (const tgui::String& button) {
            msgBox->getParent()->remove(msgBox->shared_from_this());
        });
        gui.add(messageBox);
    }
}

// Метод, отвечающий за кнопку Program -> Start
void EventHandler::startProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "Program" && menuItem[1] == "Start") {
        plane_texture_ = new sf::Texture;
        plane_texture_->loadFromFile("../meta/plane_test.png");
        sf::Sprite plane_sprite;
        plane_sprite.setTexture(*plane_texture_);
        plane_sprite.setPosition({ 50.f, 50.f });
        plane_sprite.setScale({ 0.02f, 0.02f });
        plane.SetPrimitive(plane_sprite);
        plane.SetToDraw(true);
        plane.SetTargetPosition({ 50.f, 50.f });
    }
}

// Метод, отвечающий за кнопку Program -> Finish
void EventHandler::finishProgram(objects::Plane& plane, const std::vector<tgui::String>& menuItem) {
    if (menuItem.size() == 2 && menuItem[0] == "Program" && menuItem[1] == "Finish") {
        plane.SetToDraw(false);
        delete plane_texture_;
    }
}

// Метод, отвечающий за передвижение круга
void EventHandler::moveCircle(objects::Plane& plane, const sf::Vector2f& mousePosition) {
    plane.SetTargetPosition(mousePosition - plane.GetPlaneSize());
}

// Системный метод для передачи логгера в EventHandler
void EventHandler::SetLogger(log_handler::LogHandler* logger) {
    EventHandler::logger_ = logger;
}

} // namespace event_handler