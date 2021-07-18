#include <iostream>
#include <vector>
using namespace std;

bool visited[105] = { 0 };
vector<int> graph[105];
int maxHeight = 0;

void dfs(int node, int cnt) {
	if (cnt > maxHeight) maxHeight = cnt;
	if (!visited[node]) {
		visited[node] = true;
		for (int i = 0; i < graph[node].size(); i++) {
			if (!visited[graph[node][i]]) {
				dfs(graph[node][i], cnt + 1);
			}
		}
	}
}

int main() {
	int n, r, a, b;
	cin >> n >> r;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(r, 0);
	cout << maxHeight;
	return 0;
}
