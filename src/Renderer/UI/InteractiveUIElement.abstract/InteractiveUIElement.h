//
// Created by wolfplay on 10/17/24.
//

#ifndef INTERACTABLEUIELEMENT_H
#define INTERACTABLEUIELEMENT_H

#include "raylib.h"

#include "Renderer/UI/UIElement.abstract/UIElement.h"

namespace Snowflake::UI {
class InteractiveUIElement : UIElement {

public:
    InteractiveUIElement(Vector2 pos, Vector2 size): UIElement(pos, size) {};

    virtual void checkInteraction();

    virtual void execute() = 0;
};
}



#endif //INTERACTABLEUIELEMENT_H
