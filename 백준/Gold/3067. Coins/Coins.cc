#include <iostream>
using namespace std;

int main()
{
	int t, n;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int dp[21][10001] = { 0 };
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			int cost;
			cin >> cost;
			dp[j][cost] = 1;
			for (int k = 1; k <= 10000; k++)
			{
				if (k < cost)
				{
					dp[j][k] += dp[j - 1][k];
				}
				else
				{
					dp[j][k] += dp[j - 1][k] + dp[j][k - cost];
				}
			}
			
		}
		int m;
		cin >> m;
		cout << dp[n][m] <<'\n';
	}

	return 0;
}