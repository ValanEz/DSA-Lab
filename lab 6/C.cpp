#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char d) { data = d; next = nullptr; }
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(char ch) {
        Node* temp = new Node(ch);
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    char peek() {
        return (top) ? top->data : '#';
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (char ch : infix) {
        if (isalnum(ch)) postfix += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.peek();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.peek();
        s.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    Stack s;
    for (char ch : postfix) {
        if (isdigit(ch)) s.push(ch - '0');
        else {
            int b = s.peek(); s.pop();
            int a = s.peek(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.peek();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << "\n";
    cout << "Evaluation: " << evaluatePostfix(postfix) << "\n";
}
