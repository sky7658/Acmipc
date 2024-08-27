#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> w;
	int columns[1000] = { 0, };

	int n, l, h, maxh = 0, ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> l >> h;
		columns[l - 1] = h;
		if (maxh < h) maxh = h;
	}

	int i = 0;
	w.push(columns[0]);
	while (true)
	{
		if (w.top() == maxh) break;

		i++;

		if (w.top() < columns[i]) w.push(columns[i]);
		else w.push(w.top());
	}
	if (i != 999) w.push(columns[999]);
	for (int j = 998; j > i; j--)
	{
		if (w.top() < columns[j]) w.push(columns[j]);
		else w.push(w.top());
	}

	while (!w.empty())
	{
		ans += w.top();
		w.pop();
	}

	cout << ans;
	return 0;
}