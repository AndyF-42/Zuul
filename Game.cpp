//main Game class

#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Command.h"
#include "CommandWords.h"
#include "Parser.h"

using namespace std;

void createRooms(vector<Room*>* &vRooms, Room* &currentRoom);
bool processCommand(Command command, Parser* parser, vector<Item*>* &inventory, Room* &currentRoom, int &stonesPlaced, bool &nothingPlaced);
void printInventory(vector<Item*>* inventory);
void dropItem(Command command, vector<Item*>* &inventory, int &stonesPlaced, bool &nothingPlaced, Room* &currentRoom);
void getItem(Command command, Room* &currentRoom, vector<Item*>* &inventory);
void printHelp(Parser* parser);
void goRoom(Command command, Room* &currentRoom);
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
  cout << "\nType \"help\" if you need help.\n" << endl;
  cout << currentRoom->getLongDescription() << endl;

  
  
  //while not finished, get commands
  bool finished = false;
  while (!finished) {
    Command command = parser->getCommand();
    cout << "hi" << endl;
    //cout << "got command" << endl;
    finished = processCommand(command, parser, inventory, currentRoom, stonesPlaced, nothingPlaced);
    if (stonesPlaced == 6 && notSaid) {
      cout << "Huh. You totally thought that would work and you would be able to get out." << endl;
      cout << "What else would you even need? Nothing!" << endl;
    }
    if (nothingPlaced) {
      cout << "Turns out \"Nothing\" is exactly what you needed. The pedastal turns" << endl;
      cout << "into an upward beam, shining straight through the hole in the ceiling." << endl;
      cout << "You step into the beam and it lifts you off your feet, carrying you up" << endl;
      cout << "through the hole. Unfortunately, on your way up all the items you collected" << endl;
      cout << "fall out. But hey, you finally escaped!" << endl;
      finished = true;
    }
  }
  cout << "Thank you for playing!" << endl;
  
}

