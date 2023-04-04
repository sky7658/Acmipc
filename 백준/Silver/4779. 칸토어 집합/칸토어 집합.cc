#include <cmath>
#include <iostream>
using namespace std;

string str;
int n;

void Recursive(int s, int e) {
    if (s == e) return;
    int div = (e - s + 1) / 3;

    for (int i = s + div; i <= e - div; i++) str[i] = ' ';

    Recursive(s, s + div - 1);
    Recursive(e - div + 1, e);
}

int main(void) {
    while (cin >> n) {
        str.clear();
        for (int i = 0; i < pow(3, n); i++) str += '-';
        Recursive(0, str.length() - 1);
        cout << str << '\n';
    }
    return 0;
}