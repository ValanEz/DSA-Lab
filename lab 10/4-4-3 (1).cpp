#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (size >= MAX) {
        printf("Heap full\n");
        return;
    }
    int i = size;
    heap[size++] = value;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

void deleteMax() {
    if (size <= 0) {
        printf("Heap empty\n");
        return;
    }
    printf("Deleted: %d\n", heap[0]);
    heap[0] = heap[--size];
    heapify(0);
}

void display() {
    if (size == 0) {
        printf("Heap empty\n");
        return;
    }
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

void search(int value) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found\n");
}

void heapSort() {
    int tempSize = size;
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(i);
    for (int i = size - 1; i > 0; i--) {
        swap(&heap[0], &heap[i]);
        size--;
        heapify(0);
    }
    printf("Sorted: ");
    for (int i = 0; i < tempSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
    size = tempSize;
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                deleteMax();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 5:
                heapSort();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
