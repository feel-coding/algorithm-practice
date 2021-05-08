#include <iostream>
using namespace std;

int arr[105][3];

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || j == k || i == k) continue;
				bool flag = true;
				for (int q = 0; q < n; q++) {
					int first = arr[q][0] / 100;
					int second = arr[q][0] / 10 % 10;
					int third = arr[q][0] % 10;
					int strike = 0;
					int ball = 0;
					if (i == first) strike++;
					if (j == second) strike++;
					if (k == third) strike++;
					if (j == first || k == first) ball++;
					if (i == second || k == second) ball++;
					if (i == third || j == third) ball++;
					if (strike != arr[q][1] || ball != arr[q][2]) {
						flag = false;
						break;
					}
				}
				if (flag) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
