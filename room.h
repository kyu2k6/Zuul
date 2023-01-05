#ifndef roomh
#define roomh

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
	public:
		Room();
		char* getTrait();
		int getID();
		map <int, char*>* getExits();
		int getItem();

		void setTrait(char*); //the words part or a description
		void setExits(map<int, char*>); 
		void setID(int);
		void setItem(int);
	private:
		char* trait;
		map<int, char*> exits;
		int ID;
		int item;
};
#endif
