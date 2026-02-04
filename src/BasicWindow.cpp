#include "BasicWindow.hpp"
#include "raylib.h"

BasicWindow::BasicWindow(const std::string& title, Texture2D icon, float x, float y, float w, float h)
{
    this->title = title;
    rect = {x, y, w, h};

    titleIcon = icon;
    hasIcon = true;

    isOpen = true;
    isDragging = false;

    activeColor = DARKBLUE;

    float btnS = 5;
    float gap = 5.0f;

    CloseButton = { rect.x + rect.width - btnS - gap, rect.y + 5, btnS, btnS };
    MaximizeButton = { rect.x + rect.width - (btnS * 2) - (gap * 2), rect.y + 5, btnS, btnS };
    MinimizeButton = { rect.x + rect.width - (btnS * 3) - (gap * 3), rect.y + 5, btnS, btnS };
}

void BasicWindow::Draw()
{
    if(!isOpen) return;
    if(isMinimized) return;

    DrawRectangleRec(rect, LIGHTGRAY);
    DrawLine(rect.x, rect.y, rect.x + rect.width, rect.y, WHITE);
    DrawLine(rect.x, rect.y, rect.x, rect.y + rect.height, WHITE);
    DrawRectangle(rect.x + 3, rect.y + 3, rect.width - 6, 20, activeColor);

    if(hasIcon)
    {
        DrawTextureEx(titleIcon, {rect.x + 6, rect.y + 6}, 0.0f, 0.5, WHITE);
    }

    float textOffset = hasIcon ? 26.0f : 10.0f;
    DrawText(title.c_str(), rect.x + textOffset, rect.y + 7, 10, WHITE);

    // Close button
    DrawRectangleRec(CloseButton, RED);
    DrawText("X", CloseButton.x + 5, CloseButton.y + 3, 10, WHITE);

    //Maximize button
    DrawRectangleRec(MaximizeButton, GRAY);
    DrawText("[]", MaximizeButton.x + 5, MaximizeButton.y + 2, 15, BLACK);

    //Minimize button
    DrawRectangleRec(MinimizeButton, GRAY);
    DrawText("-", MinimizeButton.x + 2, MinimizeButton.y, 30, BLACK);
}

void BasicWindow::Restore()
{
    isMinimized = false;
}

const std::string &BasicWindow::GetTitle() const
{
    return title;
}

void BasicWindow::Update()
{
    /*if(!isOpen) return;

    Vector2 mousePos = GetMousePosition();
    Rectangle titleBar = {rect.x, rect.y, rect.width, 25};

    CloseButton = {rect.x + rect.width - 21, rect.y + 5, 15, 15};
    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, CloseButton))
    {
        isOpen = false;
    }

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, titleBar))
    {
        isDragging = true;
    }

    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    {
        isDragging = false;
    }

    if(isDragging)
    {
        Vector2 delta = GetMouseDelta();
        rect.x += delta.x;
        rect.y += delta.y;
    }

    MinimizeButton.x = rect.x + rect.width - 45;
    MinimizeButton.y = rect.y + 5;*/

    if(!isOpen) return;

    Vector2 mousePos = GetMousePosition();
    Rectangle titleBar = {rect.x, rect.y, rect.width, 25};

    // --- MANUEL BUTON GÜNCELLEME ---
    float btnS = 18.0f;
    float gap = 5.0f;

    CloseButton    = { rect.x + rect.width - btnS - gap, rect.y + 5, btnS, btnS };
    MaximizeButton = { rect.x + rect.width - (btnS * 2) - (gap * 2), rect.y + 5, btnS, btnS };
    MinimizeButton = { rect.x + rect.width - (btnS * 3) - (gap * 3), rect.y + 5, btnS, btnS };
    // -------------------------------

    // Kapatma butonu kontrolü
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, CloseButton))
    {
        isOpen = false;
    }

    // Küçültme butonu kontrolü
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, MinimizeButton))
    {
        isMinimized = true;
        if(onMinimize) onMinimize(this);
    }

    // Sürükleme mantığı (Butonlara basılmadığından emin oluyoruz)
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, titleBar))
    {
        if(!CheckCollisionPointRec(mousePos, CloseButton) && !CheckCollisionPointRec(mousePos, MinimizeButton))
        {
            isDragging = true;
        }
    }

    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) isDragging = false;

    if(isDragging)
    {
        Vector2 delta = GetMouseDelta();
        rect.x += delta.x;
        rect.y += delta.y;
    }

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, MinimizeButton))
    {
        isMinimized = true;

        if(onMinimize)
        {
            onMinimize(this);
        }
    }
}
