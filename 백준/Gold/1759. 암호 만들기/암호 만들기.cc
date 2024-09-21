#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<char> v, char str[], bool visit[], int l, int c, int n1, int n2, int start)
{
	if (v.size() == l)
	{
		if (n1 < 1 || n2 < 2) return;
		for (int i = 0; i < v.size(); i++) cout << v[i];
		cout << '\n';
		return;
	}

	for (int i = start; i < c; i++)
	{
		v.push_back(str[i]);

		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
			|| str[i] == 'o' || str[i] == 'u') 
			dfs(v, str, visit, l, c, n1 + 1, n2, i + 1);
		else dfs(v, str, visit, l, c, n1, n2 + 1, i + 1);

		v.pop_back();
	}
}

int main()
{
	bool visit[15];
	char str[15];
	int l, c;
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> str[i];
	}

	sort(str, str + c);
	vector<char> v;

	dfs(v, str, visit, l, c, 0, 0, 0);
	return 0;
}