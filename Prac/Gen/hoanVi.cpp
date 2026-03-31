#include <iostream>
using namespace std;
string s[6] = {"tam", "toan", "trang", "cong", "trung", "tu"};

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void nextConfig(int a[], int n, int i){
    int k = n;
    while(a[k]<a[i]){
        k--;
    }
    swap(a[k], a[i]);

    int j = n;
    i++;
    while(i<j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void showConfig(int a[], int n){
    for(int i = 1 ;i<=n;i++)
        cout <<a[i];
    cout <<endl;
}

void listing_configs(int n){
    int count = 1;
    int i;
    int a[n+1];
    for(int i = 1 ;i<=n;i++){
        a[i] = i;
    }
    do {
        showConfig(a, n);
        i = n - 1;
    while (i > 0 && a[i]>a[i+1]) {
        i --;
    }
    if (i > 0) {
        count++;
        nextConfig(a, n, i);
    }
    } while (i > 0);
}

int main(){
    int n = 3;
    listing_configs(n);
}