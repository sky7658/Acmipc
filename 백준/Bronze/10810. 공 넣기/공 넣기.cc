#include <iostream>
using namespace std;

int arr[101];

int main(void)
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = a; j <= b; j++) arr[j] = c;
    }
    
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}