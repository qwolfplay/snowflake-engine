//
// Created by edi7 on 23.06.2024.
//

#include "Sprite.h"
#include "raylib.h"

Sprite::Sprite(const char* path)
{
    pathToImg = path;
    texture = LoadTexture(pathToImg);
}
void Sprite::DrawSprite(int x, int y, Color tint)
{
    DrawTexture(texture, x, y, tint);
}
void Sprite::changeTexture(const char* path)
{
    pathToImg = path;
    texture = LoadTexture(pathToImg);
}
const char* Sprite::getPathToImg()
{
    return pathToImg;
}