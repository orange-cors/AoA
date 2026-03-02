#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void myArray(int *arr, int n){
    for(int i=0; i<n; i++){
        arr[i] = rand() % 10 + 1;
    }
}

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 3 loops O(n^3)
void ListAllSubArray(int *arr, int n){
    for(int i =0 ;i<n;i++){ // starting point
        for(int j=i; j<n; j++){ // ending point
            int sum = 0;
            for(int k=i; k<=j; k++) // sum of subarray (i, j)
                cout << arr[k] << " ";
            cout << endl;    
        }
    }
}

int minSubArraySum(int *arr, int n){
    int min_sum = arr[0];
    for(int i =0 ;i<n;i++){ // starting point
        for(int j=i; j<n; j++){ // ending point
            int sum = 0;
            for(int k=i; k<=j; k++) // sum of subarray (i, j)
                sum += arr[k];
            min_sum = min_sum > sum ? sum : min_sum;
        }
    }return min_sum;
}

int maxSubArraySum(int *arr, int n){
    int max_sum = arr[0];
    for(int i =0 ;i<n;i++){ // starting point
        for(int j=i; j<n; j++){ // ending point
            int sum = 0;
            for(int k=i; k<=j; k++) // sum of subarray (i, j)
                sum += arr[k];
            max_sum = max_sum < sum ? sum : max_sum;
        }
    }return max_sum;
}

int main(){
    srand(time(0));
    int n;
    cin >> n;
    int *arr = new int[n];
    myArray(arr, n);
    printArray(arr, n);
    // ListAllSubArray(arr, n);
    cout << "Minimum subarray sum is: " << minSubArraySum(arr, n) << endl;
    cout << "Maximum subarray sum is: " << maxSubArraySum(arr, n) << endl;
    delete[] arr;
}