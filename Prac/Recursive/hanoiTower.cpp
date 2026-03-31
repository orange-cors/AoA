#include <iostream>
using namespace std;

void hanoiTower(int n, char a, char b, char c){
    if(n==1)
        cout <<"Chuyen 1 dia tu "<<a << " -> " <<c<<endl;
    else{
        hanoiTower(n-1, a, c, b);
        cout <<"Chuyen 1 dia tu "<<a << " -> " <<c;
        cout <<endl;
        hanoiTower(n-1, b, a, c);
    }
}

int main(){
    int n;
    cout <<"Nhap so dia n: ";
    cin>>n;

    hanoiTower(n, 'A', 'B', 'C');


}