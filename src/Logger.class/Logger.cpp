//
// Created by WolfPlay on 6/26/2024.
//

#include "Logger.h"

#include <chrono>
#include <utility>

#include "spdlog/async.h"
#include "spdlog/fmt/chrono.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

// TODO: class GlobalLoggerController
// static std::shared_ptr<spdlog::async_logger> &getInstance();
// static std::shared_ptr<spdlog::async_logger> *getInstancePtr();

namespace Snowflake
{
Logger::Logger(): _name("Logger") {
#ifdef DEBUG_BUILD
    _loggingLevel = DEBUG;
#else
    _loggingLevel = INFO;
#endif

    auto t = std::chrono::system_clock::now();
    std::vector<spdlog::sink_ptr> sinks;

    sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(fmt::format("{:%F-%T.log}", t)));

    _asyncLogger = std::make_shared<spdlog::async_logger>(
                                                          _name,
                                                          begin(sinks),
                                                          end(sinks),
                                                          spdlog::thread_pool(),
                                                          spdlog::async_overflow_policy::block
                                                         );
}

Logger::Logger(std::string name): _name(std::move(name)) {
#ifdef DEBUG_BUILD
    _loggingLevel = DEBUG;
#else
    _loggingLevel = INFO;
#endif

    auto t = std::chrono::system_clock::now();
    std::vector<spdlog::sink_ptr> sinks;

    sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(fmt::format("{:%F-%T.log}", t)));

    _asyncLogger = std::make_shared<spdlog::async_logger>(
                                                          _name,
                                                          begin(sinks),
                                                          end(sinks),
                                                          spdlog::thread_pool(),
                                                          spdlog::async_overflow_policy::block
                                                         );
}
}

