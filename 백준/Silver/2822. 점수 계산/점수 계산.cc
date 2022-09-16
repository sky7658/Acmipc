#include <iostream>
#include <queue>
#include <set>
using namespace std;

priority_queue<pair<int, int>> score;
set<int> q_index;

int main(void) {
    int n, sum = 0;
    for (int i = 0; i < 8; i++) {
        cin >> n;
        score.push(make_pair(n, i + 1));
    }
    for (int i = 0; i < 5; i++) {
        sum += score.top().first;
        q_index.emplace(score.top().second);
        score.pop();
    }
    cout << sum << '\n';
    for (auto itr = q_index.begin(); itr != q_index.end(); itr++) {
        cout << *itr << ' ';
    }
    return 0;
}