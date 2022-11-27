#include <iostream>
#include <queue>
using namespace std;

int field[300][300];
pair<int, int> d[8] = {{2, 1}, {1, 2}, {2, -1}, {1, -2},
					{-2, 1}, {-1, 2}, {-2, -1}, {-1, -2}};
int t, sx, sy, tx, ty, l;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	
	while(!q.empty()) {
		for(int i = 0; i < 8; i++) {
			int nx = q.front().first + d[i].first;
			int ny = q.front().second + d[i].second;
			if(nx >= 0 && ny >= 0 && nx < l && ny < l && field[ny][nx] == 0) {
				q.push({nx, ny});
				if(field[ny][nx] == 0)
					field[ny][nx] = field[q.front().second][q.front().first] + 1;
				else
					field[ny][nx] = min(field[ny][nx], field[q.front().second][q.front().first] + 1);
					
			}
			if(nx == tx && ny == ty) {
				return;
			}
		}
		q.pop();
	}
}

int main() {
	cin >> t;
	while(t-- > 0) {
		cin >> l;
		cin >> sx >> sy >> tx >> ty;
		for(int i = 0; i < l; i++) {
			for(int j = 0; j < l; j++) {
				field[i][j] = 0;
			}
		}
		bfs(sx, sy);
		if(sx == tx && sy == ty) cout << 0 << '\n';
		else cout << field[ty][tx] << '\n';
	}
	return 0;
}