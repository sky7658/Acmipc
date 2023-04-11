#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
queue<int> command;
int floor[1000001];

bool EscapeRange(int x) {
    if (x < 1 || x > f) return true;
    return false;
}

void bfs() {
    command.push(s);
    floor[s] = 1;

    while (!command.empty()) {
        if (!EscapeRange(command.front() + u) && !floor[command.front() + u]) {
            command.push(command.front() + u);
            floor[command.front() + u] = floor[command.front()] + 1;
        }
        if (!EscapeRange(command.front() - d) && !floor[command.front() - d]) {
            command.push(command.front() - d);
            floor[command.front() - d] = floor[command.front()] + 1;
        }
        command.pop();
    }
}

int main() {
    cin >> f >> s >> g >> u >> d;
    bfs();
    if (floor[g] == 0)
        cout << "use the stairs";
    else
        cout << floor[g] - 1;
    return 0;
}