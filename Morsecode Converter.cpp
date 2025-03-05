#include <iostream>
#include <string>
#include <vector> // Include vector header
using namespace std;

// Morse code mapping
string morseCode[] = {".-", // A
                      "-...", // B
                      "-.-.", // C
                      "-..", // D
                      ".", // E
                      "..-.", // F
                      "--.", // G
                      "....", // H
                      "..", // I
                      ".---", // J
                      "-.-", // K
                      ".-..", // L
                      "--", // M
                      "-.", // N
                      "---", // O
                      ".--.", // P
                      "--.-", // Q
                      ".-.", // R
                      "...", // S
                      "-", // T
                      "..-", // U
                      "...-", // V
                      ".--", // W
                      "-..-", // X
                      "-.--", // Y
                      "--.."}; // Z

// Function to convert text to Morse code
string toMorse(string text) {
    string morse = "";
    for (char c : text) {
        c = toupper(c); // Convert to uppercase
        if (c >= 'A' && c <= 'Z') {
            morse += morseCode[c - 'A'] + " ";
        }
    }
    return morse;
}

// Function to convert Morse code to text
string fromMorse(string morse) {
    string text = "";
    vector<string> morseChars;
    string temp = "";

    for (char c : morse) {
        if (c == ' ') {
            if (!temp.empty()) { // Avoid adding empty strings
                morseChars.push_back(temp);
                temp = "";
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) { // Add the last Morse character
        morseChars.push_back(temp);
    }

    for (string morseChar : morseChars) {
        for (int i = 0; i < 26; i++) {
            if (morseCode[i] == morseChar) {
                text += 'A' + i;
                break; // Break after finding the character
            }
        }
    }
    return text;
}

int main() {
    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Convert text to Morse code" << endl;
    cout << "2. Convert Morse code to text" << endl;
    cout << "Enter your choice(Only a number between 2 and 1): ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character after the choice input
    switch (choice) {
        case 1: {
            string text;
            cout << "Enter text: ";
            getline(cin, text); // Use getline to read the entire line
            cout << "Morse code: " << toMorse(text) << endl;
            break;
        }
        case 2: {
            string morse;
            cout << "Enter Morse code: ";
            getline(cin, morse); // Use getline to read the entire line
            cout << "Text: " << fromMorse(morse) << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please select 1 or 2." << endl;
            break;
        }
    }
    return 0;
}