#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


int main() {
	int n, m, v;
	cin >> n >> m >> v;
	vector<int> graph[1001];
	vector<bool> visited(n + 1);
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	stack<int> s;
	s.push(v);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		if (!visited[cur]) {
			visited[cur] = true;
			cout << cur << " ";
			for (int i = graph[cur].size() - 1; i >= 0; i--) {
				if (!visited[graph[cur][i]]) {
					s.push(graph[cur][i]);
				}
			}
		}
	}
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!visited[cur]) {
			visited[cur] = true;
			cout << cur << " ";
			for (int i = 0; i < graph[cur].size(); i++) {
				if (!visited[graph[cur][i]]) {
					q.push(graph[cur][i]);
				}
			}
		}
	}
	return 0;
}