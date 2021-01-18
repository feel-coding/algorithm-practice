#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	vector<bool> visited(f + 1, false);
	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	int answer = -1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (cur.first == g) {
			answer = cur.second;
			break;
		}
		if (!visited[cur.first]) {
			visited[cur.first] = true;
			if (cur.first + u <= f) {
				q.push(make_pair(cur.first + u, cur.second + 1));
			}
			if (cur.first - d >= 1) {
				q.push(make_pair(cur.first - d, cur.second + 1));
			}
		}
	}
	if (answer == -1) {
		cout << "use the stairs";
	}
	else {
		cout << answer;
	}
	return 0;
}
