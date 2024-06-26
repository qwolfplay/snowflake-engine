//
// Created by WolfPlay on 4/10/2024.
//

#ifndef POLYMORPHISM_ITEM_H
#define POLYMORPHISM_ITEM_H

#include <string>

class Item {
public:
    enum Rarity {
        COMMON,
        UNCOMMON,
        RARE,
        EPIC,
        LEGENDARY
    };

    enum ItemType {
        WEAPON,
        ARMOR,
        CONSUMABLE,
        MATERIAL
    };

    static std::string to_string(Rarity rarity) {
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
    const Rarity        _rarity;
    const ItemType          _type;
    float               _price;

public:
    Item(std::string name, std::string description, float price, ItemType type, Rarity rarity);
    ~Item() = default;

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] std::string getDescription() const;

    [[nodiscard]] float getPrice() const;

    [[nodiscard]] ItemType getType() const;

    [[nodiscard]] Rarity getRarity() const;

    void setPrice(float price);
};


#endif //POLYMORPHISM_ITEM_H
