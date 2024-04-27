//
// Created by WolfPlay on 4/27/2024.
//

#ifndef RPG_SLOTEMPTYEXCEPTION_H
#define RPG_SLOTEMPTYEXCEPTION_H

#include <exception>
#include <string>

class SlotEmptyException : public std::exception
{
    std::string _message = "Slot is empty";
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return _message.c_str();
    }
};


#endif //RPG_SLOTEMPTYEXCEPTION_H
