#include <iostream>
#include <stack>

using namespace std;

int Cal(stack<pair<bool, int>> _stack, int _n)
{
	while (!_stack.empty())
	{
		if (_stack.top().second == '(') _n *= 2;
		else if (_stack.top().second == '[') _n *= 3;
		_stack.pop();
	}
	return _n;
}

int main()
{
	stack<pair<bool, int>> stack;
	string str;
	int ans = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (stack.empty()) 
		{
			stack.push(make_pair(false, str[i]));
			continue;
		}

		if (str[i] == ')' && stack.top().second == '(')
		{
			if (stack.top().first) stack.pop();
			else
			{
				stack.pop();
				ans += Cal(stack, 2);
			}
			continue;
		}

		if (str[i] == ']' && stack.top().second == '[')
		{
			if (stack.top().first) stack.pop();
			else
			{
				stack.pop();
				ans += Cal(stack, 3);
			}
			continue;
		}
		stack.top().first = true;
		stack.push(make_pair(false, str[i]));
	}
	if (stack.empty()) cout << ans;
	else  cout << 0;
	return 0;
}