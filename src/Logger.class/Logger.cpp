//
// Created by WolfPlay on 6/26/2024.
//

#include "Logger.h"

#include <chrono>
#include <utility>

#include "spdlog/async.h"
#include "spdlog/fmt/chrono.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"
#include "spdlog/sinks/ansicolor_sink.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/pattern_formatter.h"

// TODO: class GlobalLoggerController
// static std::shared_ptr<spdlog::async_logger> &getInstance();
// static std::shared_ptr<spdlog::async_logger> *getInstancePtr();

const std::string LOGGER_PATTERN = "[%T:%f] [p:%P/t:%t] [%n] [%^%l%$]: %v";

namespace Snowflake
{
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

    const auto fileSinkSharedPtr = std::make_shared<spdlog::sinks::basic_file_sink_mt>(fmt::format("{:%F_%H-%M-%S}.log", t));
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

    const auto fileSinkSharedPtr = std::make_shared<spdlog::sinks::basic_file_sink_mt>(fmt::format("{}_{:%F_%H-%M-%S}.log", _name, t));
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
}
}

