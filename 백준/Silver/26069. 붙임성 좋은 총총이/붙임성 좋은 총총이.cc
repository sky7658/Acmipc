#include <iostream>
#include <map>
using namespace std;

map<string, bool> peoples;
int n;

int main(void) {
    cin >> n;
    int count = 0;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (a == "ChongChong")
            peoples.insert({a, true});
        else
            peoples.insert({a, false});

        if (b == "ChongChong")
            peoples.insert({b, true});
        else
            peoples.insert({b, false});

        if (peoples[a] || peoples[b]) {
            peoples[a] = true;
            peoples[b] = true;
        }
    }

    for (auto p : peoples) {
        if (p.second) count++;
    }
    cout << count;
    return 0;
}