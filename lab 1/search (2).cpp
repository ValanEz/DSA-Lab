#include<iostream>
#include "sorting.h"
using namespace std;
int linearsearch(int[],int,int);
int binarysearch(int[],int,int);
int main(){
    int n,i,ch,target,index;
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
}
    cout << "\nEnter the element to be searched for:";
    cin >> target;
    
    cout << "\nChoose Search method";
    cout << "1.Linear Search\n";
    cout << "2.Binary Search\n";
    cout << "Enter your choice :";
    cin >> ch;

    switch(ch){
        case 1:
        index = linearsearch(arr,n,target);
        break;
        case 2:
        index = binarysearch(arr,n,target);
        break; 
    }
    if(index == -1){
        cout << "Target not Found";
    }
    else{
        cout << "Target found at index " << index;
    }


}
int linearsearch(int arr[],int n,int target){
    int i;
    for(i=0;i<n;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}
int binarysearch(int arr[],int n,int target){
    int low = 0;
    int high = n-1;
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        if(target > arr[mid]){
            low = mid+1;
        }
        else if(target < arr[mid]){
            high = mid-1;
        }
        else if(target == arr[mid]){
            return mid;
        }
    }
    return -1;
}