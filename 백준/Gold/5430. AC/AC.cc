#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int t, arr_size, r = -1, error = 0, s = 1, e = 1, num = 0;
    string fun, arr;
    cin >> t;
    for (int i = 0; i < t; i++) {
        deque<int> dq;
        cin >> fun;
        cin >> arr_size;
        cin >> arr;
        if (arr_size > 0) {
            for (int j = 0; j < arr.length(); j++) {
                if (arr[j] - '0' >= 0 && arr[j] - '0' < 10) e++;
                if (arr[j] == ',' || arr[j] == ']') {
                    for (int k = s; k < e; k++) {
                        num += (arr[k] - '0') * pow(10, e - k - 1);
                    }
                    dq.push_back(num);
                    num = 0;
                    e++;
                    s = e;
                }
            }
        }
        s = 1;
        e = 1;
        for (int j = 0; j < fun.length(); j++) {
            if (fun[j] == 'R')
                r *= -1;
            else if (fun[j] == 'D') {
                if (r == 1 && !dq.empty())
                    dq.pop_back();
                else if (r == -1 && !dq.empty())
                    dq.pop_front();
                else
                    error = 1;
            }
        }
        if (error) {
            cout << "error\n";
        } else {
            cout << '[';
            while (dq.size() > 1) {
                if (r == 1) {
                    cout << dq.back() << ',';
                    dq.pop_back();
                } else {
                    cout << dq.front() << ',';
                    dq.pop_front();
                }
            }
            if (dq.size() == 0)
                cout << "]\n";
            else
                cout << dq.back() << "]\n";
        }
        error = 0;
        r = -1;
    }
    return 0;
}