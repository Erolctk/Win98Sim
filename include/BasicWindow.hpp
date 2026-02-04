#ifndef BASICWINDOW_HPP
#define BASICWINDOW_HPP

#include "Window.hpp"
#include <functional>

class BasicWindow : public OSWindow
{
    public:
        BasicWindow(const std::string& title, Texture2D icon, float x, float y, float w, float h);

        void Update() override;
        void Draw() override;
        void Restore();

        const std::string& GetTitle() const;
        std::function<void(BasicWindow*)> onMinimize;

        Rectangle getRect() const { return rect; }
        bool getIsDragging() const { return isDragging; }

    protected:
        Rectangle rect;
        Rectangle CloseButton;
        std::string title;
        Color activeColor;
        bool isDragging;

        Texture2D titleIcon;
        //Texture2D GetIcon() const { return titleIcon; }

        bool hasIcon = false;

        bool isMinimized = false;
        Rectangle MinimizeButton;
        Rectangle MaximizeButton;
};

#endif