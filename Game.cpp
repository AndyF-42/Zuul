//main Game class

#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Command.h"
#include "CommandWords.h"
#include "Parser.h"

using namespace std;

void createRooms(vector<Room*>* vRooms, Room* currentRoom);
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
  Room* currentRoom;
  vector<Room*>* vRooms = new vector<Room*>();
  int stonesPlaced = 0;
  bool nothingPlaced = false;
  bool notSaid = true;
  vector<Item*>* inventory = new vector<Item*>();

  createRooms(vRooms, currentRoom);
  

  //Inventory  
  Item* sword = new Item((char*)("An elvish sword of great antiquity"), (char*)("sword"), false);
  inventory->push_back(sword);

  
  //print welcome
  cout << "You wake up in a strange cave. It's dark in here, but from" << endl;
  cout << "the ceiling there shines a beam of light. You realize that" << endl;
  cout << "it is the only way out, but how will you get up there?" << endl;
  cout << "Suddenly, the ground starts vibrating and you hear the walls" << endl;
  cout << "of the cave moving around you. When it's over, the room has" << endl;
  cout << "changed. Maybe you can find a way to get out now?" << endl;
  cout << "\nType \"help\" if you need help.\n";
  cout << currentRoom->getLongDescription() << endl;

  //while not finished, get commands

}

void createRooms(vector<Room*>* vRooms, Room* currentRoom) {
  //Create rooms
  Room* mainCave = new Room((char*)("You are in a massive cave, with mysterious openings all around you.\nAbove you is an opening in the cave where light shines throubtgh.\nIn the middle of the room is a pedestal, with 6 holes of different shapes."), (char*)("Main Cave"));
  Room* laboratory = new Room((char*)("Test tubes, pipettes, and beakers full of strange liquids\nfill the room. You probably shouldn't touch anything."), (char*)("Laboratory"));
  Room* livingQuarters = new Room((char*)("This is where you assume people lived, whoever\nwould be crazy enough to live here. You notice\na bunk bed at the end of the room"), (char*)("Living Quarters"));

  //Set Exits
  mainCave->setExit((char*)("north"), laboratory);
  mainCave->setExit((char*)("east"), livingQuarters);
  currentRoom = mainCave; //start game in main cave
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
