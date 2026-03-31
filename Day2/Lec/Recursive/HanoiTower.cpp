#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << A << " -> " << C << endl;
        return;
    }

    hanoi(n - 1, A, C, B);
    cout << A << " -> " << C << endl;
    hanoi(n - 1, B, A, C);
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
}