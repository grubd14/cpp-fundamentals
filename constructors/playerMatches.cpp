//An example to show parameterized constructor along with classes and
//objects

#include <iostream>

using namespace std;

class Player {
public:
  string playerName;
  int playerNum;
  int playerMatchesNum;
  int* playerGoalsNum;

  Player(string name, int num, int match, int goal)  {
    playerName = name;
    playerNum = num;
    playerMatchesNum = match;
    playerGoalsNum = new int[playerMatchesNum];
    
    //initializing the goals array with zeros
    for (int i = 0; i < playerMatchesNum; i++) {
      playerGoalsNum[i] = 0;
    }
  }

  //destructor
  ~Player() {
    delete[] playerGoalsNum;
  }

  void setGoals(int matchIndex, int goals) {
    if (matchIndex >= 0 && matchIndex < playerMatchesNum) {
      playerGoalsNum[matchIndex] = goals;
    }
  }

  void displayPlayerInfo() {
    cout << "Player No: " << playerName << endl;
    cout << "Name: " << playerNum << endl;
    cout << "Number of Matches: " << playerMatchesNum << endl;
    cout << "Goals in each match: ";
    for (int i = 0; i < playerMatchesNum; i++) {
      cout << playerGoalsNum[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Player p1("Sushil", 10, 100, 66);
  cout << "Player Name: " << p1.playerName ;
  cout << "Player No: " << p1.playerNum;
}
