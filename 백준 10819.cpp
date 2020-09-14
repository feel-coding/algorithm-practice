#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

int n;
vector<int> v;
vector<bool> visited;
int maxSum = 0;

void permutation(int num, vector<int> result) {
	if (n == num) {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += (abs(result[i] - result[i + 1]));
		}
		if (sum > maxSum)
			maxSum = sum;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[num] = v[i];
			permutation(num + 1, result);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	v = vector<int>(n);
	visited = vector<bool>(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	permutation(0, vector<int>(n));
	cout << maxSum;
	return 0;
}