//body of Item class

#include <cstring>
#include "Item.h"

Item::Item(char* newDescription, char* newNick, char* newTag) {
  strcpy(description, newDescription);
  strcpy(nick, newNick);
  strcpy(tag, newTag);
}

char* Item::getNick() {
  return nick;
}
char* Item::getDescription() {
  return description;
}
char* Item::getTag() {
  return tag;
}
