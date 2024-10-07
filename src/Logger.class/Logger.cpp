//
// Created by WolfPlay on 6/26/2024.
//

#include "Logger.h"

#include <chrono>
#include <filesystem>
#include <utility>

#include "raylib.h"
#include "spdlog/async.h"
#include "spdlog/pattern_formatter.h"
#include "spdlog/fmt/chrono.h"
#include "spdlog/sinks/ansicolor_sink.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"
#include "Exceptions/LoggerNotInitialized.h"


// TODO: class GlobalLoggerController
// static std::shared_ptr<spdlog::async_logger> &getInstance();
// static std::shared_ptr<spdlog::async_logger> *getInstancePtr();

const std::string LOGGER_PATTERN = "[%T:%f] [p:%P/t:%t] [%n] [%^%l%$]: %v";

namespace Snowflake
{
void Logger::customRaylibLog(int logLevel, const char *text, va_list args) {
    auto formattedString = fmt::vformat(text, fmt::make_format_args(args));

    switch (logLevel) {
        case LOG_TRACE:
            _asyncLogger->trace(formattedString);
            break;
        case LOG_DEBUG:
            _asyncLogger->debug(formattedString);
            break;
        case LOG_INFO:
            _asyncLogger->info(formattedString);
            break;
        case LOG_WARNING:
            _asyncLogger->warn(formattedString);
            break;
        case LOG_ERROR:
            _asyncLogger->error(formattedString);
            break;
        case LOG_FATAL:
            _asyncLogger->critical(formattedString);
            break;
        default:
            _asyncLogger->error("[Wrong log level!] {}", formattedString);
    }
}

void Logger::s_customRaylibLog(int logLevel, const char *text, va_list args) {
    if (s_instancePtr) {
        s_instancePtr->customRaylibLog(logLevel, text, args);
    } else {
        throw LoggerNotInitialized();
    }
}

Logger::Logger(): _name("main") {
#ifdef DEBUG_BUILD
    _loggingLevel = DEBUG;
#else
    _loggingLevel = INFO;
#endif

    auto t = std::chrono::system_clock::now();
    std::vector<spdlog::sink_ptr> sinks;

    const auto stdoutSinkSharedPtr = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    stdoutSinkSharedPtr->set_pattern(LOGGER_PATTERN);
    sinks.push_back(stdoutSinkSharedPtr);

    if (!std::filesystem::exists("logs")) {
        std::filesystem::create_directory("logs");
    }

    const auto fileSinkSharedPtr = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
         fmt::format("logs/{:%F_%H-%M-%S}.log", t)
        );
    fileSinkSharedPtr->set_pattern(LOGGER_PATTERN);
    sinks.push_back(fileSinkSharedPtr);

    spdlog::init_thread_pool(10240, 2);
    _asyncLogger = std::make_shared<spdlog::async_logger>(
                                                          _name,
                                                          begin(sinks),
                                                          end(sinks),
                                                          spdlog::thread_pool(),
                                                          spdlog::async_overflow_policy::block
                                                         );

    _asyncLogger->flush_on(spdlog::level::debug);
    _asyncLogger->set_level(spdlog::level::debug);

    s_instancePtr = this;
    register_logger(_asyncLogger);
}

Logger::Logger(std::string name): _name(std::move(name)) {
#ifdef DEBUG_BUILD
    _loggingLevel = DEBUG;
#else
    _loggingLevel = INFO;
#endif

    auto t = std::chrono::system_clock::now();
    std::vector<spdlog::sink_ptr> sinks;

    const auto stdoutSinkSharedPtr = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    stdoutSinkSharedPtr->set_pattern(LOGGER_PATTERN);
    sinks.push_back(stdoutSinkSharedPtr);

    const auto fileSinkSharedPtr = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
         fmt::format("{}_{:%F_%H-%M-%S}.log", _name, t)
        );
    fileSinkSharedPtr->set_pattern(LOGGER_PATTERN);
    sinks.push_back(fileSinkSharedPtr);

    _asyncLogger = std::make_shared<spdlog::async_logger>(
                                                          _name,
                                                          begin(sinks),
                                                          end(sinks),
                                                          spdlog::thread_pool(),
                                                          spdlog::async_overflow_policy::block
                                                         );

    _asyncLogger->flush_on(spdlog::level::debug);
    _asyncLogger->set_level(spdlog::level::debug);

    s_instancePtr = this;
}

void Logger::initRaylibLogger() {
    s_instancePtr = this;
    SetTraceLogCallback(s_customRaylibLog);
}

void Logger::initRaylibLogger(Logger *logger) {
    s_instancePtr = logger;
    SetTraceLogCallback(s_customRaylibLog);
}

}
