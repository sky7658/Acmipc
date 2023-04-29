#include <iostream>
using namespace std;

int arr[200000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, size = 0, node, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) {
            arr[size] = x;
            node = size;
            while (node > 0) {
                if (arr[(node - 1) / 2] > arr[node]) {
                    tmp = arr[(node - 1) / 2];
                    arr[(node - 1) / 2] = arr[node];
                    arr[node] = tmp;
                }
                node = (node - 1) / 2;
            }
            size++;
        } else {
            cout << arr[0] << '\n';
            if (size != 0) size--;
            arr[0] = arr[size];
            arr[size] = 0;
            node = 0;
            while (node < size - 1) {
                int a = arr[node * 2 + 1], b = arr[node * 2 + 2];
                if (a == 0 || b == 0) {
                    if (a == 0 && b == 0)
                        break;
                    else {
                        if (arr[node] > max(a, b)) {
                            if (a > b) {
                                arr[node * 2 + 1] = arr[node];
                                arr[node] = a;
                                node = node * 2 + 1;
                            } else {
                                arr[node * 2 + 2] = arr[node];
                                arr[node] = b;
                                node = node * 2 + 2;
                            }
                        } else
                            break;
                    }
                } else {
                    if (arr[node] > min(a, b)) {
                        if (a <= b) {
                            arr[node * 2 + 1] = arr[node];
                            arr[node] = a;
                            node = node * 2 + 1;
                        } else {
                            arr[node * 2 + 2] = arr[node];
                            arr[node] = b;
                            node = node * 2 + 2;
                        }
                    } else
                        break;
                }
            }
        }
    }
    return 0;
}