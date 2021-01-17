#include <iostream>
#include <queue>
#include <tuple>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	queue<tuple<int, int, int>> q; // 화면, 클립보드, 몇 초
	q.push(make_tuple(1, 0, 0));
	map<pair<int, int>, bool> visited;
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();
		if (get<0>(cur) == n) {
			cout << get<2>(cur);
			break;
		}
		if (!visited[make_pair(get<0>(cur), get<1>(cur))]) {
			visited[make_pair(get<0>(cur), get<1>(cur))] = true;
			if (get<1>(cur) > 0) { // 클립보드가 비어있지 않으면
				q.push(make_tuple(get<0>(cur) + get<1>(cur), get<1>(cur), get<2>(cur) + 1));
			}
			if (get<0>(cur) > 1) { // 화면에 있는 이모티콘 개수가 2 이상이면
				q.push(make_tuple(get<0>(cur) - 1, get<1>(cur), get<2>(cur) + 1));
			}
			q.push(make_tuple(get<0>(cur), get<0>(cur), get<2>(cur) + 1));
		}
	}
	return 0;
}
