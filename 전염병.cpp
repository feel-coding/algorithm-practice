#include <iostream>
#include <queue>
using namespace std;

bool visited[100005];

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(k);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!visited[cur]) {
			visited[cur] = true;
			if (cur / 3 >= 1) q.push(cur / 3);
			if (cur * 2 <= n) q.push(cur * 2);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) cnt++;
	}
	cout << cnt;
	return 0;
}
