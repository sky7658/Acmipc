#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int s, e, m;

    s = -1, e = 2e5;

    while(s + 1 < e) {
        int work = 0;
        m = (s + e) / 2;

        if(m > 0) for(int i = 0; i < cores.size(); i++) work += (m / cores[i] + 1);

        if(work < n) {
            s = m;
        } else {
            e = m;
        }
    }
    
    if(s == -1) return n;
    int work = 0;
    for(int i = 0; i < cores.size(); i++) work += (s / cores[i] + 1);
    for(int i = 0; i < cores.size(); i++) {
        if((s + 1) % cores[i] == 0) work++;
        if(n == work) return i + 1;
    }
    
    return 0;
}