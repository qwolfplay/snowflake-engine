//
// Created by edi7 on 01.05.2024.
//

#include "Window.h"
#include "raylib.h"

Window::Window(int pHeight, int pWidth, char* pTitle, char* pIconPath)
{
    height = pHeight;
    width = pWidth;
    title = pTitle;
    iconPath = pIconPath;
    InitWindow(width, height, title);
    Image icon(iconPath);
    SetWindowIcon(icon);
}