#include <iostream>
#include <algorithm>
using namespace std;

int m, n;

int Binary_Search(int s, int e, int a[])
 {
	if (s >= e) return s;

	int mid = (s + e) / 2;

	if (mid == 0) return 0;

	long long sum = 0;
	for (int i = 0; i < n; i++) sum += (a[i] / mid);

	if (sum >= m) return Binary_Search(mid + 1, e, a);
	else return Binary_Search(s, mid, a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int snacks[1000000];
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> snacks[i];

	sort(snacks, snacks + n);

	int result = Binary_Search(0, 1000000000, snacks);
	result = result > 0 ? result - 1 : 0;
	cout << result;
	return 0;
}