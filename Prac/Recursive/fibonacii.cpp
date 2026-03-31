#include <iostream>
using namespace std;

int fib(int n){
    if(n==1) return 1;
    else if(n==0) return 0;
    else if(n==2) return 1;
    else{
        return fib(n-1) + fib(n-2);
    }
}


int main(){
    int n;
    cout <<"Nhap n: ";
    cin>>n;

    int res = fib(n);

    cout <<"So fib thu "<<n <<" la: "<<res;
}