#include "stdafx.h"
#include <iostream>
#include <string>
#include <locale>
#include <sstream>

using namespace std;

const char* STANDARD_COLOR = "color 9";
const char* HELP_COLOR = "color A";
const char* ERROR_COLOR = "color 4";

/**
* Given a std:string, capitalizes each character into another std::string and returns the result
*/
string capitalizeString(string inputString) {
	string newString = "";
	locale loc;
	for (string::size_type i = 0; i < inputString.length(); ++i) {
		newString += toupper(inputString[i], loc);
	}

	return newString;
}

/**
* Gets a std::string input from the user, capitalizes it, and returns it
*/
string getInputFromUser() {
	system(STANDARD_COLOR);
	string input = "";
	cout << "\n Enter command :";
	getline(cin, input);
	return capitalizeString(input);
}

void printHelp() {
	system(HELP_COLOR);
	cout << "\t\t****************\n";
	cout << "\t\tConsole App Help\n";
	cout << "\t\t Enter 'help' for this menu. \n";
	cout << "\t\t Enter 'test' to see if the application is still running. \n";
	cout << "\t\t Enter 'quit' to exit the application. \n";
	cout << "\t\t****************\n";
}

void printTest() {
	system(STANDARD_COLOR);
	cout << "\nApplication still running.\n";
}

void printError() {
	system(ERROR_COLOR);
	cout << "\nInvalid command, please try again or enter 'help' for more information.\n";
}

void printQuit() {
	system(STANDARD_COLOR);
	cout << "Exiting program.";
	system("pause");       //For_waiting_program_exit_until_a_character_entered
}

int main() {
	system(STANDARD_COLOR);
	cout << "\t\t****************\n";
	cout << "\t\tConsole App Test\n";
	cout << "\t\t****************\n";

	/* Get the current user input */
	string input = getInputFromUser();

	while(input != "QUIT") {
		if (input == "HELP") {
			printHelp();
		}
		else if (input == "TEST") {
			printTest();
		}
		/* Invalid input has been given, print an error. */
		else {
			printError();
		}

		/* Current user input has been handled, get the next bit of input. */
		input = getInputFromUser();
	}

	printQuit();
	return 0;
}

