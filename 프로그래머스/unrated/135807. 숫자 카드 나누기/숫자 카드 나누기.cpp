#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int fun(vector<int> arrA, vector<int> arrB) {
    int cnt = 0;
    vector<int> v;
    
    
    for(int i = 2; i <= arrA[0]; i++) {
        for(int j = 0; j < arrA.size(); j++) {
            if(arrA[j] % i > 0 || arrA[j] < i) break;
            cnt++;
        }
        if(cnt == arrA.size()) {
            cout << i << '\n';
            v.push_back(i);
        }
        cnt = 0;
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < arrB.size(); j++) {
            if(arrB[j] % v[i] == 0 && v[i] <= arrB[j]) break;
            cnt++;
        }
        if(cnt == arrB.size()) return v[i];
        cnt = 0;
    }
    
    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end(), greater<>());
    sort(arrayB.begin(), arrayB.end(), greater<>());
    
    answer = max(fun(arrayA, arrayB), fun(arrayB, arrayA));
    
    return answer;
}