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

    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711 ,519,458,119})){
        menu_game = LoadTexture("../img/frames/buttons/play_hovered.png");
        if(nextState){
            sceneState = SECOND_MENU;
        }
    } 
    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711 ,657,458,119})){
        menu_about = LoadTexture("../img/frames/buttons/about_hovered.png");
        if (nextState){
            sceneState = ABOUT_MENU;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711 ,795,458 ,119})){
        menu_quit = LoadTexture("../img/frames/buttons/exit_hovered.png");
        if (nextState){
            CloseWindow();
        }
    } 
        DrawTexture(game_title,525  ,292 ,WHITE); 

            // Draw rectangles
        DrawTexture(menu_game, 711  ,519  , WHITE);
        DrawTexture(menu_about, 711 ,657 , WHITE);
        DrawTexture(menu_quit, 711 ,795 , WHITE);

}   

void secondMenu(SceneType& sceneState,float* problemTimer, int level){
    
    Texture2D menu_game = LoadTexture("../img/frames/buttons/game.png");
    Texture2D menu_help = LoadTexture("../img/frames/buttons/help.png");
    Texture2D menu_back = LoadTexture("../img/frames/buttons/back.png");

    Texture2D game_title = LoadTexture("../img/frames/mathsolvers.png");

    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    DrawTexture(game_title,525 ,292,WHITE); 

    // Draw rectangles
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711 ,519,458,119})){
            menu_game = LoadTexture("../img/frames/buttons/game_hovered.png");
            if (nextScene){
                *problemTimer = 30 - 2* level;

                sceneState = GAME_MENU;
            }
        } 
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711 ,657,458,119})){
            menu_help = LoadTexture("../img/frames/buttons/help_hovered.png");
            if (nextScene){
                sceneState = HELP_MENU;
            }
        } 
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711 ,795,458,119})){
            menu_back = LoadTexture("../img/frames/buttons/back_hovered.png");
            if(nextScene){
                sceneState = MAIN_MENU;
            }
        } 
       
        DrawTexture(menu_game, 711 ,519 , WHITE);
        DrawTexture(menu_help, 711 ,657 , WHITE);
        DrawTexture(menu_back, 711 ,795, WHITE);

        
    }
void aboutMenu(SceneType& sceneState){
    Texture2D menu_back = LoadTexture("../img/frames/buttons/back.png");
    //color for the button
    Texture2D game_title = LoadTexture("../img/frames/mathsolvers.png");

    Texture2D about_d = LoadTexture("../img/frames/aboutdimi.png");
    Texture2D about_i = LoadTexture("../img/frames/aboutivan.png");
    Texture2D about_m = LoadTexture("../img/frames/aboutmishev.png");
    DrawTexture(game_title,525,86,WHITE); 

    //fonts

    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711,935,458,119})){
            menu_back = LoadTexture("../img/frames/buttons/back_hovered.png");
            if(nextScene){
                sceneState = MAIN_MENU;
            }
        } 
        DrawTexture(menu_back, 711,935, WHITE);

        DrawTexture(about_d, 451,616, WHITE);
        DrawTexture(about_i, 136,308, WHITE);
        DrawTexture(about_m, 1133,401, WHITE);


    }
void helpMenu(SceneType& sceneState){
    Texture2D menu_back = LoadTexture("../img/frames/buttons/back.png");
    //color for the button
    Texture2D game_title = LoadTexture("../img/frames/mathsolvers.png");
    Texture2D helpContent = LoadTexture("../img/frames/helpMenuContent.png");
    DrawTexture(game_title,525,86,WHITE); 

    //fonts

    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711,795,458,119})){
            menu_back = LoadTexture("../img/frames/buttons/back_hovered.png");
            if(nextScene){
                sceneState = SECOND_MENU;
            }
        } 
        DrawTexture(menu_back, 711,795, WHITE);
        DrawTexture(helpContent, 268,354, WHITE);

    }