#pragma once

#include "menu.h"
#include <iostream>
#include "raylib.h"

using namespace std;

void mainMenu(SceneType& sceneState){
    Texture2D menu_game = LoadTexture("../img/frames/buttons/play.png");
    Texture2D menu_about = LoadTexture("../img/frames/buttons/about.png");
    Texture2D menu_quit = LoadTexture("../img/frames/buttons/exit.png");

    Texture2D game_title = LoadTexture("../img/frames/mathsolvers.png");


    bool nextState = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    if(IsKeyPressed (KEY_C)){
        ToggleFullscreen();
    }

    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){777 ,537,458,119})){
        menu_game = LoadTexture("../img/frames/buttons/play_hovered.png");
        if(nextState){
            sceneState = SECOND_MENU;
        }
    } 
    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){777 ,675,458,119})){
        menu_about = LoadTexture("../img/frames/buttons/about_hovered.png");
        if (nextState){
            sceneState = ABOUT_MENU;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){777 ,813,458,119})){
        menu_quit = LoadTexture("../img/frames/buttons/exit_hovered.png");
        if (nextState){
            CloseWindow();
        }
    } 
        DrawTexture(game_title,562 ,269 ,WHITE); 

            // Draw rectangles
        DrawTexture(menu_game, 777 ,537 , WHITE);
        DrawTexture(menu_about, 777 ,675 , WHITE);
        DrawTexture(menu_quit, 777 ,813, WHITE);

    
}   

void secondMenu(SceneType& sceneState){
    
    Texture2D menu_game = LoadTexture("../img/frames/buttons/game.png");
    Texture2D menu_help = LoadTexture("../img/frames/buttons/help.png");
    Texture2D menu_back = LoadTexture("../img/frames/buttons/back.png");

    Texture2D game_title = LoadTexture("../img/frames/mathsolvers.png");

    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    DrawTexture(game_title,562 ,269,WHITE); 

    // Draw rectangles
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){777 ,537,458,119})){
            menu_game = LoadTexture("../img/frames/buttons/game_hovered.png");
            if (nextScene){
                sceneState = GAME_MENU;
            }
        } 
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){777 ,675,458,119})){
            menu_help = LoadTexture("../img/frames/buttons/help_hovered.png");
        } 
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){777 ,813,458,119})){
            menu_back = LoadTexture("../img/frames/buttons/back_hovered.png");
            if(nextScene){
                sceneState = MAIN_MENU;
            }
        } 
       
        DrawTexture(menu_game, 777 ,537 , WHITE);
        DrawTexture(menu_help, 777 ,675 , WHITE);
        DrawTexture(menu_back, 777 ,813, WHITE);
        
    }
void aboutMenu(SceneType& sceneState){
    Texture2D menu_back = LoadTexture("../img/frames/buttons/back.png");
    //color for the button
    Texture2D game_title = LoadTexture("../img/frames/mathsolvers.png");
    DrawTexture(game_title,562,86,WHITE); 

    //fonts

    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){777,935,458,119})){
            menu_back = LoadTexture("../img/frames/buttons/back_hovered.png");
            if(nextScene){
                sceneState = MAIN_MENU;
            }
        } 
        DrawTexture(menu_back, 777,935, WHITE);
    }
