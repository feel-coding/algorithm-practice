#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[105];
bool visited[105];

int main() {
	int n, m, from, to;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	int cnt = 0;
	stack<int> s;
	s.push(1);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		if (!visited[cur]) {
			cnt++;
			visited[cur] = true;
			for (int i = 0; i < graph[cur].size(); i++) {
				s.push(graph[cur][i]);
			}
		}
	}
	cout << cnt - 1;
	return 0;
}
