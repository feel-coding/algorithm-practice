#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a, b;
	vector<int> graph[501];
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	vector<bool> visited(n + 1, false);
	vector<vector<bool>> approach(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; i++) {
		visited = vector<bool>(n + 1, false);
		stack<int> stack;
		stack.push(i);
		while (!stack.empty()) {
			int cur = stack.top();
			stack.pop();
			if (!visited[cur]) {
				visited[cur] = true;
				approach[i][cur] = true;
				for (int j = 0; j < graph[cur].size(); j++) {
					stack.push(graph[cur][j]);
				}
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (approach[i][j])
				cnt++;
			if (approach[j][i])
				cnt++;
		}
		if (cnt == n + 1) {
			answer++;
		}
	}
	cout << answer;
	return 0;
}
