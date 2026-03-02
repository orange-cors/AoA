#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void myArray(vector<int>& arr, int n){
    for(int i=0; i<n; i++){
        arr[i] = rand() % 10 + 1;
    }
}

void printArray(const vector<int>& arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sumEle(const vector<int>& arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int maxVal(const vector<int>& arr, int n){
    int maxValue = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int minVal(const vector<int>& arr, int n){
    int minValue = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < minValue){
            minValue = arr[i];
        }
    }
    return minValue;
}

void QuickSort(vector<int>& arr, int left, int right) {
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
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}

int main(){
    srand(time(0));
    int n;
    cin >> n;
    vector<int> arr(n);
    myArray(arr, n);
    printArray(arr, n);
    cout << "Sum: " << sumEle(arr, n) << endl;
    cout << "Max: " << maxVal(arr, n) << endl;
    cout << "Min: " << minVal(arr, n) << endl;
    QuickSort(arr, 0, n-1);
    cout << "Sorted array: ";
    printArray(arr, n);
}