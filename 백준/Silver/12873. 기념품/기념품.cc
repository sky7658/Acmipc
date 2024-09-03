#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	queue<int> p;
	int n, stage = 1;
	cin >> n;

	for (int i = 0; i < n; i++) p.push(i + 1);

	while (p.size() > 1)
	{
		long long count = (long long)pow(stage, 3) % p.size() - 1;
		if (count < 0) count += p.size();
		for (int i = 0; i < count; i++)
		{
			p.push(p.front());
			p.pop();
		}
		p.pop();
		stage++;
	}

	cout << p.front();
	return 0;
}