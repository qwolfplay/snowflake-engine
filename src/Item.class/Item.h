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

    enum type {
        WEAPON,
        ARMOR,
        CONSUMABLE,
        MATERIAL
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
    const type          _type;
    float               _price;

public:
    Item(std::string name, std::string description, float price, type type, rarity rarity);
    ~Item() = default;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getDescription() const;
    [[nodiscard]] float getPrice() const;
    [[nodiscard]] type getType() const;
    [[nodiscard]] rarity getRarity() const;

    void setPrice(float price);
};


#endif //POLYMORPHISM_ITEM_H
