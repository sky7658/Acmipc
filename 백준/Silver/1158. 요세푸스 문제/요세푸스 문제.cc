#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) q.push(i + 1);
	cout << '<';
	while (!q.empty())
	{
		if (q.size() != n) cout << ", ";
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
	}
	cout << '>';
	return 0;
}