//
// Created by WolfPlay on 7/14/2024.
//

#ifndef SNOWFLAKE_UIELEMENT_H
#define SNOWFLAKE_UIELEMENT_H

#include "raylib.h"

namespace Snowflake::UI
{
class UIElement
{
    Vector2 pos;
    Vector2 size;

public:
    UIElement(Vector2 pos, Vector2 size);

    virtual ~UIElement();

    [[nodiscard]] Vector2 getPos() const;

    [[nodiscard]] Vector2 getSize() const;

    virtual void draw() = 0;

    virtual void updateState() = 0;
};
}

// Snowflake

#endif //SNOWFLAKE_UIELEMENT_H
