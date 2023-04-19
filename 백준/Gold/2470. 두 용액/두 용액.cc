#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n;
int arr[100001];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int s, e, minX = 2000000001;
    int a, b;

    s = 0;
    e = n - 1;

    while (s < e) {
        int sum = arr[s] + arr[e];

        if (minX > abs(sum)) {
            minX = abs(sum);
            a = arr[s];
            b = arr[e];
        }

        if (sum <= 0)
            s++;
        else
            e--;
    }

    cout << a << ' ' << b;
    return 0;
}