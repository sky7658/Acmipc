#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
    int k;
    long long n;
    cin >> k;
    while (k-- > 0) {
        cin >> n;
        if (n == 1 || n == 0) {
            cout << 2 << '\n';
            continue;
        }
        bool stop = true;
        n--;
        while (stop) {
            stop = false;
            n++;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    stop = true;
                    break;
                }
            }
        }
        cout << n << '\n';
    }
    return 0;
}