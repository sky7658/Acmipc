#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    long long s, m, e;
    
    sort(times.begin(), times.end());
    
    s = 1;
    e = (long long)times[times.size() - 1] * n;
    
    while(s <= e) {
        long long check = 0;
        m = (s + e) / 2;
        
        for(int i = 0; i < times.size(); i++) {
            check += (m / (long long)times[i]);
        }
        
        if(check < n) {
            s = m + 1;
        } else {
            e = m - 1;
            answer = m;
        }
    }
    
    return answer;
}