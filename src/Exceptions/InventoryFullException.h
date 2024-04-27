//
// Created by WolfPlay on 4/27/2024.
//

#ifndef RPG_INVENTORYFULLEXCEPTION_H
#define RPG_INVENTORYFULLEXCEPTION_H

#include <exception>
#include <string>

class InventoryFullException : public std::exception
{
    std::string _message = "Inventory is full";
public:
    [[nodiscard]] const char *what() const noexcept override
    {
        return _message.c_str();
    }
};


#endif //RPG_INVENTORYFULLEXCEPTION_H
