// Assume Customer and Book structures and related functions are defined here

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PURCHASES_FILE_NAME = "purchases_data.txt";
const int MAX_PURCHASES = 100;

// Define the structure for purchase data
struct Purchase {
    string bookName[MAX_PURCHASES];
    int customerId[MAX_PURCHASES];
    string customerName[MAX_PURCHASES];
    int sellingPrice[MAX_PURCHASES];
};

// Function prototypes
void addPurchase(const Customer& customerData, const Book& bookData, Purchase& purchaseData, int& numPurchases);
void viewPurchases(const Purchase& purchaseData, int numPurchases);
void savePurchasesToFile(const Purchase& purchaseData, int numPurchases);
void loadPurchasesFromFile(const Customer& customerData, const Book& bookData, Purchase& purchaseData, int& numPurchases);

void addPurchase(const Customer& customerData, const Book& bookData, Purchase& purchaseData, int& numPurchases) {
    if (numPurchases < MAX_PURCHASES) {
        cout << "Enter details for the new purchase:\n";

        cin.ignore(); // Consume the newline character left by previous cin
        cout << "Book Name: ";
        getline(cin, purchaseData.bookName[numPurchases]);

        // Check if the entered book name exists
        bool bookNameExists = false;
        for (int i = 0; i < MAX_BOOKS; ++i) {
            if (bookData.name == purchaseData.bookName[numPurchases]) {
                bookNameExists = true;
                break;
            }
        }

        if (!bookNameExists) {
            cout << "Book name specified does not exist in the records.\n";
            return;
        }

        cout << "Customer ID: ";
        cin >> purchaseData.customerId[numPurchases];

        // Check if the entered customer ID exists
        bool customerIdExists = false;
        for (int i = 0; i < MAX_CUSTOMERS; ++i) {
            if (customerData.customerId[i] == purchaseData.customerId[numPurchases]) {
                customerIdExists = true;
                break;
            }
        }

        if (!customerIdExists) {
            cout << "Customer ID specified does not exist in the records.\n";
            return;
        }

        cin.ignore(); // Consume the newline character left by previous cin
        cout << "Customer Name: ";
        getline(cin, purchaseData.customerName[numPurchases]);

        cout << "Selling Price: ";
        cin >> purchaseData.sellingPrice[numPurchases];

        numPurchases++;
        cout << "Purchase added successfully.\n";
    }
    else {
        cout << "Maximum purchases reached!\n";
    }
}

void viewPurchases(const Purchase& purchaseData, int numPurchases) {
    if (numPurchases == 0) {
        cout << "No purchases available.\n";
        return;
    }

    cout << "Purchase List:\n";
    for (int i = 0; i < numPurchases; ++i) {
        cout << "Purchase " << i + 1 << ":\n";
        cout << "Book Name: " << purchaseData.bookName[i] << "\n"
            << "Customer ID: " << purchaseData.customerId[i] << "\n"
            << "Customer Name: " << purchaseData.customerName[i] << "\n"
            << "Selling Price: " << purchaseData.sellingPrice[i] << "\n";
    }
}

void savePurchasesToFile(const Purchase& purchaseData, int numPurchases) {
    ofstream fout(PURCHASES_FILE_NAME);
    if (!fout.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    for (int i = 0; i < numPurchases; ++i) {
        fout << purchaseData.bookName[i] << "\t" << purchaseData.customerId[i] << "\t"
            << purchaseData.customerName[i] << "\t" << purchaseData.sellingPrice[i] << "\n";
    }

    fout.close();
    cout << "Purchases data saved to file." << endl;
}

void loadPurchasesFromFile(Customer& customerData, const Book& bookData, Purchase& purchaseData, int& numPurchases) {
    ifstream fin(PURCHASES_FILE_NAME);
    if (!fin.is_open()) {
        cerr << "No previous purchases data found." << endl;
        return;
    }

    numPurchases = 0; // Reset the count before loading new data

    while (numPurchases < MAX_PURCHASES &&
        getline(fin >> ws, purchaseData.bookName[numPurchases]) &&
        fin >> purchaseData.customerId[numPurchases] >> ws &&
        getline(fin >> ws, purchaseData.customerName[numPurchases]) &&
        fin >> purchaseData.sellingPrice[numPurchases]) {
        numPurchases++;
    }

    fin.close();
    cout << "Purchases data loaded from file." << endl;
}

