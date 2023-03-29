#pragma once

#include "game.h"
#include <iostream>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
using namespace std;


void levelbar(int remainTasks, int* level,int* score){
    DrawRectangle(1047,54,450,83 ,WHITE);
    
    *score = 1000 * *level;
    DrawText(TextFormat("%d", *level), 1791,80,50,BLACK);
    DrawText(TextFormat("%d", *score), 1700,165,50,BLACK);
    DrawRectangle(1047,54,(100 * remainTasks),80 ,RED);  
    DrawText("Level Bar",1047,54,40,BLACK);
}

void game(SceneType& sceneState,int dec[8],int binaryValue[7],int binarySum,int* remainTasks,int* valueBox1,int* valueBox2,int* valueBox3,int* valueBox4,int* valueBox5,int* valueBox6,int* valueBox7,int* valueBox8,float* problemTimer, int problemTimer_x,int level){
    //rectangles pos
    
    Rectangle rectangle_pos = {1079, 791,100,91};
    int text_y = 0;

    Texture valueBoxTexture = LoadTexture("../img/frames/buttons/128.png");
    Texture valueBoxTexture1 = LoadTexture("../img/frames/buttons/64.png");
    Texture valueBoxTexture2 = LoadTexture("../img/frames/buttons/32.png");
    Texture valueBoxTexture3 = LoadTexture("../img/frames/buttons/16.png");
    Texture valueBoxTexture4 = LoadTexture("../img/frames/buttons/8.png");
    Texture valueBoxTexture5 = LoadTexture("../img/frames/buttons/4.png");
    Texture valueBoxTexture6 = LoadTexture("../img/frames/buttons/2.png");
    Texture valueBoxTexture7 = LoadTexture("../img/frames/buttons/1.png");

    Texture symEqual = LoadTexture("../img/frames/buttons/equal.png");
    Texture valueSum = LoadTexture("../img/frames/buttons/sectionInput.png");
    Texture scoreBoard = LoadTexture("../img/frames/buttons/border.png");
    Texture timeRemaining = LoadTexture("../img/frames/buttons/timeremaining.png");

    Texture2D exit_button = LoadTexture("../img/frames/exit_game.png");

        
       
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 67, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox1 = 1;
                binaryValue[0] = 128;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox1 = 0;
                binaryValue[0] = 0;
            }

        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 207, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox2 = 1;
                binaryValue[1] = 64;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox2 = 0;
                binaryValue[1] = 0;
            }

        }
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 347, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox3 = 1;
                binaryValue[2] = 32;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox3 = 0;
                binaryValue[2] = 0;
            }

        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 487, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox4 = 1;
                binaryValue[3] = 16;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox4 = 0;
                binaryValue[3] = 0;
                
            }

        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 627, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox5 = 1;
                binaryValue[4] = 8;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox5 = 0;
                binaryValue[4] = 0;
            }

        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 767, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox6 = 1;
                binaryValue[5] = 4;
                
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox6 = 0;
                binaryValue[5] = 0;
            }

        }
 
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 907, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox7 = 1;
                binaryValue[6] = 2;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox7 = 0;
                binaryValue[6] = 0;
            }

        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 1047, 791, 96, 91 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                *valueBox8 = 1;
                binaryValue[7] = 1;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                *valueBox8 = 0;
                binaryValue[7] = 0;
            }

        }
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){ 1540 , 906, 309, 93 })){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                sceneState = SECOND_MENU;
            }
        }

         for (int i = 0; i < 8; i++){
                binarySum += binaryValue[i];  
                
            }          
                
        DrawTexture(valueBoxTexture,67,897,WHITE);
        DrawTexture(valueBoxTexture1,207,897,WHITE);
        DrawTexture(valueBoxTexture2,347,897,WHITE);
        DrawTexture(valueBoxTexture3,487,897,WHITE);
        DrawTexture(valueBoxTexture4,627 ,897,WHITE);
        DrawTexture(valueBoxTexture5,766 ,897,WHITE);
        DrawTexture(valueBoxTexture6,906 ,897,WHITE);
        DrawTexture(valueBoxTexture7,1047,897,WHITE);
        DrawTexture(symEqual,1204,827,WHITE);
        DrawTexture(valueSum,1280,790,WHITE);
        DrawTexture(scoreBoard,1525,54,WHITE);
        DrawTexture(timeRemaining,380,342 ,WHITE);
        DrawTexture(exit_button,1540,906 ,WHITE);
        DrawText(TextFormat("%d", binarySum), 1362, 900,50,RED);  
        
        for(int i = 0; i < 1; i++){
            DrawText(TextFormat("%d", dec[i]), 1350, 808 - text_y,50,WHITE);
            text_y += 112;        
        }
        if (binarySum == dec[0]){
                *problemTimer = 30 - 2* level;
            
                dec[0] = GetRandomValue(0,255);
                *remainTasks += 1;
                    
        }

        if (*problemTimer <= 0)
        {
            sceneState = LOST_MENU;
        }
        else
        {
            if(*problemTimer <= 9){
                problemTimer_x = 40;
            }
            DrawText(TextFormat("%.0f", *problemTimer),560 + problemTimer_x,410, 160, BLACK);
        }
        if (level == 10){
            sceneState = WON_MENU;
        }
           

}
void lostMenu(SceneType& sceneState,float* problemTimer,int level){
    Texture2D menu_back = LoadTexture("../img/frames/buttons/lost_exit.png");
    Texture2D menu_again = LoadTexture("../img/frames/buttons/playagain.png");
    //color for the button

    //fonts

    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711,797,458,119})){
            menu_back = LoadTexture("../img/frames/buttons/lost_exit.png");
            if(nextScene){
                sceneState = SECOND_MENU;
            }
        } 
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711,608,458,119})){
            menu_again = LoadTexture("../img/frames/buttons/playagain.hovered.png");
            if(nextScene){
                sceneState = GAME_MENU;
            }
        } 
        DrawTexture(menu_again, 711,608 , WHITE);
        DrawTexture(menu_back, 711,797 , WHITE);
        DrawText("You Lost", 764,260 , 100, BLACK);
        level = 0;
        *problemTimer = 30 - 2* level;
        
        
    }
