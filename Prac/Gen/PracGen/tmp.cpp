#include <iostream>
using namespace std;
char c[2] = {'a', 'b'};
int n = 3;
char a[100];

void showConfig(char x[], int n){
    for(int i = 1 ;i<=n;i++)
        cout <<x[i];
    cout <<endl;
}

void listing_configs(int n){
    char x[n+1] ={'a'};
    showConfig(x, n);
}

int main(){
    listing_configs(n);
}