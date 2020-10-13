#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<vector<int>> count(1001,vector<int>(10));
	for (int i = 0; i < 10; i++) {
		count[0][i] = 1;
		count[1][i] = 10 - i;
	}
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				count[i][j] = (count[i][j] + count[i - 1][k]) % 10007;
			}
		}
	}
	int total = 0;
	for (int i = 0; i < 10; i++) {
		total = (total + count[n - 1][i]) % 10007;
	}
	cout << total;
	return 0;
}