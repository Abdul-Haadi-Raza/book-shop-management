#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string BOOKS_FILE_NAME = "books_data.txt";
const int MAX_BOOKS = 100;

// Define the structure for book data
struct Book {
    string name;
    string author;
    int pages;  // Number of pages instead of price
    string availability;
};

// Function prototypes
void addBook(Book books[], int& numBooks);
void viewBooks(const Book books[], int numBooks);
void searchBook(const Book books[], int numBooks);
void deleteBook(Book books[], int& numBooks);
void updateBook(Book books[], int numBooks);
void saveBooksToFile(const Book books[], int numBooks);
void loadBooksFromFile(Book books[], int& numBooks);

// Function definitions
void addBook(Book books[], int& numBooks) {
    if (numBooks < MAX_BOOKS) {
        char choice;
        Book book;

        do {
            cout << "Enter details for the new book:\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, book.name);
            cout << "Author: ";
            getline(cin, book.author);
            cout << "Number of Pages: ";
            cin >> book.pages;
            cout << "Availability (Yes/No): ";
            cin >> book.availability;

            books[numBooks++] = book;
            cout << "Book added successfully.\n\n";

            cout << "Do you wish to add another book? (Y/N): ";
            cin >> choice;
        } while (toupper(choice) == 'Y');
    }
    else {
        cout << "Maximum number of books reached. Cannot add more.\n";
    }
}

void viewBooks(const Book books[], int numBooks) {
    cout << "Book List:\n";
    for (int i = 0; i < numBooks; ++i) {
        cout << "Book " << i + 1 << ":\n";
        cout << "Name: " << books[i].name << "\n"
            << "Author: " << books[i].author << "\n"
            << "Number of Pages: " << books[i].pages << "\n"
            << "Availability: " << books[i].availability << "\n";
    }
}

void searchBook(const Book books[], int numBooks) {
    string searchName;
    cin.ignore();
    cout << "Enter the name of the book you want to search: ";
    getline(cin, searchName);

    for (int i = 0; i < numBooks; i++) {
        if (books[i].name == searchName) {
            cout << "Book found at index " << i + 1 << ":\n";
            cout << "Name: " << books[i].name << "\n"
                << "Author: " << books[i].author << "\n"
                << "Number of Pages: " << books[i].pages << "\n"
                << "Availability: " << books[i].availability << "\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

void deleteBook(Book books[], int& numBooks) {
    string searchName;
    cout << "Enter the name of the book you want to delete: ";
    cin.ignore();
    getline(cin, searchName);

    for (int i = 0; i < numBooks; i++) {
        if (books[i].name == searchName) {
            for (int j = i; j < numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            numBooks--;
            cout << "Book deleted successfully.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

void updateBook(Book books[], int numBooks) {
    string searchName;
    cout << "Enter the name of the book you want to update: ";
    cin.ignore();
    getline(cin, searchName);

    for (int i = 0; i < numBooks; i++) {
        if (books[i].name == searchName) {
            cout << "Enter new details for the book:\n";
            cout << "Name: ";
            getline(cin, books[i].name);
            cout << "Author: ";
            getline(cin, books[i].author);
            cout << "Number of Pages: ";
            cin >> books[i].pages;
            cout << "Availability (Yes/No): ";
            cin >> books[i].availability;

            cout << "Book updated successfully.\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

void saveBooksToFile(const Book books[], int numBooks) {
    ofstream fout(BOOKS_FILE_NAME);
    if (!fout.is_open()) {
        cerr << "Error opening the file for writing." << endl;
        return;
    }

    for (int i = 0; i < numBooks; i++) {
        fout << books[i].name << "|" << books[i].author << "|"
            << books[i].pages << "|" << books[i].availability << "\n";
    }

    fout.close();
    cout << "Book data saved to file.\n";
}

void loadBooksFromFile(Book books[], int& numBooks) {
    ifstream fin(BOOKS_FILE_NAME);
    if (!fin.is_open()) {
        cerr << "No previous book data found." << endl;
        return;
    }

    numBooks = 0; // Reset the count before loading new data

    while (getline(fin, books[numBooks].name, '|')) {
        getline(fin, books[numBooks].author, '|');
        fin >> books[numBooks].pages;
        fin.ignore(); // Ignore the delimiter
        getline(fin, books[numBooks].availability);
        numBooks++;

        if (numBooks == MAX_BOOKS) {
            break; // Prevent overflow of the array
        }
    }

    fin.close();
    cout << "Book data loaded from file.\n";
}
