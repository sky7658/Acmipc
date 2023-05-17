#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int arr[100][100];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int result = arr[i][j];
            cin >> arr[i][j];
            cout << result + arr[i][j]  << ' ';
        }
        cout << '\n';
    }
    return 0;
}