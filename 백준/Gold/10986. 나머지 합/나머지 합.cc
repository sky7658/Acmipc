#include <iostream>
using namespace std;

int count[1000];

int main(void) {
    int n, m, sum = 0, num;
    long long cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum += num;
        sum %= m;
        count[sum]++;
    }
    for (int i = 0; i < 1000; i++) {
        cnt += (long long)count[i] * (count[i] - 1) / 2;
    }
    cout << cnt + count[0];
    return 0;
}