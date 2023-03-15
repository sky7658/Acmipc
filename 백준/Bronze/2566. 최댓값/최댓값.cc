#include <iostream>
using namespace std;

int main(void)
{
    int row, col, max_n = 0, n;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++) 
        {
            cin >> n;
            if(max_n <= n) {
                max_n = n;
                row = i + 1;
                col = j + 1;
            }
        }
    }
    
    cout << max_n << '\n' << row << ' ' << col;
    return 0;
}