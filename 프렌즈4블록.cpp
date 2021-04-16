#include <string>
#include <vector>
using namespace std;

vector<string> arr;
int cnt = 0;
int width;
int height;

int erase() {
	int eraseCount = 0;
	vector<vector<bool>> check(height, vector<bool>(width, false));
	for (int i = 0; i < height - 1; i++) {
		for (int j = 0; j < width - 1; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j + 1]) {
				check[i][j] = true;
				check[i + 1][j] = true;
				check[i][j + 1] = true;
				check[i + 1][j + 1] = true;
			}
		}
	}
	for (int col = 0; col < width; col++) {
		vector<char> tempChar;
		for (int i = height - 1; i >= 0; i--) {
			if (!check[i][col] && arr[i][col] != '0') {
				tempChar.push_back(arr[i][col]);
			}
		}
		int row = height - 1;
		for (int i = 0; i < tempChar.size(); i++) {
			arr[row--][col] = tempChar[i];
		}
		for (int i = 0; i < height - tempChar.size(); i++) {
			if (arr[i][col] != '0') {
				arr[i][col] = '0';
				eraseCount++;
			}
		}
	}
	return eraseCount;
}

int solution(int n, int m, vector<string> board) {
	int answer = 0;
	width = m;
	height = n;
	for (int i = 0; i < board.size(); i++) {
		arr.push_back(board[i]);
	}
	while (true) {
		int result = erase();
		if (result == 0) break;
		cnt += result;
	}
	return cnt;
}