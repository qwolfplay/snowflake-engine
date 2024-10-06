//
// Created by WolfPlay on 10/6/2024.
//

#ifndef LOGGERNOTINITIALIZED_H
#define LOGGERNOTINITIALIZED_H

#include <exception>
#include <string>

class LoggerNotInitialized : public std::exception
{
    std::string _message = "Logger was not initialized";
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return _message.c_str();
    }
};


#endif //LOGGERNOTINITIALIZED_H
