//body of Parser class

#include <string.h>
#include <cstddef>
#include <cstring>
#include <vector>
#include <iostream>
#include "Parser.h"

using namespace std;

//creates CommandWords class for variable commands
Parser::Parser() {
  commands = CommandWords();
}

//function for parsing a command from user input 
Command Parser::getCommand() {
  char inputLine[80];
  vector<char*> words;

  //get input
  cout << ">> ";
  cin.get(inputLine, 80);
  cin.get();

  //use string tokenizers to split string on spaces
  char *ptr;
  ptr = strtok(inputLine, " ");

  while (ptr != NULL) {
    words.push_back(ptr);
    ptr = strtok(NULL, " ");
  }

  //if it is not 1 word or 2 words, it is bad, return NULL for both words
  if (words.size() > 2 || words.size() < 1) {
    return Command(NULL, NULL);
  }
  //right number of words, and the first is a valid command
  else if (commands.isCommand(words[0])) {
    if (words.size() == 2) { //for two words, return word 1 and word 2
      return Command(words[0], words[1]);
    }
    else { //for one word, return NULL for the second word
      return Command(words[0], NULL);
    }
  }
  //right number of words, but invalid command, return NULL for both words 
  else {
    return Command(NULL, NULL);
  }
}

//show all valid commands
void Parser::showCommands() {
  commands.showAll();
}
