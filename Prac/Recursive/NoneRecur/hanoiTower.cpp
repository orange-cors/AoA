#include <iostream>
using namespace std;

struct Node {
    int n;
    char a, b, c;
};

struct Stack {
    Node data[1000];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

bool empty(Stack s) {
    return s.top == -1;
}

void push(Stack &s, int n, char a, char b, char c) {
    s.data[++s.top] = {n, a, b, c};
}

void pop(Stack &s, int &n, char &a, char &b, char &c) {
    Node tmp = s.data[s.top--];
    n = tmp.n;
    a = tmp.a;
    b = tmp.b;
    c = tmp.c;
}

void chuyen(int n, char a, char b, char c) {
    Stack s;
    init(s);

    push(s, n, a, b, c);

    while (!empty(s)) {
        pop(s, n, a, b, c);

        if (n == 1) {
            cout << "Chuyen 1 dia tu " << a << " sang " << c << endl;
        } else {
            push(s, n - 1, b, a, c);
            push(s, 1, a, b, c);
            push(s, n - 1, a, c, b);
        }
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    chuyen(n, 'A', 'B', 'C');

    return 0;
}