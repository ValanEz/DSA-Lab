#include<iostream>
using namespace std;
void bubblesort(int[],int);
void selectionsort(int[],int);
void insertionsort(int[],int);
int main(){
    int n,i,ch;
    cout << "enter the number of array elements:";
    cin >> n;
    int arr[n];
    for(i=0;i<n;i++){
        cout << "enter the element:";
        cin >> arr[i];
    }
    cout << "1.Bubble Sort\n";
    cout << "2.Selection Sort\n";
    cout << "3.Insertion Sort\n";
    cout << "4. Exit\n";
    cout << "Enter your choice:";
    cin >> ch;
    switch(ch){
        case 1:
        bubblesort(arr,n);
        break;
        case 2:
        selectionsort(arr,n);
        break;
        case 3:
        insertionsort(arr,n);
        break;
        case 4:
        break;
    }
}
void bubblesort(int arr[],int n){
    int i,j;
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionsort(int arr[],int n){
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j] < arr[i]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

    }
}
void insertionsort(int arr[],int n){
   int i,j,temp;
   for(i=0;i<n;i++){
    temp=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>temp){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
   }
}

