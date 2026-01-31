#include "Window.hpp"

OSWindow::OSWindow(std::string title, float x, float y, float w, float h)
{
    this->title = title;
    this->rect = {x, y, w, h};
    this->activeColor = {0, 0, 128, 255};
    this->isOpen = true;
    this->isDragging = false;
}

void OSWindow::Draw()
{
    if(!isOpen) return;

    DrawRectangleRec(rect, LIGHTGRAY);
    DrawLine(rect.x, rect.y, rect.x + rect.width, rect.y, WHITE);
    DrawLine(rect.x, rect.y, rect.x, rect.y + rect.height, WHITE);
    DrawRectangle(rect.x + 3, rect.y + 3, rect.width - 6, 20, activeColor);
    DrawText(title.c_str(), rect.x + 10, rect.y + 7, 10, WHITE);

    //Close (X) button
    DrawRectangleRec(closeButton, RED);
    DrawText("X", closeButton.x + 4, closeButton.y + 2, 10, WHITE);
}

void OSWindow::Update()
{
    if(!isOpen) return;

    Vector2 mousePos = GetMousePosition();
    Rectangle titleBar = {rect.x, rect.y, rect.width, 25};

    this->closeButton = {rect.x + rect.width - 20, rect.y + 5, 15, 15};
    Vector2 mouse = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouse, closeButton))
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
}
