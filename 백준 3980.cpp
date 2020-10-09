#include <iostream>
#include <vector>
using namespace std;

int ability[11][11];
vector<int> result(11);
int maxTotal = 0;

void select(vector<bool> visited, int num) {
	if (num == 11) {
		int total = 0;
		for (int i = 0; i < 11; i++) {
			total += ability[i][result[i]];
		}
		if (total > maxTotal) maxTotal = total;
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (ability[num][i] != 0 && !visited[i]) {
			visited[i] = true;
			result[num] = i;
			select(visited, num + 1);
			visited[i] = false;
		}
	}
}


int main() {
	cin.tie(NULL);
	vector<bool> person(11);
	vector<bool> position(11);
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> ability[i][j];
			}
		}
		vector<bool> visited(11);
		maxTotal = 0;
		select(visited, 0);
		cout << maxTotal << '\n';
	}
	return 0;
}