#include <iostream>
using namespace std;

#define SIZE 5 // Fixed array size

// Function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to rotate the array to the right by k steps
void rotate(int arr[], int n, int k) {
    k = k % n; // Handle cases where k > n
    if (k == 0) return;

    // Reverse entire array
    reverse(arr, 0, n - 1);
    // Reverse first k elements
    reverse(arr, 0, k - 1);
    // Reverse remaining elements
    reverse(arr, k, n - 1);
}

int main() {
    int arr[SIZE], k;

    // Take user input for array elements
    cout << "Enter " << SIZE << " elements: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    // Take input for number of shifts
    cout << "Enter number of shifts: ";
    cin >> k;

    // Perform rotation
    rotate(arr, SIZE, k);

    // Display rotated array
    cout << "Rotated array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
