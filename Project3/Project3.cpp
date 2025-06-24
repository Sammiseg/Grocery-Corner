#include <iostream>     // For input/output stream operations
#include <fstream>      // For reading/writing files
#include <map>          // For storing item frequencies
#include <string>       // For using strings
#include <iomanip>      // For formatting output
#include <algorithm>    // For transforming strings to lowercase
#include <limits>       // For input validation limits

using namespace std;

// Class to handle all grocery tracking operations
class GroceryTracker {
private:
    map<string, int> itemFrequencyMap;

    // ✅ Correct file path provided by user
    const string inputFilename = "C:\\Users\\elija\\OneDrive\\Desktop\\School\\CS210\\Project3\\Project3\\x64\\Debug\\CS210_Project_Three_Input_File.txt";
    const string outputFilename = "frequency.dat";

    // Helper function to convert a string to lowercase
    string ToLowerCase(const string& str) {
        string lowerStr = str;
        transform(str.begin(), str.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }

public:
    GroceryTracker() {
        LoadItems();
        WriteFrequencyFile();
    }

    // Loads items from the input file and populates the map
    void LoadItems() {
        ifstream inputFile(inputFilename);
        if (!inputFile.is_open()) {
            cerr << "Error: Could not open input file: " << inputFilename << endl;
            exit(1);
        }

        string item;
        while (getline(inputFile, item)) {
            itemFrequencyMap[item]++;
        }
        inputFile.close();
    }

    // Returns frequency count of a given item (case-insensitive)
    int GetItemFrequency(const string& item) {
        for (const auto& pair : itemFrequencyMap) {
            if (ToLowerCase(pair.first) == ToLowerCase(item)) {
                return pair.second;
            }
        }
        return 0;
    }

    // Displays all items with their frequency counts
    void DisplayAllFrequencies() {
        cout << endl;
        cout << "Item Purchase Frequency:";
        cout << endl;
        cout << "--------------------------";
        cout << endl;
        for (const auto& pair : itemFrequencyMap) {
            cout << setw(15) << left << pair.first << ": " << pair.second << endl;
        }
    }

    // Displays a text-based histogram using asterisks
    void DisplayHistogram() {
        cout << endl;
        cout << "Item Frequency Histogram:";
        cout << endl;
        cout << "--------------------------";
        cout << endl;
        for (const auto& pair : itemFrequencyMap) {
            cout << setw(15) << left << pair.first << ": ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Writes item frequencies to a backup file
    void WriteFrequencyFile() {
        ofstream outFile(outputFilename);
        if (!outFile.is_open()) {
            cerr << "Error: Could not open output file: " << outputFilename << endl;
            return;
        }

        for (const auto& pair : itemFrequencyMap) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }
};

// Function to display the menu and get a valid user choice
static int GetValidatedMenuChoice() {
    int choice;
    while (true) {
        cout << endl;
        cout << "=== Corner Grocer Item Tracker ===" << endl;
        cout << "1. Look up frequency of a specific item" << endl;
        cout << "2. Display frequency of all items" << endl;
        cout << "3. Display histogram of item frequency" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";

        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

// Main function: program entry point
int main() {
    cout << "Loading data from: CS210_Project_Three_Input_File.txt" << endl;
    cout << "File Source: https://learn.snhu.edu/content/enforced/1918187-CS-210-10387.202551-1/course_documents/CS210_Project_Three_Input_File.txt" << endl;

    GroceryTracker tracker;

    int choice;
    do {
        choice = GetValidatedMenuChoice();

        switch (choice) {
        case 1: {
            string item;
            cout << "Enter item name to search: ";
            getline(cin, item);

            int frequency = tracker.GetItemFrequency(item);
            if (frequency > 0) {
                cout << item << " was purchased " << frequency << " time(s)." << endl;
            }
            else {
                cout << item << " was not found in today's purchases." << endl;
            }
            break;
        }
        case 2:
            tracker.DisplayAllFrequencies();
            break;
        case 3:
            tracker.DisplayHistogram();
            break;
        case 4:
            cout << "Thank you for using the Corner Grocer Item Tracker. Goodbye!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
