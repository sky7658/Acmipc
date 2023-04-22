#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> decimal;
bool num[4000001];

void Decimal_number() {
    for (int i = 2; i <= sqrt(n); i++) {
        if (!num[i])
            for (int j = i * 2; j <= n; j += i) num[j] = true;
    }
}

int main(void) {
    cin >> n;

    Decimal_number();

    for (int i = 2; i <= n; i++) {
        if (!num[i]) decimal.push_back(i);
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    int l = 0, r = 0;
    int sum = 2;
    int answer = 0;
    while (l <= r) {
        if (sum == n) answer++;

        if (sum > n) {
            sum -= decimal[l];
            l++;
        } else {
            if (r < decimal.size() - 1) {
                r++;
                sum += decimal[r];
            } else
                break;
        }
    }

    cout << answer;
    return 0;
}