#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char d) { data = d; next = nullptr; }
};

class StackList {
    Node* top;
public:
    StackList() { top = nullptr; }
    void push(char ch) {
        Node* temp = new Node(ch);
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (!top) { cout << "Stack Underflow\n"; return; }
        cout << "Popped: " << top->data << "\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void peek() {
        if (!top) cout << "Stack is empty\n";
        else cout << "Top: " << top->data << "\n";
    }
};

int main() {
    StackList s;
    int choice;
    char ch;
    do {
        cout << "1. Push 2. Pop 3. Peek 4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter char: "; cin >> ch; s.push(ch); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
        }
    } while (choice != 4);
}
