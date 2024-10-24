//
// Created by WolfPlay on 7/14/2024.
//

#include "UIElement.h"

namespace Snowflake
{
UI::UIElement::UIElement(Vector2 pos, Vector2 size): pos(pos), size(size) {}

UI::UIElement::~UIElement() = default;

Vector2 UI::UIElement::getPos() const {
    return pos;
}

Vector2 UI::UIElement::getSize() const {
    return size;
}
} // Snowflake