#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<queue<int>> q(20);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		q[str.length() - 1].push(i);
	}
	long long count = 0;
	for (int i = 0; i < 20; i++)
	{
		queue<int> q2;
		while (!q[i].empty())
		{
			if (!q2.empty())
			{
				while (!q2.empty() && q[i].front() - q2.front() > k)
				{
					count += q2.size() - 1;
					q2.pop();
				}
			}
			q2.push(q[i].front());
			q[i].pop();
		}

		while (!q2.empty())
		{
			count += q2.size() - 1;
			q2.pop();
		}
	}
	cout << count;
	return 0;
}