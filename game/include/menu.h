#include <iostream>
#include "raylib.h"



enum SceneType
{
    MAIN_MENU,
    SECOND_MENU,
    ABOUT_MENU,
    GAME_MENU

};
enum ButtonCheck{
    firstFrame, 
    secondFrame
};
void mainMenu(SceneType& sceneState);
void secondMenu(SceneType& sceneState);
void aboutMenu(SceneType& sceneState);
void game(SceneType& sceneState);