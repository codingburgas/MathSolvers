#include "raylib.h"
enum SceneType
{
    MAIN_MENU,
    SECOND_MENU,
    ABOUT_MENU,
    GAME_MENU

};

void mainMenu(SceneType& sceneState);
void secondMenu(SceneType& sceneState);
void aboutMenu(SceneType& sceneState);
void game(SceneType& sceneState);