#include "IconManager.hpp"

IconManager::IconManager()
{
}

IconManager::~IconManager()
{
}

void IconManager::AddIcon(AppType type, const std::string &label, Texture2D texture, float x, float y)
{
    Icon newIcon;
    newIcon.Rec = {x, y, 40, 40};
    newIcon.label = label;
    newIcon.icon = texture;
    newIcon.LastClickTime = 0.0f;
    newIcon.appType = type;

    icon.push_back(newIcon);
}

void IconManager::Update()
{
    Vector2 mousePos = GetMousePosition();

    if(!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return;

    for(auto& ic : icon)
    {
        if(!CheckCollisionPointRec(mousePos, ic.Rec)) continue;

        float now = GetTime();
        constexpr float DOUBLE_CLICK_TIME = 0.3;

        if(ic.LastClickTime > 0 && now - ic.LastClickTime < DOUBLE_CLICK_TIME)
        {
            onIconDoubleClick(ic.label, ic.icon);
            ic.LastClickTime = 0;
        }else{
            ic.LastClickTime = now;
        }
    }
}

void IconManager::Draw()
{
    for(auto& ic : icon)
    {
        DrawTexture(ic.icon, ic.Rec.x, ic.Rec.y, WHITE);
        DrawText(ic.label.c_str(), ic.Rec.x, ic.Rec.y + ic.Rec.height + 2, 10, BLACK);
    }
}
