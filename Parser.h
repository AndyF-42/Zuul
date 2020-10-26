//header for Parser class

#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
  CommandWords commands;

public:
  Command getCommand();
  void showCommands();

  Parser();
};
