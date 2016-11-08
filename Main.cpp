#include "World.h"
#include "Utils.h"

using namespace std;

//Entry point of the game
int main()
{
	string input;
	bool running = true;  
  World world = World();
  Player* player = world.player;

  TextColor(11);
  cout << "Welcome to BORK: A Tale of Tails!\n";
  TextColor(15);
	while (running)
  {
    cin >> input;
    running = (player)->parseCommands(input);
	}
	return 0;
}
