#pragma once

#include "game.h"
#include <iostream>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
using namespace std;

void levelbar(){
    DrawRectangle(1382,55,500,80 ,WHITE);
    DrawRectangle(1382,55,100,80 ,RED);
}

void game(SceneType& sceneState, bool* SpinnerEditMode,int* SpinnerValue){

    //positions
    Rectangle rec_lines = {300, 1080 - 200, 100,100};
    Rectangle rec_lines1 = {300, 1080 - 200, 100,100};
    Vector2 startPos = {300, 870};
    Vector2 endPos = {1175, 870};
    //structure
    Color rec_text = CLITERAL(Color){ 3, 43, 67, 255 };
    Color rec_text1 = CLITERAL(Color){ 63, 136, 197, 255 };
    DrawRectangle(0,0,1920,1080,rec_text1);
    DrawRectangle(100, 0, 1300, 1080, rec_text);
    DrawRectangleRec(rec_lines, WHITE);
    DrawRectangleLinesEx(rec_lines,3.0f, BLACK);    
    //rectangles
    Rectangle rec_pos = {300, 1080 - 330, 100, 100};
    //color of the buttons

    Rectangle rec_pos1 =  { 800, 360, 120, 24 };



    for (int i = 0; i < 7; i++){
        rec_lines.x += 110;
        DrawRectangleRec(rec_lines, WHITE);
        DrawRectangleLinesEx(rec_lines,3.0f, BLACK);
    }
    DrawText("128",350, 1080 - 175, 30, BLACK);
    DrawText("64",460, 1080 - 175, 30, BLACK);
    DrawText("32",570, 1080 - 175, 30, BLACK);
    DrawText("16",680, 1080 - 175, 30, BLACK);
    DrawText("8",790, 1080 - 175, 30, BLACK);
    DrawText("4",900, 1080 - 175, 30, BLACK);
    DrawText("2",1010, 1080 - 175, 30, BLACK);
    DrawText("1",1120, 1080 - 175, 30, BLACK);
    DrawLineBezier(startPos, endPos, 5.0f, WHITE);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
    GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, 0x904a888a );

    if (GuiSpinner((Rectangle){ 1200, 1080- 300, 120, 60 }, "", SpinnerValue, 0, 255, *SpinnerEditMode)) {
        *SpinnerEditMode = !*SpinnerEditMode;
    }

        
    levelbar();

    
    
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
                WaitTime(1);
                sceneState = MAIN_MENU;
            }
        }
    } 
}
void reg(SceneType& sceneState,bool* RUserBoxEditMode ,bool* RPassBoxEditMode,char* RUserBoxInput ,char* RPassBoxInput){
    string userId, password, id, pass;
    
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
