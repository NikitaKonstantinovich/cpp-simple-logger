#include "../include/logger/LogMessage.hpp"
#include <iomanip>
#include <sstream>

namespace logger {
    LogMessage::LogMessage(std::string msg, LogLevel lvl) noexcept
        : timestamp{std::chrono::system_clock::now()},
        level{lvl},
        text{std::move(msg)}
    {}

    std::string LogMessage::to_string() const {
        using std::chrono::system_clock;
        using logger::to_string;

        auto t = system_clock::to_time_t(timestamp);
        auto tm = *std::localtime(&t);

        std::ostringstream os;
        os << std::put_time(&tm, "%F %T")
            << " [" << to_string(level) << "] " << text;
        return os.str();
    }
} // namespace logger