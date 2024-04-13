//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_ITEM_H
#define POLYMORPHISM_ITEM_H

#include <string>

class Item {
public:
    enum rarity {
        COMMON,
        UNCOMMON,
        RARE,
        EPIC,
        LEGENDARY
    };

    static std::string to_string(rarity rarity) {
        switch (rarity) {
            case COMMON:
                return "Common";
            case UNCOMMON:
                return "Uncommon";
            case RARE:
                return "Rare";
            case EPIC:
                return "Epic";
            case LEGENDARY:
                return "Legendary";
            default:
                return "Unknown";
        }
    }

private:
    const std::string   _name;
    const std::string   _description;
    const rarity        _rarity;
    float               _price;

public:
    Item(std::string name, std::string description, float price, rarity rarity);
    ~Item() = default;

    std::string getName() const;
    std::string getDescription() const;
    float getPrice() const;
    rarity getRarity() const;

    void setPrice(float price);
};


#endif //POLYMORPHISM_ITEM_H
