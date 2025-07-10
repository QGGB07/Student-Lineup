#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("LineUp.txt");
    string name;
    string firstName, lastName;
    int count = 0;

    if (inputFile >> name) {
        firstName = name;
        lastName = name;
        count = 1;

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
        cout << "The file is empty or missing." << endl;
    }

    inputFile.close();
    return 0;
}
