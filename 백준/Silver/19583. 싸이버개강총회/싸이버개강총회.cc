#include <iostream>
#include <string>
#include <set>

using namespace std;

int Cal_Time(string s)
{
	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 5));
}

int main()
{
	int st[3];

	for (int i = 0; i < 3; i++)
	{
		string str;
		cin >> str;
		st[i] = Cal_Time(str);
	}

	set<string> check;
	int count = 0;

	while (true)
	{
		string t, n;

		cin >> t >> n;
		if (cin.eof()) break;

		int s = Cal_Time(t);
		
		if (s <= st[0])
		{
			check.insert(n);
		}
		else
		{
			if (s >= st[1] && s <= st[2] && check.find(n) != check.end())
			{
				count++;
				check.erase(n);
			}
		}
	}
	cout << count;
	return 0;
}