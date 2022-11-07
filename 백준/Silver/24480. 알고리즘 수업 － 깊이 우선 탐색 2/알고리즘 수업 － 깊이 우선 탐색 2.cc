#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visit[100001];
int cnt = 1;
vector<int> arr[100001];

void dfs(int v, int e, int r) {
	visit[r] = cnt++;
	for(int i = 0; i < arr[r].size(); i++) {
		if(visit[arr[r][i]] == 0) dfs(v, e, arr[r][i]);
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
		sort(arr[i].begin(), arr[i].end(), greater<>());
	}
	dfs(n, m, r);
	for(int i = 1; i <= n; i++) {
		cout << visit[i] << '\n';
	}
	return 0;
}