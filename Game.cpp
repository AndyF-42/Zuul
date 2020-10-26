//main Game class

#include <iostream>
#include "Item.h"
#include "Room.h"
#include "Command.h"
#include "CommandWords.h"
#include "Parser.h"

using namespace std;

void createRooms();
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
  //createRooms();
  //make parser
  //print welcome
  //while not finished, get commands
  cout << "Hello, world!" << endl;
}

void createRooms() {
  mainCave = new Room("You are in a massive cave, with mysterious openings all around you.\n" +
		      "Above you is an opening in the cave where light shines through.\n" +
		      "In the middle of the room is a pedestal, with 6 holes of different shapes", "Main Cave");
  laboratory = new Room("Test tubes, pipettes, and beakers full of strange liquids\n" +
			"fill the room. You probably shouldn't touch anything.", "Laboratory");
  livingQuarters = new Room("This is where you assume people lived, whoever\n" +
			    "would be crazy enough to live here. You notice\n" +
			    "a bunk bed at the end of the room", "Living Quarters");

}

bool processCommand(Command command) {

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

}
