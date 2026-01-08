#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m;
	int dp[100002] = { 0, };

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << dp[b] - dp[a - 1] << '\n';
	}

	return 0;
}