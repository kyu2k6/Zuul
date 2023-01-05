#include <iostream>
#include <cstring>
#include "room.h"
#include <map>

using namespace std;

Room::Room() {

}

char* Room::getTrait() {
	return trait;
}

map<int, char*>* Room::getExits() {
	return &exits;
}

int Room::getID() {
	return ID;
}

int Room::getItem() {
	return item;
}

void Room::setTrait(char* newTrait) {
	trait = newTrait;
}

void Room::setExits(map<int, char*> newExits) {
	exits = newExits;
}

void Room::setID(int newID) {
	ID = newID;
}

void Room::setItem(int newItem) {
	item = newItem;
}


