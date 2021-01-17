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
	queue<tuple<int, int, int>> q; // ȭ��, Ŭ������, �� ��
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
			if (get<1>(cur) > 0) { // Ŭ�����尡 ������� ������
				q.push(make_tuple(get<0>(cur) + get<1>(cur), get<1>(cur), get<2>(cur) + 1));
			}
			if (get<0>(cur) > 1) { // ȭ�鿡 �ִ� �̸�Ƽ�� ������ 2 �̻��̸�
				q.push(make_tuple(get<0>(cur) - 1, get<1>(cur), get<2>(cur) + 1));
			}
			q.push(make_tuple(get<0>(cur), get<0>(cur), get<2>(cur) + 1));
		}
	}
	return 0;
}
