#include <iostream>
using namespace std;

class Stack {
    char stack[100];
    int top;
public:
    Stack() { top = -1; }
    void push(char ch) { stack[++top] = ch; }
    void pop() { if (top >= 0) top--; }
    bool isEmpty() { return top == -1; }
    char peek() { return top >= 0 ? stack[top] : '#'; }
};

bool checkBalanced(string expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(') s.push(ch);
        else if (ch == ')') {
            if (s.isEmpty() || s.peek() != '(') return false;
            s.pop();
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter parentheses string: ";
    cin >> expr;
    cout << (checkBalanced(expr) ? "Balanced" : "Not Balanced") << "\n";
}
