#include <iostream>
using namespace std;
int k = 6;
int n = 4;

void nextConfig(int a[], int i){
    a[i] += 1;
    i++;
    while(i<=n){
        a[i] = a[i-1] + 1;
        i++;
    } 
}

void showConfig(int a[]){
    for(int i = 1 ;i<=n;i++){
        cout <<a[i];
    }cout <<endl;
}

void listingConfig(){
    int i;
    int a[n+1];
    for(int i = 1 ;i<=n;i++){
        a[i]=i;
    }
    do{
        showConfig(a);
        i=n;
        while(i>0&&a[i]>=k-n+i)
            i--;
        if(i>0)
            nextConfig(a,i);
    }while(i>0);
}

int main(){
    listingConfig();
}