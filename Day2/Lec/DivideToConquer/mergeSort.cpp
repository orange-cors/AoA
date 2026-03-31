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

void merge(int a[], int l, int m, int r){

    int i = l;
    int j = m + 1;

    int temp[100];
    int k = 0;

    while(i <= m && j <= r){

        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= r)
        temp[k++] = a[j++];

    for(int t=0;t<k;t++)
        a[l+t] = temp[t];
}

void mergeSort(int a[], int left, int right){

    if(left < right){

        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}


int main(){
    srand(time(0));
    int n;
    cout <<"Nhap n: ";
    cin >> n;
    int *arr = new int[n];

    myArray(arr, n);
    displayArray(arr,n);
    mergeSort(arr, 0, n-1);
    displayArray(arr,n);

}