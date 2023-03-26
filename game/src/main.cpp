#pragma once

#include "main.h"
#include "menu.h"
#include "game.h"
#include "raylib.h"
#include <cmath>
using namespace std;

int main(){
    
    SceneType currentScene = LOGIN_MENU;
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Math Solvers - Game");
    //
    bool SpinnerEditMode = false;
    int SpinnerValue = 0;
    // login data base

    bool UserBoxEditMode = false;
    char UserBoxInput[128] = "";
    bool PassBoxEditMode = false; 
    char PassBoxInput[128] = "";

    // register date base
    bool RPassBoxEditMode = false;
    char RPassBoxInput[128] = "";
    bool RUserBoxEditMode = false;
    char RUserBoxInput[128] = "";

    Texture2D background_color = LoadTexture("../img/frames/background.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawTexture(background_color,0,0,WHITE);
        
        switch (currentScene)
        {
        case LOGIN_MENU:
            login(currentScene, &UserBoxEditMode ,&PassBoxEditMode, UserBoxInput, PassBoxInput);
            break;
        case REGISTER_MENU:
            reg(currentScene,&RUserBoxEditMode, &RPassBoxEditMode ,RUserBoxInput,RPassBoxInput);
            break;
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
            game(currentScene,&SpinnerEditMode,&SpinnerValue);
            break;
        } 

        EndDrawing();
       
    }
    UnloadTexture(background_color);
    CloseWindow();
};