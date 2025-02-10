//Thomas Cubstead
//2-10-25
//Review_Project
//Rock_Paper_Scissors
//This program will prompt a user to play a gmae of rock paper scissors and track the score until the user is done then a winner will be displayed based on the score.

#include <iostream>
#include <random>
#include <string>
using namespace std;

//get the user input and stores it in choice
string userChoice() {
	string choice;
	while (true) {
		cout << "enter rock, paper, Scissors, or quit" << endl;
		cin >> choice;
		//turn choice lowercase for code flow
		for (auto & c : choice) c = tolower(c);
		if (choice == 'rock' || choice == 'paper' || choice == 'scissors' || choice == 'quit') {
			return choice;
		} else {
			cout << "you must input rock, paper, scissors, or quit, please try again" << endl;
		}
	}
}

//determines the winner based on the selection of user and computer
string winSelection(string userChoice, string computerChoice) {
	if (userChoice == computerChoice) {
		return "draw";
	}
	if ((userChoice == "rock" && computerChoice == "scissors") || (userChoice == "paper" && computerChoice == "rock") || (userChoice == "scissors" && computerChoice == "paper")) {
		return "YOU WIN!";
	} else {
		return "COMPUTER WINS!";
	}
}

int main() {
	//max and min values to simulated rock paper scissor values
	const int MIN = 1;
	const int MAX = 3;

	random_device engine;

	uniform_int_distribution<int>rValue(MIN, MAX);
	cout << rValue(engine) << endl;
	return 0;
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
