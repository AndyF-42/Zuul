//body of Item class

#include <cstring>
#include "Item.h"

//set up variables
Item::Item(char* newDescription, char* newNick, bool newTag) {
  strcpy(description, newDescription);
  strcpy(nick, newNick);
  isStone = newTag;
}

//getters
char* Item::getNick() {
  return nick;
}
char* Item::getDescription() {
  return description;
}
bool Item::getTag() {
  return isStone;
}
