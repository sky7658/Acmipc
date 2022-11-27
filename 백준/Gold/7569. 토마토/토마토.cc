#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int>> q;
tuple<int, int, int> d[6] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0},
								{0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int tomato[100][100][100];
// mx ny hz
int m, n, h, ans;

void bfs() {
	int size = q.size();
	
	while(!q.empty()) {
		tuple<int, int, int> p = q.front();
		for(int i = 0; i < 6; i++) {
			int nx = get<0>(p) + get<0>(d[i]);
			int ny = get<1>(p) + get<1>(d[i]);
			int nz = get<2>(p) + get<2>(d[i]);
			if(nx >= 0 && ny >= 0 && nz >= 0 && nx < m && ny < n && nz < h &&
				tomato[nz][ny][nx] == 0) {
					q.push({nx, ny, nz});
					tomato[nz][ny][nx] = 1;
				}
		}
		q.pop();
		if(--size == 0) {
			size = q.size();
			ans++;
		}
	}
}

int main() {
	cin >> m >> n >> h;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if(tomato[i][j][k] == 1)
					q.push({k, j, i});
			}
		}
	}
	bfs();
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				if(tomato[i][j][k] == 0){
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << ans - 1;
	return 0;
}