#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void myArray(int *arr, int n){
    for(int i=0; i<n; i++){
        // arr[i] = rand() % 10 + 1;
        cin >> arr[i];
    }
}

void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 3 loops O(n^3)
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

// 2 loops O(n^2)
int maxSubArraySum2(int *arr, int n){
    int max_sum = arr[0];
    for(int i =0 ;i<n;i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            max_sum = max_sum < sum ? sum : max_sum;
        }
    }return max_sum;
}
// O(n log n) divide and conquer
int maxSuffix(int *arr, int left, int mid){
    int sum = 0;
    int best = arr[mid];

    for(int i = mid; i >= left; i--){
        sum += arr[i];
        if(sum > best)
            best = sum;
    }
    return best;
}

int maxPrefix(int *arr, int midPlusOne, int right){
    int sum = 0;
    int best = arr[midPlusOne];

    for(int i = midPlusOne; i <= right; i++){
        sum += arr[i];
        if(sum > best)
            best = sum;
    }
    return best;
}

int maxSubArrayDivide(int *arr, int left, int right){
    if(left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftBest  = maxSubArrayDivide(arr, left, mid);
    int rightBest = maxSubArrayDivide(arr, mid + 1, right);
    int crossBest = maxSuffix(arr, left, mid) + maxPrefix(arr, mid + 1, right);

    return max(max(leftBest, rightBest), crossBest);
}

// O(n) Dynamic programming
int maxSubarrayKadane(int arr[], int n) {
    int currentSum[n];
    currentSum[0] = arr[0];

    int globalMax = arr[0];

    for (int i = 1; i < n; i++) {

        if (currentSum[i - 1] > 0) 
            currentSum[i] = currentSum[i - 1] + arr[i];
        else
            currentSum[i] = arr[i];

        if (currentSum[i] > globalMax)
            globalMax = currentSum[i];
    }

    return globalMax;
}

int main(){
    srand(time(0));
    int n;
    cin >> n;
    int *arr = new int[n];
    myArray(arr, n);
    printArray(arr, n);
    // cout << "Maximum subarray sum is: " << maxSubArrayDivide(arr, 0, n-1) << endl;
    cout << "Maximum subarray sum is: " << maxSubarrayKadane(arr, n) << endl;
    delete[] arr;
}