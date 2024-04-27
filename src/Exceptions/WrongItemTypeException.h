//
// Created by WolfPlay on 4/27/2024.
//

#ifndef RPG_WRONGITEMTYPEEXCEPTION_H
#define RPG_WRONGITEMTYPEEXCEPTION_H

#include <exception>
#include <string>

class WrongItemTypeException : public std::exception
{
    std::string _message = "Item is not a weapon";
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return _message.c_str();
    }
};


#endif //RPG_WRONGITEMTYPEEXCEPTION_H
