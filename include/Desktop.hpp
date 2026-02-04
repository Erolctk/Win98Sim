#ifndef DESKTOP_HPP
#define DESKTOP_HPP

#include "raylib.h"
#include "BasicWindow.hpp"
#include "IconManager.hpp"
#include <vector>
#include <string>
#include <memory>

class Desktop
{
    public:
        IconManager iconManager;
        
        std::vector<std::unique_ptr<BasicWindow>> windows;
        Texture2D myComputerIcon;
        Texture2D TrashIcon;
        Texture2D NotepadIcon;
        Texture2D PaintIcon;
        Texture2D FolderIcon;
        Texture2D StartIcon;
        Texture2D CalculatorIcon;
        Texture2D InternetIcon;

        Desktop();
        ~Desktop();

        void Update();
        void Draw();
        void AddWindow(const std::string& title, Texture2D icon);
        void AddIcon(std::string label, Texture2D tex, float x, float y);
};

#endif