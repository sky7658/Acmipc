#include <iostream>
#include <algorithm>
using namespace std;


int Binary_Search(int s, int e, int search, int note[])
{
	if (s > e) return 0;

	int m = (s + e) / 2;

	if (note[m] == search) return 1;
	else if (note[m] > search)
	{
		return Binary_Search(s, m - 1, search, note);
	}
	else
	{
		return Binary_Search(m + 1, e, search, note);
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m;

	cin >> t;
	while (t-- > 0)
	{
		int note1[1000000];
		cin >> n;
		for (int i = 0; i < n; i++) cin >> note1[i];
		sort(note1, note1 + n);
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a;
			cin >> a;
			cout << Binary_Search(0, n - 1, a, note1) << '\n';
		}
	}

	return 0;
}