#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> locationX(19);
	vector<vector<int>> locationY(19);
	locationX[0] = { 0, 0, 0, 0 };
	locationY[0] = { 0, 1, 2, 3 }; // 가로 일직선
	locationX[1] = { 0, 1, 2, 3 };
	locationY[1] = { 0, 0, 0, 0 }; // 세로 일직선
	locationX[2] = { 0, 0, 1, 1 };
	locationY[2] = { 0, 1, 0, 1 }; // 정사각형
	locationX[3] = { 0, 1, 2, 2 };
	locationY[3] = { 0, 0, 0, 1 }; // └
	locationX[4] = { 0, 0, 0, 1 };
	locationY[4] = { 0, 1, 2, 0 }; // ┌
	locationX[5] = { 0, 0, 1, 2 };
	locationY[5] = { 0, 1, 1, 1 }; // ┐
	locationX[6] = { 0, 0, 0, -1 };
	locationY[6] = { 0, 1, 2, 2 }; // ┘
	locationX[7] = { 0, 0, -1, -2 };
	locationY[7] = { 0, 1, 1, 1 }; // ┘
	locationX[8] = { 0, 0, 0, 1 };
	locationY[8] = { 0, 1, 2, 2 }; // ㄱ
	locationX[9] = { 0, 0, 1, 2 };
	locationY[9] = { 0, 1, 0, 0 }; // ┌
	locationX[10] = { 0, 1, 1, 1 };
	locationY[10] = { 0, 0, 1, 2 }; // ㄴ
	locationX[11] = { 0, 1, 1, 2 };
	locationY[11] = { 0, 0, 1, 1 }; // └┐
	locationX[12] = { 0, 0, -1, -1 };
	locationY[12] = { 0, 1, 1, 2 }; // ┘┌
	locationX[13] = { 0, -1, -1, -2 };
	locationY[13] = { 0, 0, 1, 1 }; // ┌┘
	locationX[14] = { 0, 0, 1, 1 };
	locationY[14] = { 0, 1, 1, 2 }; // ┐└
	locationX[15] = { 0, 0, 0, 1 };
	locationY[15] = { 0, 1, 2, 1 }; // ┬
	locationX[16] = { 0, 0, 0, -1 };
	locationY[16] = { 0, 1, 2, 1 }; // ┴
	locationX[17] = { 0, 1, 2, 1 };
	locationY[17] = { 0, 0, 0, -1 }; // ┤
	locationX[18] = { 0, 1, 2, 1 };
	locationY[18] = { 0, 0, 0, 1 }; // ├
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	int maxSum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				int sum = 0;
				for (int l = 0; l < 4; l++) {
					int row = i + locationX[k][l];
					int col = j + locationY[k][l];
					if (row >= 0 && row < n && col >= 0 && col < m) {
						sum += v[row][col];
					}
					else {
						sum = -1;
						break;
					}
				}
				if (sum > maxSum) {
					maxSum = sum;
				}
			}
		}
	}
	cout << maxSum;
	return 0;
}
