#include <iostream>
using namespace std;

class queue {
    struct node {
        int data;
        struct node *next;
    } *front, *rear;

public:
    queue();
    void enqueue(int);
    int dequeue();
    int peek();
    void display();
};

int main() {
    queue q1;
    while (1) {
        int ch1;
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch1);
        printf("\n");

        if (ch1 == 1) {
            int num;
            printf("Enter number:");
            scanf("%d", &num);
            q1.enqueue(num);
        }
        if (ch1 == 2) {
            int ch = q1.dequeue();
            if (ch == -1) {
                printf("Queue is empty\n");
            } else {
                printf("Deleted element: %d \n", ch);
            }
        }
        if (ch1 == 3) {
            int ch = q1.peek();
            if (ch == -1) {
                printf("Queue is empty\n");
            } else {
                printf("Front element: %d \n", ch);
            }
        }
        if (ch1 == 4) {
            break;
        }
    }
    return 0;
}

queue::queue() {
    front = NULL;
    rear = NULL;
}

void queue::enqueue(int num) {
    struct node *newnode = (struct node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    if (rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int queue::dequeue() {
    if (front == NULL) {
        return -1;
    }
    struct node *temp = front;
    int num = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return num;
}

int queue::peek() {
    if (front == NULL) {
        return -1;
    }
    return front->data;
}
