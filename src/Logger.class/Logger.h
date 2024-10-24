//
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_LOGGER_H
#define SNOWFLAKE_LOGGER_H

#include "raylib.h"
#include "spdlog/spdlog.h"
#include "spdlog/async_logger.h"

namespace Snowflake
{
class Logger
{
    std::shared_ptr<spdlog::async_logger> _asyncLogger;
    std::string _name;

    static Logger *s_instancePtr;

    static std::shared_ptr<spdlog::async_logger> getLoggerInstance();

    void customRaylibLog(int logLevel, const char *text, va_list args);

    static void s_customRaylibLog(int logLevel, const char *text, va_list args);

public:
    Logger();

    ~Logger();

    explicit Logger(std::string name);

    void initRaylibLogger();

    static void initRaylibLogger(Logger *logger);

    void setLoggingLevel(spdlog::level::level_enum loggingLevel) const;

    [[nodiscard]] spdlog::level::level_enum getLoggingLevel() const;

    void trace(const char *message) const;

    void debug(const char *message) const;

    void info(const char *message) const;

    void warn(const char *message) const;

    void error(const char *message) const;

    void critical(const char *message) const;
};
}


#endif //SNOWFLAKE_LOGGER_H
