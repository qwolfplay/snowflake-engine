//
// Created by edi7 on 01.05.2024.
//

#include "Window.h"
#include "raylib.h"

Window::Window(int height, int width, char* title, char* iconPath)
{
    InitWindow(height, width, title);
    Image icon(iconPath);
    SetWindowIcon(icon);
}