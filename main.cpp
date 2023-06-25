#include <iostream>
#include <string>
#include "Gad.h"
using namespace std;

//Function to add separation lines in menu.
string nCharString (size_t numChars, char ch) {
    return string (numChars, ch) ;
}
//Function to add leading zero if user only types in single digit.
string twoDigitString(unsigned int n){
    if (n < 10) {
        return "0" + to_string(n);
    }else {
            return to_string(n);
        }
    }
// Function for hours
void addOneHour(int& hours) {
    hours++;
}
// Function for minutes
void addOneMinute(int& minutes) {
    minutes++;
}
// Function for seconds
void addOneSecond(int& seconds) {
    seconds++;
}
//Function to clean up code for main menu
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
    for (unsigned int i = 0; i < numStrings; i++) {
        cout << strings[i] << endl;
    }
    cout << nCharString(27, '*') << endl;
}
//Function for user choices in menu
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    cout << "Choose an option: ";
    cin >> choice;
}
// Function to format time in 24-hour format (HH:MM:SS)
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

// Function to format time in 12-hour format (HH:MM:SS AM/PM)
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string suffix = (h < 12) ? "AM" : "PM";
    if (h == 0)
        h = 12;
    else if (h > 12)
        h -= 12;
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + suffix;
}

// Function to display the current time in both 24-hour and 12-hour formats
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << "Current Time (24-hour format): " << formatTime24(h, m, s) << endl;
    cout << "Current Time (12-hour format): " << formatTime12(h, m, s) << endl;
}


int main() {
// Initialize Variables
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
//User Input for time
    cout << "Enter the initial time:" << endl;
    cout << "Hours: ";
    cin >> hours;
    cout << "Minutes: ";
    cin >> minutes;
    cout << "Seconds: ";
    cin >> seconds;
// Main menu loop
    while (true) {
        displayClocks(hours, minutes, seconds);
        cout << nCharString(27, '*') << endl;
        cout << "MENU:" << endl;

        char* menuStrings[] = {
                "1. Add an hour",
                "2. Add a minute",
                "3. Add a second",
                "4. Exit"
        };

        printMenu(menuStrings, 4, 27);

        unsigned int option = getMenuChoice(4);

        //Depending on user input from menu, interaction to update time from functions or exit program
        if (option == 1) {
            addOneHour(hours);
        } else if (option == 2) {
            addOneMinute(minutes);
        } else if (option == 3) {
            addOneSecond(seconds);
        } else if (option == 4) {
            cout << "Exiting program" << endl; // Exit program
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;// if user selects other than menu options
            continue;
        }
    }
    return 0;
}