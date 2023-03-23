#pragma once

#include <iostream>
#include "raylib.h"
#include "menu.h"
#include "main.h"


void login(SceneType& sceneState, bool* UserBoxEditMode ,char* UserBoxInput,bool* PassBoxEditMode, char* PassBoxInput);
void reg(SceneType& sceneState,bool* RUserBoxEditMode ,char* RUserBoxInput,bool* RPassBoxEditMode ,char* RPassBoxInput);

