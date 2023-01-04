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
void printRooms(vector<Room*>* rooms, int currentRoom);
int move(vector<Room*>* rooms, int currentRoom, char direction[]);

int main() {
	
	cout << "Your mission is to get a wine bottle from the wine room and bring it to the pool to enjoy(drop it)." << endl;
	
	cout << "Use the commands: Go, Take, Drop, Inventory, Quit" << endl;
		
	bool play = true;
	char command[10]; 

	vector<Room*> rooms;
	
	createRooms(&rooms);
	int currentRoom = 1;

	cout << "" << endl;

	while (play == true) {
		cout << "You are in the ";
		printRooms(&rooms, currentRoom);
		cin.get(command, 10);
		cin.get();
		if (strcmp(command, "Go") == 0) {
			cout << "Direction: ";
			cin.get(command, 10);
			cin.get();
			currentRoom = move(&rooms, currentRoom, command);
		}
		else if (strcmp(command, "Quit") == 0) {
			play = false;
		}
	}

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
	entranceroom->setTrait((char*)("entrance room, why is my house so big?"));
	entranceroom->setID(1);
	tempMap.insert(pair<int, char*>(3, north)); //garden
	tempMap.insert(pair<int, char*>(2, east)); //piano room
	tempMap.insert(pair<int, char*>(4, west)); //bathroom
	entranceroom->setExits(tempMap);
	rooms->push_back(entranceroom);
	tempMap.clear();

	//piano room
	Room* pianoroom = new Room();
	pianoroom->setTrait((char*)("piano room, LALALALALALA!"));
	pianoroom->setID(2);
	tempMap.insert(pair<int, char*>(9, north)); //elevator
	tempMap.insert(pair<int, char*>(5, east)); //dining room
	tempMap.insert(pair<int, char*>(1, west)); //entrance room
	pianoroom->setExits(tempMap);
	rooms->push_back(pianoroom);
	tempMap.clear();
	
	//garden
	Room* garden = new Room();
        garden->setTrait((char*)("garden, be smelling like dandelions and roses."));
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
        bathroom->setTrait((char*)("bathroom, that Dave's was bussin and now I'm bouta destroy this toilet."));
        bathroom->setID(4);
        tempMap.insert(pair<int, char*>(12, north)); //living room
        tempMap.insert(pair<int, char*>(1, east)); //entrance room
        tempMap.insert(pair<int, char*>(15, west)); //pool
        bathroom->setExits(tempMap);
        rooms->push_back(bathroom);
        tempMap.clear();

	//dining room
	Room* diningroom = new Room();
	diningroom->setTrait((char*)("dining room, this Dave's bouta be bussin."));	
	diningroom->setID(5);
	tempMap.insert(pair<int, char*>(2, west)); //piano room
	tempMap.insert(pair<int, char*>(6, north)); //kitchen
	diningroom->setExits(tempMap);
	rooms->push_back(diningroom);
	tempMap.clear();

        //kitchen
        Room* kitchen = new Room();
        kitchen->setTrait((char*)("kitchen, can you smell what the rock is cooking."));
        kitchen->setID(6);
        tempMap.insert(pair<int, char*>(7, north)); //pantry
        tempMap.insert(pair<int, char*>(5, south)); //dining room
        kitchen->setExits(tempMap);
        rooms->push_back(kitchen);
        tempMap.clear();

	//pantry
        Room* pantry= new Room();
        pantry->setTrait((char*)("pantry, watermelon flavored dumplings."));
        pantry->setID(7);
        tempMap.insert(pair<int, char*>(8, west)); //wine room
        tempMap.insert(pair<int, char*>(6, south)); //kitchen
        pantry->setExits(tempMap);
        rooms->push_back(pantry);
        tempMap.clear();
	
	//wine room
        Room* wineroom = new Room();
        wineroom->setTrait((char*)("wine room, I love driking."));
        wineroom->setID(8);
        tempMap.insert(pair<int, char*>(7, east)); //pantry
        wineroom->setExits(tempMap);
        rooms->push_back(wineroom);
        tempMap.clear();

	//elevator
        Room* elevator = new Room();
        elevator->setTrait((char*)("elevator, who needs stairs?"));
        elevator->setID(9);
        tempMap.insert(pair<int, char*>(3, west)); //garden
        elevator->setExits(tempMap);
        rooms->push_back(elevator);
        tempMap.clear();
	
	//balconey room
        Room* balconeyroom = new Room();
        balconeyroom->setTrait((char*)("balconey, my yard is so big."));
        balconeyroom->setID(10);
        tempMap.insert(pair<int, char*>(3, south)); //garden
        balconeyroom->setExits(tempMap);
        rooms->push_back(balconeyroom);
        tempMap.clear();
	
	//bedroom
        Room* bedroom = new Room();
        bedroom->setTrait((char*)("bedroom, I need sleep."));
        bedroom->setID(11);
        tempMap.insert(pair<int, char*>(13, west)); //game room
        tempMap.insert(pair<int, char*>(12, south)); //living room
        bedroom->setExits(tempMap);
        rooms->push_back(bedroom);
        tempMap.clear();

	//living room
        Room* livingroom = new Room();
        livingroom->setTrait((char*)("living room, what am I doing here?"));
        livingroom->setID(12);
        tempMap.insert(pair<int, char*>(11, north)); //bedroom
        tempMap.insert(pair<int, char*>(4, south)); //bathroom
	tempMap.insert(pair<int, char*>(3, east)); //garden
        livingroom->setExits(tempMap);
        rooms->push_back(livingroom);
        tempMap.clear();

	//gameroom
        Room* gameroom = new Room();
        gameroom->setTrait((char*)("gameroom, ILOVE FORTNITE!"));
        gameroom->setID(13);
        tempMap.insert(pair<int, char*>(11, east)); //bedroom
        tempMap.insert(pair<int, char*>(14, south)); //work room
        gameroom->setExits(tempMap);
        rooms->push_back(gameroom);
        tempMap.clear();

	//work room
        Room* workroom = new Room();
        workroom->setTrait((char*)("workroom, 0 work bouta be done."));
        workroom->setID(14);
        tempMap.insert(pair<int, char*>(13, north)); //gameroom
        workroom->setExits(tempMap);
        rooms->push_back(workroom);
        tempMap.clear();

	//pool
        Room* pool = new Room();
        pool->setTrait((char*)("pool, something's in the water..."));
        pool->setID(15);
        tempMap.insert(pair<int, char*>(4, east)); //bathroom
        pool->setExits(tempMap);
        rooms->push_back(pool);
        tempMap.clear();


}

void printRooms(vector<Room*>* rooms, int currentRoom) {
	vector<Room*>::iterator room;
	for (room = rooms->begin(); room != rooms->end();room++) {
		if (currentRoom == (*room)->getID()) {
			cout << (*room)->getTrait() << endl;
			cout << "Exits: ";
			for (map<int, char*>::const_iterator r = (*room) -> getExits()->begin();r != (*room) -> getExits() -> end(); r++) {
				cout << r->second << " ";
			}
			cout << endl;
		}
	}
}

int move(vector<Room*>* rooms, int currentRoom, char direction[]) {
    vector<Room*>::iterator move;
    for (move = rooms->begin(); move != rooms->end(); move++) {
        if (currentRoom == (*move)->getID()) {
            map<int, char*> exits;
            exits = *(*move)->getExits();
            //get exits 
            map<int, char*>::const_iterator map;
            for (map = exits.begin(); map != exits.end(); ++map) {
                if (strcmp(map->second, direction) == 0) {
                    return map->first;
                }
            }
        }
    }
    return 0;
}
