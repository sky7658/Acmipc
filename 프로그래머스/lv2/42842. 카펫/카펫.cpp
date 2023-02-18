#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int size = brown + yellow;
    int i = 2;
    
    while(true) {
        if(!(size % i)) {
            if((size / i + (i - 2)) * 2 == brown) {
                answer.push_back(size / i);
                answer.push_back(i);
                break;
            }
        }
        i++;
    }
    return answer;
}