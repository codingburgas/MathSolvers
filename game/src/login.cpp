
#include "login.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


void login(SceneType& sceneState, bool* UserBoxEditMode ,char* UserBoxInput,bool* PassBoxEditMode, char* PassBoxInput){
    string userId, password, id, pass;
    int count;
    
    DrawRectangle(622,140,700,800, GRAY);
    DrawText("LOGIN", 895,246,50, WHITE);
    DrawRectangle(722,602, 500, 90, GREEN);
    DrawText("ENTER", 891,620,50, WHITE);
    DrawText("Don't you have an account?", 841,715,20, WHITE);

    if (GuiTextBox((Rectangle){ 722, 373, 500, 80 }, UserBoxInput, 128, UserBoxEditMode)) UserBoxEditMode = !UserBoxEditMode;
    if (GuiTextBox((Rectangle){ 722, 478, 500, 80 }, PassBoxInput, 128, PassBoxEditMode)) PassBoxEditMode = !PassBoxEditMode;
    
    userId = UserBoxInput;
    password = PassBoxInput;

    ifstream input("register.txt");
    
    while(input>>id>>pass){
        if(id == userId && pass == password){
            count = 1;
        }
    }
    input.close();
    if (count == 1){
        if(CheckCollisionPointRec(GetMousePosition(),(Rectangle){722,602, 500, 90})){
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                sceneState = MAIN_MENU;
            }
        }
    } else {
        DrawText("Try Again", 881, 853, 30, RED);
    }
}
void reg(SceneType& sceneState,bool* RUserBoxEditMode ,char* RUserBoxInput,bool* RPassBoxEditMode ,char* RPassBoxInput){
    string ruserId, rpassword, rid, rpass;
    
    DrawRectangle(622,140,700,800, GRAY);
    DrawText("REGISTER", 852,246,50, WHITE);
    DrawRectangle(722,602, 500, 90, GREEN);
    DrawText("CREATE", 877,620,50, WHITE);

    if (GuiTextBox((Rectangle){ 722, 373, 500, 80 }, RUserBoxInput, 128, RUserBoxEditMode)) RUserBoxEditMode = !RUserBoxEditMode;
    if (GuiTextBox((Rectangle){ 722, 478, 500, 80 }, RPassBoxInput, 128, RPassBoxEditMode)) RPassBoxEditMode = !RPassBoxEditMode;

    ruserId = RUserBoxInput;
    rpassword = RPassBoxInput;

    ofstream f1("register.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    WaitTime(2);
    sceneState = LOGIN_MENU;
}
