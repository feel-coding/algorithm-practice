#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Ball {
	int row, col, power, direction;
	bool exist;
};

int n, m, s, k;
int ballCount[105][105];
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, -1, 1 };
int reverseDirection[5] = { 0, 2, 1, 4, 3 };
Ball balls[55];

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		vector<int> disappearedBalls;
		cin >> n >> m >> s >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ballCount[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			cin >> balls[i].row >> balls[i].col >> balls[i].power >> balls[i].direction;
			ballCount[balls[i].row][balls[i].col]++;
			balls[i].exist = true;
		}
		for (int second = 0; second < s; second++) {
			for (int i = 0; i < k; i++) {
				if (!balls[i].exist) continue;
				int nr = balls[i].row + dr[balls[i].direction];
				int nc = balls[i].col + dc[balls[i].direction];
				if (nr < 1 || nc < 1 || nr >= n - 1 || nc >= m - 1) { // ���� �ε��� ��� ��ġ�� �״��
					balls[i].direction = reverseDirection[balls[i].direction]; // ������ �ݴ��
					balls[i].power /= 2; // ���� ���� ����
					if (balls[i].power == 0) {
						balls[i].exist = false; // ���� 0�� �Ǹ� �������
						disappearedBalls.push_back(i + 1);
						ballCount[balls[i].row][balls[i].col]--;
					}
				}
				else {
					ballCount[balls[i].row][balls[i].col]--;
					ballCount[nr][nc]++;
					balls[i].row = nr;
					balls[i].col = nc;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (ballCount[i][j] > 1) { // �� ��ġ�� �籸���� ���������
						vector<int> crushBalls;
						for (int b = 0; b < k; b++) {
							if (balls[b].exist && balls[b].row == i && balls[b].col == j) {
								crushBalls.push_back(b);
							}
						}
						int maxPowerBall = 1000;
						int maxPower = 0;
						for (int b = 0; b < crushBalls.size(); b++) {
							int ballNum = crushBalls[b];
							if (balls[ballNum].power > maxPower || balls[ballNum].power == maxPower && ballNum < maxPowerBall) {
								maxPowerBall = ballNum;
								maxPower = balls[ballNum].power;
							}
						}
						for (int b = 0; b < crushBalls.size(); b++) {
							int ballNum = crushBalls[b];
							if (ballNum != maxPowerBall) {
								balls[ballNum].exist = false; // ���� ���� �� ���� �����ϰ�� �� �������
								disappearedBalls.push_back(ballNum + 1);
								ballCount[balls[ballNum].row][balls[ballNum].col]--;
							}
						}
						balls[maxPowerBall].power /= 2;
						if (balls[maxPowerBall].exist && balls[maxPowerBall].power == 0) {
							disappearedBalls.push_back(maxPowerBall + 1);
							balls[maxPowerBall].exist = false;
							ballCount[balls[maxPowerBall].row][balls[maxPowerBall].col]--;
						}
					}
				}
			}
		}
		sort(disappearedBalls.begin(), disappearedBalls.end());
		cout << "#" << t << " ";
		if (disappearedBalls.size() == 0) {
			cout << -1 << '\n';
		}
		else {
			for (int i = 0; i < disappearedBalls.size(); i++) {
				cout << disappearedBalls[i] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}