#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int visit[100001];
int cnt = 1;
vector<int> arr[100001];
deque<int> dq;

void bfs(int r) {
	dq.push_front(r);
	visit[dq.front()] = cnt++;
	while(!dq.empty()) {
		for(int i = 0; i < arr[dq.front()].size(); i++) {
			if(visit[arr[dq.front()][i]] == 0) {
				dq.push_back(arr[dq.front()][i]);
				visit[arr[dq.front()][i]] = cnt++;
			}
		}
		dq.pop_front();
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
	bfs(r);
	for(int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
	return 0;
}