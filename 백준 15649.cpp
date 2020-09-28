#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m;

void combination(int num, vector<bool> visited, vector<int> result) {
	if (num == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			result[num] = i;
			visited[i] = true;
			combination(num + 1, visited, result);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	vector<bool> visited(n + 1, false);
	vector<int> result(m);
	combination(0, visited, result);
	return 0;
}