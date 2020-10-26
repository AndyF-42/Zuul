//body of Parser class

#include <string.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include "Parser.h"

using namespace std;

Parser::Parser() {
  commands = CommandWords();
}

Command Parser::getCommand() {
  char inputLine[80];
  char word1[40];
  char word2[40];

  cout << ">> ";
  cin.get(inputLine, 80);
  cin.get();
 
  char *ptr;
  ptr = strtok(inputLine, " ");
  strcpy(word1, ptr);
  ptr = strtok(NULL, " ");
  strcpy(word2, ptr);

  if (commands.isCommand(word1)) {
    return Command(word1, word2);
  }
  else {
    return Command(NULL, word2);
  }
  
}

void Parser::showCommands() {
  commands.showAll();
}
