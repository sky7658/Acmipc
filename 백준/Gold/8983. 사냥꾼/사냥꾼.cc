#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool Binary_Search(int s, int e, int minNum, int maxNum, int a[], int len)
{
	if (s > e)
	{
		if (s < 0 || s >= len) return false;
		if (a[s] <= maxNum && a[s] >= minNum) return true;
		return false;
	}

	int m = (s + e) / 2;

	if (a[m] < minNum) return Binary_Search(m + 1, e, minNum, maxNum, a, len);
	else if (a[m] > maxNum) return Binary_Search(s, m - 1, minNum, maxNum, a, len);
	else return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m, n, l;
	int hunts[100];

	int ans = 0;

	cin >> m >> n >> l;

	for (int i = 0; i < m; i++) cin >> hunts[i];

	sort(hunts, hunts + m);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		int range = l - y;
		if (range < 0) continue;
		ans = Binary_Search(0, m, x - range, x + range, hunts, m) ? ans + 1 : ans;
	}

	cout << ans;
	return 0;
}