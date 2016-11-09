#include "World.h"
#include "Utils.h"

using namespace std;

//Entry point of the game
int main()
{
	string input;
	bool running = true;  
  World world = World(); //Maybe it should be World world; without the = World() ?

  TextColor(11);
  cout << "Welcome to BORK: A Tale of Tails!\n";
  TextColor(15);
	while (running)
  {
    cin >> input;
    running = world.sendCommands(input);
	}
	return 0;
}
