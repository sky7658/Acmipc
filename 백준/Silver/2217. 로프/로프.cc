#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main(void) {
    int n, max_sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n + 1);
    for (int i = 1; i <= n; i++) {
        max_sum = max(max_sum, arr[i] * (n - i + 1));
    }
    cout << max_sum;
    return 0;
}