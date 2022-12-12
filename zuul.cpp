//Kevin Yu
//12-6-22
//Move through rooms and try to win the game
//Got help from Nathan Zou

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include <iomanip>
#include <algorithm>

using namespace std;

void createRooms(vector<Room*>* rooms);

int main() {
	bool play = true;
	vector<Room*> rooms;
	createRooms(&rooms);

	return 0;
}

void createRooms(vector<Room*>* rooms) {
	/*
	1. Entrance Room
        2. Piano Room	
	3. Garden
	4. Bathroom
	5. Dining Room
	6. Kitchen
	7. Pantry
	8. Wine Room
	9. Elevator
	10. Balconey Room
	11. Bedroom
	12. Living Room
	13. Game Room
	14. Work Room
	15. Pool
	*/

	//set directions
	char* north = (char*)("north");
	char* east = (char*)("east");
	char* west = (char*)("west");
	char* south = (char*)("south");
	
	//made to create exits for each room
	map<int, char*> tempMap;
	
	//entrance room
	Room* entranceroom = new Room();
	entranceroom->setTrait((char*)("why is my house so big?"));
	entranceroom->setID(1);
	tempMap.insert(pair<int, char*>(3, north)); //garden
	tempMap.insert(pair<int, char*>(2, east)); //piano room
	tempMap.insert(pair<int, char*>(4, west)); //bathroom
	entranceroom->setExits(tempMap);
	rooms->push_back(entranceroom);
	tempMap.clear();

	//piano room
	Room* pianoroom = new Room();
	pianoroom->setTrait((char*)("LALALALALALA!"));
	pianoroom->setID(2);
	tempMap.insert(pair<int, char*>(9, north)); //elevator
	tempMap.insert(pair<int, char*>(5, east)); //dining room
	tempMap.insert(pair<int, char*>(1, west)); //entrance room
	pianoroom->setExits(tempMap);
	rooms->push_back(pianoroom);
	tempMap.clear();
	
	//garden
	Room* garden = new Room();
        garden->setTrait((char*)("be smelling like dandelions and roses."));
        garden->setID(3);
        tempMap.insert(pair<int, char*>(9, east)); //elevator
        tempMap.insert(pair<int, char*>(10, north)); //balconey room
        tempMap.insert(pair<int, char*>(12, west)); //living room
	tempMap.insert(pair<int, char*>(1, south)); //entrance room
        garden->setExits(tempMap);
        rooms->push_back(garden);
        tempMap.clear();
	
	//bathroom
        Room* bathroom = new Room();
        bathroom->setTrait((char*)("that Dave's was bussin and now I'm bouta destroy this toilet."));
        bathroom->setID(4);
        tempMap.insert(pair<int, char*>(12, north)); //living room
        tempMap.insert(pair<int, char*>(1, east)); //entrance room
        tempMap.insert(pair<int, char*>(15, west)); //pool
        bathroom->setExits(tempMap);
        rooms->push_back(bathroom);
        tempMap.clear();

	//dining room
	Room* diningroom = new Room();
	diningroom->setTrait((char*)("this Dave's bouta be bussin."));	
	diningroom->setID(5);
	tempMap.insert(pair<int, char*>(2, west)); //piano room
	tempMap.insert(pair<int, char*>(6, north)); //kitchen
	diningroom->setExits(tempMap);
	rooms->push_back(diningroom);
	tempMap.clear();

        //kitchen
        Room* kitchen = new Room();
        kitchen->setTrait((char*)("can you smell what the rock is cooking."));
        kitchen->setID(6);
        tempMap.insert(pair<int, char*>(7, north)); //pantry
        tempMap.insert(pair<int, char*>(5, south)); //dining room
        kitchen->setExits(tempMap);
        rooms->push_back(kitchen);
        tempMap.clear();



}


