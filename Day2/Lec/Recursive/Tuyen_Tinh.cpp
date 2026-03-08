#include <iostream>
using namespace std;

int giai_thua(int n) { //Chỉ có 1 lời gọi đệ quy
    if (n == 0) return 1;
    return n * giai_thua(n - 1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Factorial of " << n << " is: " << giai_thua(n) << endl;
    return 0;
}