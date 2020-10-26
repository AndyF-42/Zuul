//header for Item class

#pragma once

class Item {
public:
  char description[80];
  char nick[20];
  bool isStone;

  char* getNick();
  char* getDescription();
  bool getTag();
  
  
  Item(char* newDescription, char* newNick, bool isStone);
};
