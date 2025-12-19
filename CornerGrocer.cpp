#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// This class handles reading the file and tracking item frequencies
class GroceryTracker {
private:
    map<string, int> itemCount;   // Stores item names and how often they appear

public:
    // Constructor reads the file and creates the backup file
    GroceryTracker() {
        ReadInputFile();
        CreateBackupFile();
    }

    // Reads items from the input file and counts them
    void ReadInputFile() {
        ifstream inputFile;
        string item;

        inputFile.open("CS210_Project_Three_Input_File.txt");

        if (!inputFile.is_open()) {
            cout << "Error opening input file." << endl;
            return;
        }

        while (inputFile >> item) {
            itemCount[item] = itemCount[item] + 1;
        }

        inputFile.close();
    }

    // Writes frequency data to frequency.dat
    void CreateBackupFile() {
        ofstream outputFile;
        outputFile.open("frequency.dat");

        for (auto it = itemCount.begin(); it != itemCount.end(); ++it) {
            outputFile << it->first << " " << it->second << endl;
        }

        outputFile.close();
    }

    // Menu option 1
    void SearchItem() {
        string userItem;
        cout << "Enter item name: ";
        cin >> userItem;

        if (itemCount.find(userItem) != itemCount.end()) {
            cout << userItem << " was purchased "
                << itemCount[userItem] << " times." << endl;
        }
        else {
            cout << "Item not found." << endl;
        }
    }

    // Menu option 2
    void PrintAllItems() {
        for (auto it = itemCount.begin(); it != itemCount.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }

    // Menu option 3
    void PrintHistogram() {
        for (auto it = itemCount.begin(); it != itemCount.end(); ++it) {
            cout << it->first << " ";

            for (int i = 0; i < it->second; i++) {
                cout << "*";
            }

            cout << endl;
        }
    }
};

int main() {
    GroceryTracker tracker;
    int choice = 0;

    while (choice != 4) {
        cout << "\nCorner Grocer Menu" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again." << endl;
        }
        else if (choice == 1) {
            tracker.SearchItem();
        }
        else if (choice == 2) {
            tracker.PrintAllItems();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
        }
        else {
            cout << "Please enter a valid option." << endl;
        }
    }

    return 0;
}