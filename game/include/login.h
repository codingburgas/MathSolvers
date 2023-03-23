#pragma once

#include <iostream>
#include <fstream>
#include <string.h>
#include "raylib.h"
#include "main.h"

void login(bool* UserBoxEditMode ,char* UserBoxInput,bool* PassBoxEditMode ,char* PassBoxInput,int count, string userId, string password,string id, string pass);
void reg(bool* RUserBoxEditMode ,char* RUserBoxInput,bool* RPassBoxEditMode ,char* RPassBoxInput,string ruserId, string rpassword, string rid, string rpass);

enum LoginType
{
    LOGIN,
    REG,
    FORGET,
    GUEST

};