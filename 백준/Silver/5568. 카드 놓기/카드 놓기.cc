#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> nums;
void dfs(string str[], vector<string> v, bool visit[], int n, int k)
{
	if (v.size() == k)
	{
		string num;
		for (int i = 0; i < v.size(); i++) num += v[i];
		nums.insert(num);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i]) continue;
		v.push_back(str[i]);
		visit[i] = true;
		dfs(str, v, visit, n, k);
		v.pop_back();
		visit[i] = false;
	}
}

int main()
{
	bool visit[10] = { false, };
	int n, k;
	string str[10];
	vector<string> v;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> str[i];

	dfs(str, v, visit, n, k);
	cout << nums.size();
	return 0;
}