#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	int ans = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string str;
		stack<char> word;

		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (word.empty())
			{
				word.push(str[i]);
				continue;
			}

			if (word.top() == str[i]) word.pop();
			else word.push(str[i]);
		}

		if (word.empty()) ans++;
	}

	cout << ans;
	return 0;
}