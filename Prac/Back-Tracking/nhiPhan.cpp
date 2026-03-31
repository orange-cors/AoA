#include <iostream>
using namespace std;

void show(int a[], int n){
    for(int i = 1;i<=n;i++){
        cout <<a[i];
    }cout <<endl;
}

void Try(int a[], int dd[],int k, int n){
    for(int i=0;i<=1;i++){
        a[k]=i;
        if(k==n)
            show(a, n);
        else{
            Try(a, dd, k+1, n);
        }
    }
}

int main(){
    int n;
    cout <<"Nhap n: ";
    cin >>n;

    int a[n+1];
    int dd[1000];
    Try(a, dd, 1, n);
}



















