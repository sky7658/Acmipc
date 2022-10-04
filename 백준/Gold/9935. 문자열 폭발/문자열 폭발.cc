#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

stack<char> str1;
string s, boom, ans;

int main() {
    cin >> s >> boom;
    for (int i = 0; i < s.length(); i++) {
        str1.push(s[i]);
        if (str1.top() == boom[boom.length() - 1] &&
            str1.size() >= boom.length()) {
            string check;
            for (int j = 0; j < boom.length(); j++) {
                check += str1.top();
                str1.pop();
            }
            reverse(check.begin(), check.end());
            if (check != boom) {
                for (int j = 0; j < check.length(); j++) {
                    str1.push(check[j]);
                }
            }
        }
    }
    if (str1.size() == 0) {
        cout << "FRULA";
    } else {
        while (!str1.empty()) {
            ans += str1.top();
            str1.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}