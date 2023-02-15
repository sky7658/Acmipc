#include <iostream>
using namespace std;

int num[100];

int main(void)
{
    int n, f, count = 0;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> num[i];
    cin >> f;
    for(int i = 0; i<n; i++) if(num[i] == f) count++;
    cout << count;
    return 0;
}