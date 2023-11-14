#pragma once

#include <iostream>
#include <fstream>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>

namespace log_handler {

namespace logging = boost::log;

class LogHandler {
public:
    LogHandler() {
        InitConsoleLogging();
    }

    explicit LogHandler(const std::string& filename) {
        InitFileLogging(filename);
    }

    ~LogHandler() {
        boost::log::core::get()->flush();
    }

    void LogTrivial(logging::trivial::severity_level level, const std::string& message) {
        BOOST_LOG_SEV(logger_, level) << message;
    }

private:
    logging::sources::severity_logger<logging::trivial::severity_level> logger_;

    void InitConsoleLogging() {
        logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");
        logging::add_console_log(std::clog, logging::keywords::format = "[%TimeStamp%] [%Severity%] %Message%");
        logging::add_common_attributes();
    }

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