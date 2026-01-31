#include "raylib.h"
#include "Desktop.hpp"

const Color WIN98_DESKTOP = { 0, 128, 128, 255 };

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1024, 768, "Windows 98 Simulator");
    Image icon = LoadImage("assets/icons/icon-Win-32x32.png");
    SetWindowIcon(icon);
    UnloadImage(icon);
    SetTargetFPS(60);

    Desktop myDesktop;

    myDesktop.AddIcon("My Computer", myDesktop.myComputerIcon, 20, 20);
    myDesktop.AddIcon("Trash", myDesktop.TrashIcon, 20, 100);
    myDesktop.AddIcon("Notepad", myDesktop.NotepadIcon, 20, 180);
    myDesktop.AddIcon("Paint", myDesktop.PaintIcon, 20, 260);
    myDesktop.AddIcon("Folder", myDesktop.FolderIcon, 20, 340);

    while(!WindowShouldClose())
    {
        myDesktop.Update();

        BeginDrawing();
        ClearBackground(WIN98_DESKTOP);
        
        myDesktop.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}