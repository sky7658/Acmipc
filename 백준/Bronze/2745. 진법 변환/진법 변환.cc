#include <iostream>
using namespace std;

int main(void) {
    string n;
    int b;
    int result = 0;

    cin >> n >> b;

    for (int i = 0; i < n.length(); i++) {
        if (n[i] >= 'A' && n[i] <= 'Z') result += (n[i] - 'A' + 10);
        else result += n[i] - '0';
        if (i != n.length() - 1) result *= b;
    }
    cout << result;
    return 0;
}