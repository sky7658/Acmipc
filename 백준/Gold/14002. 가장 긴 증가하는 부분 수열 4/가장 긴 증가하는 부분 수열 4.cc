#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000], dp[1000];
vector<int> v, ans;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    v.push_back(arr[0]);
    dp[0] = 1;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
            cnt++;
            dp[i] = cnt;
        } else {
            int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[index] = arr[i];
            dp[i] = index + 1;
        }
    }
    cout << v.size() << '\n';
    for (int i = n - 1; i >= 0; i--) {
        if (cnt == dp[i]) {
            ans.push_back(arr[i]);
            cnt--;
        }
    }
    while (!ans.empty()) {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    return 0;
}