//
// Created by WolfPlay on 4/14/2024.
//

#ifndef SNOWFLAKE_ARMOR_H
#define SNOWFLAKE_ARMOR_H

#include "Item.class/Item.h"

class Armor : public Item
{
public:
    enum armorType
    {
        HELMET,
        CHESTPLATE,
        LEGGINGS
    };

private:
    const armorType _type;
    const float _baseDefence;
    const float _baseResistance;

public:
    const float defenceMultiplier;
    const float resistanceMultiplier;

    Armor(std::string name,
          std::string description,
          float price,
          armorType type,
          rarity rarity,
          float baseDefence,
          float baseResistance);

    ~Armor();

    [[nodiscard]] float getBaseDefence() const;

    [[nodiscard]] float getBaseResistance() const;

    [[nodiscard]] armorType getArmorType() const;

    [[nodiscard]] virtual float getEffectiveDefence();

    [[nodiscard]] virtual float getEffectiveResistance();

    virtual float calculateMeleeDamageReduction(float damage) const;

    virtual float calculateMagicDamageReduction(float damage) const;

};


#endif //SNOWFLAKE_ARMOR_H
