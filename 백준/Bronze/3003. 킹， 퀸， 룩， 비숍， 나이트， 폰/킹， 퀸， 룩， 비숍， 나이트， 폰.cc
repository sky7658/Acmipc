#include <iostream>
using namespace std;

int arr[6];
int arr2[6] = {1, 1, 2, 2, 2, 8};
int main(void) {
    for(int i = 0; i < 6; i++) cin >> arr[i];
    for(int i = 0; i < 6; i++) cout << arr2[i] - arr[i] << ' ';
    return 0;
}