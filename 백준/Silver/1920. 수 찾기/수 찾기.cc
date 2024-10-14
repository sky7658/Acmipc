#include <algorithm>
#include <iostream>
using namespace std;

int arr[100000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, s, e, a, find_n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        s = 0;
        e = n - 1;
        a = n / 2;
        cin >> find_n;
        while (s <= e) {
            a = (s + e) / 2;
            if (arr[a] == find_n) {
                ans = 1;
                break;
            }
            if (find_n > arr[a]) {
                s = a + 1;
            } else {
                e = a - 1;
            }
            ans = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}