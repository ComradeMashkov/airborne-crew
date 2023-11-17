#pragma once

#include <iostream>
#include <fstream>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>

/* 
   Здесь хранятся определения методов класса LogHandler,
   который отвечает за логгирование процессов, 
   происходящих во время работы программы.
   
   Реализация здесь же.
*/

namespace log_handler {

namespace logging = boost::log;

class LogHandler {
public:
    // Коснтруктор по умолчанию, вызывает метод InitConsoleLogging()
    // Сам конструктор вызывается при создании объекта
    LogHandler() {
        InitConsoleLogging();
    }

    // Параметризованный конструктор, вызывает метод InitFileLogging()
    // Сам конструктор вызывается при создании объекта
    explicit LogHandler(const std::string& filename) {
        InitFileLogging(filename);
    }

    // Деструктор, очищает поток вывода логгера
    // Вызывается при разрушении объекта
    ~LogHandler() {
        boost::log::core::get()->flush();
    }

    // Базовая реализация функции логгирования
    // Параметры:
    // 
    // 1. logging::trivial::severity_level level - уровни логгирования 
    // Все уровни см. тут: https://www.boost.org/doc/libs/1_81_0/boost/log/trivial.hpp
    //
    // 2. Сообщение, которое будет выводиться при логгах
    void LogTrivial(logging::trivial::severity_level level, const std::string& message) {
        // Вызывается стандартый макрос из Boost.Log
        BOOST_LOG_SEV(logger_, level) << message;
    }

private:
    // Поле самого логгера
    logging::sources::severity_logger<logging::trivial::severity_level> logger_;

    // Метод вывода в консоль
    void InitConsoleLogging() {
        logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");
        logging::add_console_log(std::clog, logging::keywords::format = "[%TimeStamp%] [%Severity%] %Message%");
        logging::add_common_attributes();
    }

    // Метод вывода в файл
    void InitFileLogging(const std::string& filename) {
        logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");
        logging::add_file_log(
            logging::keywords::file_name = filename,
            logging::keywords::format = "[%TimeStamp%] [%Severity%] %Message%"
        );
        logging::add_common_attributes();
    }
};

} // namespace log_handler