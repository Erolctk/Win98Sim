#ifndef ICONMANAGER_HPP
#define ICONMANAGER_HPP

#include "raylib.h"
#include <string>
#include <vector>
#include <functional>
#include "AppType.hpp"

class IconManager 
{
    public:
        IconManager();
        ~IconManager();

        std::function<void(const std::string&, Texture2D)> onIconDoubleClick;

        void AddIcon(AppType type, const std::string& label, Texture2D icon, float x, float y);
        void Update();
        void Draw();

    private:
        struct Icon
        {
            Rectangle Rec;
            std::string label;
            Texture2D icon;
            float LastClickTime;
            AppType appType;
        };

        std::vector<Icon> icon;
};


#endif