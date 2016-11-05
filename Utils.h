#ifndef __Utils__
#define __Utils__

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <assert.h>

using namespace std;

//-------------------- Console Related Functions --------------------

// Pause(): Halts execution until next any key is pressed
void Pause();

// TextColor(color): Changes the color in what the text will print. color = Int (0-15)
// 0 = Black, 8 = Gray / 1 = Blue, 9 = Light Blue / 2 = Green, 10 = Light Green / 3 = Aqua, 11 = Light Aqua 
// 4 = Red, 12 = Light Red / 5 = Purple, 13 = Light Purple / 6 = Yellow, 14 = Light Yellow / 7 = White, 15 = Bright White
void TextColor(const int& color);

#endif
