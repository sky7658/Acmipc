#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int temp = 2;
    for (int i = 0; i < n; i++) {
        temp += temp - 1;
    }
    cout << temp * temp;
    return 0;
}