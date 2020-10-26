//body of Room class

#include <cstring>
#include <cstddef>
#include "Room.h"

Room::Room(char* inputDescription, char* inputRoom) {
  strcpy(description, inputDescription);
  strcpy(roomName, inputRoom);
}

void Room::setExit(char* direction, Room neighbor) {
  exits->insert({direction, neighbor});
}
char* Room::getShortDescription() {
  return description;
}
char* Room::getRoom() {
  return roomName;
}
char* Room::getLongDescription() {
  char* output = new char[160];
  strcpy(output, getRoom());
  strcat(output, "\n");
  strcat(output, description);
  strcat(output, "\n");
  strcat(output, getExitString());

  return output;
}
char* Room::getExitString() {
  char* returnString = new char[50];

  strcpy(returnString, "Exits:");
  /*
  Set keys = exits.keySet();
  iter stuff
  */
  return returnString;
}
Item Room::getItem(int index) {
  return items->at(index);
}
Item* Room::getItem(char* itemName) {
  for (int i = 0; i < strlen(itemName); i++) {
    itemName[i] = tolower(itemName[i]);
  }
  for (int i = 0; i < sizeof(items); i++) {
    if (strcmp(items->at(i).getDescription(), itemName) == 0
	|| strcmp(items->at(i).getNick(), itemName) == 0) {
      return items.at(i);
    }
  }
  return NULL;
}
void Room::setItem(Item newItem) {
  items.push_back(newItem);
}
char* Room::getRoomItems() {
  char* output = new char[160];
  for (int i = 0; sizeof(items); i++) {
    strcat(output, "\n");
    strcat(output, items[i].getDescription());
  }
  return output;
}
void Room::removeItem(Item item) {
  for (int i = 0; sizeof(items); i++) {
    if (strcmp(items[i].getDescription(), item.getDescription()) == 0) {
      items.erase(items.begin()+i);
    }
  }
}
Room Room::getExit(char* direction) {
  return exits.at(direction);
}
