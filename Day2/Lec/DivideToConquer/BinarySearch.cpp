#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void myArray(int *arr, int n){
    for(int i = 0 ;i<n;i++){
        arr[i] = rand() % 10 + 1;
    }
}

void displayArray(int arr[], int n){
    for(int i = 0 ;i<n;i++){
        cout <<arr[i]<<" ";
    }cout<<endl;
}

void insertSort(int arr[], int n){
    for(int i = 1;i<n;i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0&&arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }arr[j+1] = key;
    }
}

int binarySearch(int arr[], int left, int right, int key){
    if(left>right) return 0;
    else{
        int mid = (left+right)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) return binarySearch(arr, left, mid-1, key);
        else return binarySearch(arr, mid+1, right, key);
    }
}

int main(){
    srand(time(0));
    int n, key;
    cout <<"Nhap n: ";
    cin >> n;
    int *arr = new int[n];

    myArray(arr, n);
    displayArray(arr,n);
    insertSort(arr,n);
    displayArray(arr,n);

    cout << "Nhap key: ";
    cin >> key;

    int res = binarySearch(arr, 0, n-1, key);

    if(!res){
        cout <<"Khong tim thay key!";
    }else 
        cout <<"Tim thay key tai vi tri: " <<res;
}