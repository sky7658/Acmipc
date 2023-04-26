#include <iostream>
using namespace std;

int n, m;
int arr[101];

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        while (a < b) {
            int swap = arr[a];
            arr[a] = arr[b];
            arr[b] = swap;
            a++;
            b--;
        }
    }

    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}
