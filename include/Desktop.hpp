#ifndef DESKTOP_HPP
#define DESKTOP_HPP

#include "raylib.h"
#include "Window.hpp"
#include <vector>

struct Icon
{
    Rectangle rect;
    std::string label;
    Texture2D texture;
    float lastClickTime;
};


class Desktop
{
    public:
        std::vector<OSWindow> windows;
        std::vector<Icon> icons;
        Texture2D myComputerIcon;
        Texture2D TrashIcon;
        Texture2D NotepadIcon;
        Texture2D PaintIcon;
        Texture2D FolderIcon;
        Texture2D StartIcon;

        Desktop();
        ~Desktop();

        void Update();
        void Draw();
        void AddWindow(std::string title);
        void AddIcon(std::string label, Texture2D tex, float x, float y);
};

#endif