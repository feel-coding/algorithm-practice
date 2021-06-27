#include <iostream>
using namespace std;

int arr[1005][5];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	int maxCnt = -1;
	int studentNo;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (arr[i][0] == arr[j][0] || arr[i][1] == arr[j][1] || arr[i][2] == arr[j][2] || arr[i][3] == arr[j][3] || arr[i][4] == arr[j][4]) {
				cnt++;
			}
		}
		if (cnt > maxCnt) {
			maxCnt = cnt;
			studentNo = i + 1;
		}
	}
	cout << studentNo;
	return 0;
}
