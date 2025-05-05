#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree {
public:
    Node* root;
    
    Tree() : root(NULL) {}

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    void preorder(Node* node) {
        if (!node) return;
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
};

int main() {
    Tree t;
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                t.root = t.insert(t.root, val);
                break;
            case 2:
                printf("Preorder: ");
                t.preorder(t.root);
                printf("\n");
                break;
            case 3:
                printf("Inorder: ");
                t.inorder(t.root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                t.postorder(t.root);
                printf("\n");
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
