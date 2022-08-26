#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> q1;
priority_queue<int> q2;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n;
    cin >> x;
    q1.push(x);
    cout << q1.top() << '\n';
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (q1.size() == q2.size()) {
            if (x > -q2.top()) {
                q1.push(-q2.top());
                q2.pop();
                q2.push(-x);
            } else
                q1.push(x);
        } else if (q1.size() > q2.size()) {
            if (x < q1.top()) {
                q2.push(-q1.top());
                q1.pop();
                q1.push(x);
            } else {
                q2.push(-x);
            }
        }
        v.push_back(q1.top());
    }
    for (auto itr = v.begin(); itr != v.end(); itr++) cout << *itr << '\n';
    return 0;
}