//
// Created by WolfPlay on 6/25/2024.
//

#ifndef SNOWFLAKE_WEAPONSLOTEMPTYEXCEPTION_H
#define SNOWFLAKE_WEAPONSLOTEMPTYEXCEPTION_H

#include <string>
#include <exception>

class WeaponSlotEmptyException : public std::exception
{
    std::string _message = "Weapon slot is empty";
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return _message.c_str();
    }
};

#endif //SNOWFLAKE_WEAPONSLOTEMPTYEXCEPTION_H
