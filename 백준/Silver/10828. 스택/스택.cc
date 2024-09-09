#include <iostream>
using namespace std;

int stack[100000];
int cnt;

int main(void) {
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "push") cin >> stack[cnt++];
        if (str == "pop") {
            if (cnt == 0) {
                cout << -1 << '\n';
            } else {
                cout << stack[cnt - 1] << '\n';
                stack[cnt - 1] = 0;
                cnt--;
            }
        }
        if (str == "size") cout << cnt << '\n';
        if (str == "empty") {
            if (cnt > 0)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
        if (str == "top") {
            if (cnt > 0)
                cout << stack[cnt - 1] << '\n';
            else
                cout << -1 << '\n';
        }
    }
    return 0;
}