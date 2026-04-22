// Created by Becky Jordan Abreo
// on 04/16/2026
// Project 3: Corner Grocer

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include "GrocerItems.h"
using namespace std;


int main() {
    GrocerItems* tracker = new GrocerItems();
    int choice = 0;

    while (choice != 4) {
        tracker->printMenu();
        cin >> choice;

        // Input validation
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number 1–4: ";
            cin >> choice;
        }

        if (choice == 1) {
            string item;
            cout << "Enter item to search: ";
            cin >> item;

            int freq = tracker->getItemQuantity(item);
            cout << item << " appears " << freq << " times.\n";
        }
        else if (choice == 2) {
            tracker->printAllFrequencies();
        }
        else if (choice == 3) {
            tracker->printHistogram();
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
    }

    delete tracker;
    return 0;
}