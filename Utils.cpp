#include "Utils.h"

void Pause() 
{
  cout << "<Press any key to continue>" << endl;
  while (!_kbhit());
}

void TextColor(const int& color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  if (color < 0 || color > 15) SetConsoleTextAttribute(hConsole, 15);
  else SetConsoleTextAttribute(hConsole, color);
}