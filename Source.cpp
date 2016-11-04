#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	bool running = true;

  cout << "Welcome to BORK: A Tale of Tails!" << endl;
	while (running) {
    cin >> input;
    if (input == "bazinga") {
      cout << "How did you know?!" << endl;
      running = false;
    }
    else cout << "I'm not listenning! Lalala~!" << endl;
	}
	
	return 0;
}
