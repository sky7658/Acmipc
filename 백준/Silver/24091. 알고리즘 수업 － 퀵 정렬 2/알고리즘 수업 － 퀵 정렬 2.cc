#include <iostream>

using namespace std;
int cnt;
int n, k;

int Partition(int a[], int low, int high)
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
			if (++cnt == k)
			{
				for (int z = 0; z < n; z++) cout << a[z] << ' ';
				exit(0);
			}
		}
	}
	if (i + 1 != high)
	{
		int temp = a[i + 1];
		a[i + 1] = a[high];
		a[high] = temp;
		if (++cnt == k)
		{
			for (int z = 0; z < n; z++) cout << a[z] << ' ';
			exit(0);
		}
	}

	return i + 1;
}

void Quick_Sort(int a[], int low, int high)
{
	if (low >= high) return;

	int p = Partition(a, low, high);
	Quick_Sort(a, low, p - 1);
	Quick_Sort(a, p + 1, high);
}

int main()
{
	int arr[10000];

	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];

	Quick_Sort(arr, 0, n - 1);

	if (cnt < k) cout << -1;
	return 0;
}