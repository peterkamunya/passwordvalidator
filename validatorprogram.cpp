#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

// Function to read the passwords in the filee........
void readData(const string& filename, string passwords[], int& count, int maxSize) {
    ifstream inputFile(filename);
    
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl; // Debug message
        return;
    }

    count = 0;
    cout << "........ Validator Reading passwords from  file........" << endl; // Debug message
    
    while (count < maxSize && getline(inputFile, passwords[count])) {
        cout << "Reads  each password: " << passwords[count] << endl; // Print each password
        count++;
    }
    
    inputFile.close();
    cout << "Finished reading file." << endl; // Debug message for finishing reading the file

}



// Function to check if a password is valid
bool isValidPassword(const string& password) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string specialChars = "!@#$%^&*()-+=<>?/{}[]|";
    
    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (specialChars.find(ch) != string::npos) hasSpecial = true;
    }
    
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Function to write valid passwords to a new file
void writeData(const string& filename, string passwords[], int count) {
    ofstream outputFile(filename);
    
    if (!outputFile) {
        cerr << "Error opening file: " << filename << endl; // Debug message
        return;
    }

    cout << "..........Writing valid passwords to file....." << endl; // The debug message shows the valid passwords Debug messages
    
    int validCount = 0;
    for (int i = 0; i < count; i++) {
        if (isValidPassword(passwords[i])) {
            outputFile << passwords[i] << endl;
            cout << "Valid Password are: " << passwords[i] << endl; //  This is the Debug messages
            validCount++;
            if (validCount == 25) break;  // Stop after 25 valid passwords
        }
    }
    
    outputFile.close();
    cout << "Finished writing to file." << endl; // Debug message
}

int main() {
    const int MAX_SIZE = 50;
    string passwords[MAX_SIZE];
    int count = 0;

    cout << "Starting password validation program..." << endl; // Debug message

    readData("passwords.txt", passwords, count, MAX_SIZE);
    writeData("valid_passwords.txt", passwords, count);

    cout << "Processing complete. Check valid_passwords.txt for results." << endl;

    return 0;
}
