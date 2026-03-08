#include <iostream>
using namespace std;

int to_hop(int n, int k) { //Có 2 lời gọi đệ quy
    if (k == 0 || k == n) return 1;
    return to_hop(n - 1, k - 1) + to_hop(n - 1, k);
}

int main() {
    int n, k;
    cout << "Enter two positive integers (n and k): ";
    cin >> n >> k;
    cout << "C(" << n << ", " << k << ") = " << to_hop(n, k) << endl;
    return 0;
}