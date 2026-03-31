#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(int i = 0; i < n2; i++)
        R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while(i < n1)
        a[k++] = L[i++];

    while(j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

int main(){
    int a[] = {5,2,4,1,3};
    int n = 5;

    mergeSort(a, 0, n-1);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}