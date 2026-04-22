#pragma once
#ifndef GROCERITEMS_H
#define GROCERITEMS_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

class GrocerItems {
private:
    // Encapsulated item structure
    struct ItemData {
        int quantity = 0;
        double price = 0.0;
        
    };

    // Encapsulated map (no external access)
    map<string, ItemData> items;
   

    // Loads data from the input file into the map
    void loadDataFromFile() {
        ifstream inputFile("Inventory.txt");
        string item;

        while (inputFile >> item) {
            // If exists, increment; if not, create with quantity = 1
            if (items.count(item) > 0) {
                items[item].quantity++;
            }
            else {
                ItemData newItem;
                newItem.quantity = 1;
                items.emplace(item, newItem);
            }
        }

        inputFile.close();
    }

    // Writes frequency.dat backup file
    void writeBackupFile() {
        ofstream outFile("frequency.dat");

        for (auto& pair : items) {
            outFile << pair.first << " " << pair.second.quantity << " "<< pair.second.price << endl;
        }

        outFile.close();
    }

public:
	// Default constructor loads data and writes backup file automatically
	GrocerItems() {
		loadDataFromFile();
		writeBackupFile();
	}

	// Optional parameterized constructor kept for compatibility
	GrocerItems(const std::string& name, int quantity) {
	// Parameters currently unused; preserve signature for existing code
		loadDataFromFile();
		writeBackupFile();
	}

    // Returns quantity of a specific item
        int getItemQuantity(const string & name) const {
        if (items.count(name) > 0) {
            return items.at(name).quantity;
        }

        return 0;
    }

    
    // Prints all items and their frequencies
    void printAllFrequencies() {
        for (auto& pair : items) {
            cout << pair.first << " " << pair.second.quantity << endl;
        }
    }

    // Prints histogram using asterisks
    void printHistogram() {
        for (auto& pair : items) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second.quantity; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    // Adds a new item, updates map, input file, and backup file
    void addNewItem(const string& name, double price = 0.0, const string& category = "Uncategorized") {

        if (items.count(name) > 0) {
    // Item exists → increment quantity
            items[name].quantity++;
        }
        else {
            // Item does not exist → create new struct and emplace
            ItemData newItem;
            newItem.quantity = 1;
            newItem.price = price;
           
            items.emplace(name, newItem);
        }
       
     // Append to original input file
        ofstream appendFile("Inventory.txt", ios::app);
        appendFile << name << endl;
        appendFile.close();

     // Rewrite backup file to reflect new counts
        writeBackupFile();
    }

    // Displays menu
    void printMenu() {
        cout << "\n===== Corner Grocer Menu =====\n";
        cout << "1. Search for an item\n";
        cout << "2. Print item frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }
};

#endif




