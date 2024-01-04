#include "Books.h"
#include "customer.h"
#include "purchase.h"

int main() {
    Book books[MAX_BOOKS];
    int numBooks = 0;

    Customer customerData;
    int numCustomers = 0;

    Purchase purchaseData;
    int numPurchases = 0;

    // Load data from files
    loadBooksFromFile(books, numBooks);
    loadCustomersFromFile(customerData, numCustomers);
    loadPurchasesFromFile(customerData, books[100], purchaseData, numPurchases);

    int choice;
    do {
        cout << "\nMenu:\n1. Book Management\n2. Customer Management\n3. Purchase Management\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            // Book Management
            int bookOption;
            do {
                cout << "\nBook Management:\n1. Add Book\n2. View Books\n3. Search Book\n4. Delete Book\n5. Update Book\n6. Return to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> bookOption;
                cout << endl;

                switch (bookOption) {
                case 1:
                    addBook(books, numBooks);
                    break;
                case 2:
                    viewBooks(books, numBooks);
                    break;
                case 3:
                    searchBook(books, numBooks);
                    break;
                case 4:
                    deleteBook(books, numBooks);
                    break;
                case 5:
                    updateBook(books, numBooks);
                    break;
                case 6:
                    cout << "Returning to Main Menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            } while (bookOption != 6);

            break;

        case 2:
            // Customer Management
            int customerOption;
            do {
                cout << "\nCustomer Management:\n1. Add Customer\n2. View List\n3. Update Record\n4. Search Record\n5. Delete Record\n6. Return to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> customerOption;
                cout << endl;

                switch (customerOption) {
                case 1:
                    addCustomer(customerData, numCustomers);
                    break;
                case 2:
                    viewList(customerData, numCustomers);
                    break;
                case 3:
                    updateRecord(customerData, numCustomers);
                    break;
                case 4:
                    searchRecord(customerData, numCustomers);
                    break;
                case 5:
                    deleteRecord(customerData, numCustomers);
                    break;
                case 6:
                    cout << "Returning to Main Menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            } while (customerOption != 6);

            break;

        case 3:
            // Purchase Management
            int purchaseOption;
            do {
                cout << "\nPurchase Management:\n1. Add Purchase\n2. View Purchases\n3. Return to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> purchaseOption;
                cout << endl;

                switch (purchaseOption) {
                case 1:
                    addPurchase(customerData, books[100], purchaseData, numPurchases);
                    break;
                case 2:
                    viewPurchases(purchaseData, numPurchases);
                    break;
                case 3:
                    cout << "Returning to Main Menu.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
                    break;
                }
            } while (purchaseOption != 3);

            break;

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 4);

    // Save data to files before exiting
    saveBooksToFile(books, numBooks);
    saveCustomersToFile(customerData, numCustomers);
    savePurchasesToFile(purchaseData, numPurchases);

    return 0;
}
