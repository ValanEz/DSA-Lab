#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
};

// List class definition
class List {
private:
    Node* head; // Pointer to the first node
    Node* gethead() { return head; } // Private function to return head

public:
    List(); // Constructor
    void insertAscending(int value); // Insert in ascending order
    static List mergeLists(const List& list1, const List& list2); // Merge two lists
    void display() const; // Display list
};

#endif
