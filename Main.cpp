#include "Utils.h"

using namespace std;

int main()
{
	string input;
	bool running = true;  
  TextColor(11);
  cout << "Welcome to BORK: A Tale of Tails!\n";
  TextColor(15);
	while (running)
  {
    cin >> input;
    if (input == "bazinga")
    {
      cout << "How did you know?!\n";
      Pause();
      running = false;
    }
    else cout << "I'm not listenning! Lalala~!\n";
	}
	return 0;
}