#include <iostream>
using namespace std;

int main()
{
	int g;

	cin >> g;

	int l = 1, r = 1;
	bool flag = false;

	while (true)
	{
		int l2 = l * l;
		int r2 = r * r;
		if (l2 - r2 == g)
		{
			cout << l << '\n';
			flag = true;
		}

		if (l - r == 1 && l2 - r2 > g) break;

		if (l2 - r2 < g)
		{
			l++;
		}
		else
		{
			r++;
		}
	}

	if (!flag) cout << -1;

	return 0;
}