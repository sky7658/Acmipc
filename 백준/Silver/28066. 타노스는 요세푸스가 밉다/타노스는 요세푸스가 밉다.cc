#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) q.push(i + 1);

	while (q.size() > 1)
	{
		if (k > q.size()) break;

		q.push(q.front());
		q.pop();
		for (int i = 0; i < k - 1; i++) q.pop();
	}

	cout << q.front();
	return 0;
}