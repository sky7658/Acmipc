#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	queue<pair<int, int>> arr;
	int people[10];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push(make_pair(i, x));
		people[i] = 100;
	}

	while (!arr.empty())
	{
		int index = arr.front().first + 1;
		int left = arr.front().second;
		arr.pop();

		for (int i = 0; i < n; i++)
		{
			if (left == 0 && people[i] == 100)
			{
				people[i] = index;
				break;
			}
			if (people[i] > index) left--;
		}
	}

	for (int i = 0; i < n; i++) cout << people[i] << ' ';
	return 0;
}