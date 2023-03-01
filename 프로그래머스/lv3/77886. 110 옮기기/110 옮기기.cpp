#include <string>
#include <vector>

using namespace std;

pair<string, int> Search_110(string s) {
    int count = 0;
    
    for(int i = 2; i < s.length(); i++) {
        string str;
        for(int j = 2; j >= 0; j--) str.push_back(s[i - j]);
        if(str == "110") {
            s.erase(i - 2, 3);
            i -= 3;
            count++;
        }
    }
    
    return make_pair(s ,count);
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(int i = 0; i < s.size(); i++) {
        pair<string, int> str = Search_110(s[i]);
        string cpy_str = str.first;
        
        int index = -1;
        for(int j = 0; j < cpy_str.length(); j++) {
            if(cpy_str[j] == '0') index = j;
        }
        
        for(int i = 0; i < str.second; i++)
            cpy_str.insert(index + 1, "110");
        
        answer.push_back(cpy_str);
    }
    
    return answer;
}