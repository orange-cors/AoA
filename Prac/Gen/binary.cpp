#include <iostream>
using namespace std;

void nextConfig(int a[], int n, int i){
    a[i] = 1;
    i++;
    while(i<=n){
        a[i]=0;
        i++;
    }
}

void showConfig(int a[], int n){
    for(int i = 1 ;i<=n;i++)
        cout <<a[i];
    cout <<endl;
}

void listing_configs(int n){
    int i;
    int x[n] = {0};
    do {
        showConfig(x, n);
        i = n;
    while (i > 0 && x[i] == 1) {
        i --;
    }
    if (i > 0) {
        nextConfig(x, n, i);
    }
    } while (i > 0);
}

int main(){
    int n = 3;
    int a[100] = {0};
    listing_configs(n);
}