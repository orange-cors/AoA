#include <iostream>
using namespace std;

void nextConfig(int a[], int n, int i){
    a[i] += 1;
    i++;
    while(i<=n){
        a[i]=a[i-1] + 1;
        i++;
    }
}

void showConfig(int a[], int n){
    for(int i = 1 ;i<=n;i++)
        cout <<a[i];
    cout <<endl;
}

void listing_configs(int k, int n){
    int i;
    int a[n];
    for(int i = 1 ;i<=n;i++){
        a[i] = i;
    }
    do {
        showConfig(a, n);
        i = n;
    while (i > 0 && a[i] == k-n+i) {
        i --;
    }
    if (i > 0) {
        nextConfig(a, n, i);
    }
    } while (i > 0);
}

int main(){
    int n = 4;
    int k = 6;
    listing_configs(k, n);
}