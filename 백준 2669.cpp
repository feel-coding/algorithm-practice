#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> v(100, vector<int>(100));
	int a, b, c, d;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++) {
			for (int k = b; k < d; k++) {
				v[j][k] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (v[i][j] == 1) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}