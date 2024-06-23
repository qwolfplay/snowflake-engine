//
// Created by edi7 on 23.06.2024.
//

#ifndef RPG_SPRITE_H
#define RPG_SPRITE_H

#include "raylib.h"

class Sprite
{
private:
    const char* pathToImg;
    Texture texture;
public:
    Sprite(const char* path);
    void DrawSprite(int x, int y, Color tint);
    void changeTexture(const char* path);
    const char* getPathToImg();
};


#endif //RPG_SPRITE_H
