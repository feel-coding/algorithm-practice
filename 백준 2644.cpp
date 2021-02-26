#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n, a, b, m;
	vector<int> graph[101];
	bool visited[101] = { 0 };
	cin >> n >> a >> b >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	stack<pair<int, int>> s;
	s.push(make_pair(a, 0));
	bool flag = false;
	while (!s.empty()) {
		pair<int, int> cur = s.top();
		s.pop();
		if (cur.first == b) {
			cout << cur.second;
			flag = true;
			break;
		}
		if (!visited[cur.first]) {
			visited[cur.first] = true;
			for (int i = 0; i < graph[cur.first].size(); i++) {
				s.push(make_pair(graph[cur.first][i], cur.second + 1));
			}
		}
	}
	if (!flag) cout << -1;
	return 0;
}