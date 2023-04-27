#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000];
int dp[1000][2];
vector<int> v;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][1] = -1;
    }

    dp[0][0] = 1;

    int max_len = 1;
    int max_index = 0;

    for (int i = 1; i < n; i++) {
        int temp = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                if (temp < dp[j][0] + 1) {
                    temp = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }
            dp[i][0] = temp;
        }
        if (max_len < dp[i][0]) {
            max_len = dp[i][0];
            max_index = i;
        }
    }

    cout << max_len << '\n';

    while (true) {
        v.push_back(arr[max_index]);
        if (dp[max_index][1] == -1) break;
        max_index = dp[max_index][1];
    }

    for (auto itr = v.rbegin(); itr != v.rend(); itr++) cout << *itr << ' ';

    return 0;
}
