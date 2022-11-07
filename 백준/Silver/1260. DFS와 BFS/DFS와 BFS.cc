#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool visit[1001];
vector<int> arr[1001];
deque<int> dq;

void bfs(int r) {
	dq.push_front(r);
	visit[dq.front()] = true;
	while(!dq.empty()) {
		cout << dq.front() << ' ';
		for(int i = 0; i < arr[dq.front()].size(); i++) {
			if(!visit[arr[dq.front()][i]]) {
				dq.push_back(arr[dq.front()][i]);
				visit[arr[dq.front()][i]] = true;
			}
		}
		dq.pop_front();
	}
}

void dfs(int r) {
	visit[r] = true;
	cout << r << ' ';
	for(int i = 0; i < arr[r].size(); i++) {
		if(!visit[arr[r][i]]) dfs(arr[r][i]);
	}
}

int main() {
	int n, m, r, u, v;
	cin >> n >> m >> r;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	dfs(r);
	cout << '\n';
	for(int i = 1; i <= n; i++) {
		visit[i] = false;
	}
	bfs(r);
	return 0;
}