//
// Created by WolfPlay on 7/14/2024.
//

#include "GameScene.h"

#include <algorithm>

#include "raylib.h"

namespace Snowflake
{
GameScene::GameScene(const std::vector<GameObject *> &gameObjects, const std::vector<UI::UIElement *> &uiElements) {
    _gameObjects.reserve(_gameObjects.size());
    _gameObjects.reserve(_uiElements.size());
    std::copy(gameObjects.begin(), gameObjects.end(), _gameObjects.begin());
    std::copy(uiElements.begin(), uiElements.end(), _uiElements.begin());
}

GameScene::~GameScene() {
    for (GameObject* object : _gameObjects) {
        object->~GameObject();
    }
    for (UI::UIElement* elem : _uiElements) {
        elem->~UIElement();
    }
}

void GameScene::addGameObject(GameObject* gameObject) {
    _gameObjects.push_back(gameObject);
}

void GameScene::addUIiElement(UI::UIElement* uiElement) {
    _uiElements.push_back(uiElement);
}

void GameScene::update() {
    for (GameObject* object : _gameObjects) {
        object->updateState();
    }
    for (UI::UIElement* element : _uiElements) {
        element->updateState();
    }
}

void GameScene::render() {
    BeginDrawing();

    ClearBackground(BLACK);

    for (GameObject* object : _gameObjects) {
        object->draw();
    }
    for (UI::UIElement* element : _uiElements) {
        element->draw();
    }

    EndDrawing();
}
} // Snowflake
