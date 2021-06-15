#include <iostream>
using namespace std;

int cnt[105][105];

int main() {
	int n, y, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		cnt[y][x]++;
	}
	int aloneCnt = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (cnt[i][j] == 1) aloneCnt++;
		}
	}
	cout << aloneCnt;
	return 0;
}
