#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "raylib.h"
#include <string>

class OSWindow
{
    public:
        Rectangle rect;
        Rectangle closeButton;
        std::string title;
        Color activeColor;
        bool isOpen;
        bool isDragging;

        OSWindow(std::string title, float x, float y, float w, float h);

        void Draw();
        void Update();

};

#endif