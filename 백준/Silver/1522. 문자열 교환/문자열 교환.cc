#include <iostream>
using namespace std;

int main()
{
	string str;
	int lenb = 0;
	int minb = 1000;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'b') lenb++;
	}

	if (lenb == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != 'b') continue;

		int temp = 0;
		for (int j = 1; j < lenb; j++)
		{
			int index = (i + j) % str.length();

			if (str[index] == 'a') temp++;
		}

		minb = temp < minb ? temp : minb;
	}
	
	cout << minb;
	return 0;
}