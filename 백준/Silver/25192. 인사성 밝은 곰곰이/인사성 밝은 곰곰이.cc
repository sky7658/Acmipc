#include <iostream>
#include <set>
using namespace std;

set<string> records;

int main() {
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "ENTER") {
            records.clear();
            continue;
        }
        if (records.find(str) == records.end()) {
            records.insert(str);
            count++;    
        }
    }
    cout << count;
    return 0;
}