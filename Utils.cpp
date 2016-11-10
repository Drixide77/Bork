#include "Utils.h"

void Split(string& str, list<string>& words)
{
  int pos = 0;
  string token;
  while ((pos = str.find(" ")) != string::npos) {
    token = str.substr(0, pos);
    words.push_back(token);
    str.erase(0, pos + 1);
  }
  words.push_back(str);
}

void Uncase(string& str)
{
  for (int i = 0; i < str.length(); ++i)
  {
    if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
    if (str[i] == '\n') str[i] = ' ';
  };
}

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
