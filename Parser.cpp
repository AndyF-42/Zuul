//body of Parser class

#include <string.h>
#include <cstddef>
#include <cstring>
#include <vector>
#include <iostream>
#include "Parser.h"

using namespace std;

Parser::Parser() {
  commands = CommandWords();
}

Command Parser::getCommand() {
  char inputLine[80];
  vector<char*> words;

  cout << ">> ";
  cin.get(inputLine, 80);
  cin.get();
 
  char *ptr;
  ptr = strtok(inputLine, " ");

  while (ptr != NULL) {
    words.push_back(ptr);
    ptr = strtok(NULL, " ");
  }
  
  if (words.size() > 2 || words.size() < 1) {
    cout << "1" << endl;
    return Command(NULL, NULL);
  }
  else if (commands.isCommand(words[0])) {
    if (words.size() == 2) {
      cout << "2" << endl;
      return Command(words[0], words[1]);
    }
    else {
      cout << "3" << endl;
      return Command(words[0], NULL);
    }
  }
  else {
    cout << "4" << endl;
    return Command(NULL, NULL);
  }
  
}

void Parser::showCommands() {
  commands.showAll();
}
