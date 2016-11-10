#include "World.h"
#include "Utils.h"
#include "memleaks.h"

using namespace std;

//Entry point of the game
int main()
{
  ReportMemoryLeaks(); //From memleaks

	string input;
	bool running = true;  
  World world;

  TextColor(11);
  cout << "Welcome to BORK: A Tale of Tails!\n";
  cout << "\n";
  TextColor(15);

	while (running)
  {
    getline(cin, input);
    running = world.sendCommands(input);
    cout << "\n";
	}
	return 0;
}
