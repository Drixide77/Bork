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

  //Printing game intro
  world.PrintIntro();

  //Game Loop
	while (running)
  {
    getline(cin, input);
    running = world.sendCommands(input);
    cout << "\n";
	}
  Pause();
	return 0;
}
