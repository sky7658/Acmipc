#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int m;
	vector<int> arr;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}

	m = n;

	for (int i = n - 1; i >= 0; i--)
	{
		if (m == arr[i]) m--;
	}

	cout << m;
	return 0;
}