#include <iostream>
#include <stack>
using namespace std;

int arr[1000000];
int result[1000000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (s.empty())
            result[i] = -1;
        else
            result[i] = s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}