#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int front, rear;

public:
    CircularQueue();
    void enqueue(int);
    int dequeue();
    int peek();
    void display();
};

int main() {
    CircularQueue q1;
    while (1) {
        int ch1;
        printf("1. Enqueue\n");
        printf("2. Dequeue \n");
        printf("3. Peek \n");
        printf("4. Exit \n");
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

CircularQueue::CircularQueue() {
    front = -1;
    rear = -1;
}

void CircularQueue::enqueue(int num) {
    if ((rear + 1) % 5 == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % 5;
    arr[rear] = num;
}

int CircularQueue::dequeue() {
    if (front == -1) {
        return -1;
    }
    int num = arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % 5;
    }
    return num;
}

int CircularQueue::peek() {
    if (front == -1) {
        return -1;
    }
    return arr[front];
}

void CircularQueue::display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d", arr[i]);
        if (i == rear) {
            break;
        }
        printf(" -> ");
        i = (i + 1) % 5;
    }
    printf("\n");
}
