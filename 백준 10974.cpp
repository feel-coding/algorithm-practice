#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int n;

void permutation(int num, vector<bool> visited, vector<int> result) {
	if (num == n) {
		for (int i = 0; i < n; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			result[num] = i + 1;
			visited[i] = true;
			permutation(num + 1, visited, result);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	permutation(0, vector<bool>(n, false), vector<int>(n));
	return 0;
}