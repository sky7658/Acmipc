#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[500000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int f;
        cin >> f;
        cout << upper_bound(arr, arr + n, f) - lower_bound(arr, arr + n, f)
             << ' ';
    }
    return 0;
}