void createRooms(vector<Room*>* &vRooms, Room* &currentRoom) {
  //Create rooms
  Room* mainCave = new Room((char*)("You are in a large cave, with openings all around you.\nAbove is an opening where light shines through. In the\ncenter of the room is a pedestal with 6 holes."), (char*)("Main Cave"));
  Room* laboratory = new Room((char*)("Test tubes, pipettes, and beakers full of strange liquids\nfill the room. You probably shouldn't touch anything."), (char*)("Laboratory"));
  Room* livingQuarters = new Room((char*)("This is where you assume people lived, whoever\nwould be crazy enough to live here. You notice\na bunk bed at the end of the room."), (char*)("Living Quarters"));

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

bool processCommand(Command command, Parser* parser, vector<Item*>* &inventory, Room* &currentRoom, int &stonesPlaced, bool &nothingPlaced) {
  bool wantToQuit = false;

  if (command.isUnknown()) {
    cout << "I do not know what you mean..." << endl;
  }
  char commandWord[40];
  strcpy(commandWord, command.getCommand());

  cout << commandWord << endl;
  
  if (strcmp(commandWord, "help") == 0) {
    printHelp(parser);
  }
  if (strcmp(commandWord, "go") == 0) {
    goRoom(command, currentRoom);
  }
  if (strcmp(commandWord, "quit") == 0) {
    wantToQuit = quit(command);
  }
  if (strcmp(commandWord, "inventory") == 0) {
    cout << "pog" << endl;
    printInventory(inventory);
  }
  if (strcmp(commandWord, "get") == 0) {
    getItem(command, currentRoom, inventory);
  }
  if (strcmp(commandWord, "drop") == 0) {
    dropItem(command, inventory, stonesPlaced, nothingPlaced, currentRoom);
  }
  if (strcmp(commandWord, "look") == 0) {
    cout << currentRoom->getLongDescription() << endl;
  }
  if (strcmp(commandWord, "walkthrough") == 0) {
    ruinGame();
  }
  if (strcmp(commandWord, "eat") == 0) {
    eat(command);
  }
  return wantToQuit;
}

void printInventory(vector<Item*>* inventory) {
  cout << "You are holding:" << endl;
  for (int i = 0; i < inventory->size(); i++) {
    cout << " " << inventory->at(i)->getDescription() << endl;
  }
}

void dropItem(Command command, vector<Item*>* &inventory, int &stonesPlaced, bool &nothingPlaced, Room* &currentRoom) {
  
  if (!command.hasSubject()) { //cannot drop if no second word
    cout << "Drop what?" << endl;
    return;
  }
  
  char item[80];
  strcpy(item, command.getSubject());

  //try to get the item
  Item* newItem;
  int index = 0;
  for (int i = 0; inventory->size(); i++) {
    if (strcmp(inventory->at(i)->getDescription(), item) == 0 ||
	strcmp(inventory->at(i)->getNick(), item) == 0) {
      newItem = inventory->at(i);
      index = i;
    }
  }

  if (newItem == NULL) {
    cout << "That item is not in your inventory!" << endl;
  }
  else {
    if (newItem->getTag()) {
      cout << "You look at the stone as it glows bright and burns up." << endl;
      cout << "You frantically drop the stone but instead of falling down," << endl;
      cout << "it is attracted to the pedastal in the center of the cave." << endl;
      stonesPlaced++;
    }
    else if (strcmp(newItem->getNick(), "nothing") == 0 && stonesPlaced == 6) {
      nothingPlaced = true;
    }
    else {
      currentRoom->setItem(*newItem);
      cout << item << " dropped." << endl;
    }
    inventory->erase(inventory->begin() + index);
  }
    
}

void getItem(Command command, Room* &currentRoom, vector<Item*>* &inventory) {
  if (!command.hasSubject()) { //no specified item to get
    cout << "Get what?" << endl;
    return;
  }

  char item[80];
  strcpy(item, command.getSubject());

  Item* newItem = currentRoom->getItem(item);

  if (newItem == NULL) {
    cout << "That item is not here!" << endl;
  }
  else {
    if (strcmp(newItem->getNick(), "nothing") == 0) {
      cout << "You aren't quite sure what \"Nothing\" is, but you pick it up anyway." << endl;
    }
    inventory->push_back(newItem);
    currentRoom->removeItem(*newItem);
    cout << item << " acquired." << endl;
  }
}

void printHelp(Parser* parser) {
  cout << "You wander around the room and you find" << endl;
  cout << "a strange poster on the wall. It says:\n" << endl;
  cout << "Your command words are:" << endl;
  parser->showCommands();
  cout << "\nNote: \"walkthrough\" will spoil the entire game!" << endl;
  cout << "\nAlso note that when dropping and getting items" << endl;
  cout << "you do not need to spell out the full name." << endl;
}

void goRoom(Command command, Room* &currentRoom) {
  if (!command.hasSubject()) {//no second word, don't know where to go
    cout << "Go where?" << endl;
    return;
  }

  char direction[40];
  strcpy(direction, command.getSubject());

  //Try to leave current room
  Room* nextRoom = NULL;
  if (strcmp(direction, "north") == 0) {
    nextRoom = currentRoom->getExit((char*)("north"));
  }
  else if (strcmp(direction, "east") == 0) {
    nextRoom = currentRoom->getExit((char*)("east"));
  }
  else if (strcmp(direction, "south") == 0) {
    nextRoom = currentRoom->getExit((char*)("south"));
  }
  else if (strcmp(direction, "west") == 0) {
    nextRoom = currentRoom->getExit((char*)("west"));
  }
  
  if (nextRoom == NULL) {
    cout << "There is no exit that way!" << endl;
  }
  else {
    currentRoom = nextRoom;
    cout << currentRoom->getLongDescription() << endl;
  }
}

void eat(Command command) {

}

void ruinGame() {
  cout << "You consider for a moment not looking at the walkthrough. After all," << endl;
  cout << "what fun would this be if all the instructions were perfectly laid out" <<  endl;
  cout << "for you. Then you realize you could die down here so you don't care." << endl;
  cout << "\nStep 1: Find and place all 6 stones into the pedestal" << endl;
  cout << "The stones are in the Main Cave, Main Sewer, Sewage Dump, Dining Room, Upper bunk and Storage Room" << endl;
  cout << "Place a stone by having it in your inventory and dropping it" << endl;
  cout << "Step 2: Find and place \"Nothing\" into the pedestal by dropping it" << endl;
  cout << "\"Nothing\" is found in the Underground Reservoir" << endl;
  cout << "Ez win." << endl;
  
}

bool quit(Command command) {
  if (command.hasSubject()) {
    cout << "You used the action \"quit\" in a way I don't understand." << endl;
    return false;
  }
  else {
    return true;
  }
}
