#include <iostream>
using namespace std;
string s[6] = {"tam", "toan", "trang", "cong", "trung", "tu"};
int n = 6;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void nextConfig(int a[], int i){
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

void showConfig(int a[]){
    for(int i = 1 ;i<=n;i++){
        cout <<s[a[i]-1]<< " ";
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
        i=n-1;
        while(i>0&&a[i]>a[i+1])
            i--;
        if(i>0)
            nextConfig(a, i);
    }while(i>0);    
}

int main(){
    listingConfig();
}