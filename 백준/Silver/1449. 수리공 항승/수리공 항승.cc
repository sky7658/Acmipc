#include <iostream>

using namespace std;

int main()
{
	int n, l;
	bool arr[1000] = { false, };

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr[x - 1] = true;
	}

	int cnt = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i])
		{
			cnt++;
			i += (l - 1);
		}
	}

	cout << cnt;
	return 0;
}