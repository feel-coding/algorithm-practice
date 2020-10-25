#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int n;
int s;
vector<int> v;
int cnt = 0;

void combination(vector<bool> visited, vector<pair<int, int>> result, int num, int k) {
	if (num == k) {
		int total = 0;
		for (int i = 0; i < result.size(); i++) {
			total += result[i].first;
		}
		if (total == s) cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (num == 0) {
			if (!visited[i]) {
				visited[i] = true;
				result[num].first = v[i];
				result[num].second = i;
				combination(visited, result, num + 1, k);
				visited[i] = false;
			}
		}
		else {
			if (result[num - 1].second < i && !visited[i]) {
				visited[i] = true;
				result[num].first = v[i];
				result[num].second = i;
				combination(visited, result, num + 1, k);
				visited[i] = false;
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	v = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		vector<bool> visited(n);
		vector<pair<int, int>> result(i);
		combination(visited, result, 0, i);
	}
	cout << cnt;
	return 0;
}