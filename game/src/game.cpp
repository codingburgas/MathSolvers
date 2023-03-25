#pragma once

#include "game.h"
#include <iostream>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
using namespace std;


void game(SceneType& sceneState, bool* SpinnerEditMode,int* SpinnerValue, int value,int value1, int value2, int value3, int value4, int value5, int value6,int value7,int* sum){

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


    GuiValueBox(Rectangle {300, 1080-310, 80,80}, "", &value, 0, 1, false);
    GuiValueBox(Rectangle {410, 1080-310, 80,80}, "", &value1, 0, 1, false);
    GuiValueBox(Rectangle {520, 1080-310, 80,80}, "", &value2, 0, 1, false);
    GuiValueBox(Rectangle {630, 1080-310, 80,80}, "", &value3, 0, 1, false);
    GuiValueBox(Rectangle {740, 1080-310, 80,80}, "", &value4, 0, 1, false);
    GuiValueBox(Rectangle {850, 1080-310, 80,80}, "", &value5, 0, 1, false);
    GuiValueBox(Rectangle {960, 1080-310, 80,80}, "", &value6, 0, 1, false);
    GuiValueBox(Rectangle {1070, 1080-310, 80,80}, "", &value7, 0, 1, false);
    
    

    
    
}
void login(SceneType& sceneState, bool* UserBoxEditMode ,bool* PassBoxEditMode,char* UserBoxInput, char* PassBoxInput){
    string userId, password,id, pass; 

    int count = 0;
    
    DrawRectangle(622,140,700,800, GRAY);
    DrawText("LOGIN", 895,246,50, WHITE);
    DrawRectangle(722,602, 500, 90, GREEN);
    DrawText("ENTER", 891,620,50, WHITE);
    DrawText("Don't you have an account?", 841,715,20, WHITE);


    if (GuiTextBox((Rectangle){ 722, 373, 500, 80 }, UserBoxInput, 128, UserBoxEditMode)){
            *UserBoxEditMode = !*UserBoxEditMode
    }

    else if (GuiTextBox((Rectangle){ 722, 478, 500, 80 }, PassBoxInput, 128, PassBoxEditMode)) {
            *PassBoxEditMode = !*PassBoxEditMode;
        
    }

    userId = UserBoxInput;
    password = PassBoxInput;

    ifstream read(userId + ".txt");
    getline(read, id);
    getline(read, pass);
    
    if(id == userId && pass == password){
        count = 1;
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
    string userId, password, id, pass;
    
    DrawRectangle(622,140,700,800, GRAY);
    DrawText("REGISTER", 852,246,50, WHITE);
    DrawRectangle(722,602, 500, 90, GREEN);
    DrawText("CREATE", 877,620,50, WHITE);

    if (GuiTextBox((Rectangle){ 722, 373, 500, 80 }, RUserBoxInput, 128, RUserBoxEditMode)) *RUserBoxEditMode = !*RUserBoxEditMode;
    if (GuiTextBox((Rectangle){ 722, 478, 500, 80 }, RPassBoxInput, 128, RPassBoxEditMode)) *RPassBoxEditMode = !*RPassBoxEditMode;

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
