#pragma once

#include <boost/log/trivial.hpp>
#include <iostream>

namespace log_handler {

enum SeverityLevel {
    trace,
    debug,
    info,
    warning,
    error,
    fatal
};

class LogHandler {
public:
    LogHandler() = default;

    LogHandler(std::ostream& out)
        : out_(out) {
    }

    void LogTrivial(SeverityLevel lvl, const std::string& message);

private:
    std::ostream& out_ = std::cout;
    boost::log::sources::severity_logger<SeverityLevel> logger_;
};

} // namespace log_handler