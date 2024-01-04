#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const string CUSTOMER_FILE_NAME = "customer_data.txt";
const int MAX_CUSTOMERS = 100;

// Define the structure for customer data
struct Customer {
    int customerId[MAX_CUSTOMERS];
    string Cname[MAX_CUSTOMERS];
    string address[MAX_CUSTOMERS];
    string email[MAX_CUSTOMERS];
    int phoneNumber[MAX_CUSTOMERS];
};

// Function prototypes
void addCustomer(Customer& customerData, int& numCustomers);
void viewList(const Customer& customerData, int numCustomers);
void updateRecord(Customer& customerData, int numCustomers);
void searchRecord(const Customer& customerData, int numCustomers);
void deleteRecord(Customer& customerData, int& numCustomers);
void saveCustomersToFile(const Customer& customerData, int numCustomers);
void loadCustomersFromFile(Customer& customerData, int& numCustomers);

// Function definitions
void addCustomer(Customer& customerData, int& numCustomers) {
    if (numCustomers < MAX_CUSTOMERS) {
        char choice;
        do {
            cout << "Enter details for the new customer:\n";
            cout << "Customer ID: ";
            cin >> customerData.customerId[numCustomers];
            cout << "Name: ";
            cin.ignore();
            getline(cin, customerData.Cname[numCustomers]);
            cout << "Address: ";
            getline(cin, customerData.address[numCustomers]);
            cout << "Email: ";
            getline(cin, customerData.email[numCustomers]);
            cout << "Phone Number: ";
            cin >> customerData.phoneNumber[numCustomers];

            numCustomers++;
            cout << "Customer added successfully.\n\n";

            cout << "Do you wish to add another customer? If yes then type 'Y', otherwise type any alphabet to cancel.\nYour choice: ";
            cin >> choice;
        } while (toupper(choice) == 'Y');
    }
    else {
        cout << "Maximum number of customers reached. Cannot add more.\n";
    }
}

void viewList(const Customer& customerData, int numCustomers) {
    cout << "Customer List:\n";
    for (int i = 0; i < numCustomers; ++i) {
        cout << "Customer " << i + 1 << ":\n";
        cout << "Customer ID: " << customerData.customerId[i] << "\n"
            << "Name: " << customerData.Cname[i] << "\n"
            << "Address: " << customerData.address[i] << "\n"
            << "Email: " << customerData.email[i] << "\n"
            << "Phone Number: " << customerData.phoneNumber[i] << "\n";
    }
}

void deleteRecord(Customer& customerData, int& numCustomers) {
    string deleteName;
    cout << "Enter the name of the customer you want to delete: ";
    cin.ignore();
    getline(cin, deleteName);

    for (int i = 0; i < numCustomers; i++) {
        if (customerData.Cname[i] == deleteName) {
            for (int j = i; j < numCustomers - 1; j++) {
                customerData.customerId[j] = customerData.customerId[j + 1];
                customerData.Cname[j] = customerData.Cname[j + 1];
                customerData.address[j] = customerData.address[j + 1];
                customerData.email[j] = customerData.email[j + 1];
                customerData.phoneNumber[j] = customerData.phoneNumber[j + 1];
            }
            numCustomers--;
            cout << "\nCustomer deleted successfully.\n";
            return;
        }
    }
    cout << "Customer with name '" << deleteName << "' not found.\n";
}

void updateRecord(Customer& customerData, int numCustomers) {
    string updateName;
    cout << "Enter the name of the customer you want to update: ";
    cin.ignore();
    getline(cin, updateName);

    int choice;
    for (int i = 0; i < numCustomers; i++) {
        if (customerData.Cname[i] == updateName) {
            do {
                cout << "\nMenu:\n1. Update the customer's ID.\n2. Update the customer's name.\n3. Update the customer's address.\n4. Update the customer's email.\n5. Update the customer's phone number.\n6. Exit the update function.\n";
                cout << "Enter your choice: ";
                cin >> choice;
                cout << endl;
                switch (choice) {
                case 1:
                    cout << "Enter new ID for Customer " << i + 1 << ":\n";
                    cout << "Customer ID: ";
                    cin >> customerData.customerId[i];
                    cout << "ID updated successfully!\n";
                    break;
                case 2:
                    cout << "Enter new name for Customer " << i + 1 << ":\n";
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, customerData.Cname[i]);
                    cout << "Name updated successfully!\n";
                    break;
                case 3:
                    cout << "Enter new address of Customer " << i + 1 << ":\n";
                    cin.ignore();
                    cout << "Address: ";
                    getline(cin, customerData.address[i]);
                    cout << "Address updated successfully!\n";
                    break;
                case 4:
                    cout << "Enter new email of Customer " << i + 1 << ":\n";
                    cout << "Email: ";
                    cin.ignore();
                    getline(cin, customerData.email[i]);
                    cout << "Email updated successfully!\n";
                    break;
                case 5:
                    cout << "Enter new phone number of Customer " << i + 1 << ":\n";
                    cout << "Phone Number: ";
                    cin >> customerData.phoneNumber[i];
                    cout << "Phone number updated successfully!\n";
                    break;
                case 6:
                    cout << "Exiting the Update function.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            } while (choice != 6);
            return;
        }
    }
    cout << "Customer with name '" << updateName << "' not found.\n";
}

void searchRecord(const Customer& customerData, int numCustomers) {
    string searchName;
    cin.ignore();
    cout << "Enter the name of the customer you want to search: ";
    getline(cin, searchName);

    for (int i = 0; i < numCustomers; i++) {
        if (customerData.Cname[i] == searchName) {
            cout << "Customer found at index " << i + 1 << ":\n";
            cout << "Customer ID: " << customerData.customerId[i] << "\n"
                << "Name: " << customerData.Cname[i] << "\n"
                << "Address: " << customerData.address[i] << "\n"
                << "Email: " << customerData.email[i] << "\n"
                << "Phone Number: " << customerData.phoneNumber[i] << "\n";
            return;
        }
    }

    cout << "Customer not found.\n";
}

void saveCustomersToFile(const Customer& customerData, int numCustomers) {
    ofstream fout(CUSTOMER_FILE_NAME);
    if (!fout.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    for (int i = 0; i < numCustomers; i++) {
        fout << customerData.customerId[i] << "|" << customerData.Cname[i] << "|"
            << customerData.address[i] << "|" << customerData.email[i] << "|"
            << customerData.phoneNumber[i] << "\n";
    }

    fout.close();
    cout << "Customer data saved to file.\n";
}

void loadCustomersFromFile(Customer& customerData, int& numCustomers) {
    ifstream fin(CUSTOMER_FILE_NAME);
    if (!fin.is_open()) {
        cerr << "No previous customer data found." << endl;
        return;
    }

    numCustomers = 0; // Reset the count before loading new data

    while (fin >> customerData.customerId[numCustomers]) {
        fin.ignore(); // Ignore the delimiter
        getline(fin, customerData.Cname[numCustomers], '|');
        getline(fin, customerData.address[numCustomers], '|');
        getline(fin, customerData.email[numCustomers], '|');
        fin >> customerData.phoneNumber[numCustomers];

        numCustomers++;
        if (numCustomers == MAX_CUSTOMERS) {
            break; // Prevent overflow of the array
        }
    }

    fin.close();
    cout << "Customer data loaded from file.\n";
}
