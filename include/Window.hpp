#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "raylib.h"
#include <string>

class OSWindow
{
    public:
        virtual ~OSWindow() = default;

        virtual void Update() = 0;
        virtual void Draw() = 0;

        bool isOpen = true;
};

#endif