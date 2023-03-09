#include "raylib.h"
#include <iostream>

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 500;
    InitWindow(screenWidth, screenHeight, "MathSolvers - GAME");
    
    Rectangle btnBounds = {100, 200, 100, 200};
    Color rectangeColor = BLUE;
    SetTargetFPS(60);               
    // Main game loop
    while (!WindowShouldClose())  
    {   
        if (CheckCollisionPointRec(GetMousePosition(),btnBounds)){
            rectangeColor = ORANGE;
        } else {
            rectangeColor = BLUE;
        }
        
        BeginDrawing();
            DrawText("The Game",300 , 200, 30, BLUE); 
            ClearBackground(RAYWHITE);
            DrawRectangle(0, 0, 100, 200, rectangeColor);
        EndDrawing();
    }
    return 0;
}
