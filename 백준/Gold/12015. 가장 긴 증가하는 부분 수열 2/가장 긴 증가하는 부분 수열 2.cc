#include <iostream>
#include <vector>
using namespace std;

int arr[1000000];
vector<int> lis;

int main(void) {
    int n, s, e, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (lis.empty() || arr[i] > lis.back())
            lis.push_back(arr[i]);
        else {
            s = 0;
            e = lis.size() - 1;
            int ret = 1000000007;
            while (s <= e) {
                m = (s + e) / 2;
                if (lis[m] >= arr[i]) {
                    if (ret > m) ret = m;
                    e = m - 1;
                } else
                    s = m + 1;
            }
            lis[ret] = arr[i];
        }
    }
    cout << lis.size();
    return 0;
}