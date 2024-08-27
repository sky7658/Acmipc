#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<char> stack;
	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (stack.empty())
		{
			stack.push(str[i]);
			continue;
		}

		if (str[i] == ')' && stack.top() == '(')
		{
			stack.pop();
			continue;
		}
		stack.push(str[i]);
	}
	
	cout << stack.size();
	return 0;
}