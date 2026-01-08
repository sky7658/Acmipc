#include <iostream>
using namespace std;

int n;
int minnum;
pair<int, int> arr[10];

void dfs(int start, int s, int b)
{
	minnum = min(minnum, abs(s - b));

	for (int i = start; i < n; i++)
	{
		int s2 = s * arr[i].first;
		int b2 = b + arr[i].second;

		dfs(i + 1, s2, b2);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int s, b;
		cin >> s >> b;
		arr[i] = make_pair(s, b);
	}

	minnum = abs(arr[0].first - arr[0].second);

	for (int i = 0; i < n; i++)
	{
		dfs(i + 1, arr[i].first, arr[i].second);
	}

	cout << minnum;
	return 0;
}