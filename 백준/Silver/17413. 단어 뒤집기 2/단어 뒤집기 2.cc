#include <iostream>
#include <string>
#include <stack>

using namespace std;

void InsertReverseWord(stack<char>& _word, string& _ans)
{
	while (!_word.empty())
	{
		_ans += _word.top();
		_word.pop();
	}
}

int main()
{
	bool flag = false;
	string str, ans;
	stack<char> word;

	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && !flag)
		{
			InsertReverseWord(word, ans);
			ans += str[i];
			continue;
		}

		if (str[i] == '<')
		{
			InsertReverseWord(word, ans);
			flag = true;
		}

		if (flag) ans += str[i];
		else word.push(str[i]);

		if (str[i] == '>') flag = false;
	}
	InsertReverseWord(word, ans);
	cout << ans;
	return 0;
}