#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1005];
int visited[1005];

int main() {
	int n, m, from, to;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
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
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
