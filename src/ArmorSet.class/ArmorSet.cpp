//
// Created by WolfPlay on 4/27/2024.
//

#include "ArmorSet.h"

#include <stdexcept>

#include "Exceptions/SlotEmptyException.h"
#include "Exceptions/SlotAlreadyOccupiedException.h"

ArmorSet::ArmorSet()
{
    _helmet = nullptr;
    _chestplate = nullptr;
    _leggings = nullptr;

    _isHelmetEquipped = false;
    _isChestplateEquipped = false;
    _isLeggingsEquipped = false;
}

ArmorSet::ArmorSet(Helmet *helmet, Chestplate *chestplate, Leggings *leggings)
{
    _helmet = helmet;
    _chestplate = chestplate;
    _leggings = leggings;

    _isHelmetEquipped = helmet != nullptr;
    _isChestplateEquipped = chestplate != nullptr;
    _isLeggingsEquipped = leggings != nullptr;
}

ArmorSet::~ArmorSet()
{
    delete _helmet;
    delete _chestplate;
    delete _leggings;
}

Helmet *ArmorSet::getHelmetPtr() const
{
    if (!_isHelmetEquipped) { throw SlotEmptyException(); }
    return _helmet;
}

Chestplate *ArmorSet::getChestplatePtr() const
{
    if (!_isChestplateEquipped) { throw SlotEmptyException(); }
    return _chestplate;
}

Leggings *ArmorSet::getLeggingsPtr() const
{
    if (!_isLeggingsEquipped) { throw SlotEmptyException(); }
    return _leggings;
}

bool ArmorSet::isHelmetEquipped() const
{
    return _isHelmetEquipped;
}

bool ArmorSet::isChestplateEquipped() const
{
    return _isChestplateEquipped;
}

bool ArmorSet::isLeggingsEquipped() const
{
    return _isLeggingsEquipped;
}

void ArmorSet::equipHelmet(Helmet *helmet)
{
    if (_isHelmetEquipped) { throw SlotAlreadyOccupiedException(); }
    if (helmet == nullptr) { throw std::invalid_argument("ArmorSet::equipHelmet: helmet is nullptr"); }
    _helmet = helmet;
    _isHelmetEquipped = true;
}

void ArmorSet::equipChestplate(Chestplate *chestplate)
{
    if (_isChestplateEquipped) { throw SlotAlreadyOccupiedException(); }
    if (chestplate == nullptr) { throw std::invalid_argument("ArmorSet::equipChestplate: chestplate is nullptr"); }
    _chestplate = chestplate;
    _isChestplateEquipped = true;
}

void ArmorSet::equipLeggings(Leggings *leggings)
{
    if (_isLeggingsEquipped) { throw SlotAlreadyOccupiedException(); }
    if (leggings == nullptr) { throw std::invalid_argument("ArmorSet::equipLeggings: leggings is nullptr"); }
    _leggings = leggings;
    _isLeggingsEquipped = true;
}

Helmet *ArmorSet::unequipHelmet()
{
    if (!_isHelmetEquipped) { throw SlotEmptyException(); }
    Helmet *helmet = _helmet;
    _helmet = nullptr;
    _isHelmetEquipped = false;
    return helmet;
}

Chestplate *ArmorSet::unequipChestplate()
{
    if (!_isChestplateEquipped) { throw SlotEmptyException(); }
    Chestplate *chestplate = _chestplate;
    _chestplate = nullptr;
    _isChestplateEquipped = false;
    return chestplate;
}

Leggings *ArmorSet::unequipLeggings()
{
    if (!_isLeggingsEquipped) { throw SlotEmptyException(); }
    Leggings *leggings = _leggings;
    _leggings = nullptr;
    _isLeggingsEquipped = false;
    return leggings;
}

float ArmorSet::getEffectiveDefence()
{
    float effective = 0;
    if (_isHelmetEquipped) { effective += _helmet->getEffectiveDefence(); }
    if (_isChestplateEquipped) { effective += _chestplate->getEffectiveDefence(); }
    if (_isLeggingsEquipped) { effective += _leggings->getEffectiveDefence(); }

    return effective;
}

float ArmorSet::getEffectiveResistance()
{
    float effective = 0;
    if (_isHelmetEquipped) { effective += _helmet->getEffectiveResistance(); }
    if (_isChestplateEquipped) { effective += _chestplate->getEffectiveResistance(); }
    if (_isLeggingsEquipped) { effective += _leggings->getEffectiveResistance(); }

    return effective;
}

float ArmorSet::getDamageReduction(float damage)
{
    return damage - (damage * (1 - (1 / (0.05f * getEffectiveDefence() + 1))));
}

float ArmorSet::getDamageReductionMultiplier()
{
    return 1.0f / (0.05 * getEffectiveDefence() + 1);
}

float ArmorSet::calculateArmorPeneterationFactor(float armorPenetration)
{
    return 1 - (1 / ((0.03f * armorPenetration) + 1));
}
