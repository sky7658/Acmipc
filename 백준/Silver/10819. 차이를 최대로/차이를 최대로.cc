#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void dfs(vector<int> v, int n, bool visit[], int arr[])
{
	if (v.size() == n)
	{
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
			sum += abs(v[i] - v[i + 1]);
		ans = sum > ans ? sum : ans;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i]) continue;

		visit[i] = true;
		v.push_back(arr[i]);
		dfs(v, n, visit, arr);
		visit[i] = false;
		v.pop_back();
	}
}

int main()
{
	int n;
	bool visit[8] = { false, };
	int arr[8];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vector<int> v;
	dfs(v, n, visit, arr);

	cout << ans;

	return 0;
}