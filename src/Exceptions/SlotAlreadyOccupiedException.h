//
// Created by WolfPlay on 4/27/2024.
//

#ifndef RPG_SLOTALREADYOCCUPIEDEXCEPTION_H
#define RPG_SLOTALREADYOCCUPIEDEXCEPTION_H

#include <exception>
#include <string>

class SlotAlreadyOccupiedException : public std::exception
{
    std::string _message = "Slot is occupied";
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return _message.c_str();
    }
};


#endif //RPG_SLOTALREADYOCCUPIEDEXCEPTION_H
