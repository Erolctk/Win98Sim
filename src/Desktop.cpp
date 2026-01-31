#include "Desktop.hpp"
#include <ctime>

Desktop::Desktop()
{
    myComputerIcon = LoadTexture("assets/icons/myComputer-32x32.png");
    TrashIcon = LoadTexture("assets/icons/Recycle-Bin-32x32.png");
    NotepadIcon = LoadTexture("assets/icons/NotePad-32x32.png");
    PaintIcon = LoadTexture("assets/icons/Paint-32x32.png");
    StartIcon = LoadTexture("assets/icons/icon-Win-32x32.png");
    FolderIcon = LoadTexture("assets/icons/Folder-32x32.png");
}

Desktop::~Desktop()
{
    UnloadTexture(myComputerIcon);
    UnloadTexture(TrashIcon);
    UnloadTexture(NotepadIcon);
    UnloadTexture(PaintIcon);
    UnloadTexture(StartIcon);
    UnloadTexture(FolderIcon);
}

void Desktop::Update()
{
    Vector2 mousePos = GetMousePosition();

    for(auto& icon : icons)
    {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, icon.rect))
        {
            float currentTime = GetTime();
            if(currentTime - icon.lastClickTime < 0.3f)
            {
                AddWindow(icon.label);
            }
            icon.lastClickTime = currentTime;
        }
    }

    bool mouseHandled = false;

    for(int i = windows.size() - 1; i >= 0; i--)
    {

        if(!mouseHandled && windows[i].isOpen)
        {
            Rectangle titleBar = {windows[i].rect.x, windows[i].rect.y, windows[i].rect.width, 25};
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, titleBar) || IsKeyDown(KEY_ENTER))
            {
               mouseHandled = true; 
            }
        }

        windows[i].Update();

        if(!windows[i].isOpen)
        {
            windows.erase(windows.begin() + i);
            continue;
        }

        if(windows[i].isDragging && i != windows.size() - 1)
        {
            OSWindow temp = windows[i];
            windows.erase(windows.begin() + i);
            windows.push_back(temp);
            break;
        }
    }
}

void Desktop::Draw()
{
    int barY = GetScreenHeight() - 30;
    DrawRectangle(0, barY, GetScreenWidth(), barY, LIGHTGRAY);
    DrawLine(0, barY, GetScreenWidth(), barY, WHITE);

    time_t now = time(0);
    struct tm tstruct;
    char buf[10];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%H:%M", &tstruct);

    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();
    DrawRectangle(screenW - 65, screenH - 25, 60, 20, LIGHTGRAY);

    DrawLine(screenW - 65, screenH - 25, screenW - 5, screenH - 25, GRAY);
    DrawLine(screenW - 65, screenH - 25, screenW - 65, screenH - 5, GRAY);

    DrawText(buf, screenW - 50, screenH - 20, 10, BLACK);

    int btnX = 5;
    int btnY = GetScreenHeight() - 25;
    DrawRectangle(btnX, btnY, 65, 20, LIGHTGRAY);
    DrawLine(btnX, btnY, btnX + 65, btnY, WHITE);
    DrawLine(btnX, btnY, btnX, btnY + 20, WHITE);
    DrawLine(btnX + 65, btnY, btnX + 65, btnY + 20, BLACK);
    DrawLine(btnX, btnY + 20, btnX + 65, btnY + 20, BLACK);

    DrawTextureEx(StartIcon, {(float)btnX + 4, (float)btnY +2}, 0.0f, 0.5f, WHITE);
    DrawText("Start", btnX + 24, btnY + 5, 10, BLACK);

    for(auto& icon : icons)
    {
        DrawTextureEx(icon.texture, {icon.rect.x, icon.rect.y}, 0.0f, 1.0f, WHITE);
        DrawText(icon.label.c_str(), icon.rect.x - 5, icon.rect.y + 40, 10, WHITE);
    }
    
    for(auto& win : windows)
    {
        win.Draw();
    }
}

void Desktop::AddWindow(std::string title)
{
    float offset = windows.size() * 20.0f;
    windows.push_back(OSWindow(title, 100 + offset, 100 + offset, 400, 300));
}

void Desktop::AddIcon(std::string label, Texture2D tex, float x, float y)
{
    icons.push_back({{x, y, 40, 40}, label, tex, 0.0f});
}
