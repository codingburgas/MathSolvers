#include "raylib.h"
#include "menu.h"
#include <iostream>


using namespace std;

void game (){
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    char text_input;
    InitWindow(screenWidth,screenHeight, "Math Solvers - Game");

    while(!WindowShouldClose){
        BeginDrawing;
            ClearBackground(WHITE);
            DrawRectangle(GetScreenHeight() / 2 - 200, GetScreenWidth()/ 2 - 10, 20, 10, BLACK);
            

    }

}
