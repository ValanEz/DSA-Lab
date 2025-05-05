#include "List.h"

int main() {
    List list1, list2, list3;
    int choice, value;

    while (true) {
        cout << "\n1. Insert in List 1\n";
        cout << "2. Insert in List 2\n";
        cout << "3. Merge List 1 and List 2 into List 3\n";
        cout << "4. Display Lists\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list1.insertAscending(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list2.insertAscending(value);
                break;
            case 3:
                list3 = List::mergeLists(list1, list2);
                cout << "Lists merged successfully.\n";
                break;
            case 4:
                cout << "List 1: ";
                list1.display();
                cout << "List 2: ";
                list2.display();
                cout << "List 3 (Merged): ";
                list3.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
