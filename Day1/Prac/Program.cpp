#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void myArray(int *arr, int n){
    for(int i=0; i<n; i++){
        arr[i] = rand() % 20000 + 1;
    }
}

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int n){
    for(int i=0; i<n-1;i++){
        for(int j =0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int *arr, int n){
    for(int i = 0;i<n-1;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++)
            if(arr[j]<arr[minIndex])
                minIndex = j;
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2]; // chọn pivot ở giữa

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main(){
    srand(time(0));
    int n;
    cin >> n;
    int *arr = new int[n];
    myArray(arr, n);
    printArray(arr, n);

    quickSort(arr, 0, n-1);
    printArray(arr, n);
    delete[] arr;
}