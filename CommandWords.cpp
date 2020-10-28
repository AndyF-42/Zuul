//body of CommandWords class

#include <iostream>
#include <cstring>
#include "CommandWords.h"

using namespace std;

//needs nothing in constructor
CommandWords::CommandWords() {
}

//returns true if given phrase is one of the valid commands
bool CommandWords::isCommand(char* phrase) {
  for (int i = 0; i < sizeof(validCommands); i++) {
    if (strcmp(validCommands[i], phrase) == 0) {
      return true;
    }
  }
  return false;
}

//prints out all the valid commands
void CommandWords::showAll() {
  for (int i = 0; i < sizeof(validCommands); i++) {
    cout << validCommands[i] << " ";
  }
  cout;
}
