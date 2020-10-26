//main Game class

#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Command.h"
#include "CommandWords.h"
#include "Parser.h"

using namespace std;

void createRooms(vector<Room*>* vRooms);
bool processCommand(Command command);
void printInventory();
void dropItem();
void getItem();
void printHelp();
void goRoom(Command command);
void eat(Command command);
void ruinGame();
bool quit(Command command);

int main() {

  Parser* parser = new Parser();
  vector<Room*>* vRooms;
  int stonesPlaced = 0;
  bool nothingPlaced = false;
  bool notSaid = true;
  vector<Item*>* inventory;

  createRooms(vRooms);
  Room* currentRoom = vRooms->at(0); //start game in mainCave

  //Inventory  
  inventory->push_back(new Item((char*)("An elvish sword of great antiquity"), (char*)("sword"), false));
  
  //print welcome

  //while not finished, get commands

}

void createRooms(vector<Room*>* vRooms) {
  //Create rooms
  Room* mainCave = new Room((char*)("You are in a massive cave, with mysterious openings all around you.\nAbove you is an opening in the cave where light shines through.\nIn the middle of the room is a pedestal, with 6 holes of different shapes."), (char*)("Main Cave"));
  Room* laboratory = new Room((char*)("Test tubes, pipettes, and beakers full of strange liquids\nfill the room. You probably shouldn't touch anything."), (char*)("Laboratory"));
  Room* livingQuarters = new Room((char*)("This is where you assume people lived, whoever\nwould be crazy enough to live here. You notice\na bunk bed at the end of the room"), (char*)("Living Quarters"));

  //Set Exits
  mainCave->setExit((char*)("north"), laboratory);
  mainCave->setExit((char*)("east"), livingQuarters);
  vRooms->push_back(mainCave);

  laboratory->setExit((char*)("south"), mainCave);
  vRooms->push_back(laboratory);

livingQuarters->setExit((char*)("west"), mainCave);
  vRooms->push_back(livingQuarters);

}

bool processCommand(Command command) {
  return false;
}

void printInventory() {

}

void dropItem() {

}

void getItem() {

}

void printHelp() {

}

void goRoom(Command command) {

}

void eat(Command command) {

}

void ruinGame() {

}

bool quit(Command command) {
  return false;
}
