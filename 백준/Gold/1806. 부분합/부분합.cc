#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n, s;
int arr[100001];

int main(void) {
    int sn = 0, en = 0;
    int answer = 100001;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = arr[0];

    while (sn <= en) {
        if (sum >= s) {
            answer = min(answer, en - sn + 1);
            sum -= arr[sn];
            sn++;
        } else {
            if (en < n - 1) {
                en++;
                sum += arr[en];
            } else
                break;
        }
    }
    if (answer == 100001)
        cout << 0;
    else
        cout << answer;
    return 0;
}