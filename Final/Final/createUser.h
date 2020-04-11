#include<string>
#include <array>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class createUser {
private:
	string name;
	string password;
	int notecount;
	array<string, 0> note;
public:
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	void setName(string s) {
		name = s;
	}
	void setPassword(string s) {
		password = s;
	}
	int getnoteCount() {
		return 0;
	}
	void addNote(string x) {
		notecount = notecount + 1;
		note[notecount] = x;
	}
	friend std::ostream& operator << (std::ostream& out, const createUser& obj)
	{
		out << obj.name << "\n" << obj.password << "\n" << obj.notecount << '\n'  << std::endl;
		return out;
	}
	/*
	 * Read data from stream object and fill it in member variables
	 */
	friend std::istream& operator >> (std::istream& in, createUser& obj)
	{
		in >> obj.name;
		in >> obj.password;
		in >> obj.notecount;
		
		return in;
	}



};
//Child class
class noteCreator : public createUser {
	string filename = getName();
	string message;


};




