//body of Command class

#include <cstddef>
#include <cstring>
#include "Command.h"

Command::Command(char* firstWord, char* secondWord) {
  if (firstWord != NULL) {
    strcpy(command, firstWord);
  }
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
  return (command == NULL);
}
bool Command::hasSubject() {
  return (subject != NULL);
}
