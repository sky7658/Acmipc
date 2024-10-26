#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	
	while (s.length() < t.length())
	{
		if (t.back() == 'A')
		{
			t.pop_back();
		}
		else
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	if (s == t) cout << 1;
	else cout << 0;

	return 0;
}