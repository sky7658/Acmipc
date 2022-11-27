#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int map[10][10];
int ans[10][10];
int n, m;

void bfs() {
	q.push({0, 0});
	
	while(!q.empty()) {
		pair<int, int> p = q.front();
		for(int i = 1; i <= 6; i++) {
			int n = map[p.second][p.first] - 1;
			int nx = (n + i) % 10;
			int ny = (n + i) / 10;
			if(ny < 10 && ans[ny][nx] == 0) {
				q.push({nx, ny});
				ans[ny][nx] = ans[p.second][p.first] + 1;
			}
			if(ny == 9 && nx == 9) return;
		}
		q.pop();
	}
}

int main() {
	int x, y;
	cin >> n >> m;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			map[i][j] = 10 * i + j + 1;
		}
	}
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		map[(x - 1) / 10][(x - 1) % 10] = y;
	}
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		map[(x - 1) / 10][(x - 1) % 10] = y;
	}
	bfs();
	cout << ans[9][9];
	return 0;
}