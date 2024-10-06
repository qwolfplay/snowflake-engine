    //
// Created by WolfPlay on 6/26/2024.
//

#ifndef SNOWFLAKE_LOGGER_H
#define SNOWFLAKE_LOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/async_logger.h"

namespace Snowflake
{
    class Logger
    {
    public:
        enum LOGGING_LEVEL
        {
            SILLY,
            TRACE,
            DEBUG,
            LOG,
            INFO,
            WARN,
            ERROR,
            CRITICAL
        };

    private:
        std::shared_ptr<spdlog::async_logger> _asyncLogger;

        LOGGING_LEVEL _loggingLevel;
        std::string _name;



    public:
        Logger();

        Logger(std::string name);

        void setLoggingLevel(LOGGING_LEVEL loggingLevel);

        LOGGING_LEVEL getLoggingLevel(LOGGING_LEVEL loggingLevel);

        void silly(const char *message);

        void debug(const char *message);

        void log(const char *message);

        void info(const char *message);

        void warn(const char *message);

        void error(const char *message);

        void critical(const char *message);
    };
}


#endif //SNOWFLAKE_LOGGER_H
