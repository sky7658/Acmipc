#include <iostream>
using namespace std;

int main()
{
	long long dp[32][32] = { 0 , };
	int n, l;
	long long i;

	cin >> n >> l >> i;

	dp[0][0] = 1;
	for (int j = 1; j < 32; j++)
	{
		dp[j][0] = 1;
		dp[j][j] = 1;
	}

	for (int j = 2; j < 32; j++)
	{
		for (int k = 1; k < j; k++)
		{
			dp[j][k] = dp[j - 1][k - 1] + dp[j - 1][k];
		}
	}

	i--;
	for (int j = n - 1; j >= 0; j--)
	{
		long long sum = 0;

		for (int k = 0; k <= min(l, j); k++)
		{
			sum += dp[j][k];
		}
		
		if (sum <= i)
		{
			cout << '1';
			l--;
			i -= sum;
		}
		else
		{
			cout << '0';
		}
	}

	return 0;
}