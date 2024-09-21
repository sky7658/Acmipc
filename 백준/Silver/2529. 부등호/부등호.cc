#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long maxAns = 0;
long long minAns = 9999999999;

void dfs(vector<int> v, char c[], int k, bool visit[])
{
	if (v.size() == k + 1)
	{
		long long sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i] * pow(10, v.size() - i - 1);
		}
		maxAns = sum > maxAns ? sum : maxAns;
		minAns = sum < minAns ? sum : minAns;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visit[i]) continue;
		if (!v.empty())
		{
			if (c[v.size() - 1] == '<')
			{
				if (v.back() >= i) continue;
			}
			else
			{
				if (v.back() <= i) continue;
			}
		}
		v.push_back(i);
		visit[i] = true;
		dfs(v, c, k, visit);
		v.pop_back();
		visit[i] = false;
	}
}

int main()
{
	bool visit[10] = { false, };
	char c[9];
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
	}

	vector<int> v;
	dfs(v, c, k, visit);

	cout.width(k + 1);
	cout.fill('0');
	cout << maxAns << '\n';
	cout.width(k + 1);
	cout.fill('0');
	cout << minAns;
	return 0;
}