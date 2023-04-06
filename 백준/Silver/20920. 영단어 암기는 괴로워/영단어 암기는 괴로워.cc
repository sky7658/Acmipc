#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string str;
int n, m;
unordered_map<string, int> m_words;
vector<string> v_words;

bool Compare(string a, string b) {
    if (m_words[a] == m_words[b]) {
        if (a.length() == b.length()) {
            return a < b;
        } else {
            return a.length() > b.length();
        }
    } else {
        return m_words[a] > m_words[b];
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str.length() < m) continue;

        if (m_words.find(str) == m_words.end()) {
            m_words.insert({str, 1});
            v_words.push_back(str);
        } else {
            m_words[str]++;
        }
    }

    sort(v_words.begin(), v_words.end(), Compare);

    for (auto itr = v_words.begin(); itr != v_words.end(); itr++)
        cout << *itr << '\n';

    return 0;
}