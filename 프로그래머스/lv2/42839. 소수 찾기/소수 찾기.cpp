#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool dp[50000000];
int answer;
set<int> s;

bool IsPrime(int n) {
    if (n < 2) return false;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int i = 2;
    int j = 2;
    dp[0] = true;
    dp[1] = true;
    while(true) {
        if(i * j >= 10000000) {
            while(++i < 10000000 && dp[i])
            j = 2;
        }
        if(i >= 10000000) break;
        dp[i * j] = true;
        j++;
    }
    
    vector<char> v;
    
    for(int i = 0; i < numbers.length(); i++) {
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());
    do {
        string temp;
        
        for(int i = 0; i < v.size(); i++) {
            temp.push_back(v[i]);
            s.insert(stoi(temp));
        }

    } while(next_permutation(v.begin(), v.end()));
    
    for(auto itr = s.begin(); itr != s.end(); itr++) {
        if(IsPrime(*itr)) answer++;
    }
    
    return answer;
}