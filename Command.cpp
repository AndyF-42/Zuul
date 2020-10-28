//body of Command class

#include <iostream>
#include <cstddef>
#include <cstring>
#include "Command.h"

using namespace std;

//set strings to empty, then if NULL was not passed in,
//copy in the passed words
Command::Command(char* firstWord, char* secondWord) {
  strcpy(command, "");
  if (firstWord != NULL) {
    strcpy(command, firstWord);
  }
  strcpy(subject, "");
  if (secondWord != NULL) {
    strcpy(subject, secondWord);
  }
}

//getters
char* Command::getCommand() {
  return command;
}
char* Command::getSubject() {
  return subject;
}

//returns false if command exists, otherwise true 
bool Command::isUnknown() {
  return (strcmp(command, "") == 0);
}
//returns true if the command has no second word, otherwise false
bool Command::hasSubject() {
  return (strcmp(subject, "") != 0);
}
