//body of CommandWords class

#include <iostream>
#include <cstring>
#include "CommandWords.h"

using namespace std;

CommandWords::CommandWords() {
}

bool CommandWords::isCommand(char* phrase) {
  for (int i = 0; i < sizeof(validCommands); i++) {
    if (strcmp(validCommands[i], phrase) == 0) {
      return true;
    }
  }
  return false;
}

void CommandWords::showAll() {
  for (int i = 0; i < sizeof(validCommands); i++) {
    cout << validCommands[i] << " ";
  }
  cout;
}
