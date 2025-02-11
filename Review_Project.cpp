//Thomas Cubstead
//2-10-25
//Review_Project
//Grade_Book
// this program will take the average of a set of grades for individual students and sort them into grade averages for the teacher

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//global const of teast scores on file
const int maxTestScores = 5;

int readInfo(ifstream& inputFile, string names[], int scores[][maxTestScores]);
void averageCalc(int scores[][maxTestScores], double averages[], int numStudents);
char letterGrade(double averages);
void reportCard(string names[], double averages[], int numStudents);

int main() {
    ifstream inputFile("StudentGrades.txt");

    if (!inputFile) {
        cerr << "error opening file" << endl;
        return 1;
    }

    //arrays to store names, grades, and averages
    string names[100];
    int scores[100][maxTestScores];
    double averages[100];

    int numStudents = readInfo(inputFile, names, scores);

    averageCalc(scores, averages, numStudents);

    reportCard(names, averages, numStudents);

    inputFile.close();

    return 0;
}

//gets the data from the file to be used in sorting and calculations
int readInfo(ifstream &inputFile, string names, int scores[][maxTestScores]) {
    int numStudents = 0;
    while (inputFile >> names[numStudents]) {
        for (int i = 0; i < maxTestScores; ++i) {
            inputFile >> scores[numStudents][i];
        }
        numStudents++;
    }
    return numStudents;
}

//function to read the info from the file
int readInfo(ifstream& inputFile, string names[], int scores[][maxTestScores]) {
    int numStudents = 0;
    while (inputFile >> numStudents[names]) {
        for (int i = 0; i < maxTestScores; ++i) {
            inputFile >> scores[numStudents][i];
        }
        numStudents++;
    }
    return numStudents;
}

//function to calculate grade averages
void averageCalc(int scores[][maxTestScores], double averages[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        int total = 0;
        for (int j = 0; j < maxTestScores; ++j) {
            total += scores[i][j];
        }
        averages[i] = static_cast<double>(total) / maxTestScores;
    }
}

//turns the numerical average into a letter grade
char letterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

//function to show the results of grade averages for each student
void reportCard(string names[], double averages[], int numStudents) {
    cout << left << setw(20) << "student name"
         << setw(10) << "average" << "grade" << endl;
    cout << string(40, '-') << endl;

    for (int i = 0; i < numStudents; ++i) {
        char grade = letterGrade(averages[i]);
        cout << left << setw(20) << names[i] << setw(10) << fixed << setprecision(2) 
             << averages[i] << grade << endl;
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
