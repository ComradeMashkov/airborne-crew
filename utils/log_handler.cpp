#include "log_handler.h"

namespace log_handler {

void LogHandler::LogTrivial(SeverityLevel lvl, const std::string& message) {
    BOOST_LOG_SEV(logger_, lvl) << message;
}

} // namespace log_handler