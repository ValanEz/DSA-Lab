#include <iostream>
using namespace std;
#define SIZE 5

class StackArray {
    char stack[SIZE];
    int top;
public:
    StackArray() { top = -1; }
    void push(char ch) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        stack[++top] = ch;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << stack[top--] << "\n";
    }
    void peek() {
        if (top == -1) cout << "Stack is empty\n";
        else cout << "Top: " << stack[top] << "\n";
    }
};

int main() {
    StackArray s;
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
