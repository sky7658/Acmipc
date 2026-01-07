#include <iostream>
using namespace std;

int main()
{
	long long dp[65][10] = { 0 ,};
	int t, n;

	for (int i = 0; i < 10; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i <= 64; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp[n][0] << '\n';
	}
	return 0;
}