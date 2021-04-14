#include <iostream>
using namespace std;

int n;
int arr[25][25];
bool visited[105];

int getTotalProtein(int row, int col) {
	for (int i = 0; i < n; i++) {
		int weight = arr[i][col];
		visited[weight] = true;
	}
	for (int i = 0; i < n; i++) {
		int weight = arr[row][i];
		visited[weight] = true;
	}
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (visited[i]) {
			sum += i;
			visited[i] = false;
		}
	}
	return sum;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int maxProtein = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				int protein = getTotalProtein(i, j);
				if (protein > maxProtein) {
					maxProtein = protein;
				}
			}
		}
		cout << "#" << t << " " << maxProtein << endl;
	}
	return 0;
}
