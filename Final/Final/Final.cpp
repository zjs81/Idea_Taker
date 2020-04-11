// Final.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <fstream>
#include <iostream>
#include "createUser.h"
#include <string>
#include <cassert>


//Available Options for Logged In Users
string loggedin(string x) {
	int option;
	string filename;
	string note;
	cout << "Hello ";
	cout << x;
	cout << " what would you like to do?\n";
	bool done = true;
	//Checks User Input
	while (done) {
		option = 0;
		cout << "1). Create Note \n";
		cout << "2). View Notes \n";
		cout << "3). quit \n";
		cin >> option;
		if (option == 1) {
			cout << "What do you want the note to be called? \n";
			cin >> filename;
			ofstream myfile;
			myfile.open(filename + ".txt");
			cout << "What do you want to write?\n";
			cin >> note;
			myfile << note;
			myfile.close();
			cout << "saved\n";
			
			loggedin(x);
			myfile.close();
		}else if (option == 2){
			cout << "What is the name of the note? \n";
			cin >> filename;
			ifstream input(filename + ".txt");
			for (std::string line; getline(input, line); )
			{
				cout << line+"\n";
			}
		}
		else if (option == 3) {
			done = false;
			return "exited";
		}
	}

	return 0;
}

using namespace std;
string login(string name) {
	ifstream in(name + ".txt");
	createUser x;
	in >> x;
	return x.getPassword();
	in.close();

	
}

void writetofile(createUser obj) {
	using namespace std;
	ofstream out(obj.getName() + ".txt");
	out << obj;
	out.close();
	
}
//Main Fuction
int main()
{
	
	using namespace std;
	cout << "Idea Taking app By Zach Sylvester\n";
	cout << "---------------------------------------\n";
	bool done = true;
	string firstname;
	string name;
	string password1;
	string password;
	bool passloop = true;
	int option;
	//Checks User Input
	while (done) {
		cout << "1).Register\n";
		cout << "2).Login\n";
		cout << "3).More information\n";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter your first name\n";
			cin >> firstname;
			name = firstname;
				cout << "Enter your password\n";
				cin >> password;
				cout << "Enter your password one more time\n";
				cin >> password1;
				if (password1 == password) {
					cout << "User Created\n";
					createUser firstname;
					firstname.setName(name);
					firstname.setPassword(password);
					writetofile(firstname);
					done = false;
					break;
				}
				else {
					cout << "Passwords don't match. Please try again.\n";
				}


			done = false;
			
		case 2:
			cout << "Please enter your name\n";
			cin >> name;
			firstname = name;
			password1 = login(name);
			cout << "Please enter your password\n";
			cin >> password;
			if (password1 == password) {
				done = false;
				
				cout << "Success\n";
				loggedin(firstname);
			}
			else {
				cout << "Password incorrect please try again.\n";
			}
			break;
			
		case 3:
			cout << "What is this program?\n";
				cout << "This program is a note creating app\n";
				cout << "Why cant I edit notes?\n";
				cout << "This app is not meant as a text editor but more as an idea keeper\n";
				cout << "Once you have an idea you can open this app login and then view or create new ideas.\n";
				break;
		}



	
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
