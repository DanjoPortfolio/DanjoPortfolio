#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int choice;
bool logged = false;


string fileTxt;
string username;
string password;
string enteredUser;
string enteredPass;

void logIn()
{
	ifstream storedInfo("AccountInfo.txt");
	getline(storedInfo, fileTxt);

	// Gets every character before the "|" for the username

	username = fileTxt.substr(0, fileTxt.find("|"));

	// Gets every character after the "|" for the password
	password = fileTxt.substr(fileTxt.find("|") + 1, fileTxt.length());
	
	cout << "\n===================\n";
	cout << "Please Enter Your UserName ";
	cin >> enteredUser;
	cout << "Please Enter Your Password ";
	cin >> enteredPass;
	cout << "\n===================\n";

	// checks if the entered username and password matches
	if (enteredUser == username && enteredPass == password) {
		cout << "\nWelcome " << username << endl;
		// breaks loop if they match
		logged = true;
	}else {
		// If they don't it repeats the loop
		cout << "Invalid Username/Password please try again";
	}

}

void registerAcc () {
	cout << "\n===================\n";
	cout << "\nPlease Enter Your UserName "; cin >> username;
	cout << "\nPlease Enter Your Password "; cin >> password;
	// Opens the file named AccountInfo.txt and adds the username and password to it all on 1 line seperated by a "|"
	ofstream file;
	file.open("AccountInfo.txt");

	file << username << "|" << password;
	// Closes file for memory saving
	file.close();

}

void initalize()
{
	cout << "\n===================\n";
	cout << "\nPress 1 To Log In\n";
	cout << "\nPress 2 To Register\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		// calls login() function which asks player for username + password it also checks them to what is stored in the databse.
		logIn();
		break;
	case 2:
		// calls the registerAcc() function which asks player to enter a username and password it then saves it to a file named "AccountInfo.txt"
		registerAcc();
		break;

	default:
		// Invalid choice repeats the loop till either 1 or 2 is entered
		cout << "Please Enter a Valid Choice!!" << endl;
		break;
	}

}

int main() {
	
	cout << "Hello Welcome to Dannys Terminal\n";
	cout << "What would you like to do\n";

	do
	{
		// Loops until logged becomes true It also calls a function that brings up a choice menu for the user.
		initalize();
	} while (logged == false);


}
