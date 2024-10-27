#include <iostream>
#include <set>

using namespace std;

int main()
{
	int r, c;
	string str[1000];

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string temp;
		cin >> temp;
		for (int i = 0; i < c; i++)
		{
			str[i] += temp[i];
		}
	}

	int count = 0;
	bool flag = true;
	while (flag)
	{
		set<string> s;
		for (int i = 0; i < c; i++)
		{
			if (!str[i].empty()) str[i].erase(str[i].begin());
			if (!(s.find(str[i]) == s.end()))
			{
				flag = false;
				break;
			}
			s.insert(str[i]);
		}
		if (flag) count++;
	}
	
	cout << count;
	return 0;
}