#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> population;
vector<int> difference;

void select(vector<int> result, int num) {
	if (num == 4) {
		int x = result[0];
		int y = result[1];
		int d1 = result[2];
		int d2 = result[3];
		if (x + d1 + d2 >= n) return;
		if (y - d1 < 0) return;
		if (y + d2 >= n) return;
		if (d1 == 0 || d2 == 0) return;
		vector<vector<int>> map(n, vector<int>(n));
		for (int i = 0; i <= d1; i++) {
			map[x + i][y - i] = 5;
		}
		for (int i = 0; i <= d2; i++) {
			map[x + i][y + i] = 5;
		}
		for (int i = 0; i <= d2; i++) {
			map[x + d1 + i][y - d1 + i] = 5;
		}
		for (int i = 0; i <= d1; i++) {
			map[x + d2 + i][y + d2 - i] = 5;
		}
		for (int i = 1; ; i++) {
			if (x - i >= 0) map[x - i][y] = 1;
			else break;
		}
		for (int i = 1; ; i++) {
			if(y + d2 + i < n) map[x + d2][y + d2 + i] = 2;
			else break;
		}
		for (int i = 1; ; i++) {
			if (y - d1 - i >= 0) map[x + d1][y - d1 - i] = 3;
			else break;
		}
		for (int i = 1; ; i++) {
			if (x + d1 + d2 + i < n) map[x + d1 + d2 + i][y - d1 + d2] = 4;
			else break;
		}
		for (int i = 0; i < n; i++) {
			if (map[i][0] != 0) break;
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0) break;
				map[i][j] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			if (map[i][n - 1] != 0) break;
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j] != 0) break;
				map[i][j] = 2;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (map[i][0] != 0) break;
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0) break;
				map[i][j] = 3;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (map[i][n - 1] != 0) break;
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j] != 0) break;
				map[i][j] = 4;
			}
		}

		int sum[5] = { 0 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				switch (map[i][j]) {
				case 0:
				case 5:
					sum[4] += population[i][j]; break;
				case 1:
					sum[0] += population[i][j]; break;
				case 2:
					sum[1] += population[i][j]; break;
				case 3:
					sum[2] += population[i][j]; break;
				case 4:
					sum[3] += population[i][j]; break;
				}
			}
		}
		int minPopulation = 40000;
		int maxPopulation = 0;
		for (int i = 0; i < 5; i++) {
			if (sum[i] < minPopulation) minPopulation = sum[i];
			if (sum[i] > maxPopulation) maxPopulation = sum[i];
		}
		difference.push_back(maxPopulation - minPopulation);
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		result[num] = i;
		select(result, num + 1);
	}
}


int main() {
	cin >> n;
	population = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> population[i][j];
		}
	}
	vector<int> result(4);
	select(result, 0);
	int totalMin = 40000;
	for (int i = 0; i < difference.size(); i++) {
		if (difference[i] < totalMin) totalMin = difference[i];
	}
	cout << totalMin;
	return 0;
}