#include <iostream>
using namespace std;

int scores[4][30] = { {0, 5, 10, 15, 20, 50, 30, 35, 40, 45, 100, 55, 60, 65, 70, 75, 80, 85, 90, 95, 500, 1000},
					 {0, 5, 10, 15, 20, 50, 275, 250, 300, 150, 175, 75, 80, 85, 90, 95, 500, 1000},
					 {0, 5, 10, 15, 20, 50, 30, 35, 40, 45, 100, 150, 125, 300, 350, 400, 500, 1000},
					 {0, 5, 10, 15, 20, 50, 275, 250, 300, 350, 400, 500, 1000} };
int arr[2][10];
int scoreType[5];
int currentLocation[5];
int currentScore[5];
int maxScore = -1;

bool isAlreadyExist(int score) {
	for (int i = 1; i <= 4; i++) {
		if (currentScore[i] == score) return true;
	}
	return false;
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int flag = true;
		for (int i = 1; i <= 4; i++) {
			scoreType[i] = 0;
			currentLocation[i] = 0;
			currentScore[i] = 0;
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < 10; i++) {
			bool arrived = false;
			int horse = arr[1][i]; // 몇 번 말을
			int move = arr[0][i]; // 몇 칸 움직인다
			currentLocation[horse] += move; // horse번 말을 move만큼 움직인다
			int score;
			if (scores[scoreType[horse]][currentLocation[horse]] == 50) {
				scoreType[horse] = 1;
				score = 50;
			}
			else if (scores[scoreType[horse]][currentLocation[horse]] == 100) {
				scoreType[horse] = 2;
				score = 100;
			}
			else if (scores[scoreType[horse]][currentLocation[horse]] == 300) {
				scoreType[horse] = 3;
				score = 300;
			}
			else if (scores[scoreType[horse]][currentLocation[horse]] == 0 || scores[scoreType[horse]][currentLocation[horse]] == 1000) {
				currentLocation[horse] = 0;
				score = 1000;
				arrived = true;
			}
			else score = scores[scoreType[horse]][currentLocation[horse]];
			if (!arrived) {
				if (isAlreadyExist(score)) {
					flag = false;
					break;
				}
			}
			currentScore[horse] = score;
		}
		if (flag) {
			int total = 0;
			for (int i = 1; i <= 4; i++) {
				total += currentScore[i];
			}
			if (total > maxScore) maxScore = total;
		}
	}
	cout << maxScore;
	return 0;
}