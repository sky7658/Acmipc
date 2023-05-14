#include <iostream>
using namespace std;

int main(void) {
    int n, b;
    cin >> n >> b;
    string answer = "";
    while (n > 0) {
        int temp = n % b;
        if (temp > 9)
            answer = char(temp - 10 + 'A') + answer;
        else
            answer = char(temp + '0') + answer;
        n /= b;
    }
    cout << answer;
    return 0;
}