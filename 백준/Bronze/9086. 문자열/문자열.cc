#include <iostream>
using namespace std;

int main(void) {
    int n;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        cout << str[0] << str[str.length() - 1] << '\n';
    }
    return 0;
}