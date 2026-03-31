#include <iostream>
using namespace std;

int fib(int n){
    if(n==1) return 1;
    else if(n==0) return 0;
    else if(n==2) return 1;
    int n1 = 1;
    int n2 = 1;
    int res = 0;
    for(int i = 2;i<n;i++){
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }return res;
}

int main(){
    int n;
    cout <<"Nhap n: ";
    cin>>n;

    int res = fib(n);

    cout <<"So fib thu "<<n <<" la: "<<res;
}