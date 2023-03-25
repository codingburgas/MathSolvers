#pragma once

#include <iostream>
#include "raylib.h"
#include "menu.h"
#include <fstream>
#include <string>
#include <iostream>

void game(SceneType& sceneState, bool* SpinnerEditMode,int* SpinnerValue, int value,int value1, int value2, int value3, int value4, int value5, int value6,int value7,int* sum);
void login(SceneType& sceneState, bool* UserBoxEditMode ,bool* PassBoxEditMode,char* UserBoxInput, char* PassBoxInput);
void reg(SceneType& sceneState,bool* RUserBoxEditMode ,bool* RPassBoxEditMode,char* RUserBoxInput, char* RPassBoxInput);