//
// Created by wolfplay on 10/21/24.
//

#include "InteractiveUIElement.h"

#include "globals.h"

namespace Snowflake::UI {
InteractiveUIElement::InteractiveUIElement(Vector2 pos, Vector2 size): UIElement(pos, size) {
    _bounds = Rectangle{pos.x, pos.y, size.x, size.y};
    _state = RELEASED;
}

void InteractiveUIElement::updateState() {
    if (CheckCollisionPointRec(g_mousePos, _bounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            _state = LEFT_CLICK;
        } else {
            _state = HOVER;
        }
    } else {
        _state = RELEASED;
    }
}
} // Snowflake