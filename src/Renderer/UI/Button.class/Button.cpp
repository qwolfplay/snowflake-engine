//
// Created by wolfplay on 10/18/24.
//

#include "Button.h"


namespace Snowflake::UI
{
Button::Button(Vector2 pos, Vector2 size) : InteractiveUIElement(pos, size) {}

    void Button::draw() {
        switch (_state) {
            case RELEASED:
                DrawRectangleRec(_bounds, RED);
                break;
            case HOVER:
                DrawRectangleRec(_bounds, LIME);
                break;
            case LEFT_CLICK:
                DrawRectangleRec(_bounds, BLUE);
                break;
        }
    }
} // UI
// Snowflake
