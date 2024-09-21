#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> v, int n, bool visit[])
{
	if (v.size() == n)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] + 1 << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i]) continue;

		v.push_back(i);
		visit[i] = true;
		dfs(v, n, visit);
		v.pop_back();
		visit[i] = false;
	}
}

int main()
{
	int n;
	bool visit[8] = { false, };
	cin >> n;

	vector<int> v;

	dfs(v, n, visit);

	return 0;
}