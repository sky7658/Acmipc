#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, c;
int objects[30];
vector<long long> sumA;
vector<long long> sumB;

void dfs(int s, int e, long long sum, vector<long long>& v) {
    if (s >= e) {
        v.push_back(sum);
        return;
    }
    dfs(s + 1, e, sum, v);
    dfs(s + 1, e, sum + objects[s], v);
}

int main(void) {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> objects[i];
    }

    dfs(0, n / 2, 0, sumA);
    dfs(n / 2, n, 0, sumB);

    sort(sumB.begin(), sumB.end());

    int answer = 0;
    for (long long a : sumA) {
        answer += upper_bound(sumB.begin(), sumB.end(), c - a) - sumB.begin();
    }

    cout << answer;
    return 0;
}
