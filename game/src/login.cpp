#include "login.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include "raylib.h"
#include "main.h"
using namespace std;

void login(bool* UserBoxEditMode ,char* UserBoxInput,bool* PassBoxEditMode ,char* PassBoxInput,int count, string userId, string password,string id, string pass){
    DrawRectangle(100, 100, 100, 100, GRAY);
    if (GuiTextBox((Rectangle){ 480, 216, 120, 24 }, UserBoxInput, 128, UserBoxEditMode)) UserBoxEditMode = !UserBoxEditMode;
    if (GuiTextBox((Rectangle){ 480, 216, 120, 24 }, PassBoxInput, 128, PassBoxEditMode)) PassBoxEditMode = !PassBoxEditMode;
    
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
        CloseWindow();
    } else {
        DrawText("Try Again", 130, 100, 20, BLACK);
        login();
    }
}
void reg(bool* RUserBoxEditMode ,char* RUserBoxInput,bool* RPassBoxEditMode ,char* RPassBoxInput,string ruserId, string rpassword, string rid, string rpass){
    DrawRectangle(100, 100, 100, 100,GRAY );

    if (GuiTextBox((Rectangle){ 480, 216, 120, 24 }, RUserBoxInput, 128, RUserBoxEditMode)) RUserBoxEditMode = !RUserBoxEditMode;
    if (GuiTextBox((Rectangle){ 480, 216, 120, 24 }, RPassBoxInput, 128, RPassBoxEditMode)) RPassBoxEditMode = !RPassBoxEditMode;

    ruserId = RUserBoxInput;
    rpassword = RPassBoxInput;

    ofstream f1("register.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    login();
}
