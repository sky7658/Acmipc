#include <iostream>

using namespace std;

int ans = 0;

void dfs(string str[], bool visit[], int n, int k, int start, int count)
{
	if (count == k)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			bool flag = true;
			for (int j = 0; j < str[i].length(); j++)
			{
				if (!visit[str[i][j] - 'a'])
				{
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		ans = cnt > ans ? cnt : ans;
		return;
	}

	for (int i = start; i < 26; i++)
	{
		if (visit[i]) continue;

		visit[i] = true;
		dfs(str, visit, n, k, i, count + 1);
		visit[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bool visit[26] = { false, };
	string str[50];

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> str[i];

	visit[0] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['c' - 'a'] = true;

	dfs(str, visit, n, k - 5, 0, 0);
	cout << ans;
	return 0;
}