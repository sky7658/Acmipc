#include <iostream>
using namespace std;
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int a, i = 1;
	cin >> a;

	while (1)
	{
		if ((a -= i) <= 0) break;
		i++;
	}

	if (i % 2) cout << 1 - a << '/' << a + i;
	else cout << a + i << '/' << 1 - a;
	return 0;
}