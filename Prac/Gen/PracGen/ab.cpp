#include <iostream>
using namespace std;
int n = 4;

void nextConfig(char a[], int n, int i){
    a[i] = 'b';
    i++;
    while(i<=n){
        a[i]='a';
        i++;
    }
}

void showConfig(char a[], int n){
    for(int i = 1 ;i<=n;i++)
        cout <<a[i];
    cout <<endl;
}

void listing_configs(int n){
    int i;
    char c[n+1];
    for(int i = 1 ;i<=n;i++)
        c[i]= 'a';
    do {
        showConfig(c, n);
        i = n;
    while (i > 0 && c[i] == 'b') {
        i --;
    }
    if (i > 0) {
        nextConfig(c, n, i);
    }
    } while (i > 0);
}

int main(){
    listing_configs(n);
}