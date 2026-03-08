#include <iostream>
using namespace std;

int A(int n) { //Lời gọi đệ quy trong vòng lặp
    if (n == 0) return 1;
    else{
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (n-i) * (n-i) * A(i);
        }return sum;
    }
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "A(" << n << ") = " << A(n) << endl;
    return 0;
}