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

		void setTrait(char*); //the words part or a description
		void setExits(map<int, char*>); 
		void setID(int);
	private:
		char* trait;
		map<int, char*> exits;
		int ID;
};
#endif
