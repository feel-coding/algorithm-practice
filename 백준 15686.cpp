#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int numOfStore;
vector<vector<int>> v;
vector<pair<int, int>> storeLocation;
int minLength = 100000;

void combination(vector<int> result, vector<bool> visited, int num) {
	if (num == m) {
		int row, col;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 1) {
					int minLen = 1000;
					int length;
					for (int s = 0; s < m; s++) {
						row = storeLocation[result[s]].first;
						col = storeLocation[result[s]].second;
						length = ((row - i > i - row) ? row - i : i - row) + ((col - j > j - col) ? col - j : j - col);
						if (length < minLen)
							minLen = length;
					}
					sum += minLen;
				}
			}
		}
		if (sum < minLength)
			minLength = sum;
		return;
	}
	for (int i = 0; i < storeLocation.size(); i++) {
		if (!visited[i]) {
			if (num == 0) {
				result[num] = i;
				visited[i] = true;
				combination(result, visited, num + 1);
				visited[i] = false;
			}
			else {
				if (result[num - 1] < i) {
					result[num] = i;
					visited[i] = true;
					combination(result, visited, num + 1);
					visited[i] = false;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(n));
	int temp;
	numOfStore = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			v[i][j] = temp;
			if (temp == 2) {
				numOfStore++;
				storeLocation.push_back(make_pair(i, j));
			}
		}
	}
	combination(vector<int>(m), vector<bool>(numOfStore, false), 0);
	cout << minLength;
	return 0;
}