#include "List.h"

// Constructor to initialize an empty list
List::List() {
    head = nullptr;
}

// Insert a value in ascending order
void List::insertAscending(int value) {
    Node* newNode = new Node{value, nullptr};

    // If list is empty or new node should be first
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Find position to insert
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data < value) {
        temp = temp->next;
    }

    // Insert new node
    newNode->next = temp->next;
    temp->next = newNode;
}

// Merge two sorted lists into a third list
List List::mergeLists(const List& list1, const List& list2) {
    List mergedList;
    Node* t1 = list1.head;
    Node* t2 = list2.head;

    while (t1 != nullptr) {
        mergedList.insertAscending(t1->data);
        t1 = t1->next;
    }
    while (t2 != nullptr) {
        mergedList.insertAscending(t2->data);
        t2 = t2->next;
    }

    return mergedList;
}

// Display the list
void List::display() const {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
