//header for CommandWords class

#pragma once

class CommandWords {
private:
  char validCommands[8][80] = {"go", "quit", "help", "inventory", "get",
			       "drop", "look", "walkthrough"};

public:
  bool isCommand(char* phrase);
  void showAll();

  CommandWords();
};
