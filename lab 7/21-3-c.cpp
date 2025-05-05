#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    void enqueue(int);
    void dequeue();
    void peek();
};
Queue::Queue() {
    front = rear = NULL;
}

void Queue::enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void Queue::dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) 
        rear = NULL;

    delete temp;
}

void Queue::peek() {
    if (front == NULL) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

int main() {
    Queue q;
    int choice, value;

    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
