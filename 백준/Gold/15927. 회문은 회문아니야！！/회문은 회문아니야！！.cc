#include <iostream>
using namespace std;

int main()
{
	string str;

	cin >> str;
	int len = str.length() / 2;

	bool flag = true;

	for (int i = 0; i < len; i++)
	{
		if (str[i] != str[str.length() - 1 - i]) flag = false;
	}

	if (flag)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[0] != str[i])
			{
				cout << str.length() - 1;
				return 0;
			}
		}
		cout << -1;
	}
	else 
		cout << str.length();

	return 0;
}