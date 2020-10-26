//header for CommandWords class

#pragma once

class CommandWords {
private:
  char validCommands[9][80] = {"go", "quit", "help", "inventory", "get",
			       "drop", "look", "walkthrough", "eat"};

public:
  bool isCommand(char* phrase);
  void showAll();

  CommandWords();
};