#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Binary_Search(int s, int e, int search, vector<int> a)
{
	if (s > e) return false;

	int m = (s + e) / 2;

	if (a[m] < search) return Binary_Search(m + 1, e, search, a);
	else if (a[m] > search) return Binary_Search(s, m - 1, search, a);
	return true;
}

int main()
{
	int n;
	int nums[1000];
	vector<int> sums;

	cin >> n;

	for (int i = 0; i < n; i++) cin >> nums[i];

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) sums.push_back(nums[i] + nums[j]);

	sort(nums, nums + n);
	sort(sums.begin(), sums.end());

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			if (binary_search(sums.begin(), sums.end(), nums[i] - nums[j]))
			{
				cout << nums[i];
				return 0;
			}
		}
	}
}