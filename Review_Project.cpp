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
		if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit") {
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
		return "human";
	} else {
		return "computer";
	}
}


void tournament() {
	int userScore = 0;
	int computerScore = 0;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 3);

	//converts a random number into rock, paper, or scissors for the computer selection
	while (true) {
		int computerNumber = dis(gen);
		string computerChoice;
		if (computerNumber == 1) {
			computerChoice = "rock";
		}
		else if (computerNumber == 2) {
			computerChoice = "paper";
		} 
		else if (computerNumber == 3) {
			computerChoice = "scissors";
		}

		string uChoice = userChoice();

		//ends the tournament
		if (uChoice == "quit") {
			break;
		}

		cout << "The computer chose: " << computerChoice << endl;

		string winner = winSelection(uChoice, computerChoice);

		if (winner == "human") {
			cout << "YOU WON THIS ROUND!" << endl;
			userScore++;
		} else if (winner == "computer") {
			cout << "THE COMPUTER WON THIS ROUND!" << endl;
			computerScore++;
		} else {
			cout << "DRAW!";
		}
		
	}
	cout << endl;
	if (userScore > computerScore) {
		cout << "YOUR WON THE TOURNAMENT!!!";
	} else if (computerScore > userScore) {
		cout << "THE COMPUTER WON THIS TIME BETTER LUCK NEXT TIME!!!";
	} else {
			cout << "THE TOURNAMENT IS A DRAW, WELL PLAYED!";
	}
	cout << "Final score: USER: " << userScore << " COMPUTER: " << computerScore << endl;
}

int main() {
	tournament();
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
