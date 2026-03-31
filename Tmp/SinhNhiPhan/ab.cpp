#include <iostream>
using namespace std;
int n =3;

void nextConfig(char a[], int i){
    a[i] = 'b';
    i++;
    while (i<=n)
    {
        a[i] = 'a';
        i++;
    }
    
}

void showConfig(char a[]){
    for(int i = 1;i<=n;i++){
        cout <<a[i];
    }cout<<endl;
}

void listingConfig(){
    int i;
    char a[n+1];
    for(int i = 1;i<=n;i++){
        a[i] = 'a';
    }
    do{
        showConfig(a);
        i=n;
        while(i>0&&a[i]=='b')
        i--;
        if(i>0)
        nextConfig(a,i);
    }while(i>0);
}

int main(){
    listingConfig();
}