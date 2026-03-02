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

void insertionSort(int *arr, int n){
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for(int i=0; i<n1; i++)
        L[i] = arr[left + i];
    for(int j=0; j<n2; j++)
        R[j] = arr[mid + 1 + j];

    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int *arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for(int i = n - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
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