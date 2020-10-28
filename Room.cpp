//body of Room class

#include <cstring>
#include <cstddef>
#include "Room.h"

using namespace std;

Room::Room(char* inputDescription, char* inputRoom) {
  strcpy(description, inputDescription);
  strcpy(roomName, inputRoom);
  exits = new unordered_map<char*, Room*>();
  items = new vector<Item*>();
}

void Room::setExit(char* direction, Room* neighbor) {
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

  for (unordered_map<char*, Room*>::iterator it = exits->begin(); it != exits->end(); ++it) {
    strcat(returnString, " ");
    strcat(returnString, it->first);
  }
  strcat(returnString, "\nIn this room you see:");
  if (strcmp(getRoomItems(), "") == 0) {
    strcat(returnString, "\nNothing");
  }
  else {
    strcat(returnString, getRoomItems());
  }
  
  return returnString;
}
Item* Room::getItem(int index) {
  return items->at(index);
}
Item* Room::getItem(char* itemName) {
  for (int i = 0; i < strlen(itemName); i++) {
    itemName[i] = tolower(itemName[i]);
  }
  for (int i = 0; i < items->size(); i++) {
    if (strcmp(items->at(i)->getDescription(), itemName) == 0
	|| strcmp(items->at(i)->getNick(), itemName) == 0) {
      return items->at(i);
    }
  }
  return NULL;
}
void Room::setItem(Item* newItem) {
  items->push_back(newItem);
}
char* Room::getRoomItems() {
  char* output = new char[160];

  if (items->size() == 0) {
    return (char*)("");
  }
  else {
    for (vector<Item*>::iterator it = items->begin(); it != items->end(); ++it) {
      strcat(output, "\n ");
      strcat(output, (*it)->getDescription());
    }
    return output;
  }
}
void Room::removeItem(Item* item) {
  for (int i = 0; sizeof(items); i++) {
    if (strcmp(items->at(i)->getDescription(), item->getDescription()) == 0) {
      items->erase(items->begin()+i);
      break;
    }
  }
}
Room* Room::getExit(char* direction) {
  unordered_map<char*, Room*>::const_iterator got = exits->find(direction);
  if (got == exits->end()) { //did not find room
    return NULL;
  }
  else {
    return got->second;
  }
}
