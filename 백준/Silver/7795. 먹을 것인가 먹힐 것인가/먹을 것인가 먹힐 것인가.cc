#include <iostream>
#include <algorithm>
using namespace std;

int Binary_Search(int s, int e, int search, int a[])
{
	if (s >= e) return s;

	int m = (s + e) / 2;

	if (a[m] >= search) return Binary_Search(s, m, search, a);
	return Binary_Search(m + 1, e, search, a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m;

	cin >> t;
	while (t-- > 0)
	{
		int a[20000];
		int b[20000];
		cin >> n >> m;
		int ans = 0;

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		sort(b, b + m);

		for (int i = 0; i < n; i++) ans += Binary_Search(0, m, a[i], b);

		cout << ans << '\n';
	}

	return 0;
}