#include <iostream>
#include <vector>
using namespace std;

int arr[105][105];
int n, m, k, t;
int cnt = 0;
vector<pair<int, int>> diffuser;
int result[10005];
bool flag = false;
bool visited[10005];

void getResult(int current) {
	if (flag) return;
	if (current == k) {
		cnt++;
		if (cnt == t) {
			flag = true;
			for (int i = 0; i < k; i++) {
				cout << diffuser[result[i]].first + 1 << " " << diffuser[result[i]].second + 1 << '\n';
			}
		}
		return;
	}
	for (int i = 0; i < diffuser.size(); i++) {
		if (!visited[i]) {
			if (current == 0) {
				visited[i] = true;
				result[current] = i;
				getResult(current + 1);
				visited[i] = false;
			}
			else if (result[current - 1] < i) {
				visited[i] = true;
				result[current] = i;
				getResult(current + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				diffuser.push_back(make_pair(i, j));
			}
		}
	}
	getResult(0);
	return 0;
}