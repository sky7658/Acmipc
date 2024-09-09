#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, w, l;

	cin >> n >> w >> l;
	queue<int> truck;
	queue<int> bridge;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		truck.push(a);
	}
	for (int i = 0; i < w; i++) bridge.push(0);

	int time = 0;
	int curw = 0;
	while (true)
	{
		curw -= bridge.front();
		bridge.pop();
		if (!truck.empty() && curw + truck.front() <= l)
		{
			curw += truck.front();
			bridge.push(truck.front());
			truck.pop();
		}
		else
		{
			bridge.push(0);
		}
		time++;
		if (curw == 0) break;
	}
	cout << time;
	return 0;
}