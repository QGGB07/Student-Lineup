#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("LineUp.txt");
    string name;
    string firstName, lastName;
    int count = 0;

    // Check if the file opens successfully
    if (!inputFile) {
        cout << "ERROR: Could not open LineUp.txt" << endl;
        return 1;
    }

    // Read the first name from the file
    if (inputFile >> name) {
        firstName = name;
        lastName = name;
        count = 1;

        // Keep reading the rest of the names
        while (inputFile >> name) {
            count++;
            if (name < firstName) {
                firstName = name;
            }
            if (name > lastName) {
                lastName = name;
            }
        }

        cout << "Total students: " << count << endl;
        cout << "First in line: " << firstName << endl;
        cout << "Last in line: " << lastName << endl;
    } else {
        cout << "The file is empty." << endl;
    }

    inputFile.close();
    return 0;
}