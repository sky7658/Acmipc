#include <iostream>
using namespace std;

int n, m;
int basket[101];

int main(void)
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) basket[i] = i;
    
    for(int i = 1; i <= m; i++) {
        int a, b, swap;
        cin >> a >> b;
        swap = basket[a];
        basket[a] = basket[b];
        basket[b] = swap;
    }
    for(int i = 1; i <= n; i++) cout << basket[i] << ' ';
    return 0;
}