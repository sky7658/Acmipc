#include <iostream>
using namespace std;

int main(void) {
    int a, b, n, m;
    cin >> a >> b >> n;
    for (int i = 0; i <= n; i++) {
        m = a / b;
        a %= b;
        a *= 10;
    }
    cout << m;
    return 0;
}