#include <iostream>
using namespace std;

void collatz(int n);

void xuly_chan(int n) {
    cout << n/2 << " ";
    collatz(n/2);
}

void xuly_le(int n) {
    cout << 3 * n + 1 << " ";
    collatz(3 * n + 1);
}

void collatz(int n) {
    if(n == 1) return;
    else if (n % 2 == 0) {
        xuly_chan(n);
    } else {
        xuly_le(n);
    }
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Collatz sequence: ";
    collatz(n);
}