#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int> numbers, int target, int count, int sum) {
    if(count == numbers.size()) {
        if(sum == target) answer++;
        return;
    }
    
    int n = numbers[count];
    
    for(int i = 0; i < 2; i++) {   
        dfs(numbers, target, count + 1, sum + n);
        n *= -1;
    }
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);
    
    return answer;
}