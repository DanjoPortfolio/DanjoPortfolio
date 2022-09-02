#include <iostream>
#include <stdlib.h>

class student {
public:

	std::string name;
	char scienceGrade;
	char mathsGrade;
	char englishGrade;

	void newEntry();
	int studentSearch(std::string name);
	void displayReport();

};

// displays the students report

void student::displayReport() {
	std::cout << "\n\t\t\t Grade System " << std::endl;
	std::cout << "\t\t\t=======================" << std::endl;
	std::cout << "\n Student: " << name << std::endl;
	std::cout << "\n Science : " << scienceGrade << std::endl;
	std::cout << "\n Maths : " << mathsGrade << std::endl;
	std::cout << "\n English : " << englishGrade << std::endl;
	std::cout << "\t\t\t=======================" << std::endl;


}

// performs search on objects name if found it returns true if not it returns false
int student::studentSearch(std::string studentName) {
	if (name == studentName) {
		return 1;
	}
	else {
		return 0;
	}
}

// prompts users for students' names and their grades
void student::newEntry() {
	std::cout << "\nPlease Enter Students Name : "; std::cin >> name;
	std::cout << "\nPlease Enter Science Grade : "; std::cin >> scienceGrade;
	std::cout << "\nPlease Enter Maths Grade : "; std::cin >> mathsGrade;
	std::cout << "\nPlease Enter English Grade : "; std::cin >> englishGrade;
}



int main() {
	const int tableSize = 20;
	// creates array to store created objects
	student* students[tableSize];
	int choice;
	int noOfEntries = 0;
	std::string key;

	while (true) {
		system("CLS");
		std::cout << "Grade System " << std::endl;
		std::cout << "=======================" << std::endl;
		std::cout << "Press 1 to make a new Entry " << std::endl;
		std::cout << "Press 2 to edit an Entry " << std::endl;
		std::cout << "Press 3 to view an Entry " << std::endl;
		std::cout << "Press 4 to remove an Entry " << std::endl;
		std::cin >> choice;
		std::string searchTerm;

		switch (choice) {

		case 1:
			system("CLS");
			// creates new object and adds to array at the index.
			students[noOfEntries] = new student;
			students[noOfEntries]->newEntry();
			noOfEntries++;
			break;

		case 2:
			system("CLS");
			std::cout << "Please Enter Name of Student you wish to edit" << std::endl;
			std::cin >> searchTerm;
			// loops through all entries and applies the search query if true allows user to edit the entry 
			for (int i = 0; i < noOfEntries; i++) {
				if (students[i]->studentSearch(searchTerm)) {
					students[i]->newEntry();
				}
			}


			break;


		case 3:
			system("CLS");
			std::cout << "Please Enter Name of Student you wish to view" << std::endl;
			std::cin >> searchTerm;
			// loops through all entries and applies the search query if true allows user to view the entry
			for (int i = 0; i < noOfEntries; i++) {
				if (students[i]->studentSearch(searchTerm)) {
					students[i]->displayReport();
					std::cout << "Press anykey then Enter to return to menu" << std::endl;
					std::cin >> key;
				}
			}
			break;

		case 4:
			system("CLS");
			std::cout << "Please Enter Name of Student you wish to view" << std::endl;
			std::cin >> searchTerm;

			for (int i = 0; i < noOfEntries; i++) {
				if (students[i]->studentSearch(searchTerm)) {
					delete students[i];
					noOfEntries--;
				}
			}
			break;

		default:
			std::cout << "Please use a Valid Entry - 1,2,3  or 4" << std::endl;
			break;
		}

	};

}