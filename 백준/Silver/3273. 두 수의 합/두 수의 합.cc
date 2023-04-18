#include <iostream>
using namespace std;

int n, x;
int arr[100000];
bool num[2000001];

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (x - arr[i] > 0 && num[x - arr[i]]) count++;
        num[arr[i]] = true;
    }
    cout << count;
    return 0;
}