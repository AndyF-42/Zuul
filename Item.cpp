//body of Item class

#include <cstring>
#include "Item.h"

Item::Item(char* newDescription, char* newNick, bool newTag) {
  strcpy(description, newDescription);
  strcpy(nick, newNick);
  isStone = newTag;
}

char* Item::getNick() {
  return nick;
}
char* Item::getDescription() {
  return description;
}
bool Item::getTag() {
  return isStone;
}
