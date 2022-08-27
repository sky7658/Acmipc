#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<vector<int>> s;
vector<int> v;
int arr[8];

void dfs(int n, int cnt, int start) {
    if (cnt == 0) {
        s.insert(v);
        return;
    }
    for (int i = start; i < n; i++) {
        v.push_back(arr[i]);
        dfs(n, cnt - 1, i + 1);
        v.pop_back();
    }
}

void Print_Vector(vector<int> Vec) {
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << ' ';
    }
    cout << '\n';
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(n, m, 0);
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        Print_Vector(*itr);
    }
    return 0;
}