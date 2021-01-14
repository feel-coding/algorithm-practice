#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	static vector<int> graph[100001];
	int from, to;
	for (int i = 0; i < n - 1; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	vector<bool> visited(n + 1, false);
	vector<int> parent(n + 1, -1);
	queue<int> q;
	q.push(1);
	parent[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!visited[cur]) {
			visited[cur] = true;
			for (int i = 0; i < graph[cur].size(); i++) {
				if (parent[graph[cur][i]] == -1) {
					parent[graph[cur][i]] = cur;
					q.push(graph[cur][i]);
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}
