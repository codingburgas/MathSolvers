#pragma once

#include <iostream>
#include "raylib.h"
#include "menu.h"
#include <fstream>
#include <string>
#include <iostream>

void game(SceneType& sceneState, bool* SpinnerEditMode,int* SpinnerValue);
void login(SceneType& sceneState, bool* UserBoxEditMode ,bool* PassBoxEditMode,char* UserBoxInput, char* PassBoxInput);
void reg(SceneType& sceneState,bool* RUserBoxEditMode ,bool* RPassBoxEditMode,char* RUserBoxInput, char* RPassBoxInput);