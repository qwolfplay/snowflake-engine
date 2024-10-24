//
// Created by wolfplay on 10/18/24.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "Renderer/UI/InteractiveUIElement.abstract/InteractiveUIElement.h"

namespace Snowflake::UI {

class Button : InteractiveUIElement {

public:
    Button(Vector2 pos, Vector2 size);

    void draw() override;

    void execute() override;
};

} // UI
// Snowflake

#endif //BUTTON_H
