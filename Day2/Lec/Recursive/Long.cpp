#include <iostream>
using namespace std;

int Ackermann(int m, int n) {//Tham số của lời gọi đệ quy là 1 lời gọi đệ quy khác
    if (m == 0) return n + 1;
    else if (m > 0 && n == 0) return Ackermann(m - 1, 1);
    else return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main() {
    int m, n;
    cout << "Enter two non-negative integers (m and n): ";
    cin >> m >> n;
    cout << "Ackermann(" << m << ", " << n << ") = " << Ackermann(m, n) << endl;
    return 0;
}