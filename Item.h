//header for Item class

#pragma once

class Item {
public:
  char description[80];
  char nick[20];
  char tag[20];

  char* getNick();
  char* getDescription();
  char* getTag();
  
  
  Item(char* newDescription, char* newNick, char* newTag);
};
