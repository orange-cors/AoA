#include <iostream>
using namespace std;

int A(int a, int b) { //Lời gọi đệ quy trong vòng lặp
    if (a%b==0) return b;
    else{
        return A(b, a%b);
    }
}

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << A(a, b);
    return 0;
}