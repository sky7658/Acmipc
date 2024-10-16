#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int Binary_Search(int s, int e, int a[])
 {
	if (s >= e) return s;

	int mid = (s + e) / 2;

	int count = 0;
	int money = 0;
	for (int i = 0; i < n; i++)
	{
		if (mid < a[i])
		{
			count = 0;
			break;
		}

		if (money < a[i])
		{
			money = mid;
			count++;
		}
		money -= a[i];
	}

	if (count > m || count == 0) return Binary_Search(mid + 1, e, a);
	else return Binary_Search(s, mid, a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int days[100000];

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> days[i];

	int result = Binary_Search(1, 1000000000, days) + 1;
	result = result > 0 ? result - 1 : 0;
	cout << result;
	return 0;
}