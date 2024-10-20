//
// Created by WolfPlay on 7/14/2024.
//

#ifndef SNOWFLAKE_SCENE_H
#define SNOWFLAKE_SCENE_H
#include <vector>

#include "GameObject.abstract/GameObject.h"
#include "Renderer/UI/UIElement.abstract/UIElement.h"

namespace Snowflake
{
class GameScene
{
    std::vector<GameObject *> _gameObjects;
    std::vector<UI::UIElement *> _uiElements;

public:
    GameScene(const std::vector<GameObject *> &gameObjects, const std::vector<UI::UIElement *> &uiElements);

    virtual ~GameScene();

    void addGameObject(GameObject* gameObject);

    void addUIiElement(UI::UIElement* uiElement);

    virtual void update();

    virtual void render();
};
} // Snowflake

#endif //SNOWFLAKE_SCENE_H
