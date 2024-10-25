#include <iostream>

using namespace std;
bool num[10000];
int cnt;
int n;

void SetCount(int a[], int b[], int index)
{
	if (a[index] == b[index])
	{
		if (!num[index])
		{
			cnt++;
			num[index] = true;
		}
	}
	else
	{
		if (num[index])
		{
			cnt--;
			num[index] = false;
		}
	}
}

int Partition(int a[], int b[], int low, int high)
{
	int pivot = high;
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (a[j] <= a[pivot])
		{
			int temp = a[++i];
			a[i] = a[j];
			a[j] = temp;

			SetCount(a, b, i);
			SetCount(a, b, j);

			if (cnt == n)
			{
				cout << 1;
				exit(0);
			}
		}
	}
	if (i + 1 != high)
	{
		int temp = a[i + 1];
		a[i + 1] = a[high];
		a[high] = temp;

		SetCount(a, b, i + 1);
		SetCount(a, b, high);

		if (cnt == n)
		{
			cout << 1;
			exit(0);
		}
	}

	return i + 1;
}

void Quick_Sort(int a[], int b[], int low, int high)
{
	if (low >= high) return;

	int p = Partition(a, b, low, high);

	Quick_Sort(a, b, low, p - 1);
	Quick_Sort(a, b, p + 1, high);
}

int main()
{
	int a[10000];
	int b[10000];

	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		if (a[i] == b[i])
		{
			cnt++;
			num[i] = true;
		}
	}

	if (cnt == n)
	{
		cout << 1;
		return 0;
	}

	Quick_Sort(a, b, 0, n - 1);

	cout << 0;
	return 0;
}