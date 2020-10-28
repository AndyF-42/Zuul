//body of Room class

#include <cstring>
#include <cstddef>
#include "Room.h"

using namespace std;

//copy in the strings, initialize exits map and items vector on the heap
Room::Room(char* inputDescription, char* inputRoom) {
  strcpy(description, inputDescription);
  strcpy(roomName, inputRoom);
  exits = new unordered_map<char*, Room*>();
  items = new vector<Item*>();
}

//insert a paired direction and neighbor into the exits map 
void Room::setExit(char* direction, Room* neighbor) {
  exits->insert({direction, neighbor});
}

//getters
char* Room::getShortDescription() {
  return description;
}
char* Room::getRoom() {
  return roomName;
}

//long description = room name, room description, room exits, and room items
char* Room::getLongDescription() {
  char* output = new char[160];
  strcpy(output, getRoom());
  strcat(output, "\n");
  strcat(output, description);
  strcat(output, "\n");
  strcat(output, getExitString());

  return output;
}

//the exit string is the room exits and the room items
char* Room::getExitString() {
  char* returnString = new char[50];

  strcpy(returnString, "Exits:");
  //use iterator to print out all the exits
  for (unordered_map<char*, Room*>::iterator it = exits->begin(); it != exits->end(); ++it) {
    strcat(returnString, " ");
    strcat(returnString, it->first); //only first because that is the direction
  }
  //print items ("Nothing" if no items)
  strcat(returnString, "\nIn this room you see:");
  if (strcmp(getRoomItems(), "") == 0) {
    strcat(returnString, "\nNothing");
  }
  else {
    strcat(returnString, getRoomItems());
  }
  
  return returnString;
}

//find item in room by index
Item* Room::getItem(int index) {
  return items->at(index);
}
//find item in room by name 
Item* Room::getItem(char* itemName) {
  //convert to lowercase
  for (int i = 0; i < strlen(itemName); i++) {
    itemName[i] = tolower(itemName[i]);
  }
  //check if any items in the room match the given itemName (description or nick)
  for (int i = 0; i < items->size(); i++) {
    if (strcmp(items->at(i)->getDescription(), itemName) == 0
	|| strcmp(items->at(i)->getNick(), itemName) == 0) {
      return items->at(i);
    }
  }
  return NULL;
}

//add an item into the room items vector
void Room::setItem(Item* newItem) {
  items->push_back(newItem);
}

//get all the items in the room
char* Room::getRoomItems() {
  char* output = new char[160];

  if (items->size() == 0) {
    return (char*)("");
  }
  else { //use iterator to walk through items vector and print descriptions
    for (vector<Item*>::iterator it = items->begin(); it != items->end(); ++it) {
      strcat(output, "\n ");
      strcat(output, (*it)->getDescription());
    }
    return output;
  }
}

//remove an item from the room
void Room::removeItem(Item* item) {
  //find the item (match the descriptions), erase it, then break to avoid crash
  for (int i = 0; sizeof(items); i++) {
    if (strcmp(items->at(i)->getDescription(), item->getDescription()) == 0) {
      items->erase(items->begin()+i);
      break;
    }
  }
}

//get the room that follows in a given direction
Room* Room::getExit(char* direction) {
  unordered_map<char*, Room*>::const_iterator got = exits->find(direction);
  if (got == exits->end()) { //did not find room
    return NULL;
  }
  else {
    return got->second; //second item in the map's tuple is the room
  }
}