void wonMenu(SceneType& sceneState,float* problemTimer,int level){
    Texture2D menu_back = LoadTexture("../img/frames/buttons/lost_exit.png");
    Texture2D menu_again = LoadTexture("../img/frames/buttons/playagain.png");
    //color for the button

    //fonts

    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711,797,458,119})){
            menu_back = LoadTexture("../img/frames/buttons/lost_exit.png");
            if(nextScene){
                sceneState = SECOND_MENU;
            }
        } 
        if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){711,608,458,119})){
            menu_again = LoadTexture("../img/frames/buttons/playagain.hovered.png");
            if(nextScene){
                sceneState = GAME_MENU;
            }
        } 
        DrawTexture(menu_again, 711,608 , WHITE);
        DrawTexture(menu_back, 711,797 , WHITE);
        DrawText("You Won", 764,260 , 100, BLACK);
        level = 0;
        *problemTimer = 30 - 2* level;
        
        
    }

void login(SceneType& sceneState, bool* UserBoxEditMode ,bool* PassBoxEditMode,char* UserBoxInput, char* PassBoxInput){
    string userId, password,id, pass; 

    int count = 0;
    
    DrawRectangle(622,140,700,800, GRAY);
    DrawText("LOGIN", 895,246,50, WHITE);
    DrawRectangle(722,602, 500, 90, GREEN);
    DrawText("ENTER", 891,620,50, WHITE);
    DrawRectangleLines(841,715,300,20, GRAY);
    DrawText("Don't you have an account?", 841,715,20, WHITE);

    DrawRectangle(722, 373, 500, 80, WHITE);
    DrawRectangle(722, 478, 500, 80, WHITE);    
    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){841,715,300,20})){
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            sceneState = REGISTER_MENU;
        }
        
    }
    if (GuiTextBox((Rectangle){ 722, 373, 500, 80 }, UserBoxInput, 128, *UserBoxEditMode)){
            *UserBoxEditMode = !*UserBoxEditMode;
    }

    if (GuiTextBox((Rectangle){ 722, 478, 500, 80 }, PassBoxInput, 128, *PassBoxEditMode)){
            
            *PassBoxEditMode = !*PassBoxEditMode;
        
    }

    userId = UserBoxInput;
    password = PassBoxInput;

    ifstream read(userId + ".txt");
    getline(read, id);
    getline(read, pass);
    
    if(id == userId && pass == password){
        if(userId == "" or password == ""){
            count = 0;
        } else{
            count = 1;
        }
    
        
    }
    else {
        count = 0;
    }
    if (count == 1){
        if(CheckCollisionPointRec(GetMousePosition(),(Rectangle){722,602, 500, 90})){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                sceneState = MAIN_MENU;
            }
        }
    } 
}
void reg(SceneType& sceneState,bool* RUserBoxEditMode ,bool* RPassBoxEditMode,char* RUserBoxInput ,char* RPassBoxInput){
    string userId, password;
    
    DrawRectangle(622,140,700,800, GRAY);
    DrawText("REGISTER", 852,246,50, WHITE);
    DrawRectangle(722,602, 500, 90, GREEN);
    DrawText("CREATE", 877,620,50, WHITE);
    
    DrawRectangle(722, 373, 500, 80, WHITE);
    DrawRectangle(722, 478, 500, 80, WHITE);
    
    if (GuiTextBox((Rectangle){ 722, 373, 500, 80 }, RUserBoxInput, 128, *RUserBoxEditMode)) *RUserBoxEditMode = !*RUserBoxEditMode;
    if (GuiTextBox((Rectangle){ 722, 478, 500, 80 } ,RPassBoxInput, 128, *RPassBoxEditMode)) *RPassBoxEditMode = !*RPassBoxEditMode;

    userId = RUserBoxInput;
    password = RPassBoxInput;

    if(CheckCollisionPointRec(GetMousePosition(),(Rectangle){722,602,500,90})){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                    ofstream file;
                    file.open(userId + ".txt");
                    file << userId << endl << password << endl;
                    file.close();
                sceneState = LOGIN_MENU;
            }
    }

}
