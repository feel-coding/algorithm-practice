#include <iostream>
#include <queue>
using namespace std;

bool visited[100005];

int main() {
	int n;
	cin >> n;
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (cur.first == n) {
			cout << cur.second;
			break;
		}
		if (!visited[cur.first]) {
			visited[cur.first] = true;
			if (cur.first * 2 <= 99999) q.push(make_pair(cur.first * 2, cur.second + 1));
			q.push(make_pair(cur.first / 3, cur.second + 1));
		}
	}
	return 0;
}
