#include <iostream>
#include "menu.h"
#include "raylib.h"

using namespace std;

int main(){
    SceneType currentScene = MAIN_MENU;
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Math Solvers - Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        switch (currentScene)
        {
        case MAIN_MENU:
            mainMenu(currentScene);
            break;
        case SECOND_MENU:
            secondMenu(currentScene);
            break;
        
        case ABOUT_MENU:
            aboutMenu(currentScene);
            break;
        case GAME_MENU:
            game(currentScene);
            break;
        }
        EndDrawing();
    }
    
    CloseWindow();
}