//
// Created by WolfPlay on 4/14/2024.
//

#ifndef RPG_ARMOR_H
#define RPG_ARMOR_H

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
          Rarity rarity,
          float baseDefence,
          float baseResistance);

    virtual ~Armor() = default;

    [[nodiscard]] float getBaseDefence() const;

    [[nodiscard]] float getBaseResistance() const;

    [[nodiscard]] armorType getArmorType() const;

    [[nodiscard]] virtual float getEffectiveDefence();

    [[nodiscard]] virtual float getEffectiveResistance();

    virtual float calculateMeleeDamageReduction(float damage) const;

    virtual float calculateMagicDamageReduction(float damage) const;

};


#endif //RPG_ARMOR_H
