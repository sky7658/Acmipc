#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(void) {
    int a;
    for(int i = 0; i < 28; i++) { cin >> a, s.insert(a); }
    for(int i = 1; i <= 30; i++) if(s.find(i) == s.end()) cout << i << '\n';
    return 0;
}