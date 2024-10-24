//
// Created by wolfplay on 10/21/24.
//

#ifndef INTERACTIVEUIELEMENT_H
#define INTERACTIVEUIELEMENT_H

#include "raylib.h"

#include "Renderer/UI/UIElement.abstract/UIElement.h"

namespace Snowflake::UI {
class InteractiveUIElement : public UIElement {
public:
    enum ELEMENT_STATE
    {
        RELEASED,
        HOVER,
        LEFT_CLICK,
        RIGHT_CLICK
    };

protected:
    Rectangle _bounds{};
    ELEMENT_STATE _state;

public:
    InteractiveUIElement(Vector2 pos, Vector2 size);

    void updateState() override;

    virtual void execute() = 0;
};

} // Snowflake

#endif //INTERACTIVEUIELEMENT_H
