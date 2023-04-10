#include <iostream>
using namespace std;

int main() {
	long long s, n = 1, sum = 0;
	cin >> s;
	while(sum + n <= s) {
		sum += n;
		n++;
	}
	cout << n - 1;
	return 0;
}