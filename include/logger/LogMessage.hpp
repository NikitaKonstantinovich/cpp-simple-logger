#pragma once

#include <string>
#include <chrono>
#include "LogLevel.hpp"

namespace logger {
    /// Один лог-запрос, передаваемый от клиента к рабочему потоку.
    /// *Принцип*: никаких исключений, только тривиальные поля.
    struct LogMessage {
        std::chrono::system_clock::time_point timestamp;
        LogLevel level = LogLevel::Info;
        std::string text;

        /// Конструктор-утилита (берёт текущее время по умолчанию).
        explicit LogMessage(std::string msg, LogLevel lvl = LogLevel::Info) noexcept;

        /// Форматирует в «читаемую» строку (`2025-08-02 18:42:15 [Info] Hello`).
        [[nodiscard]] std::string to_string() const;
    };
} //namespace logger
