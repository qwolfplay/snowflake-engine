//
// Created by WolfPlay on 4/27/2024.
//

#ifndef RPG_ARMORSET_H
#define RPG_ARMORSET_H

#include "Armor.abstract/Armor.h"
#include "Armor.abstract/Helmet.class/Helmet.h"
#include "Armor.abstract/Chestplate.class/Chestplate.h"
#include "Armor.abstract/Leggings.class/Leggings.h"

class ArmorSet
{
    Helmet *_helmet;
    Chestplate *_chestplate;
    Leggings *_leggings;

    bool _isHelmetEquipped;
    bool _isChestplateEquipped;
    bool _isLeggingsEquipped;

public:
    ArmorSet();

    ArmorSet(Helmet *helmet, Chestplate *chestplate, Leggings *leggings);

    ~ArmorSet();

    Helmet *getHelmetPtr() const;

    Chestplate *getChestplatePtr() const;

    Leggings *getLeggingsPtr() const;

    [[nodiscard]] bool isHelmetEquipped() const;

    [[nodiscard]] bool isChestplateEquipped() const;

    [[nodiscard]] bool isLeggingsEquipped() const;

    void equipHelmet(Helmet *helmet);

    void equipChestplate(Chestplate *chestplate);

    void equipLeggings(Leggings *leggings);

    Helmet *unequipHelmet();

    Chestplate *unequipChestplate();

    Leggings *unequipLeggings();

    float getEffectiveDefence();

    float getEffectiveResistance();

    float getDamageReduction(float damage);

    float getDamageReductionMultiplier();
};


#endif //RPG_ARMORSET_H
