//body of Command class

#include <iostream>
#include <cstddef>
#include <cstring>
#include "Command.h"

using namespace std;

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

char* Command::getCommand() {
  return command;
}
char* Command::getSubject() {
  return subject;
}

bool Command::isUnknown() {
  return (strcmp(command, "") == 0);
}
bool Command::hasSubject() {
  return (strcmp(subject, "") != 0);
}
