#include <iostream>
#include "menu.h"
#include "raylib.h"

using namespace std;

int main(){
    Color background_color = {100,10,10};

    SceneType currentScene = MAIN_MENU;
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Math Solvers - Game");

    bool SpinnerEditMode = false;
    int SpinnerValue = 0;
    int sum = 0;
    int value = GetRandomValue(0,1);
    int value1 = GetRandomValue(0,1);
    int value2 = GetRandomValue(0,1);
    int value3 = GetRandomValue(0,1);
    int value4 = GetRandomValue(0,1);
    int value5 = GetRandomValue(0,1);
    int value6 = GetRandomValue(0,1);
    int value7 = GetRandomValue(0,1);

    if (value == 1){
        sum += 128;
    }
    if (value1 == 1){
        sum += 64;
    }
    if (value2 == 1){
        sum += 32;
    }
    if (value3 == 1){
        sum += 16;
    }
    if (value4 == 1){
        sum += 8;
    }
    if (value5 == 1){
        sum += 4;
    }
    if (value6 == 1){
        sum += 2;
    }
    if (value7 == 1){
        sum += 1;
    }
    
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
            game(currentScene,&SpinnerEditMode,&SpinnerValue, value,value1,value2,value3,value4,value5,value6,value7,&sum);
            break;
        }
        EndDrawing();
    }
    
    CloseWindow();
};