#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(NULL), right(NULL) {}
};

class ExpressionTree {
public:
    Node* root;

    ExpressionTree() : root(NULL) {}

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    Node* constructTree(char postfix[]) {
        stack<Node*> s;
        for (int i = 0; postfix[i] != '\0'; i++) {
            Node* newNode = new Node(postfix[i]);
            if (isOperator(postfix[i])) {
                newNode->right = s.top(); s.pop();
                newNode->left = s.top(); s.pop();
            }
            s.push(newNode);
        }
        return s.top();
    }

    void preorder(Node* node) {
        if (!node) return;
        printf("%c ", node->data);
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        printf("%c ", node->data);
    }
};

int main() {
    ExpressionTree et;
    char postfix[100];
    int choice;

    while (1) {
        printf("\n1. Construct Expression Tree\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                et.root = et.constructTree(postfix);
                break;
            case 2:
                printf("Preorder: ");
                et.preorder(et.root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                et.inorder(et.root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                et.postorder(et.root);
                printf("\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
