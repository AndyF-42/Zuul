//header for Command class

#pragma once

class Command {
public:
  char command[80];
  char subject[80];

  char* getCommand();
  char* getSubject();
  bool isUnknown();
  bool hasSubject();

  Command(char* firstWord, char* secondWord);
};
