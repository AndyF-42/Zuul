//header for Room class

#pragma once
#include "Item.h"
#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

class Room {
private:
  char description[160];
  char roomName[40];
  unordered_map<char*, Room>* exits;
  vector<Item>* items;
  
  char* getExitString();

public:

  void setExit(char* direction, Room neighbor);
  char* getShortDescription();
  char* getRoom();
  char* getLongDescription();
  Item getItem(int index);
  Item* getItem(char* itemName);
  void setItem(Item newItem);
  char* getRoomItems();
  void removeItem(Item item);
  Room getExit(char* direction);

  Room(char* inputDescription, char* inputRoom);
};
