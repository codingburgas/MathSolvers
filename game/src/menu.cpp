#include "raylib.h"
#include "menu.h"
#include <iostream>


using namespace std;

void mainMenu(SceneType& sceneState){
    Rectangle menu_game = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 100, 400, 100 };
    Rectangle menu_about = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 25, 400, 100  };
    Rectangle menu_quit = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 150, 400, 100 };

    Color rectangeColor = BLUE;
    Color rectangeColor1 = BLUE;
    Color rectangeColor2 = BLUE;
    //fonts
    Font text_font = LoadFont("game/font/8bitlimr.ttf");
    Vector2 text_position = {GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 400};
    Vector2 text_position1 = {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 300};

    bool nextState = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    

    if(IsKeyPressed (KEY_C)){
        ToggleFullscreen();
    }

    if (CheckCollisionPointRec(GetMousePosition(),menu_game)){
        rectangeColor = ORANGE;
        if(nextState){
            sceneState = SECOND_MENU;
        }
    } else {
        rectangeColor = BLUE;
    }
    if (CheckCollisionPointRec(GetMousePosition(),menu_about)){
        rectangeColor1 = ORANGE;
        if (nextState){
            sceneState = ABOUT_MENU;
        }
    } else {
        rectangeColor1 = BLUE;
    }
    if (CheckCollisionPointRec(GetMousePosition(),menu_quit)){
        rectangeColor2 = ORANGE;
        if (nextState){
            CloseWindow();
        }
    } else {
        rectangeColor2 = BLUE;
    }
        DrawTextEx(text_font, "The Game", text_position, 100.0f , 5, BLACK);
        DrawTextEx(text_font,"(Math Solvers)",text_position1, 50.0f,2, LIGHTGRAY);
            // Draw rectangles
        DrawRectangleRec(menu_game, rectangeColor);
        DrawRectangleRec(menu_about, rectangeColor1);
        DrawRectangleRec(menu_quit, rectangeColor2);
        DrawText("Games",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 - 70,30, WHITE);
        DrawText("About",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 60,30, WHITE);
        DrawText("Quit",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 190,30, WHITE);

}   

void secondMenu(SceneType& sceneState){
    
    Rectangle menu_game = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 100, 400, 100 };
    Rectangle menu_game2 = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 25, 400, 100 };
    Rectangle menu_help = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 150, 400, 100  };
    Rectangle menu_quit = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 275, 400, 100 };

    Color rectangeColor = BLUE;
    Color rectangeColor1 = BLUE;
    Color rectangeColor2 = BLUE;
    Color rectangeColor3 = BLUE;
    //fonts
    Font text_font = LoadFont("game/font/8bitlimr.ttf");
    Vector2 text_position = {GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 400};
    Vector2 text_position1 = {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 300};
    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        DrawTextEx(text_font, "The Game", text_position, 100.0f , 5, BLACK);
        DrawTextEx(text_font,"(Math Solvers)",text_position1, 50.0f,2, LIGHTGRAY);
            // Draw rectangles
        DrawRectangleRec(menu_game, rectangeColor);
        DrawRectangleRec(menu_game2, rectangeColor1);
        DrawRectangleRec(menu_help, rectangeColor2);
        DrawRectangleRec(menu_quit, rectangeColor3);
        
        DrawText("Game1",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 - 70,30, WHITE);
        DrawText("Game2",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 60,30, WHITE);
        DrawText("Help",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 190,30, WHITE);
        DrawText("Back",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 320,30, WHITE);

        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),menu_game)){
            rectangeColor = ORANGE;
            if (nextScene){
                sceneState = GAME_MENU;
            }
        } else {
            rectangeColor = BLUE;
        }
        if (CheckCollisionPointRec(GetMousePosition(),menu_game2)){
            rectangeColor1 = ORANGE;
            
        } else {
            rectangeColor1 = BLUE;
        }
        if (CheckCollisionPointRec(GetMousePosition(),menu_help)){
            rectangeColor2 = ORANGE;
        } else {
            rectangeColor2 = BLUE;
        }
        if (CheckCollisionPointRec(GetMousePosition(),menu_quit)){
            rectangeColor3 = ORANGE;
            if(nextScene){
                sceneState = MAIN_MENU;
            }
        } else {
            rectangeColor3 = BLUE;
        }
    }
void aboutMenu(SceneType& sceneState){
    Texture2D first_pic = LoadTexture("../game/mat/frames/button1.png");
    // button
    Rectangle menu_back = { GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 325, 400, 100 };
    //color for the button
    Color rectangeColor = BLUE;

    //fonts

    Font text_font = LoadFont("game/font/8bitlimr.ttf");
    Vector2 text_position = {GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 400};
    Vector2 text_position1 = {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 300};
    bool nextScene = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    DrawTextEx(text_font, "The Game", text_position, 100.0f , 5, BLACK);
    DrawTextEx(text_font,"(Math Solvers)",text_position1, 50.0f,2, LIGHTGRAY);
    
        if(IsKeyPressed (KEY_C)){
            ToggleFullscreen();
        }

        if (CheckCollisionPointRec(GetMousePosition(),menu_back)){
            rectangeColor = ORANGE;
            if(nextScene){
                sceneState = MAIN_MENU;
            }
        } else {
            rectangeColor = BLUE;
        }
        DrawRectangleRec(menu_back, rectangeColor);
        DrawText("Back",GetScreenWidth() / 2 - 40, GetScreenHeight() / 2 + 355,30, WHITE); 
    

    }
void game(SceneType& sceneState){

    //positions
    Rectangle rec_lines = {300, 1080 - 200, 100,100};
    Rectangle rec_lines1 = {300, 1080 - 200, 100,100};
    Vector2 startPos = {300, 870};
    Vector2 endPos = {1175, 870};
    //structure 
    DrawRectangle(100, 100, 1300, 1000, SKYBLUE);
    DrawRectangleRec(rec_lines, WHITE);
    DrawRectangleLinesEx(rec_lines,3.0f, BLACK);    
    //rectangles
    Rectangle rec_pos = {300, 1080 - 330, 100,100};
    //color of the buttons

    Color buttonColor1 = WHITE;
    Color buttonColor2 = WHITE;
    Color buttonColor3 = WHITE;
    Color buttonColor4 = WHITE;
    Color buttonColor5 = WHITE;
    Color buttonColor6 = WHITE;
    Color buttonColor7 = WHITE;
    Color buttonColor8 = WHITE;

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
    DrawLineBezier(startPos, endPos, 5.0f, BLACK);

    const char *button_text = "0";
    //the buttons
    DrawRectangle(410, 1080 - 330, 100,100, buttonColor2);
    DrawRectangle(520, 1080 - 330, 100,100, buttonColor3);
    DrawRectangle(630, 1080 - 330, 100,100, buttonColor4);
    DrawRectangle(740, 1080 - 330, 100,100, buttonColor5);
    DrawRectangle(850, 1080 - 330, 100,100, buttonColor6);
    DrawRectangle(960, 1080 - 330, 100,100, buttonColor7);
    DrawRectangle(1070, 1080 - 330, 100,100,buttonColor8);

    if (CheckCollisionPointRec(GetMousePosition(),rec_pos)){
        button_text = "0";
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            button_text = "1";
            buttonColor1 = ORANGE;
        }

    }
    else {
        button_text = "0";
    }
    DrawRectangle(300, 1080 - 330, 100,100, buttonColor1);
    DrawText(button_text,350, 1080 - 300, 30, BLACK);


    

}
