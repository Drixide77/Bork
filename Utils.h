#ifndef __Utils__
#define __Utils__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <conio.h>
#include <windows.h>

using namespace std;

//Contain global definitions and functions

void Split(string& str, list<string>& words);

void Uncase(string& str);

//-------------------- Console Related Functions --------------------

// Pause(): Halts execution until a key is pressed
void Pause();

// TextColor(color): Changes the color in what the text will print. color = Int (0-15)
// 0 = Black, 8 = Gray / 1 = Blue, 9 = Light Blue / 2 = Green, 10 = Light Green / 3 = Aqua, 11 = Light Aqua 
// 4 = Red, 12 = Light Red / 5 = Purple, 13 = Light Purple / 6 = Yellow, 14 = Light Yellow / 7 = White, 15 = Bright White
void TextColor(const int& color);

#endif
