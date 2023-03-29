#pragma once

#include "main.h"
#include "menu.h"
#include "game.h"
#include "raylib.h"
#include <cmath>
using namespace std;

int main(){
    
    SceneType currentScene = MAIN_MENU;
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Math Solvers - Game");

    SetExitKey(0);
    // login data base

    bool UserBoxEditMode = false;
    char UserBoxInput[128] = "";
    bool PassBoxEditMode = false; 
    char PassBoxInput[128] = "";
    //sound
    // register date base
    bool RPassBoxEditMode = false;
    char RPassBoxInput[128] = "";
    bool RUserBoxEditMode = false;
    char RUserBoxInput[128] = "";
    //game 
    int level = 0; 
    int score = 0; 
    //timer
    float problemTimer = 30 - 2* level;
    int problemTimer_x = 0;

	int dec[10]{};
    // binary Sum
    int binarySum = 0;
    int remainTasks = 0;
    int binaryValue[8]= {0,0,0,0,0,0,0,0};
    for (int i = 0; i < 10; i++){
        dec[i] = GetRandomValue(0,255);
    }
    // ValueBOxes input
    int valueBox1 = 0;
    int valueBox2 = 0;
    int valueBox3 = 0;
    int valueBox4 = 0;
    int valueBox5 = 0;
    int valueBox6 = 0;
    int valueBox7 = 0;
    int valueBox8 = 0;

    Texture binaryZero = LoadTexture("../img/frames/buttons/binary0.png");
    Texture binaryOne = LoadTexture("../img/frames/buttons/binary1.png");

    Texture2D background_color = LoadTexture("../img/frames/background.png");

    while (!WindowShouldClose())
    {            
            if (problemTimer > 0)
                problemTimer -= GetFrameTime();

            if (problemTimer < 0) problemTimer = 0;
        BeginDrawing();
        DrawTexture(background_color,0,0,WHITE);
        switch (currentScene)
        {
        case LOGIN_MENU:
            remainTasks = 0;
            level = 0;
            login(currentScene, &UserBoxEditMode ,&PassBoxEditMode, UserBoxInput, PassBoxInput);
            break;
        case REGISTER_MENU:
            reg(currentScene,&RUserBoxEditMode, &RPassBoxEditMode ,RUserBoxInput,RPassBoxInput);
            break;
        case MAIN_MENU:
            remainTasks = 0;
            level = 0;
            if(IsKeyPressed(KEY_F11)){
                currentScene = LOGIN_MENU;
            }
            mainMenu(currentScene);
            break;
        case SECOND_MENU:
            remainTasks = 0;
            level = 0;
            if(IsKeyPressed(KEY_ESCAPE)){
                currentScene = MAIN_MENU;
            }
            secondMenu(currentScene,&problemTimer,level);
            break;
        case ABOUT_MENU:
            if(IsKeyPressed(KEY_ESCAPE)){
                currentScene = MAIN_MENU;
            }
            aboutMenu(currentScene);
            break;
        case HELP_MENU:
            if(IsKeyPressed(KEY_ESCAPE)){
                currentScene = MAIN_MENU;
            }
            helpMenu(currentScene);
            break;
        case LOST_MENU:
            remainTasks = 0;
            level = 0;
            lostMenu(currentScene,&problemTimer,level);
            break;
        case WON_MENU:
            remainTasks = 0;
            level = 0;
            wonMenu(currentScene,&problemTimer,level);
            break;
        case GAME_MENU:
            game(currentScene,dec,binaryValue,binarySum,&remainTasks,&valueBox1,&valueBox2,&valueBox3,&valueBox4,&valueBox5,&valueBox6,&valueBox7,&valueBox8,&problemTimer,problemTimer_x,level);
            if (valueBox1 == 1){
                DrawTexture(binaryOne, 67,790, WHITE);
            } else{
                DrawTexture(binaryZero, 67,790, WHITE);
            }
            if (valueBox2 == 1){
                DrawTexture(binaryOne, 207,790, WHITE);
            } else {
                DrawTexture(binaryZero, 207,790, WHITE);
            }
            if (valueBox3 == 1){
                DrawTexture(binaryOne, 347,790, WHITE);
            } else {
                DrawTexture(binaryZero, 347,790, WHITE);
            }
            if (valueBox4 == 1){
                DrawTexture(binaryOne, 487,790, WHITE);
            } else {
                DrawTexture(binaryZero, 487,790, WHITE);
            }
            if (valueBox5 == 1){
                DrawTexture(binaryOne, 627,790, WHITE);
            } else {
                DrawTexture(binaryZero, 627,790, WHITE);
            }
            if (valueBox6 == 1){
                DrawTexture(binaryOne, 767,790, WHITE);
            } else {
                DrawTexture(binaryZero, 767,790, WHITE);
            }
            if (valueBox7 == 1){
                DrawTexture(binaryOne, 907,790, WHITE);
            } else {
                DrawTexture(binaryZero, 907,790, WHITE);
            }
            if (valueBox8 == 1){
                DrawTexture(binaryOne, 1047,790, WHITE);
            } else {
                DrawTexture(binaryZero, 1047,790, WHITE);
            }
            levelbar(remainTasks,&level, &score);
                if (remainTasks == 5){
                    level += 1;
                    remainTasks = 0;
                }            
            break;
        } 

        EndDrawing();
       
    }

    CloseWindow();
};