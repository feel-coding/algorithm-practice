#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[10005];
vector<int> graph[10005];

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (!visited[cur.first]) {
			visited[cur.first] = (cur.second % 2 == 0 ? 2 : 1);
			for (int i = 0; i < graph[cur.first].size(); i++) {
				q.push(make_pair(graph[cur.first][i], cur.second + 1));
			}
		}
		else if (cur.second % 2 == 0 && visited[cur.first] == 1 || cur.second % 2 == 1 && visited[cur.first] == 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
