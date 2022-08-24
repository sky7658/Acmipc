#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[7];

void dfs(int n, int cnt) {
    if (cnt == 0) {
        for (auto itr = v.begin(); itr != v.end(); itr++) cout << *itr << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        v.push_back(arr[i]);
        dfs(n, cnt - 1);
        v.pop_back();
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(n, m);
    return 0;
}