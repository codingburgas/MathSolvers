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
void game(SceneType& sceneState, bool* SpinnerEditMode,int* SpinnerValue, int value,int value1, int value2, int value3, int value4, int value5, int value6, int value7, int* sum

);