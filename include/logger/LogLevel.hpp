#pragma once
#include <string_view>

namespace logger {
     // --- Уровень важности сообщения ---
    enum class LogLevel : int {
        Trace = 0,
        Info = 1,
        Warning = 2,
        Error = 3,
    };

    // --- Приводит уровень к строке (без выделения в куче). ---
    [[nodiscard]]
    constexpr std::string_view to_string(LogLevel lvl) noexcept {
        using namespace std::string_view_literals;
        switch (lvl) {
            case LogLevel::Trace: return "Trace"sv;
            case LogLevel::Info: return "Info"sv;
            case LogLevel::Warning: return "Warning"sv;
            case LogLevel::Error: return "Error"sv;
        }
        return "Unknow"sv;
    }
} //namespace logger