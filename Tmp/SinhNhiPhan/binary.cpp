#include <iostream>
using namespace std;
int n =3;

void nextConfig(int a[], int i){
    a[i] = 1;
    i++;
    while (i<=n)
    {
        a[i] = 0;
        i++;
    }
    
}

void showConfig(int a[]){
    for(int i = 1;i<=n;i++){
        cout <<a[i];
    }cout<<endl;
}

void listingConfig(){
    int i;
    int a[n+1] = {0};
    do{
        showConfig(a);
        i=n;
        while(i>0&&a[i]==1)
        i--;
        if(i>0)
        nextConfig(a,i);
    }while(i>0);
}

int main(){
    listingConfig();
}