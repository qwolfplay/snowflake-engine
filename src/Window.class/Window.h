//
// Created by edi7 on 01.05.2024.
//

#ifndef RPG_WINDOW_H
#define RPG_WINDOW_H


class Window
{
private:
    int height;
    int width;
    char* title;
    char* iconPath;
public:
    Window(int height, int width, char* title, char* iconPath);
};


#endif //RPG_WINDOW_H
