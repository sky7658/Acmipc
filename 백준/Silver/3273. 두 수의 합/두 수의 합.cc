#include <iostream>
using namespace std;

int n, x;
int arr[100001];
bool num[1000001];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        num[arr[i]] = true;
    }
    cin >> x;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (x - arr[i] > 1000000 || x - arr[i] <= 0) continue;
        if (num[x - arr[i]]) count++;
    }
    cout << count / 2;
    return 0;
}