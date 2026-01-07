#include <iostream>
using namespace std;

int main()
{
	long long dp[65][9] = { 0 ,};
	int t, n;

	dp[0][0] = 1;
	
	for (int i = 0; i < 9; i++)
	{
		dp[1][i] = 9 - i;
	}

	for (int i = 2; i < 65; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			dp[i][0] += dp[i - 1][j];
		}

		for (int j = 1; j < 9; j++)
		{
			dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long ans = 10;
		cin >> n;

		for (int i = 1; i < n; i++)
		{
			ans += dp[i + 1][0];
		}

		cout << ans << '\n';
	}
	return 0;
}